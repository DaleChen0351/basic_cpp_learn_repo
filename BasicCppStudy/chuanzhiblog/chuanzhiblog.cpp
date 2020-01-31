// chuanzhiblog.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <deque>
#include <algorithm>
#include <list>
#include <ctime>
using namespace std;

class Person
{
public:
	Person(string name, int age):mName(name), mAge(age){}
	string mName;
	int mAge;
};

class Player
{
public:
	Player(string name) :m_name(name){}
	deque<int> m_score;
	string m_name;
	float Mean()
	{
		sort(m_score.begin(), m_score.end());
		m_score.pop_front();// 常数时间内去除
		m_score.pop_back();// 常数时间内去除
		int sum = 0;
		cout << "Name:" << m_name<<endl;
		for (deque<int>::iterator  it = m_score.begin(); it != m_score.end(); it++)
		{
			cout << (*it) << " ";
			sum += (*it);
		}
		cout << endl;
		return sum / static_cast<float>(m_score.size());
	}
};

void test_deque()
{
	vector<Player>v;
	Player a("A");
	Player b("B");
	v.push_back(a);
	v.push_back(b);
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (int i = 0; i < 10; i++)
		{
			int tmp = rand() % 41 + 60;
			(it)->m_score.push_back(tmp);
		}
	}
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout<<"Name: "<<(*it).m_name<<"Mean: "<< (*it).Mean() << endl;
	}
}


void test_01()
{
	vector<vector<Person>>v;

	vector<Person>v1;
	Person p11("dale", 16);
	Person p12("susan", 13);
	v1.push_back(p11);
	v1.push_back(p12);

	vector<Person>v2;
	Person p21("bob", 22);
	Person p22("Linda", 23);
	v2.push_back(p21);
	v2.push_back(p22);

	v.push_back(v1);
	v.push_back(v2);

	// 遍历

	for (vector<vector<Person>>::iterator it = v.begin(); it != v.end();it++)
	{
		for (vector<Person>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << vit->mAge << " " << vit->mName.c_str() << " ";
		}
		cout << endl;
	}

	try
	{
		//v1.at(2);// at里面会抛出异常 throw
		cout << v1[2].mAge << endl;

	}
	catch (const std::exception& e)
	{
		cout << " exception: "<<v1[0].mName << endl;
		cout << e.what() << endl;
	}
}
void test_string()
{
	string s1;
	s1 = "hello world!";
	string s2("dalechen@gmail.com");
	//s1 += s2;
	s1.append(s2);
	cout << s1 << endl;
	//find()
	int pos = s1.find("@");
	string userName = s1.substr(0, pos);
	string mailType = s1.substr(pos + 1);
	cout << userName << ": " << mailType << endl;
}

void test_pars_url()
{
	string s = "www.sina.com.cn";
	vector<string>v;
	int start = 0;
	while (true)
	{
		int pos = s.find(".", start);
		string tmp = s.substr(start, pos - start);

		if (pos == -1)
		{
			string lastStr = s.substr(start);
			v.push_back(lastStr);
			break;
		}
		v.push_back(tmp);
		start = pos + 1;

	}
	for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it) << endl;
	}
}

void test_insert()
{
	string s1("hello_world");
	s1.insert(1, "123");
	s1.insert(1, 3, 'a');
	cout << s1 << endl;

	s1.erase(0, 3);
	cout << s1 << endl;

}
void test_str_upper()
{
	string s1("hello World!");
	for (int i = 0; i < s1.size(); i++)
	{
		s1.at(i) = toupper(s1.at(i));
	}
	cout << s1<<endl;
	cout << "ascill:" <<toascii('a')<<endl;
	
}
void test_stl()
{
	vector<int>::iterator it_v;
	list<int>::iterator it_l;
	deque<int>::iterator it_d;
	string s;
	it_v++;
	it_v--;
	it_v + 5;

	it_l++;
	it_l--;
	//it_l + 5;// list ?

	it_d++;
	it_d--;
	it_d + 4;


	
}
int main()
{
	srand((unsigned int)time(NULL));
    std::cout << "Hello World!\n"; 
	//test_01();
	//test_string();
	//test_pars_url();
	//test_insert();
	//test_str_upper();
	test_deque();
}


