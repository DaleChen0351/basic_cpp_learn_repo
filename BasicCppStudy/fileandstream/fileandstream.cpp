// fileandstream.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <fstream> // 里面包含了 ofstream

class student
{
public:
	char Name[20];
	int Score;
};
void test_for_student();

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
	test_for_student();
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
