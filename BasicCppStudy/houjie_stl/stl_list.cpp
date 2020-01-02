#include "pch.h"

namespace stl_list
{
// _list_node_base
// why?
// 父类的成员变量在内存中在前，子类的成员变量在后，因为前驱和后继的指向，只需要确定出
// 前驱、后继 node的起始地址就好，与具体的data的类型无关，更安全？ 是因为这个么？
struct _List_node_base
{
	_List_node_base* _M_next;
	_List_node_base* _M_prev;
};
// node 
template <class T>
struct _List_node: public _List_node_base
{
	T _M_data;//3 
};

// iterator
template <class T>
struct _list_iterator
{
	typedef _list_iterator<T> self;//0
	//typedef bidirectional_iterator_tag iterator_category;// 1
	typedef T value_type;//2
	typedef T* pointer; //3
	typedef T& reference;//4
	typedef ptrdiff_t difference_type; // 5
	typedef _List_node<T>* link_type;
	link_type node;


// operator overloading
	// prefix ++
	self& operator++()
	{
		node = (link_type)((*node)._M_next);// 将迭代器指向了下一个位置；
		return *this;// 把修改成指向下一个元素的本迭代器对象，以引用的形式返回；
	}
	// postfix ++
	self operator++(int) // 难道是编译器能识别出来?
	{
		self tmp = *this;
		++(*this);//不会调用 * 的运算符重载函数，原因？ （因为++先被调用执行？）
		return tmp;
	}
	// * 
	reference operator* ()const // 必须是const 么？为啥不能修改值，stl::list 是可以修改的。 不能修改指向和引用，没说不能修改指向或者引用的值
	{
		return (*node)._M_data;// *this 返回的是迭代器本身，但是为了习惯方便，我们直接返回迭代器所包含的data值。
	}
	// ->
	pointer operator->() const // 
	{
		return &(operator*()); // 等于返回元素的指针
	}
	// copy ctor
	_list_iterator(const _list_iterator& x): node(x.node){}
	// using node ctor
	_list_iterator( link_type& node): node(node){}
	// default
	_list_iterator(){}
};

// list class
template <class T>
class list
{
protected:
	typedef _List_node<T> list_node; // 只能在类的内部使用
public:
	typedef list_node* link_type;// 可在类外部使用，通过类名 ::
	typedef _list_iterator<T> iterator;
protected:
	link_type node;
public:
	iterator begin()
	{
		return iterator((link_type)node->_M_next);
	}
	iterator end()
	{
		return iterator(node);
	}
};


void test_mylist()
{
	list<int>::iterator iter;

}

}






// typedef 的作用
// 注意作用域，如果定义为public的，则可以在函数体外部使用，list<int>::link_type t;