// complex_string.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>


//void test_for_String(void)
//{
//	String  s1("hi");// 构造函数
//	String s2("hello"); // 有参构造
//
//	String s3(s1); // copy ctor
//	std::cout << s3 << std::endl; // 运算符重载
//	s3 = s2; // copy op
//	std::cout << s3 << std::endl;
//}

void test_for_Complex(void)
{
	Complex c1(1, 2);
	Complex c2(1, 1);
	Complex c3(10, 3);
	c1 += c2;
	std::cout << c1 << std::endl;

	c1 = c1 + 8;
	std::cout << c1 << std::endl;

	std::cout << -c1 << std::endl;

	std::cout << (c1 == c3);
}




int main()
{
    std::cout << "Hello World!\n"; 
	test_for_Complex();
}


