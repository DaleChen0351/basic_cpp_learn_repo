#include <iostream>
#include <string>
using namespace std;
#include "show.h"
// 方法1 告诉编译器下面的这个函数是个C语言函数，编译本cpp时不要乱改名字
//extern "C" void show();

int main()
{
	show();
	system("pause");
}