// factor_function_blog.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

class Myprint
{
public:
	void operator ()(int val)
	{
		cout << "Myprint: " << val << endl;
		m_count++;
	}
	int Count()const { return m_count; }
private:
	int m_count = 0;
};

void myPrint(Myprint mp, int val)
{
	mp(val);
}

void test_01()
{
	Myprint m1;
	Myprint m2;
	m1(100);
	m2(200);
	m1(100);
	m2(200);
	m2(200);

	cout << "m1 : " << m1.Count() << endl;
	cout << "m2  : " << m2.Count() << endl;

	cout << "factor function for para for functions" << endl;
	myPrint(Myprint(), 111);
}

// 一元谓词
class Greatthen :public unary_function<int,bool>
{
public:
	bool operator()(int i) const
	{
		return i > 20;
	}
};

bool Compare(int i)
{
	return i > 20;
}
void test_02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(15);
	v.push_back(20);
	v.push_back(30);

	vector<int>::iterator it = find_if(v.begin(), v.end(), Greatthen()); // 仿函数对象 和 回调函数都可以实现相应的功能
	if (it != v.end())
	{
		cout << "finded :" << *it << endl;
	}
	else
	{
		cout << "not found!" << endl;
	}
}
// 二元谓词
bool LessCompare(int a, int b)
{
	return a > b;
}

class LessClass
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

void test_03()
{
	vector<int>v;
	v.push_back(30);
	v.push_back(15);
	v.push_back(20);
	v.push_back(10);

	//sort(v.begin(), v.end(), LessClass());// 仿函数对象和回调函数都是可以的
	//sort(v.begin(), v.end(), greater<int>());// 二元谓词
	sort(v.begin(), v.end(), not2(greater<int>()));// 二元取反适配器
	for_each(v.begin(), v.end(), [](int i) { cout << "value : " << i << " "; });
}
void test04()
{
	vector<int>v;
	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), [](int i) 
	{ 
		negate<int>n;
		cout << n(i) << endl;
	});
	
}

class Prints : public binary_function<int,int, void>
{
public:
	void operator()(int i, int start)const
	{
		cout << "val = " << i + start<< endl;
	}
};
// 增加参数适配器
void test05()
{
	vector<int>v;
	v.push_back(11);
	v.push_back(10);
	v.push_back(8);
	v.push_back(2);
	
	sort(v.begin(), v.end());
	int input = 0;
	cin >> input;
	for_each(v.begin(), v.end(), bind2nd(Prints(), input));// 可以增加额外的参数，在遍历对象的时候（在使用algorithm的算法的时候）
}
// 取反适配器
void test06()
{
	vector<int>v;
	for (int i = 15; i < 25; i++)
	{
		v.push_back(i);
	}
	//vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(Greatthen()));// 
	vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 20)));// 如果是sort中利用sort，则sort会自动遍历传入两个参数
	if (pos != v.end())                                                                                                              //而，find_if中只能传入一个参数，则必须绑定第二个参数。
	{
		cout << *pos << endl;
	}
}
// 函数指针适配器
void printonce(int i, int para)
{
	cout << i <<" "<<para<< endl;
}
void test07()
{
	vector<int>v;
	v.push_back(11);
	v.push_back(10);
	v.push_back(8);
	v.push_back(2);

	for_each(v.begin(), v.end(), bind2nd(ptr_fun(printonce), 10));// 回调函数（也就是函数指针）转化为仿函数，仿函数再绑定其他参数）
}


class girl
{
public:
	girl(int id, int age, int weight) :m_ID(id), m_Age(age), m_Weight(weight) {}
	void show()
	{
		cout << "id = " << m_ID << " age = " << m_Age << endl;
	}
	int m_ID;
	int m_Age;
	int m_Weight;
};
// 成员函数适配器
void test08()
{
	vector<girl>v;
	girl g1(1, 13, 60);
	girl g3(2, 34, 90);
	girl g2(3, 29, 110);

	v.push_back(g1);
	v.push_back(g2);
	v.push_back(g3);

	for_each(v.begin(), v.end(),mem_fun_ref(&girl::show) );// 成员函数适配器
	for_each(v.begin(), v.end(), [](girl& g) { g.show(); });// 利用lambda 匿名函数

}

void test09()
{
	vector<int>v;
	for (int i = 15; i < 25; i++)
	{
		v.push_back(i);
	}
	//vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(Greatthen()));// 
	vector<int>::iterator pos = find_if(v.begin(), v.end(), bind2nd(greater<int>(),20));// error ： 该项不会计算为接受一个参数的函数
	if (pos != v.end())                                                                                                             
	{
		cout << *pos << endl;
	}
}

void test_sensor()
{
	vector<int>pre;
	vector<int>cur;
	for (vector<int>::iterator it = pre.begin(); it != pre.end(); it++)
	{
		for_each(cur.begin(), cur.end(), bind2nd(equal_to<int>(), (*it)));
	}

}
int main()
{
    std::cout << "Hello World!\n"; 
	//test_01();
	//test_02();
	//test_03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	test09();
}
