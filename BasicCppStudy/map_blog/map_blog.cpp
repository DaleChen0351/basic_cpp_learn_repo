// map_blog.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

enum Section
{
	HR,
	ASW,
	BSW,
};
void test_01()
{
	map<int, string>m;
	m.insert(pair<int, string>(1, "Dale"));
	m.insert(make_pair(2, "Bob"));
	m.insert(map<int, string>::value_type(3, "Susan"));
	m[4] = "Linda";
	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "ID = " << it->first << "  Name = " << it->second << endl;
	}

	m.erase(2);
	cout << "erased " << endl;
	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "ID = " << it->first << "  Name = " << it->second << endl;
	}
	cout << "find " << endl;
	map<int, string>::iterator pos = m.find(3);
	if (pos != m.end())
	{
		cout << "ID = " << (*pos).first << "  Name = " << pos->second << endl;
	}

}

void test_02()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m[4] = 40;
	m.insert(map<int, int>::value_type(3, 30));

	// 遍历
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "ID = " << it->first << "  Name = " << it->second << endl;
	}

	map<int,int>::iterator res = m.lower_bound(3);
	if (res!=m.end())
	{
		cout << "lower_bound 3 has been found!" << endl;
		cout << "ID = " << res->first << "  Name = " << res->second << endl;
	}

	pair<map<int, int>::iterator, map<int, int>::iterator> mypair = m.equal_range(3);
	if (mypair.first != m.end() && mypair.second != m.end())
	{
		cout <<"lower_bound: "<< "ID = " << mypair.first->first << "  Name = " << mypair.first->second << endl;// 30
		cout << "upper_bound: " << "ID = " << mypair.second->first << "  Name = " << mypair.second->second << endl;// 40
	}
}
class girl
{
public:
	girl(int id, int age, int weight) :m_ID(id), m_Age(age), m_Weight(weight) {}
	girl(){}
	//girl(const girl& g)
	//{
	//	this->m_Age = g.m_Age;
	//	this->m_ID = g.m_ID;
	//	this->m_Weight = g.m_Weight;
	//}
	//girl& operator = (const girl& g)
	//{
	//	this->m_Age = g.m_Age;
	//	this->m_ID = g.m_ID;
	//	this->m_Weight = g.m_Weight;
	//	return *this;
	//}

	int m_ID;
	int m_Age;
	int m_Weight;
	
};

class GirlCompare
{
public:
	bool operator() (int g1, int  g2) const
	{
		return g1 > g2;
	}
};
void test_03()
{
	map<int, girl, GirlCompare>m;
	girl g1(1, 13, 60);
	girl g3(2, 34, 90);
	girl g2(3, 29, 110);

	m.insert(pair<int, girl>(1, g1));
	m.insert(make_pair(2,g2));
	m[3] = g3;// m[3] 这句： 先调用value类型的默认构造函数生成一个对象。故如果本对象不存在，最好不要用此方式insert对象

	for (map<int, girl, GirlCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout<<"Key = "<<it->first<< " ID = " << it->second.m_ID << " age= " << it->second .m_Age<< " weight= " << it->second.m_Weight<< endl;
	}
}

class WeightCompare
{
public:
	bool operator() (const girl& g1, const girl& g2)const
	{
		return g1.m_Weight < g2.m_Weight;
	}
};

void test_04()
{
	map<girl, bool, WeightCompare>m;
	girl g1(1, 13, 60);
	girl g3(2, 34, 90);
	girl g2(3, 29, 110);

	m.insert(make_pair(g1, false));
	m.insert(make_pair(g2, false));
	m.insert(make_pair(g3, false));
	for (map<girl, bool, WeightCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "Weight: " << it->first.m_Weight << " bool = " << m[it->first] << endl;
	}
	m[g3] = true;
	cout << "selected;" << endl;
	for (map<girl, bool, WeightCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "Weight: " << it->first.m_Weight << " bool = " << m[it->first] << endl;
	}

}

// multi-map
class Worker
{
public:
	Worker(string name, int salary, int sectionID) : m_Name(name), m_Salary(salary), m_SectionID(sectionID) {}
	Worker() {};
	string m_Name;
	int m_SectionID;
	int m_Salary;
};
void creatWorker(vector<Worker>&v)
{
	string nameSeed = "ABCDE";

	for (int i = 0; i < 5; i++)
	{
		Worker w;
		w.m_Name = "员工";
		w.m_Name += nameSeed[i];
		w.m_Salary = rand() % 5001 + 20000;
		v.push_back(w);
	}
}
void setGroup(vector<Worker>&v, multimap<int, Worker>&m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int num = rand() % 3;
		m.insert(make_pair(num, *it));
	}
}
void showWorker(multimap<int, Worker>&m)
{
	for (multimap<int, Worker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key " << it->first << " Name = " << it->second.m_Name << " salary = " << it->second.m_Salary << endl;
	}
}

void showSection(int sectionEnum, multimap<int, Worker>&m)
{
	int count = m.count(sectionEnum);
	cout << "Section " << sectionEnum << "的人员如下：" << endl;
	int ic = 0;
	for (multimap<int, Worker>::iterator it = m.find(sectionEnum); it != m.end(),ic<count ; it++, ic++)
	{
		cout << "key " << it->first << " Name = " << it->second.m_Name << " salary = " << it->second.m_Salary << endl;
	}
}

void test_multi_map()
{
	multimap<int, Worker>m;

	vector<Worker>v;
	creatWorker(v);

	setGroup(v, m);

	showWorker(m);

	showSection(HR, m);
	showSection(ASW, m);
	showSection(BSW, m);
}
int main()
{
    std::cout << "Hello World!\n"; 
	//test_01();
	//test_02();
	//test_03();
	//test_04();
	test_multi_map();
}


