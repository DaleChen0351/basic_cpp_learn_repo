// houjie_stl.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm> // max
#include <functional> // 仿函数
using namespace std;
#define vSIZE 50000


int main()
{
	// 特性
    std::cout << "Hello World!\n"; 
	int ia[6] = { 27,210, 12, 44, 349,69 };
	vector<int, allocator<int>> vi(ia, ia + 6);// 容器 和 迭代器 分配器
	cout << std::count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40)));// 算法 仿函数适配器 *2  仿函数（less）
	//
	for( auto i : vi) // C++11
	{
		cout << i << endl; // i is a  elem not a  iterator here
	}
	// test_array
		//test_array::test_array();
	// test_vector

	//test_vector::test_vector(vSIZE);
	//test_list::test_list(vSIZE);
	test_basic::test_max();
}
