// filter_functions.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>



int main() {
	float a;
	LimitFilter filter;
	for (int i = 0; i < SIZE; i++)
	{
		a = filter.Filter_Output(get_data2());
		std::cout << "滤波后的数据：" << a <<std::endl;
		std::cout << std::endl;
	}
	system("pause");
}


