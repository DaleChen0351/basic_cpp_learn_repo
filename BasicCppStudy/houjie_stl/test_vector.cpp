#include "pch.h"
#include <vector>
#include <ctime>
#include <cstdlib>// bsearch    abort()
#include <iostream>
#include <stdexcept>// exception
#include <algorithm>// sort 
#include <string>


namespace test_vector
{

void test_vector(long value)// 元素个数
{
	std::vector<std::string> c;
	char buf[10];

	clock_t timeStart = clock();
	for (long i = 0; i < value; i++)
	{
		try {
			snprintf(buf, 10, "%d", rand());// 随机数变成字符串
			c.push_back(std::string(buf));
		}
		catch (std::exception& p)
		{
			std::cout<<p.what()<<std::endl;
			abort();
		}

	}
	std::cout << "milli-seconds: " << clock() - timeStart << std::endl;
	std::cout << "vector-size(): " << c.size() << std::endl;
	std::cout << " vector capacity: " << c.capacity() << std::endl;

	std::string target = test_common::get_a_target_string();
// find 
	timeStart = clock();
	auto pitem = std::find(c.begin(), c.end(), target);
	std::cout << "find mill-second: " << clock() - timeStart << std::endl;
	if (pitem != c.end())
	{
		std::cout << "found :" << (*pitem)<< std::endl;
		std::cout << *(++pitem) << " " << *(++pitem) << std::endl;
	}
	else
	{
		std::cout << "not found" << std::endl;
	}
// sort and bsearch
	timeStart = clock();
	std::sort(c.begin(), c.end());//C++ 标准库。algorithem 80-90个算法
	std::string* Pitem = (std::string*)bsearch(&target, c.data(), c.size(), sizeof(std::string), test_common::compareStrings);
	std::cout << "sort + bsearch mill-second: " << clock() - timeStart << std::endl;
	if (Pitem != NULL)// 指针
	{
		std::cout << "found :" << *Pitem << std::endl;
		std::cout << *(++Pitem) << " " << *(++Pitem) << std::endl;

	}
	else
	{
		std::cout << "not found" << std::endl;
	}





}

}

// find() C++ 遍历查找, sort C++标准库提供, bsearch C提供
// find() 函数是顺序查找，正常效率应该不高。bsearch 为二分法查找，但是查找之前要先排序，排序比较费时间。