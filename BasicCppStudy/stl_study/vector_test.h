#pragma once
class point
{
public:
	point() :m_p(1) {}
private:
	int m_p; // 如果没有默认ctor 则 每个值会调用int的ctor，初始化为0；
};
// 类和类关系的复合关系
class Lane
{
public:
	point pp;// 会调用point的复合参数表的构造函数   
};
void test_array()
{
// 定义
	std::array<int, 5> a;// 内存在stack上分配但是没有初始化 为乱码，但是size = 5的
	std::array <int, 5> b = {};// 初始化为0， 调用int的构造函数
	std::array<int, 5> c = { 1,2,3 };
// 会自动调用元素的构造函数，所以这里，m_p的值都被初始化为了1；
	std::array <point, 5> p = {}; 
// 长度 和 empty（）
	int d = c.size();
	bool bt = a.empty(); // 永远不会为true
// 随机访问
	c.at(1) = 99;
	//c.at(5) = 2;//  0x769D35D2 处(位于 stl_study.exe 中)有未经处理的异常: Microsoft C++ 异常: std::out_of_range，位于内存位置 0x009AF5F0 处
	// c[30] = 3; // 系统异常
	c[2] = 88;
// 交换
	std::swap(a, c);
	c.swap(a);
// front and back
	int& ayin = a.front();// front 和back函数返回的是引用
	ayin = 66;
// 迭代器
	a.end();//最后一个元素的下一个位置 // 如果用* 号取值，会出现out of range
	int retb = *a.begin();// 
	*a.begin() = 77; // 赋值操作
	a.cbegin();// const iterator
// C接口
	// 与vector一样
	a.data();
}
void test_vector()
{
// 定义
	typedef std::vector<float> Group;
	std::vector<int> Students(10);
	Group a;// size = 0;
	Group b(10); //
	Group c(a);// c = a. copy ctor
	Group e(10, 5.0f);
	Group f(e.begin(), e.end());
	Group g({ 1.0f, 2.0f, 3.0f });// ?
	Group h = { 1.0f, 3.0f, 4.0f };

	bool flat_b = b.empty();
	int cap_int = b.capacity(); // 在重分配内存之前，可以插入数据的最大容量

	//assign 3个
	h.assign(5, 2.4);// 不管之前存的是什么东西
	h.assign({ 3.2f, 2.1f, 3.1f });// ?

	// 交换
	// 直接交换指针的, 比array效率高
	b.swap(g);
	std::swap(a, b); 

	// 元素访问
	if (b.empty()) // 注意：和array不一样，array在定义的时候已经确定好了大小，一般不会改变。而vector不一定（比如assign函数，可以动态改变的）
	{
		b.front();
		b.back();// 注意 取vector的back和front的时候，一定要先判断是否为空
	}
	// array 和 vector的迭代器是一样的
	// ...
   // pop 
	if (!b.empty())
	{
		b.pop_back();// 弹出最后一个元素
	}
	// erase
	b.erase(b.begin());// 效率如何？
	b.erase(b.begin(), b.end());// 清除一段数据, 返回最后一个删除元素下一个位置的迭代器。

	// insert
	auto iter = b.insert(b.end(), 100.0f); // 返回插入位置的元素的迭代器
	iter = b.insert(b.end(), 10, -10.0f);
	b.insert(b.end(), a.begin(), a.end());

	// emplace
	b.emplace(b.end(), 10.0); // 对于基本类型元素，和inert是一样的。对于自定义的类型，&&， move, copy&; C++11
	// risize
	b.resize(10);// 当前的100 改成10个，剩余90个被干掉了。
	b.resize(20, 1.0);// 原来的长度为10，现在resize为20，多余的位置的元素用1.0补充

	b.clear();// 清空容器中的元素。但是cap 不会变小，元素的dtor被调用
	b.shrink_to_fit();// 使cap和size一致，C++11中新增

	// 和C的接口
	std::vector<char> carr(100, 0);
//	strcpy(&carr[0], "hello world!\n");
	//printf("%s", carr.data());// 返回const char* 数组，既vector 变量carr在内存中的首地址

	// 错误的用法
	printf("%s", carr.begin());// 虽然说迭代器大部分时候返回的就是元素所在位置的指针，但是不要这样用

	// 异常
	// push back 中如果发生异常
	// ?
	// std::vector<bool> never use it
}
