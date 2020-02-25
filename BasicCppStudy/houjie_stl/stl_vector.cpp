#include "pch.h"

namespace stl_vector
{

// vector
template <class T, class Alloc = std::allocator<T>>
class vector
{
public:
	typedef T value_type;
	typedef value_type* iterator;// �˻��ĵ�������ָ��͹���
	typedef value_type& reference; 
	typedef size_t size_type // unsigned int
// protected �ڲ�ʹ�ã�
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
	reference operator[] (size_type n)// ���������ռ����Ե���������Ҫ�ṩ����[] �������
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
		// ctor  ���ô���Ԫ�صĸ��ƹ��캯����
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
	// ���� ������
	iterator new_start = len// len �����µĳ���
	iterator new_finish = new_start;
	// �����ڴ�
	try
	{
		// ��ԭvector�����ݿ������쵽������Ŀռ䣬
		// ��push_back �����Ԫ��Ҳ��ӵ��¿ռ�����һ��λ�ã�������finish������
		

	}
	catch (const std::exception&)
	{

	}

}


















}

