// queue_stack_blog.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

void test_stack()
{
	stack<float>s;
	s.push(1.0);
	s.push(2.0);
	s.push(3.0);
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	cout << "stack size:" << s.size();
}
void test_queue()
{
	queue<int>q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while(!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	cout << q.size() << endl;
}
int main()
{
    std::cout << "Hello World!\n"; 
	//test_queue();
	test_stack();
}


