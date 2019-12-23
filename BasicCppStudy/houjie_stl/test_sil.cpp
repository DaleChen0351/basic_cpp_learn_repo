#include "pch.h"
#include <array>
#include <iostream>
#include <ctime>
#include <cstdlib> // qsort, bsearch, NULL
using std::cout;
using std::cin;
using std::string;
using std::array;
using std::endl;
#define ASIZE 1000
namespace test_stl
{


	long get_a_target_long()
	{
		long target = 0;
		cout << "target (0 - " << RAND_MAX << "):";
		cin >> target;
		return target;
	}

	string get_a_target_string()
	{
		long target = 0;
		char buf[10];
		cout << "target (0 - " << RAND_MAX << "):";
		cin >> target;
		snprintf(buf, 10, "%d", target);// C std lib;
		return  string(buf);
	}

	int compareLongs(const void* a, const void*  b)
	{
		return (*(long*)a - *(long*)b);
	}

	int compareStrings(const void* a, const void* b)
	{
		if (*(string*)a > *(string*)b)
		{
			return 1; // qsort 函数决定
		}
		else if (*(string*)a < *(string*)b)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
void test_array()
{
	cout << endl << "test_array()------" << endl;
	array<long, ASIZE> c;
	clock_t timeStart = clock(); // ctime
	for (long i = 0; i < ASIZE; i++)
	{
		c[i] = rand();
	}
	cout << "milli-seconds: " << (clock() - timeStart) << endl;
	cout << "array.size() = " << c.size() << endl;
	cout << "array.front() = " << c.front() << endl;
	cout <<"array.date()"<< c.data() << endl;

	long target = get_a_target_long();

	timeStart = clock();
	qsort(c.data(), ASIZE, sizeof(long), compareLongs);// why not 
	bsearch
	
}



// bsearch 之前必须要先调用qsort进行排序
// qsort + bsearch(二分查找) 一共花费0.187s， qsort 占据花费时间的大头








}