#include <string>
#include <iostream>
#include <fstream>// 1 

using namespace std;
// �ı��ļ���ASCII��ʽ�洢�ڼ������
// �������ļ��� ios::binary  Ϊ�˼���

//�����ļ�������
//д���� ofstream
//������ ifstream
//fstream ��д����

//д�ļ�
//����ͷ�ļ�
	// #include <fstream>
//����������
//���ļ�
//д����
//�ر��ļ�

void test_01()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out | ios::app);//��׷�ӵ���ʽ

	ofs << "����" << "Dale" << endl;
	ofs << "����" << "25" << endl;
	ofs.close();
}

int main()
{
	test_01();
}