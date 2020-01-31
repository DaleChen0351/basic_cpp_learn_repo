#include <iostream>
#include <set>
#include <string>

using namespace std;

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test_01()
{
	set<int>s;
	s.insert(10);
	s.insert(30);
	s.insert(40);
	s.insert(20);

	printSet(s);

	cout << "count: " << s.count(20) << endl;
	set<int>::iterator it = s.find(40);
	if (it != s.end())
	{
		cout <<"found: "<< *it << endl;
	}
	else
	{
		cout << "not find!" << endl;
	}

}

void test_02()
{
	set<int>s;
	s.insert(10);
	s.insert(30);
	s.insert(40);
	s.insert(20);

	cout << "test_02" << endl;
	printSet(s);
	pair<set<int>::iterator, set<int>::iterator> it = s.equal_range(50);
	if (it.first != s.end() || it.second != s.end())
	{
		cout << (*it.first) << " " << (*it.second) << endl;
	}
	else
	{
		cout << "¾ù²»´æÔÚ" << endl;
	}

}


class girl
{
public:
	girl(int id, int age, int weight) :m_ID(id), m_Age(age), m_Weight(weight) {}
	int m_ID;
	int m_Age;
	int m_Weight;
	//bool operator <(const girl& g)
	//{
	//	return this->m_Age > g.m_Age;
	//}
};

class GirlCompare
{
public:
	bool operator() (const girl& g1, const girl& g2)
	{
		return g1.m_Age < g2.m_Age;
	}
};
void test_03()
{
	std::pair<string, int> p = std::make_pair("Dale", 22);
	cout << p.first << " " << p.second << endl;
	cout << "Using factor fuction for set insert" << endl;
	set<girl, GirlCompare>s;
	girl g1(1, 13, 60);
	girl g2(2, 34, 90);
	girl g3(3, 29, 110);

	s.insert(g1);
	s.insert(g2);
	s.insert(g3);

	for (set<girl, GirlCompare>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "ID = " << it->m_ID << " age= " << it->m_Age << " weight= " << it->m_Weight << endl;
	}

	
}

int main()
{
	//test_01();
	//test_02();
	test_03();
	system("pause");
}