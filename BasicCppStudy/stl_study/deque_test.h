#pragma once
// deque 是98 引入的动态数组
// 在内存中不是连续分配的，所以不能做C接口
inline void test_deque()
{
// 定义
	typedef std::deque<int> Mydeque;
	// ctor 
	Mydeque a;
	Mydeque aa(10);
	Mydeque b(10, 2);
	Mydeque c({ 1,2,3,4,5 }); // 注意大括号
	Mydeque d = {1,2,3,4,5};
	
	// copy ctor
	Mydeque e = b;
	Mydeque f(c);
	// iterator
	Mydeque g(d.begin(), d.end());

// empty size max_size
	// 和vector一致

// deque 无法确定 capacity 所以reserve 和 capacity 没有。因为deque分配内存是按块分配的

// 比较函数
	// 和vector一致

// assign  重新赋值
	// 和vector也一致
// 元素访问
	e.back();
	e.front();
	e[3];
	e.at(2);
// pop back 和vector一致

// push_front() 
	// 与vector 不一致

//push_back 比 insert（end 效率高
	// emplace_back() 比push_back 效率高


}

inline void test_deque_eg()
{
	using Buffer = std::vector<char>; // 这里是字符串信息，所以是作为一个整体出现的，不会出现单独pop_back or pop_front的需求
	using BufferGroup = std::deque<Buffer>;// 而deque中的每个元素是相对独立的，可作为独立处理的单元，所以需要单独pop
	Buffer buffer;
	BufferGroup group;
	auto ok = readFromClient(socket, &buffer);
	if (ok)
	{
		// emplace 减少零时对象的生成
		group.emplace_back(std::move(buffer));// move ?
	}
	else
	{
		//handle error
	}

	while (!group.empty())
	{
		auto ok = sendtoClient(socket, group.front());
		if (ok)
		{
			group.pop_front();// 头部pop front效率高，所以queue用deque做底层，用queue做buffer 是合理的？
		}
		else
		{
			break;
		}
	}
}
// 感悟：
// 每个object的历史信息，用deque是合理的，因为需要单独pop_front 处理
//so， list 做目标跟踪队列？deque做目标的历史轨迹信息

inline void test_for_queue()
{
	std::queue<int> q;
	q.push(2);


}