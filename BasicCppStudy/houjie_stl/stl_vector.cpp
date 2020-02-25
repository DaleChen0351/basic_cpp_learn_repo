#include "pch.h"

namespace stl_vector
{

// vector
template <class T, class Alloc = std::allocator<T>>
class vector
{
public:
	typedef T value_type;
	typedef value_type* iterator;// 退化的迭代器，指针就够了
	typedef value_type& reference; 
	typedef size_t size_type // unsigned int
// protected 内部使用？
protected:
	iterator start;
	iterator finish;
	iterator end_of_storage;
public:
	iterator begin() { return start; }
	iterator end() { return finish; }
	size_type size() const 
	{
		return size_type(end() - begin());
	}
	size_type capacity() 
	{
		return size_type(end_of_storage - begin());
	}
	bool isEmpty() const { return begin == end();}
	reference operator[] (size_type n)// 具有连续空间特性的容器都需要提供重载[] 这个函数
	{
		return *(begin() + n);
	}
	reference front() { return *begin(); }
	reference back() { return *(end() - 1); }
	void push_back(const T & x);
	void insert_aux(iterator position, const T& x);

};
template <class T, class Alloc>
void vector<T, Alloc>::push_back(const T& x)
{
	if (finish != end_of_storage)
	{
		// ctor  调用传入元素的复制构造函数？
		++finish;
	}
	else
	{
		insert_aux(end(), x);
	}
}
template <class T, class Alloc>
void vector<T, Alloc>::insert_aux(iterator position, const T& x)
{
	const size_type old_size = size();
	const size_type len = old_size != 0 ? 2 * old_size : 1;
	// 调整 迭代器
	iterator new_start = len// len 分配新的长度
	iterator new_finish = new_start;
	// 分配内存
	try
	{
		// 将原vector的内容拷贝构造到新申请的空间，
		// 将push_back 传入的元素也添加到新空间的最后一个位置，并调整finish迭代器
		

	}
	catch (const std::exception&)
	{

	}

}


















}

