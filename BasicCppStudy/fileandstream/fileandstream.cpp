// fileandstream.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <fstream> // 里面包含了 ofstream
#include <sstream>
#include <vector>
// https://www.cnblogs.com/Lin-Yi/p/11071822.html
class student
{
public:
	char Name[20];
	int Score;
};
void test_for_student();
void test_for_ifstream();

int main()
{

	std::cout << "Hello World!\n";

	std::ofstream outfile("test.dat", std::ios::out | std::ios::binary);// 初始化参数创建对象
	outfile << "this is a test";
	outfile << std::endl;
	outfile << "this ";

	outfile.close();
	std::ofstream out2;

	out2.open("test.dat", std::ios::app | std::ios::binary);
	if (!out2)
	{
		std::cout << "error" << std::endl;
	}
	else
	{
		out2 << "append sth more!" << std::endl;
	}
	out2.close();
	test_for_ifstream();
//	// 写指针
//	std::ofstream fpoint("pointgoogd.txt", std::ios::out | std::ios::binary);
//	fpoint << "tellpoint";
//	long location = fpoint.tellp();
//	location = 20L;
//	fpoint.seekp(location);// 将写指针移动到第20个字节数
//	fpoint.seekp(location, std::ios::beg);// beg cur end
//
//	// 读指针
//	std::ifstream fin("tellpoint.txt", std::ios::in);
//	//fin.getline();
//// fin.tellg();
}

void test_for_student()
{
	student s;
	std::ofstream outfile("student.cpp", std::ios::out|std::ios::binary);
	while (std::cin>>s.Name>>s.Score)
	{
		if (strcmp(s.Name,"exit") == 0)
		{
			break;
		}
		outfile.write((char*)&s, sizeof(s));
	}
	outfile.close();

}
class config
{
public:
	std::string Name;
	std::string type;
	int value;
};



void test_for_ifstream()
{
	std::ifstream inf;
	char buff[100];
	inf.open("config.txt", std::ios::in);
	if (!inf.is_open())
	{
		std::cout << "error with open" << std::endl;
	}
	else
	{
		std::vector<std::vector<config>> vec_2d;
		while (inf.getline(buff, sizeof(buff)))
		{
			std::string s;
			std::vector<config> vec;
			s = buff;
			std::cout << s.c_str()<< std::endl;

			std::stringstream linestream(s);
			std::string sub;
			linestream >> sub;
			config mfig;
			mfig.Name = sub;
			while (linestream >> sub)
			{
				std::string type;
				std::string value;
				int value_i = 0;
				int nPos = sub.find(":");
				if (nPos !=-1)
				{
					type = sub.substr(0, nPos);
					value = sub.substr(nPos+1);
					value_i = std::stoi(value);
				}
				mfig.type = type;
				mfig.value = value_i;
				vec.push_back(mfig);
			}
			vec_2d.push_back(vec);
			std::cout<<std::endl;
		}
		int i = 0;
	}

}
//for (int idx = 0; idx < vec.size(); idx++)
//{
//	std::cout << vec[idx].c_str() << std::endl;
//}