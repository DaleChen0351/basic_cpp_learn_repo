#include "pch.h"
namespace stl_deque
{
	template<class T, size_t BufSiz = 0>
	struct _deque_iterator
	{
		typedef random_access_iterator_tag iterator_category; // ��Ȼ�ڲ��Ƿֶεģ����Ƕ����������ģ����������Ǻ���� 1
		typedef T value_type //2
		typedef T* pointer; // 3
		typedef T& reference; //4 
		typedef ptrdiff_t difference_type; //5 
		typedef T** map_pointer;
		typedef _deque_iterator self;

		T* cur; // �ڵ�ǰbuffer�ڣ�������ָ���Ԫ�صĵ�ַ
		T* fisrst;// ��ǰbuffer���׵�ַ
		T* last;
		map_pointer node;// ָ��������ĵ�ĳ��Ԫ�أ�����Ԫ�ص������Ǳ����ĳ��buffer���׵�ַ
	};
	
	
	
	
	
	template <class T, class Alloc = alloc, size_t Bufsiz=0> // 0 ��ʾʹ��Ĭ��ֵ
	class deque
	{
	public:
		typedef T value_type;
		typedef _deque_iterator<T, Bufsiz> iterator;
		typedef T* pointer;
		typedef T& reference;
		typedef pointer*  map_pointer; // T**  : ��Ϊvector�������ĵ�ÿ��Ԫ�ض���ָ�룬
		typedef size_t size_type;
	protected:
		// ����һ��dque���󣬶�����40���������ڲ��Ŷ���Ԫ�أ��Ͷ�����û�й�ϵ
		iterator start; // 16 4*4       4��ָ��
		iterator finish; // 16
		map_pointer map; // 4
		size_type map_size; // 4
	public:
		iterator begin() { return start; }
		iterator end() { return finish; }
		size_type size() { return finish - start; }
		void push_froint(const value_type& x){}
		void push_back(const value_type& x) {}
		reference operator[] (size_type n)
		{
			return start[(n)];//?  ����������������ذ�?
		}
		iterator insert(iterator position, const value_type&  x)
		{
			if (position.cur = start.cur)// ������������ǰ�ˣ��򽻸�push_froint ȥ��
			{
				push_front(x);
				return start;
			}
			else if (position.cur = finish.cur)
			{
				push_back(x);
				iterator tmp = finish;// 
				--tmp;// finish ������ָ�����һ��Ԫ�ص�ַ����һ����ַ�ģ�����Ҫ --
				return tmp;
			}
			else
			{
				return insert_aux(position, x);
			}
		}
		


	};











}