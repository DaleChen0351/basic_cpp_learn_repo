#include "pch.h"
#include <array>
#include <iostream>
#include <ctime>// clock()
#include <cstdlib> // qsort, bsearch, NULL
using std::cout;
using std::cin;
using std::string;
using std::array;
using std::endl;
#define ASIZE 50000
namespace test_array
{



void test_array()
{
	cout << endl << "test_array()------" << endl;
	array<long, ASIZE> c;
	clock_t timeStart = clock(); // ctime
	for (long i = 0; i < ASIZE; i++)
	{
		c[i] = rand();// 随机数 C提供的函数，需要提供种子
	}
	cout << "milli-seconds: " << (clock() - timeStart) << endl;// 生成数需要的时间
	cout << "array.size() = " << c.size() << endl;
	cout << "array.front() = " << c.front() << endl;
	cout <<"array.date()"<< c.data() << endl;// 内存起点的地址
	// 排序
	long target = test_common::get_a_target_long();

	timeStart = clock();// 毫秒
//qsort
	qsort(c.data(), ASIZE, sizeof(long), test_common::compareLongs);// 
	cout << "qsort: milli-seconds: " << (clock() - timeStart) << endl;// qsort 排序耗时比较多，二分查找耗时较少
// binary search 二分查找之前，需要新排序
	timeStart = clock();
	long* pitem = ((long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), test_common::compareLongs));
	cout << "bsearch: milli-seconds: " << (clock() - timeStart) << endl;// 生成数需要的时间
	if (pitem != NULL)// 指针
	{
		std::cout << "found :" << *pitem << std::endl;
		std::cout << *(++pitem) << " "<< *(++pitem) <<std::endl;

	}
	else
	{
		std::cout << "not found" << std::endl;
	}
	
	
}












}