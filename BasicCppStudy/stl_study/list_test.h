#pragma once


inline void test_list()
{
	std::list<int> mlist;
// 定义
	// 和 vector 等一致

// 区别
	// 不支持 capacity, reserve, shrink_to_fit() 因为元素之间是独立的，通过指针相连，不需要提前分配内存空间
    // 不支持随机访问
	// 无法 e.at(2)  or  e[2] = 1;

// 通过迭代器访问
	// 方式1
	auto iter = mlist.begin();
	for (size_t i = 0; i < 5; ++i)
	{
		(*++iter);// ++ 运算符重载，指向下一个node，* 也是运算符重载，返回，迭代器中包含的node，node中包含的data的值
	}
	// 方式二
	std::advance(iter, 4);// 得到了这个位置的迭代器
	// 方式三 C++11
	auto iter2 = std::next(iter, 4);
// 其他和vector一致


	// 算法
	
}

class object
{
public:
	object(int x, int y) : dx(x), dy(y) { isVaild = false; }
	int dx;
	int dy;
	bool isVaild;
};
inline void algorithm_list()
{
	std::list<object> l;
	l.emplace_back(10, 2);// 减少零时对象的产生
	l.emplace_back(12, 2);
	l.emplace_back( 51, 2);
	l.emplace_back(14, 2);
	l.emplace_back(80, 2);
	l.emplace_back(30, 2);
	l.emplace_back(29, 2);

	auto iter = l.begin();// 一定要定义成局部变量
	while (iter != l.end() )
	{
		std::cout << (*iter).dx << std::endl;
		if ((*iter).dx < 50)
		{
			(*iter).isVaild = true;
			iter->dx = 20;
		}
		++iter;
	}
	// remove_if and remove()
	l.remove_if([](object v) { return (!v.isVaild); });
	//std::cout << (*iter).dx << std::endl;// 经过remove_if修改之后，指针所指的地址修改了，所以变成了无效值
	//reverse
	l.reverse();
	l.sort();// < 运算符重载函数么？
	// 排好序之后
	//b.merge();
	// unique // 对于排好序的函数，可以去除中间的重复值
	// splice(c.begin(),b); // 将b中的元素移动到c.begin()处
	
}
// 为何list包含了很多的算法的成员函数
// 1 由于list的内存空间并不连续，所以无法只通过传入收尾迭代器遍历，比如  std::sort ，list并不支持
// 2 所以，对于list，应该优先使用内部的算法

// 从时间上，遍历list的节点速度比vector慢，空间上占用空间多（因为要存前向和后向指针 及 new操作）
// 比如，某些操作。