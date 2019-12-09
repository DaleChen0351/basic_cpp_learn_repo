// stl_study.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

void test()
{
	std::vector<int> a;
	std::vector<int> b;
	for (int i = 0; i < 5; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	containerAllInterface(a, b);
}

int main()
{
    std::cout << "Hello World!\n"; 
	test();
}


