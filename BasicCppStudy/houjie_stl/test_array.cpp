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
		c[i] = rand();// ����� C�ṩ�ĺ�������Ҫ�ṩ����
	}
	cout << "milli-seconds: " << (clock() - timeStart) << endl;// ��������Ҫ��ʱ��
	cout << "array.size() = " << c.size() << endl;
	cout << "array.front() = " << c.front() << endl;
	cout <<"array.date()"<< c.data() << endl;// �ڴ����ĵ�ַ
	// ����
	long target = test_common::get_a_target_long();

	timeStart = clock();// ����
//qsort
	qsort(c.data(), ASIZE, sizeof(long), test_common::compareLongs);// 
	cout << "qsort: milli-seconds: " << (clock() - timeStart) << endl;// qsort �����ʱ�Ƚ϶࣬���ֲ��Һ�ʱ����
// binary search ���ֲ���֮ǰ����Ҫ������
	timeStart = clock();
	long* pitem = ((long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), test_common::compareLongs));
	cout << "bsearch: milli-seconds: " << (clock() - timeStart) << endl;// ��������Ҫ��ʱ��
	if (pitem != NULL)// ָ��
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