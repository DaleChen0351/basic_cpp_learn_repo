// unordered_map_demo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <sstream>// stringstream
#include <iterator>
#include <typeinfo>
#include <unordered_set>
using namespace std;

void test_01()
{
	string str = "geeks for geeks geeks quiz practice qa for";
	unordered_map<string, int>um;
	stringstream ss(str);
	string word;
	while (ss>>word)
	{
		um[word]++;// 边遍历边生成的感觉
	}
	for (unordered_map<string, int>::iterator it = um.begin(); it != um.end(); it++)
	{
		cout << it->first << " : " << it->second << endl;
	}
}

void test_02()
{
	typename iterator_traits<map<string, string>::iterator>::iterator_category cat;

	unordered_map<string, string>m;
	cout<<typeid(m).name() << endl;
	int i;

	

}
//unordered_set
void test_03()
{
	unordered_set<string>us = { "blue","green" };
	// 插入元素
	us.insert("red");
	vector<string>v = { "black","white" };
	us.insert(v.begin(), v.end());
	for (unordered_set<string>::iterator it = us.begin(); it != us.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
	
	auto iter = us.find("red");
	if (iter!=us.end())
	{
		cout << "找到了" << *iter << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
	cout << "size = " << us.size() << endl;
	cout << "bucket_count = " << us.bucket_count() << endl;
	//cout << "bucket_size = "<<us.bucket_size<< endl;
	cout << "bucket_load= " << us.load_factor() << endl;
	cout << " the red is in = " << us.bucket("red")<<endl;
	
}

void test_04()
{
	map<int, string>m;
	m.insert(make_pair(1, "a"));
	m[2] = "b";
	cout << m[3] << endl;// caution 这样会传入
	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
}

void test_05()
{
	unordered_map<string, int>um;
	um.insert(make_pair("Dale", 27));
	um.insert(make_pair("Bob", 23));

	auto iter = um.find("Dale");
	if (iter!=um.end())
	{
		cout << iter->first << endl;
	}
	else
	{
		cout << "Linda 不存在" << endl;
	}
	
	for (unordered_map<string, int>::iterator it = um.begin(); it != um.end(); it++)
	{
		cout << "first: " << it->first << "  second: " << it->second << endl;
	}

}

int main()
{
    std::cout << "Hello World!\n"; 
	//test_01();
	//test_02();
	//test_03();
	//test_04();
	test_05();
}


