// algorithm_blog.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <iterator>
#include <queue>
#include <ctime>
using namespace std;

//for_each 操作
void test_01()
{

}

// 函数对象可以有返回值
class MyPrint
{
public:
	MyPrint(){}
	MyPrint(const MyPrint& m)
	{
		this->m_count = m.m_count;
		cout << "this is MyPrint copy ctor!" << endl;
	}
	void operator ()(int val)
	{
		cout << "value = " << val << endl;
		m_count++;
	}
	int m_count = 0;
};
void test_02()
{
	vector<int>v;
	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
	}
	MyPrint mp = for_each(v.begin(), v.end(), MyPrint()); // copy ctor?
	cout << "mp return count = " << mp.m_count << endl;
	
}

// transform函数

class MyTrans :public binary_function<int,int,int>
{
public:
	int operator()(int val, int start)const
	{
		return val+start;
	}
};
void test_03()
{
	vector<int>v;
	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
	}
	vector<int>v2;
	v2.resize(v.size());

	transform(v.begin(), v.end(), v2.begin(), bind2nd(MyTrans(), 100));
	for_each(v2.begin(), v2.end(), [](int val) { cout << val << endl; });

}
// find algorithm
// 查找自定义类型

class Person
{
public:
	Person(string name, int age): m_Name(name), m_Age(age){}
	bool operator==(const Person& p)
	{
		return (this->m_Name == p.m_Name && this->m_Age == p.m_Age);
	}
	string m_Name;
	int m_Age;
};
// find  Person类型
void test_04()
{
	Person p1("A", 11);
	Person p2("B", 24);
	Person p3("C", 22);

	vector<Person>v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	vector<Person>::iterator pos = find(v.begin(), v.end(), p2);
	if (pos!=v.end())
	{
		cout << pos->m_Name << " " << pos->m_Age << endl;
	}

}
// find_if Person*
void MyPrintPerson(Person* p)
{
	cout << p->m_Name << " " << p->m_Age << endl;
}
class equalPerson:public binary_function<Person*,Person*,bool>
{
public:
	bool operator()(Person* p1,Person* p2)const
	{
		return p1->m_Name == p2->m_Name && p1->m_Age == p2->m_Age;
	}

};
void test_05()
{
	vector<Person*>v;
	string nameSeed = "ABCDE";

	for (int i = 0; i < 5; i++)
	{
		string common = "员工";
		string str = common + nameSeed[i];
		Person* tmp = new Person(str, i * 10);
		v.push_back(tmp);
	}
	// PrintPerson
	for_each(v.begin(), v.end(), MyPrintPerson);

	vector<Person*>::iterator it = find_if(v.begin(),v.end(),[](Person* p){ 
		Person temp = Person("员工C", 20);
		return (p->m_Name == temp.m_Name && p->m_Age == temp.m_Age);
	});
	if (it != v.end())
	{
		cout << "找到了" << endl;
		cout <<(*it)->m_Name<<" "<<(*it)->m_Age<< endl;
	}

	it = find_if(v.begin(), v.end(), bind2nd(equalPerson(), new Person("员工D", 30)));
	if (it != v.end())
	{
		cout << "找到了" << endl;
		cout << (*it)->m_Name << " " << (*it)->m_Age << endl;
	}

}

// adjacent find 
void print_06(int i)
{
	cout << i << endl;
}
void test_06()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(5);
	v.push_back(2);
	v.push_back(6);

	for_each(v.begin(), v.end(), print_06);
	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos!=v.end())
	{
		cout << "找到了重复相邻的第一个元素为：" << *pos << endl;
	}
	else
	{
		cout << "未找到重复相邻的值" << endl;
	}
	// count
	int countNum = count(v.begin(), v.end(), 5);
	cout << "重复的元素个数为：" << countNum << endl;

	countNum = count_if(v.begin(), v.end(), [](int val) { return val > 3; });
	cout << "大于3的个数为: " << countNum << endl;

	countNum = count_if(v.begin(), v.end(), bind2nd(greater_equal<int>(),3));
	cout << "大于等于3的个数为: " << countNum << endl;
}
// binary serch
void test_07()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	bool ret = binary_search(v.begin(), v.end(), 4);
	if (ret)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "未找到值" << endl;
	}

}
// count_if for person
class GreatPerson
{
public:
	bool operator ()(Person* p)
	{
		return p->m_Age >= 20;
	}
};
void test_08()
{
	vector<Person*>v;
	string nameSeed = "ABCDE";

	for (int i = 0; i < 5; i++)
	{
		string common = "员工";
		string str = common + nameSeed[i];
		Person* tmp = new Person(str, i * 10);
		v.push_back(tmp);
	}
	int countNum = count_if(v.begin(), v.end(), GreatPerson());
	cout << "age大于等于20的员工个数为：" << countNum << endl;

	//释放指针？
}

// 排序算法merge 
void test_09()
{
	deque<int>d;
	d.push_back(1);
	d.push_back(3);
	d.push_back(2);
	d.push_back(6);
	d.push_back(4);

	deque<int>d2;
	d2.push_back(11);
	d2.push_back(13);
	d2.push_back(12);
	d2.push_back(3);
	d2.push_back(14);
	
	sort(d.begin(), d.end(), greater<int>());
	sort(d2.begin(), d2.end(), greater<int>());

	cout << "d = ";
	copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "d2 = ";
	copy(d2.begin(), d2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	deque<int>d_target;
	d_target.resize(d.size() + d2.size());
	merge(d.begin(), d.end(), d2.begin(), d2.end(), d_target.begin(),greater<int>());
	cout << "d_target = ";
	copy(d_target.begin(), d_target.end(), ostream_iterator<int>(cout, ","));
	cout << endl;


}
// random_shuffle and reverse
void test10()
{
	deque<int>d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}

	random_shuffle(d.begin(), d.end());
	copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	reverse(d.begin(), d.end());
	copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}
// swap
void test_11()
{
	deque<int>d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	deque<int>d2(10, 100);
	
	swap(d, d2);

	for_each(d.begin(), d.end(), [](int val) { cout << val << " "; });
}
// copy
void test_12()
{
	deque<int>d;
	for (int i = 0; i < 5; i++)
	{
		d.push_back(i);
	}
	deque<int>d_target;
	d_target.resize(d.size());
	copy(d.begin(), d.end(), d_target.begin());
	for_each(d_target.begin(), d_target.end(), [](int val) { cout << val << " "; });

}
//replace and replace_if
void test_13()
{
	deque<int>d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	replace(d.begin(), d.end(), 4, 99);
	copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//replace_if
	replace_if(d.begin(), d.end(), bind2nd(greater_equal<int>(), 5), 999);
	copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));
}
int main()
{
    std::cout << "Hello World!\n"; 
	srand((unsigned int)time(NULL));
	//test_02();
	//test_03();
	//test_04();
	//test_05();
	//test_06();
	//test_07();
	//test_08();
	//test_09();
	//test10();
	//test_11();
	//test_12();
	test_13();
}


