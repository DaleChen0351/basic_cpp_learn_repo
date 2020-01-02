#include "pch.h"

namespace stl_list
{
// _list_node_base
// why?
// ����ĳ�Ա�������ڴ�����ǰ������ĳ�Ա�����ں���Ϊǰ���ͺ�̵�ָ��ֻ��Ҫȷ����
// ǰ������� node����ʼ��ַ�ͺã�������data�������޹أ�����ȫ�� ����Ϊ���ô��
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
		node = (link_type)((*node)._M_next);// ��������ָ������һ��λ�ã�
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
		return (*node)._M_data;// *this ���ص��ǵ�������������Ϊ��ϰ�߷��㣬����ֱ�ӷ��ص�������������dataֵ��
	}
	// ->
	pointer operator->() const // 
	{
		return &(operator*()); // ���ڷ���Ԫ�ص�ָ��
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
	typedef _List_node<T> list_node; // ֻ��������ڲ�ʹ��
public:
	typedef list_node* link_type;// �������ⲿʹ�ã�ͨ������ ::
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






// typedef ������
// ע���������������Ϊpublic�ģ�������ں������ⲿʹ�ã�list<int>::link_type t;