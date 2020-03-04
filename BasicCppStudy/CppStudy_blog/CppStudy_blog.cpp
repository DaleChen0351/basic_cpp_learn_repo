// CppStudy_blog.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//C++ 引用相关

#include "pch.h"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

struct Person
{
	int age;
	typedef Person* PtrPerson;
};
void test_00()
{
	int arr[10];
	int(&brr)[10] = arr;
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << brr[i] << " ";
	}
	cout << endl;
	//extern const int g_value;
	cout << g_value << endl;

}

int& myfunc()
{
	int a = 10;
	return a;
}

void test_01()
{
	//int &b = myfunc(); // int& b = a; 局部变量已经释放，错误不合法了
	int b = myfunc(); // int b = a; // 复制构造吧？通过临时变量
	cout << b << endl;
	cout << b << endl;
}
int& myfunc2()
{
	static int a = 10;//与应用程序同生命
	return a;
}
void test_02()
{
	int &ret=myfunc2() = 100;// 注意：如果一个函数的返回值是一个引用，那么这个函数可以作为左值进行运算。
	cout << ret << endl;
}

void allocatorByPoint(Person** pp)
{
	*pp=(Person*)malloc(sizeof(Person));
	(*pp)->age = 20;
}
// 通过使用引用的方式，降级指针
void allocatorByRef(Person* &p)
{
	p = (Person*)malloc(sizeof(Person));
	p->age = 30;
}

void allocatorByPointEasy(Person::PtrPerson *p)
{
	*p = (Person*)malloc(sizeof(Person));
	(*p)->age = 40;
}

void test_03()
{
	Person* p;
	allocatorByPoint(&p);
	cout << "ByPoint: "<<p->age << endl;
	allocatorByRef(p);
	cout << "ByRef: " << p->age << endl;
	allocatorByPointEasy(&p);
	cout << "ByPointEasy: " << p->age << endl;

}
// 对常数的引用
void test_04()
{
	//int &a = 10;// 引用必须是一块合法的内存空间
	const int& a = 10;// const  ，编译器优化了，相当于是：
/*
int temp = 10;// 栈上定义了临时变量
const int& a = temp; // const 引用，不可以修改临时变量的值
*/
//a = 100;// 也不可以直接修改，但是可以通过取地址的方式间接修改，但是不建议这样做，没有意义。
	int* pa = (int*)&a;
	*pa = 100;
	cout << *pa << endl;
}
// 常量引用，修饰函数中的形参，防止误操作  const int& a;




int main()
{
    std::cout << "Hello World!\n"; 
	//test_01();
	//test_02();
	//test_00();
	//test_03();
	//test_04();
	//test_05();
	//test_06();
	//test_07();
	//test_08();
	//test_09();
	//test_10();
	//test_11();
	//test_12();
	//test_13();

	system("pause");

	
}


