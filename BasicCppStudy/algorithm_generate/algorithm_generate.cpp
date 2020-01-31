// algorithm_generate.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> // accumulate and fill
using namespace std;
// 交集
void test_01()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>v_target;
	v_target.resize(min(v1.size(), v2.size()));
	vector<int>::iterator itend = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v_target.begin());
	for_each(v_target.begin(), itend, [](int val) { cout << val << " "; });
	
}
// 并集
void test_02()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>v_target;
	v_target.resize(v1.size()+v2.size());
	vector<int>::iterator itend = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v_target.begin());
	for_each(v_target.begin(), itend, [](int val) { cout << val << " "; });

}
// 差集
// resize(max(v1.size(), v2.size());
// set_difference(v1 v2)   V1 差 V2；

// accumulate and fill
void myprint(int i)
{
	cout << i << " ";
}
void test_04()
{
	vector<int>v;
	for (int i = 1; i < 101; i++) {
		v.push_back(i);
	}
	int sum = accumulate(v.begin(), v.end(), 0);
	cout << "sum = " << sum << endl;

	// fill
	vector<int>vfill;
	vfill.resize(10);
	cout << "fill" << endl;
	fill(vfill.begin(), vfill.end(), 33);
	for_each(vfill.begin(), vfill.end(), myprint);
	cout << endl;
}
int main()
{
    std::cout << "Hello World!\n"; 
	//test_01();
	//test_02();
	test_04();

}


