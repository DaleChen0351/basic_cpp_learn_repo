#include "pch.h"
namespace stl_deque
{
	template<class T, size_t BufSiz = 0>
	struct _deque_iterator
	{
		typedef random_access_iterator_tag iterator_category; // 虽然内部是分段的，但是对外是连续的，所以类型是合理的 1
		typedef T value_type //2
		typedef T* pointer; // 3
		typedef T& reference; //4 
		typedef ptrdiff_t difference_type; //5 
		typedef T** map_pointer;
		typedef _deque_iterator self;

		T* cur; // 在当前buffer内，迭代器指向的元素的地址
		T* fisrst;// 当前buffer的首地址
		T* last;
		map_pointer node;// 指向控制中心的某个元素，而此元素的内容是保存的某个buffer的首地址
	};
	
	
	
	
	
	template <class T, class Alloc = alloc, size_t Bufsiz=0> // 0 表示使用默认值
	class deque
	{
	public:
		typedef T value_type;
		typedef _deque_iterator<T, Bufsiz> iterator;
		typedef T* pointer;
		typedef T& reference;
		typedef pointer*  map_pointer; // T**  : 因为vector控制中心的每个元素都是指针，
		typedef size_t size_type;
	protected:
		// 创建一个dque对象，对象本身40个，至于内部放多少元素，和对象本身没有关系
		iterator start; // 16 4*4       4个指针
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
			return start[(n)];//?  迭代器的运算符重载吧?
		}
		iterator insert(iterator position, const value_type&  x)
		{
			if (position.cur = start.cur)// 如果安插点在最前端，则交给push_froint 去做
			{
				push_front(x);
				return start;
			}
			else if (position.cur = finish.cur)
			{
				push_back(x);
				iterator tmp = finish;// 
				--tmp;// finish 本身是指向最后一个元素地址的下一个地址的，所以要 --
				return tmp;
			}
			else
			{
				return insert_aux(position, x);
			}
		}
		


	};











}