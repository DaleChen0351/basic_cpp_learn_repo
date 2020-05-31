// point_blog.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//1  c++里面的指针 和指针常量及常量指针


#include <iostream>


#include <string>
using namespace std;
void test_01()
{
	int a = 10;
	int *p = &a;
	cout << p << endl;

	int b = 20;
	// 常量指针
	const int* const_p = &a;
	const_p = &b;
	//*const_p = 100; // 表达式必须是可修改的左值
	// 指针常量
	int* const p_const = &a;
	*p_const = 100;// 可以
	//p_const = &b; // 

}
// 指针与一维数组
void test_02()
{
	int arr[10] = {};
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 1;
	}
	for (int * p = arr, i = 0; i < 10; i++, p++)
	{
		cout << *p << endl;
	}
}


// new and delete

int main()
{
    std::cout << "Hello World!\n";

}

