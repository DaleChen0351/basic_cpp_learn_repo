#include "pch.h"

namespace stl_list
{
// node 
template <class T>
struct _list_node
{
	typedef void* void_pointer;
	void_pointer prev;// 1
	void_pointer next;//2
	T data;//3 
};

// iterator
template <class T, class Ref, class Ptr>
struct _list_iterator
{
	typedef _list_iterator<T, Ref, Ptr> self;//0
	typedef bidirectional_iterator_tag iterator_category;// 1
	typedef T value_type;//2
	typedef Ptr pointer; //3
	typedef Ref reference;//4
	typedef ptrdiff_t difference_type; // 5
	typedef _list_node<T>* link_type;
	link_type node;


// operator overloading
	// prefix ++
	self& operator++()
	{
		node = (link_type)((*node).next);// ��������ָ������һ��λ�ã�
		return *this;// ���޸ĳ�ָ����һ��Ԫ�صı����������������õ���ʽ���أ�
	}
	// postfix ++
	self operator++(int) // �ѵ��Ǳ�������ʶ�����?
	{
		self tmp = *this;
		++(*this);//������� * ����������غ�����ԭ�� ����Ϊ++�ȱ�����ִ�У���
		return tmp;
	}
	// * 
	reference operator* ()const // ������const ô��Ϊɶ�����޸�ֵ��stl::list �ǿ����޸ĵġ� �����޸�ָ������ã�û˵�����޸�ָ��������õ�ֵ
	{
		return (*node).data;// *this ���ص��ǵ�������������Ϊ��ϰ�߷��㣬����ֱ�ӷ��ص�������������dataֵ��
	}
	// ->
	pointer operator->() const // 
	{
		return &(operator*()); // ���ڷ���Ԫ�ص�ָ��
	}
};
// list class
template <class T>
class list
{
protected:
	typedef _list_node<T> list_node; // ֻ��������ڲ�ʹ��
public:
	typedef list_node* link_type;// �������ⲿʹ�ã�ͨ������ ::
	typedef _list_iterator<T, T&, T*> iterator;
protected:
	link_type node;
};

void test_mylist()
{
	list<int>::iterator iter;

}

}






// typedef ������
// ע���������������Ϊpublic�ģ�������ں������ⲿʹ�ã�list<int>::link_type t;