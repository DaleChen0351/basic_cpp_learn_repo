// vector_chuanzhiblog.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
void printVector(vector<int> v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
		
	}
	cout << endl;
}

void test_01()
{
	
	int arry[] = { 1,2,3,4,5 };
	cout << "array size = " << sizeof(arry) << endl;
	vector<int>v1(arry, arry + sizeof(arry) / sizeof(int));
	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);
	v2.resize(10, 99);
	printVector(v2);
	v2.resize(3);
	printVector(v2);

}
void test_02()
{
	vector<int>v1(5, 11);
	printVector(v1);
	v1.assign(4, 22); // 重新赋值的意思
	printVector(v1);

	vector<int>v3(9, 99);
	v1.assign(v3.begin(), v3.end());
	printVector(v1);

	v1.insert(v1.begin(), 5, 100);
	v1.insert(v1.end(), 1000);
	printVector(v1);
}

void test_03()
{
	vector<int>v1(5, 11);
	vector<int>v2(9, 22);
	printVector(v1);
	printVector(v2);
	cout << "swap v1 and v2"<<endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
	cout << "pop_back()" << endl;
	v2.pop_back();
	printVector(v2);

}
void test_04()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	cout << v.front() << endl;
	v.front() = 99;// 可以修改值
	printVector(v);
	v.erase(v.begin());
	printVector(v);
}
void test_05()
{
	vector<int>v(3, 99);
	try
	{
		//cout<<v.at(7);
		cout<<v[7];
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

}
void test_06()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << "capacity: "<<v.capacity() << endl;
	//vector<int>(v).swap(v);
	v.shrink_to_fit();// fit the capacity
	cout << "swaped capacity: " << v.capacity() << endl;
	v.reserve(1000);
	cout << "reserve capacity:" << v.capacity() << endl;
}
int main()
{
    std::cout << "Hello World!\n"; 
	//test_01();
	//test_02();
	//test_03();
	//test_04();
	//test_05();
	test_06();
}

