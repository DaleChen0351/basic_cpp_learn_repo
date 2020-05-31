// list_blog.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <list>
using namespace std;


void printList(const list<int>& l)
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test_01()
{
	list<int>l;
	l.push_back(12);
	l.push_back(11);
	l.push_front(12);
	l.push_back(3);
	l.push_back(7);

	printList(l);
	cout << "reverse" << endl;
	l.reverse();
	printList(l);
	l.sort();
	printList(l);

}

class Girl
{
public:
	Girl(int id, int age, int weight):m_ID(id), m_Age(age), m_Weight(weight) {}
	int m_ID;
	int m_Age;
	int m_Weight;
	bool operator ==(const Girl& g)// remove 函数要用到，==的比较
	{
		if (this->m_Age == g.m_Age)
		{
			return true;
		}
		return false;
	}

};
bool GirlCompare(const Girl& g1, const Girl& g2)
{
	if (g1.m_Age == g2.m_Age)
	{
		return g1.m_Weight < g2.m_Weight;
	}
	return g1.m_Age < g2.m_Age;
}

void printGirls(const list<Girl>&l)
{
	for (list<Girl>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "ID = " << it->m_ID << " age= " << it->m_Age << " weight= " << it->m_Weight << endl;
	}
}

void test_02()
{
	list<Girl>l;
	Girl g1(1, 22, 100);
	Girl g2(2, 25, 88);
	Girl g3(3, 25, 89);
	Girl g4(4, 28, 90);
	Girl g5(5, 27, 110);
	Girl g6(6, 25, 111);
	
	l.push_back(g1);
	l.push_back(g2);
	l.push_back(g3);
	l.push_back(g4);
	l.push_back(g5);
	l.push_back(g6);
	printGirls(l);

	cout << "reverse()" << endl;
	l.reverse();
	printGirls(l);
	cout << "list.sort" << endl;

	l.sort(GirlCompare);
	printGirls(l);

	cout << "remove()" << endl;
	l.remove(Girl(2, 25, 88));
	l.remove(g4);
	printGirls(l);


}
class LessCompare
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

class Removecond
{
public:
	bool operator()(int i)//应用传递？可以么？
	{
		return i == 21;
	}
};
bool Removecondi(int i)
{
	return i == 11;

}
void test_03()
{
	list<int>l;
	l.push_back(11);
	l.push_back(21);
	l.push_back(24);
	l.push_back(1);
	l.push_back(31);
	l.push_back(51);
	l.push_back(14);
	l.push_back(1);

	l.sort(LessCompare());
	printList(l);

	l.remove_if(Removecond());// 仿函数（匿名）对象
	l.remove_if([](int i) { return i == 1; });// lambda(匿名函数)
	l.remove_if(Removecondi);// 回调函数
	printList(l);

}

// 这是为什么呢？

/*for (std::list<ExistArray>::iterator it = id_list.begin(); it != id_list.end(); it++)
    {
        (*it).isExist == FALSE; 没有反应
    }*/


int main()
{
    std::cout << "Hello World!\n"; 
	//test_01();
	test_02();
	//test_03();
	

	
}

