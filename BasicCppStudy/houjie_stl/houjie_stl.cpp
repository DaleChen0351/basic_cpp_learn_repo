// houjie_stl.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // 仿函数
using namespace std;

int main()
{
    std::cout << "Hello World!\n"; 
	int ia[6] = { 27,210, 12, 44, 349,69 };
	vector<int, allocator<int>> vi(ia, ia + 6);// 容器 和 迭代器 分配器
	cout << std::count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40)));// 算法 仿函数适配器 *2  仿函数（less）

	for( auto i : vi) // C++11
	{
		cout << i << endl;
	}
}
