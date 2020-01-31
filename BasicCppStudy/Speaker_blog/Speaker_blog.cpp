// Speaker_blog.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <numeric>
using namespace std;

class Speaker
{
public:
	vector<int> m_score;
	string m_name;
};

void creatSpeaker(vector<int>&v, map<int, Speaker>& m)
{
	string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 24; i++)
	{
		Speaker mp;
		mp.m_name = "选手";
		mp.m_name += nameSeed[i];

		mp.m_score.resize(3);

		v.push_back(i + 100);
		m.insert(make_pair(i+100,mp));
	}
}

bool random_shuffle(vector<int>& v)
{
	if (!v.empty())
	{
		random_shuffle(v.begin(), v.end());
		return true;
	}
	return false;	
}
void speechDraw(vector<int>&v1, map<int, Speaker>&m, vector<int>&v2)
{
	multimap<int, int, greater<int>>t_mp; // 成绩 和 编号
	int num = 0;
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		//temp deque
		num++;
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		d.pop_back();
		d.pop_front();
		int sum = accumulate(d.begin(), d.end(), 0);
		int t_score = sum / d.size();
		m[*it].m_score.push_back(t_score);

		t_mp.insert(make_pair(t_score, (*it)));
		// 分组排序
		
		if (num % 6 == 0)
		{
			cout << "小组比赛成绩：" << endl;
			/*for (map<int, int, greater<int>>::iterator mit = t_mp.begin(); mit != t_mp.end(); mit++)
			{
				cout << "编号：" << mit->second << "姓名: " << m[mit->second].m_name << " 成绩：" << m[mit->second].m_score.back() << endl;
			}
			cout << endl;*/
			// 取前三名
			int count = 0;
			for (map<int, int, greater<int>>::iterator mit = t_mp.begin(); mit != t_mp.end(), count<3; mit++, count++)
			{
				cout << "编号：" << mit->second << " 姓名: " << m[mit->second].m_name << " 成绩：" << m[mit->second].m_score.back() << endl;
			}



			t_mp.clear();
		}
		

	}
}
int main()
{
    std::cout << "Hello World!\n"; 
	
	//
	// srand((unsigned int)time(NULL));
	map<int, Speaker>m;//编号：选手
	vector<int>v1;// 第一轮参赛选手 24 打乱顺序抽签用
	vector<int>v2;// 第二轮参赛选手 12
	vector<int>v3;// 第三轮参赛选手 6
	vector<int>v4;// 前三名

// creatSpeaker
	creatSpeaker(v1,m);
	/*for (map<int, Speaker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "编号:" << it->first << " 姓名：" << it->second.m_name << endl;
	}*/
	
	random_shuffle(v1);
	/*for_each(v1.begin(), v1.end(), [](int val) { cout << val << " "; });
	cout << endl;*/

	// 演讲比赛
	speechDraw(v1, m, v2);
}


