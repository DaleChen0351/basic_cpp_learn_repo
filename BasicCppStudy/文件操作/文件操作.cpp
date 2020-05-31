#include <string>
#include <iostream>
#include <fstream>// 1 

using namespace std;
// 文本文件：ASCII形式存储在计算机中
// 二进制文件： ios::binary  为了加密

//操作文件三大类
//写操作 ofstream
//读操作 ifstream
//fstream 读写操作

//写文件
//包含头文件
	// #include <fstream>
//创建流对象
//打开文件
//写数据
//关闭文件

void test_01()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out | ios::app);//以追加的形式

	ofs << "姓名" << "Dale" << endl;
	ofs << "年龄" << "25" << endl;
	ofs.close();
}

int main()
{
	test_01();
}