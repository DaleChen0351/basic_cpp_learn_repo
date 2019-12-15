#pragma once
// deque ��98 ����Ķ�̬����
// ���ڴ��в�����������ģ����Բ�����C�ӿ�
inline void test_deque()
{
// ����
	typedef std::deque<int> Mydeque;
	// ctor 
	Mydeque a;
	Mydeque aa(10);
	Mydeque b(10, 2);
	Mydeque c({ 1,2,3,4,5 }); // ע�������
	Mydeque d = {1,2,3,4,5};
	
	// copy ctor
	Mydeque e = b;
	Mydeque f(c);
	// iterator
	Mydeque g(d.begin(), d.end());

// empty size max_size
	// ��vectorһ��

// deque �޷�ȷ�� capacity ����reserve �� capacity û�С���Ϊdeque�����ڴ��ǰ�������

// �ȽϺ���
	// ��vectorһ��

// assign  ���¸�ֵ
	// ��vectorҲһ��
// Ԫ�ط���
	e.back();
	e.front();
	e[3];
	e.at(2);
// pop back ��vectorһ��

// push_front() 
	// ��vector ��һ��

//push_back �� insert��end Ч�ʸ�
	// emplace_back() ��push_back Ч�ʸ�


}

inline void test_deque_eg()
{
	using Buffer = std::vector<char>; // �������ַ�����Ϣ����������Ϊһ��������ֵģ�������ֵ���pop_back or pop_front������
	using BufferGroup = std::deque<Buffer>;// ��deque�е�ÿ��Ԫ������Զ����ģ�����Ϊ��������ĵ�Ԫ��������Ҫ����pop
	Buffer buffer;
	BufferGroup group;
	auto ok = readFromClient(socket, &buffer);
	if (ok)
	{
		// emplace ������ʱ���������
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
			group.pop_front();// ͷ��pop frontЧ�ʸߣ�����queue��deque���ײ㣬��queue��buffer �Ǻ���ģ�
		}
		else
		{
			break;
		}
	}
}
// ����
// ÿ��object����ʷ��Ϣ����deque�Ǻ���ģ���Ϊ��Ҫ����pop_front ����
//so�� list ��Ŀ����ٶ��У�deque��Ŀ�����ʷ�켣��Ϣ

inline void test_for_queue()
{
	std::queue<int> q;
	q.push(2);


}