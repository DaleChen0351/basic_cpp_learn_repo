// stl_study.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <fstream>

void test_All_common()
{
	std::vector<int> a;
	std::vector<int> b;
	std::vector <int> c(10);
	std::vector<float> d(5,2.8);

	for (int i = 0; i < 5; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	containerAllInterface(a, b);
}

std::vector<int> buffer_vec(5);
void test_vector_loop(int new_int)
{
	if (buffer_vec.size() == 5)
	{
		buffer_vec.erase(buffer_vec.begin());
	}
	buffer_vec.push_back(new_int);

	for (size_t i = 0; i < 5; i++)
	{
		std::cout << buffer_vec.at(i);
	}	
}
int main()
{
    std::cout << "Hello World!\n"; 

	//for (size_t i = 0; i < 10; i++)
	//{
	//	test_vector_loop(i);
	//	std::cout << std::endl;
	//}

	//algorithm_list();

	
}


