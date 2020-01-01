#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm> // max sort
using namespace std;
namespace test_basic
{

bool strLonger(const string& s1, const string s2)
{
	return s1.size() < s2.size();
}
void test_max()
{
	cout << "max of zero and hello " << max(string("zoo"), string("hello")) << std::endl;
	cout << "max of zero and hello " << max(string("zoo"), string("hello"), strLonger);// 利用std::max 框架，自定义比较函数
}



}
