#pragma once

struct _List_node_base {
	_List_node_base* _M_next;
	_List_node_base* _M_prev;
};

template <class _Tp>
struct _List_node : public _List_node_base {
	_Tp _M_data;
};

struct _List_iterator_base {
	typedef size_t                     size_type;
	typedef ptrdiff_t                  difference_type;
	typedef bidirectional_iterator_tag iterator_category;   //迭代器为双向迭代器

	_List_node_base* _M_node;   //迭代器使用_List_node_base*标志其指向

	_List_iterator_base(_List_node_base* __x) : _M_node(__x) {}// copy ctor
	_List_iterator_base() {}

	void _M_incr() { _M_node = _M_node->_M_next; }
	void _M_decr() { _M_node = _M_node->_M_prev; }

	bool operator==(const _List_iterator_base& __x) const {
		return _M_node == __x._M_node;// copy and assign
	}
	bool operator!=(const _List_iterator_base& __x) const {
		return _M_node != __x._M_node;
	}
};

template<class _Tp, class _Ref, class _Ptr>
struct _List_iterator : public _List_iterator_base {
	typedef _List_iterator<_Tp, _Tp&, _Tp*>             iterator;
	typedef _List_iterator<_Tp, const _Tp&, const _Tp*> const_iterator;
	typedef _List_iterator<_Tp, _Ref, _Ptr>             _Self;

	typedef _Tp value_type;
	typedef _Ptr pointer;
	typedef _Ref reference;
	typedef _List_node<_Tp> _Node;   //实际指向的类型

	_List_iterator(_Node* __x) : _List_iterator_base(__x) {}// 用子类的指针初始化父类指针
	_List_iterator() {}
	_List_iterator(const iterator& __x) : _List_iterator_base(__x._M_node) {}// copy ctor


	reference operator*() const { //该函数虽然可能修改结点的值,但因迭代器对象只保存
													   //指向结点的指针,因此仍然声明为const
		return ((_Node*)_M_node)->_M_data;
	}

	pointer operator->() const { return &(operator*()); }

	_Self& operator++() {
		this->_M_incr();
		return *this;
	}
	_Self operator++(int) {
		_Self __tmp = *this;
		this->_M_incr();
		return __tmp;
	}
	_Self& operator--() {
		this->_M_decr();
		return *this;
	}
	_Self operator--(int) {
		_Self __tmp = *this;
		this->_M_decr();
		return __tmp;
	}
};

inline bidirectional_iterator_tag
iterator_category(const _List_iterator_base&)
{
	return bidirectional_iterator_tag();
}

template <class _Tp, class _Ref, class _Ptr>
inline _Tp*
value_type(const _List_iterator<_Tp, _Ref, _Ptr>&)
{
	return 0;
}

inline ptrdiff_t*
distance_type(const _List_iterator_base&)
{
	return 0;
}


template <class _Tp, class _Alloc>
class _List_base
{
public:
	typedef _Alloc allocator_type;
	allocator_type get_allocator() const { return allocator_type(); }

	_List_base(const allocator_type&) {
		//唯一的构造函数,规定了list为空时的合法状态:头结点的前后指针均指向其自身
		_M_node = _M_get_node();
		_M_node->_M_next = _M_node;
		_M_node->_M_prev = _M_node;
	}
	~_List_base() {
		clear();    //将每个结点清楚
		_M_put_node(_M_node);  //将头结点归还
	}

	void clear();

protected:
	typedef simple_alloc<_List_node<_Tp>, _Alloc> _Alloc_type;

	_List_node<_Tp>* _M_get_node() { return _Alloc_type::allocate(1); }// dale 分配一个节点，返回地址
	void _M_put_node(_List_node<_Tp>* __p) { _Alloc_type::deallocate(__p, 1); }

protected:
	_List_node<_Tp>* _M_node;   ///头结点指针,为实指节点类型
};

template <class _Tp, class _Alloc>
void
_List_base<_Tp, _Alloc>::clear()
{
	//由于结点的_M_next均为基类指针,而基类指针不能直接初始化或者赋值给
	//派生类指针,因此需要强制类型转化,已将_M_node->_M_next强制转化为其
	//实质类型的指针.
	_List_node<_Tp>* __cur = (_List_node<_Tp>*) (_M_node->_M_next);
	while (__cur != _M_node) {
		_List_node<_Tp>* __tmp = __cur;
		__cur = (_List_node<_Tp>*) (__cur->_M_next);
		_Destroy(&__tmp->_M_data);    //析构结点数据元素
		_M_put_node(__tmp);         //归还结点内存
	}

	//使链表恢复合法状态
	_M_node->_M_next = _M_node;
	_M_node->_M_prev = _M_node;
}

template <class _Tp, class _Alloc = __STL_DEFAULT_ALLOCATOR(_Tp) >
class list : protected _List_base<_Tp, _Alloc> {

	__STL_CLASS_REQUIRES(_Tp, _Assignable);

	typedef _List_base<_Tp, _Alloc> _Base;
protected:
	typedef void* _Void_pointer;

public:
	typedef _Tp value_type;
	typedef value_type* pointer;
	typedef const value_type* const_pointer;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef _List_node<_Tp> _Node;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;

	typedef typename _Base::allocator_type allocator_type;
	allocator_type get_allocator() const { return _Base::get_allocator(); }

public:
	typedef _List_iterator<_Tp, _Tp&, _Tp*>             iterator;
	typedef _List_iterator<_Tp, const _Tp&, const _Tp*> const_iterator;

	typedef reverse_bidirectional_iterator<const_iterator, value_type,
		const_reference, difference_type>
		const_reverse_iterator;
	typedef reverse_bidirectional_iterator<iterator, value_type, reference,
		difference_type>
		reverse_iterator;

protected:
	using _Base::_M_node;
	using _Base::_M_put_node;
	using _Base::_M_get_node;

protected:
	_Node* _M_create_node(const _Tp& __x)  //用特定数据构造结点
	{
		_Node* __p = _M_get_node();
		try {
			_Construct(&__p->_M_data, __x);
		}
		catch (...) {
			_M_put_node(__p);
		}
		return __p;
	}

	_Node* _M_create_node()   ///构造含默认值的结点
	{
		_Node* __p = _M_get_node();
		try {
			_Construct(&__p->_M_data);
		}
		catch (...) {
			_M_put_node(__p);
		}

		return __p;
	}

public:
	explicit list(const allocator_type& __a = allocator_type()) : _Base(__a) {}

	iterator begin() {
		//此处亦必须强制进行指针类型转化,因为iterator类构造函数只接受
		//派生类指针,而_M_node->_M_next为基类指针,不能自动转化
		return (_Node*)(_M_node->_M_next);// ctor 
	}
	const_iterator begin() const { return (_Node*)(_M_node->_M_next); }

	iterator end() { return _M_node; } // current 
	const_iterator end() const { return _M_node; }

	reverse_iterator rbegin()
	{
		return reverse_iterator(end());
	}
	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(end());
	}

	reverse_iterator rend()
	{
		return reverse_iterator(begin());
	}
	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(begin());
	}

	bool empty() const { return _M_node->_M_next == _M_node; }
	size_type size() const {
		///list的size函数需要遍历整个list
		size_type __result = 0;
		distance(begin(), end(), __result);
		return __result;
	}
	size_type max_size() const { return size_type(-1); }

	reference front() { return *begin(); }
	const_reference front() const { return *begin(); }
	reference back() { return *(--end()); }
	const_reference back() const { return *(--end()); }

	///list的swap函数只需交换各自的头指针
	void swap(list<_Tp, _Alloc>& __x) { __STD::swap(_M_node, __x._M_node); }

	iterator insert(iterator __position, const _Tp& __x) {
		///该函数只需生成一个新节点,然后修改相关指针将该节点“链”到合适位置即可
		_Node* __tmp = _M_create_node(__x);
		__tmp->_M_next = __position._M_node;
		__tmp->_M_prev = __position._M_node->_M_prev;
		__position._M_node->_M_prev->_M_next = __tmp;
		__position._M_node->_M_prev = __tmp;
		return __tmp;
	}
	iterator insert(iterator __position) { return insert(__position, _Tp()); }

	/// Check whether it's an integral type.  If so, it's not an iterator.
	template<class _Integer>
	void _M_insert_dispatch(iterator __pos, _Integer __n, _Integer __x,
		__true_type) {
		_M_fill_insert(__pos, (size_type)__n, (_Tp)__x);
	}

	template <class _InputIterator>
	void _M_insert_dispatch(iterator __pos,
		_InputIterator __first, _InputIterator __last,
		__false_type);

	template <class _InputIterator>
	void insert(iterator __pos, _InputIterator __first, _InputIterator __last) {
		typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
		_M_insert_dispatch(__pos, __first, __last, _Integral());
	}


	void insert(iterator __pos, size_type __n, const _Tp& __x)
	{
		_M_fill_insert(__pos, __n, __x);
	}

	void _M_fill_insert(iterator __pos, size_type __n, const _Tp& __x); ///在x前插入n个x

	void push_front(const _Tp& __x) { insert(begin(), __x); }
	void push_front() { insert(begin()); }
	void push_back(const _Tp& __x) { insert(end(), __x); }
	void push_back() { insert(end()); }

	iterator erase(iterator __position) {
		_List_node_base* __next_node = __position._M_node->_M_next;
		_List_node_base* __prev_node = __position._M_node->_M_prev;
		_Node* __n = (_Node*)__position._M_node;
		__prev_node->_M_next = __next_node;
		__next_node->_M_prev = __prev_node;
		_Destroy(&__n->_M_data);
		_M_put_node(__n);
		return iterator((_Node*)__next_node);
	}
	iterator erase(iterator __first, iterator __last);
	void clear() { _Base::clear(); }

	void resize(size_type __new_size, const _Tp& __x);
	void resize(size_type __new_size) { this->resize(__new_size, _Tp()); }

	void pop_front() { erase(begin()); }
	void pop_back() {
		iterator __tmp = end();
		erase(--__tmp);
	}

	list(size_type __n, const _Tp& __value,
		const allocator_type& __a = allocator_type()) : _Base(__a)
	{
		insert(begin(), __n, __value);
	}

	explicit list(size_type __n) : _Base(allocator_type())
	{
		insert(begin(), __n, _Tp());
	}


	/// We don't need any dispatching tricks here, because insert does all of
	/// that anyway.
	template <class _InputIterator>
	list(_InputIterator __first, _InputIterator __last,
		const allocator_type& __a = allocator_type())
		: _Base(__a)
	{
		insert(begin(), __first, __last);
	}

	list(const list<_Tp, _Alloc>& __x) : _Base(__x.get_allocator())
	{
		insert(begin(), __x.begin(), __x.end());
	}

	~list() { }  ///善后留给基类中的析构函数

	list<_Tp, _Alloc>& operator=(const list<_Tp, _Alloc>& __x);

public:
	/// assign(), a generalized assignment member function.  Two
	/// versions: one that takes a count, and one that takes a range.
	/// The range version is a member template, so we dispatch on whether
	/// or not the type is an integer.

	void assign(size_type __n, const _Tp& __val) { _M_fill_assign(__n, __val); }

	void _M_fill_assign(size_type __n, const _Tp& __val);


	template <class _InputIterator>
	void assign(_InputIterator __first, _InputIterator __last) {
		typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
		_M_assign_dispatch(__first, __last, _Integral());
	}

	template <class _Integer>
	void _M_assign_dispatch(_Integer __n, _Integer __val, __true_type)
	{
		_M_fill_assign((size_type)__n, (_Tp)__val);
	}

	template <class _InputIterator>
	void _M_assign_dispatch(_InputIterator __first, _InputIterator __last,
		__false_type);


protected:
	///将[first,last)从原位置中摘下来,插入到position之前
	///这个函数主要通过指针的修改来完成
	void transfer(iterator __position, iterator __first, iterator __last) {
		if (__position != __last) {
			/// Remove [first, last) from its old position.
			__last._M_node->_M_prev->_M_next = __position._M_node;
			__first._M_node->_M_prev->_M_next = __last._M_node;
			__position._M_node->_M_prev->_M_next = __first._M_node;

			/// Splice [first, last) into its new position.
			_List_node_base* __tmp = __position._M_node->_M_prev;
			__position._M_node->_M_prev = __last._M_node->_M_prev;
			__last._M_node->_M_prev = __first._M_node->_M_prev;
			__first._M_node->_M_prev = __tmp;
		}
	}

public:
	///将x链入本链表position之前
	void splice(iterator __position, list& __x) {
		if (!__x.empty())
			this->transfer(__position, __x.begin(), __x.end());
	}

	///将i所指结点摘下来,插入到position之前
	void splice(iterator __position, list&, iterator __i) {
		iterator __j = __i;
		++__j;
		if (__position == __i || __position == __j) return;
		this->transfer(__position, __i, __j);
	}

	void splice(iterator __position, list&, iterator __first, iterator __last) {
		if (__first != __last)
			this->transfer(__position, __first, __last);
	}
	void remove(const _Tp& __value);
	void unique();
	void merge(list& __x);
	void reverse();
	void sort();

	template <class _Predicate> void remove_if(_Predicate);
	template <class _BinaryPredicate> void unique(_BinaryPredicate);
	template <class _StrictWeakOrdering> void merge(list&, _StrictWeakOrdering);
	template <class _StrictWeakOrdering> void sort(_StrictWeakOrdering);
};

template <class _Tp, class _Alloc>
inline bool
operator==(const list<_Tp, _Alloc>& __x, const list<_Tp, _Alloc>& __y)
{
	///此处必须使用const_iterator,因const list所得到的迭代器均为const_iterator
	typedef typename list<_Tp, _Alloc>::const_iterator const_iterator;
	const_iterator __end1 = __x.end();
	const_iterator __end2 = __y.end();

	const_iterator __i1 = __x.begin();
	const_iterator __i2 = __y.begin();
	while (__i1 != __end1 && __i2 != __end2 && *__i1 == *__i2) {
		++__i1;
		++__i2;
	}
	return __i1 == __end1 && __i2 == __end2;
}

template <class _Tp, class _Alloc>
inline bool operator<(const list<_Tp, _Alloc>& __x,
	const list<_Tp, _Alloc>& __y)
{
	return lexicographical_compare(__x.begin(), __x.end(),
		__y.begin(), __y.end());
}
template <class _Tp, class _Alloc>
template <class _InputIter>
void
list<_Tp, _Alloc>::_M_insert_dispatch(iterator __position,
	_InputIter __first, _InputIter __last,
	__false_type)
{
	for (; __first != __last; ++__first)
		insert(__position, *__first);
}
template <class _Tp, class _Alloc>
void
list<_Tp, _Alloc>::_M_fill_insert(iterator __position,
	size_type __n, const _Tp& __x)
{
	for (; __n > 0; --__n)
		insert(__position, __x);
}

template <class _Tp, class _Alloc>
typename list<_Tp, _Alloc>::iterator list<_Tp, _Alloc>::erase(iterator __first,
	iterator __last)
{
	while (__first != __last)
		erase(__first++);
	return __last;
}

template <class _Tp, class _Alloc>
void list<_Tp, _Alloc>::resize(size_type __new_size, const _Tp& __x)
{
	iterator __i = begin();
	size_type __len = 0;
	for (; __i != end() && __len < __new_size; ++__i, ++__len);

	if (__len == __new_size)        ///__new_size <= this->size()
		erase(__i, end());
	else                          /// __new_size > this->size()
		insert(end(), __new_size - __len, __x);
}

template <class _Tp, class _Alloc>
list<_Tp, _Alloc>& list<_Tp, _Alloc>::operator=(const list<_Tp, _Alloc>& __x)
{
	if (this != &__x) {
		iterator __first1 = begin();
		iterator __last1 = end();
		const_iterator __first2 = __x.begin();
		const_iterator __last2 = __x.end();

		///先挨个赋值
		while (__first1 != __last1 && __first2 != __last2)
			*__first1++ = *__first2++;

		if (__first2 == __last2)    ///x.size() <= this->size()
			erase(__first1, __last1);
		else                                        ///x.size() > this->size()
			insert(__last1, __first2, __last2);
	}
	return *this;
}

template <class _Tp, class _Alloc>
void list<_Tp, _Alloc>::_M_fill_assign(size_type __n, const _Tp& __val) {
	iterator __i = begin();
	for (; __i != end() && __n > 0; ++__i, --__n)
		*__i = __val;
	if (__n > 0)
		insert(end(), __n, __val);
	else
		erase(__i, end());
}

template <class _Tp, class _Alloc>
template <class _InputIter>
void
list<_Tp, _Alloc>::_M_assign_dispatch(_InputIter __first2, _InputIter __last2,
	__false_type)
{
	iterator __first1 = begin();
	iterator __last1 = end();
	for (; __first1 != __last1 && __first2 != __last2; ++__first1, ++__first2)
		*__first1 = *__first2;
	if (__first2 == __last2)
		erase(__first1, __last1);
	else
		insert(__last1, __first2, __last2);
}


template <class _Tp, class _Alloc>
void list<_Tp, _Alloc>::remove(const _Tp& __value)
{
	iterator __first = begin();
	iterator __last = end();
	while (__first != __last) {
		iterator __next = __first;
		++__next;
		if (*__first == __value) erase(__first);
		__first = __next;
	}
}

template <class _Tp, class _Alloc>
void list<_Tp, _Alloc>::unique()
{
	iterator __first = begin();
	iterator __last = end();
	if (__first == __last) return;
	iterator __next = __first;
	while (++__next != __last) {
		if (*__first == *__next)
			erase(__next);
		else
			__first = __next;

		__next = __first;
	}
}

///将两个非递增排序的链表合并为一个非递增排序的链表
///合并后x链表为空
template <class _Tp, class _Alloc>
void list<_Tp, _Alloc>::merge(list<_Tp, _Alloc>& __x)
{
	iterator __first1 = begin();
	iterator __last1 = end();
	iterator __first2 = __x.begin();
	iterator __last2 = __x.end();
	while (__first1 != __last1 && __first2 != __last2)
		if (*__first2 < *__first1) {
			iterator __next = __first2;
			transfer(__first1, __first2, ++__next);
			__first2 = __next;
		}
		else
			++__first1;
	if (__first2 != __last2) transfer(__last1, __first2, __last2);
}

///从指针p开始,将list翻转
inline void __List_base_reverse(_List_node_base* __p)
{
	_List_node_base* __tmp = __p;
	do {
		__STD::swap(__tmp->_M_next, __tmp->_M_prev);
		__tmp = __tmp->_M_prev;     /// Old next node is now prev.

	} while (__tmp != __p);     ///由于是循环链表,故指针再次指向p时,说明list翻转完毕
}

template <class _Tp, class _Alloc>
inline void list<_Tp, _Alloc>::reverse()
{
	__List_base_reverse(this->_M_node);
}

///由于STL sort算法要求必须为随机迭代器,因此list实现了自己的专用sort算法
///该算法采用的是归并排序的思想
template <class _Tp, class _Alloc>
void list<_Tp, _Alloc>::sort()
{
	/// Do nothing if the list has length 0 or 1.
	if (_M_node->_M_next != _M_node && _M_node->_M_next->_M_next != _M_node) {
		list<_Tp, _Alloc> __carry;
		list<_Tp, _Alloc> __counter[64];
		int __fill = 0;
		while (!empty()) {

			__carry.splice(__carry.begin(), *this, begin());  ///__carry得到list第一个元素
			int __i = 0;

			///此循环将counter[__fill]之前所有非空链表合并为一个链表
			while (__i < __fill && !__counter[__i].empty()) {
				__counter[__i].merge(__carry);     ///此时__carry为空
				__carry.swap(__counter[__i++]);    ///此时__counter[i]为空,i变为i+1
			}
			__carry.swap(__counter[__i]);   ///至此处i之前的所有链表均被合并至__counter[i]
			if (__i == __fill) ++__fill;
		}

		for (int __i = 1; __i < __fill; ++__i)
			__counter[__i].merge(__counter[__i - 1]);

		swap(__counter[__fill - 1]);
	}
}


template <class _Tp, class _Alloc> template <class _Predicate>
void list<_Tp, _Alloc>::remove_if(_Predicate __pred)
{
	iterator __first = begin();
	iterator __last = end();
	while (__first != __last) {
		iterator __next = __first;
		++__next;      ///必须先得到下一个节点位置,再删除当前结点,否则将无法找到下一个结点
		if (__pred(*__first)) erase(__first);
		__first = __next;
	}
}

template <class _Tp, class _Alloc> template <class _BinaryPredicate>
void list<_Tp, _Alloc>::unique(_BinaryPredicate __binary_pred)
{
	iterator __first = begin();
	iterator __last = end();
	if (__first == __last) return;
	iterator __next = __first;
	while (++__next != __last) {
		if (__binary_pred(*__first, *__next))
			erase(__next);
		else
			__first = __next;
		__next = __first;
	}
}

template <class _Tp, class _Alloc> template <class _StrictWeakOrdering>
void list<_Tp, _Alloc>::merge(list<_Tp, _Alloc>& __x,
	_StrictWeakOrdering __comp)
{
	iterator __first1 = begin();
	iterator __last1 = end();
	iterator __first2 = __x.begin();
	iterator __last2 = __x.end();
	while (__first1 != __last1 && __first2 != __last2)
		if (__comp(*__first2, *__first1)) {
			iterator __next = __first2;
			transfer(__first1, __first2, ++__next);
			__first2 = __next;
		}
		else
			++__first1;
	if (__first2 != __last2) transfer(__last1, __first2, __last2);
}

template <class _Tp, class _Alloc> template <class _StrictWeakOrdering>
void list<_Tp, _Alloc>::sort(_StrictWeakOrdering __comp)
{
	/// Do nothing if the list has length 0 or 1.
	if (_M_node->_M_next != _M_node && _M_node->_M_next->_M_next != _M_node) {
		list<_Tp, _Alloc> __carry;
		list<_Tp, _Alloc> __counter[64];
		int __fill = 0;
		while (!empty()) {
			__carry.splice(__carry.begin(), *this, begin());
			int __i = 0;
			while (__i < __fill && !__counter[__i].empty()) {
				__counter[__i].merge(__carry, __comp);
				__carry.swap(__counter[__i++]);
			}
			__carry.swap(__counter[__i]);
			if (__i == __fill) ++__fill;
		}

		for (int __i = 1; __i < __fill; ++__i)
			__counter[__i].merge(__counter[__i - 1], __comp);
		swap(__counter[__fill - 1]);
	}
}

