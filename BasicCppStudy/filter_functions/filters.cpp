#include "pch.h"
using namespace std;
// ����
/*********1***********/
const int N_limit = 2;
int value_lim = 50;
/*********2**********/
const int N_mid = 11;
/*********3**********/
const int N_mean = 12;
/*********4**********/
const int N_dtm = 4;
int i_dtm = 0;
int value_buf[N_dtm + 1] = { 0 };
/*********5**********/
const int N_mm = 4;
/*********6**********/
const int N_ldtm = 4;//���޷��˲�������+-4
int value_ldtm = 50;
const int N_lddtm = 5;//�ٽ��е����˲�
int i_lddtm = 0;
int value_ldtm_buf[N_lddtm + 1] = { 0 };

const int SIZE = 20;


void delay_ms(int intms);//��ʱ����
int get_data();//ģ��������ݵĺ���rand()��ȡ�������

/********�˲�����*********/
int filter_limit();//�޷��˲���
int filter_mid();//��λֵ�˲���
int filter_mean();//����ƽ���˲���
int filter_dtmean();//����ƽ���˲���
int filter_midmean();//��λֵƽ���˲���
int filter_limdtm();//�޷�ƽ���˲���

/*1.�޷��˲���������*/
/*
1���޷��˲������ֳƳ����ж��˲�����
A��������
���ݾ����жϣ�ȷ�����β������������ƫ��ֵ����ΪA��
ÿ�μ�⵽��ֵʱ�жϣ�
�������ֵ���ϴ�ֵ֮��<=A,�򱾴�ֵ��Ч
�������ֵ���ϴ�ֵ֮��>A,�򱾴�ֵ��Ч,��������ֵ,���ϴ�ֵ���汾��ֵ
B���ŵ㣺
����Ч�˷���żȻ����������������
C��ȱ��
�޷��������������Եĸ���
ƽ���Ȳ�
*/
int filter_limit() {
	int new_value;
	new_value = get_data();
	cout << "get_data����������:" << new_value << endl;
	if ((new_value - value_lim > N_limit) || (value_lim - new_value > N_limit))
		return value_lim;// ����ٶ�����������ϴ�ֵ
	return new_value;
}

/*2.��λֵ�˲���������*/
/*
2����λֵ�˲���
A��������
��������N�Σ�Nȡ������
��N�β���ֵ����С����
ȡ�м�ֵΪ������Чֵ
B���ŵ㣺
����Ч�˷���żȻ��������Ĳ�������
���¶ȡ�Һλ�ı仯�����ı�����������õ��˲�Ч��
C��ȱ�㣺
���������ٶȵȿ��ٱ仯�Ĳ�������
*/
int filter_mid() {
	int value_buf[N_mid];// ��ֵ�˲��Ĵ��ڿ���
	int count, i, j, temp;
	cout << "�������N_mid�ε������ǣ�" << endl;
	for (count = 0; count < N_mid; count++)
	{
		value_buf[count] = get_data();
		delay_ms(5);
		cout << value_buf[count] << ",";
	}
	cout << endl;
	for (j = 0; j < N_mid - 1; j++)
	{
		for (i = 0; i < N_mid - j - 1; i++)
		{
			if (value_buf[i] > value_buf[i + 1]) {
				temp = value_buf[i];
				value_buf[i] = value_buf[i + 1];
				value_buf[i + 1] = temp;
			}

		}
	}
	cout << "������N_mid�β��������ǣ�" << endl;
	for (int i = 0; i < N_mid; i++)
	{
		cout << value_buf[i] << ",";
	}
	return value_buf[(N_mid - 1) / 2];
}

/*3.��ֵ�˲���������*/
/*
3������ƽ���˲���
A��������
����ȡN������ֵ��������ƽ������
Nֵ�ϴ�ʱ���ź�ƽ���Ƚϸߣ��������Ƚϵ�
Nֵ��Сʱ���ź�ƽ���Ƚϵͣ��������Ƚϸ�
Nֵ��ѡȡ��һ��������N=12��ѹ����N=4
B���ŵ㣺
�����ڶ�һ�����������ŵ��źŽ����˲�
�����źŵ��ص�����һ��ƽ��ֵ���ź���ĳһ��ֵ��Χ�������²���
C��ȱ�㣺
���ڲ����ٶȽ�����Ҫ�����ݼ����ٶȽϿ��ʵʱ���Ʋ�����
�Ƚ��˷�RAM
*/
int filter_mean() {
	int sum = 0;
	cout << "����N_mean�����ݵ��ǣ�" << endl;
	for (int count = 0; count < N_mean; count++)
	{
		cout << get_data() << ",";
		sum += get_data();
		delay_ms(5);
	}
	cout << "��ֵΪ��" << (int)(sum / N_mean) << endl;
	return (int)(sum / N_mean);
}

/*4.���ƾ�ֵ�˲�����������ֵ�˲�����������*/
/*
4������ƽ���˲������ֳƻ���ƽ���˲�����
A��������
������ȡN������ֵ����һ������
���еĳ��ȹ̶�ΪN
ÿ�β�����һ�������ݷ����β,���ӵ�ԭ�����׵�һ������.(�Ƚ��ȳ�ԭ��)
�Ѷ����е�N�����ݽ�������ƽ������,�Ϳɻ���µ��˲����
Nֵ��ѡȡ��������N=12��ѹ����N=4��Һ�棬N=4~12���¶ȣ�N=1~4
B���ŵ㣺
�������Ը��������õ��������ã�ƽ���ȸ�
�����ڸ�Ƶ�񵴵�ϵͳ
C��ȱ�㣺
�����ȵ�
��żȻ���ֵ������Ը��ŵ��������ýϲ�
�������������������������Ĳ���ֵƫ��
��������������űȽ����صĳ���
�Ƚ��˷�RAM
*/
int filter_dtmean() {
	int sum = 0, count;
	value_buf[N_dtm] = get_data();
	cout << "������" << i_dtm++ << "�ε����ݵ��ǣ�" << value_buf[N_dtm] << endl;
	for (count = 0; count < N_dtm; count++)
	{
		value_buf[count] = value_buf[count + 1];
		sum += value_buf[count];
	}
	cout << "��ֵΪ��" << (int)(sum / N_dtm) << endl;
	return (int)(sum / N_dtm);

}

/*5.��λֵ��ֵ�˲���������*/
/*
5����λֵƽ���˲������ֳƷ��������ƽ���˲�����
A��������
�൱�ڡ���λֵ�˲�����+������ƽ���˲�����
��������N�����ݣ�ȥ��һ�����ֵ��һ����Сֵ
Ȼ�����N-2�����ݵ�����ƽ��ֵ
Nֵ��ѡȡ��3~14
B���ŵ㣺
�ں��������˲������ŵ�
����żȻ���ֵ������Ը��ţ������������������������Ĳ���ֵƫ��
C��ȱ�㣺
�����ٶȽ�����������ƽ���˲���һ��
�Ƚ��˷�RAM
*/
int filter_midmean() {
	int count, i, j, temp;
	int value_buf[N_mm];
	int sum = 0;
	cout << "�������N_mm�ε������ǣ�" << endl;
	for (count = 0; count < N_mm; count++)
	{
		value_buf[count] = get_data();
		delay_ms(5);
		cout << value_buf[count] << ",";
	}
	cout << endl;
	for (j = 0; j < N_mm - 1; j++)
	{
		for (i = 0; i < N_mm - j - 1; i++)
		{
			if (value_buf[i] > value_buf[i + 1]) {
				temp = value_buf[i];
				value_buf[i] = value_buf[i + 1];
				value_buf[i + 1] = temp;
			}

		}
	}
	cout << "ȥ�����ֵ����Сֵ֮�����С��������Ϊ��" << endl;
	for (count = 1; count < N_mm - 1; count++)
	{
		cout << value_buf[count] << ",";
		sum += value_buf[count];
	}
	cout << endl;
	return (int)(sum / (N_mm - 2));
}

/*6.�޷�ƽ���˲���������*/
/*
6���޷�ƽ���˲���
A��������
�൱�ڡ��޷��˲�����+������ƽ���˲�����
ÿ�β��������������Ƚ����޷�������
������    ���н��е���ƽ���˲�����
B���ŵ㣺
�ں��������˲������ŵ�
����żȻ���ֵ������Ը��ţ������������������������Ĳ���ֵƫ��
C��ȱ�㣺
�Ƚ��˷�RAM
*/
int filter_limdtm() {
	int new_value;
	int i;
	int sum = 0;
	new_value = get_data();
	cout << "���ݲ�����" << i_lddtm++ << "�ζ�ȡ������Ϊ��" << new_value << endl;
	if ((new_value - value_ldtm > N_ldtm) || (value_ldtm - new_value > N_ldtm))
	{
		value_ldtm_buf[N_lddtm] = value_ldtm;
	}
	else
	{
		value_ldtm_buf[N_lddtm] = new_value;
	}
	for (i = 0; i < N_lddtm; i++)
	{
		value_ldtm_buf[i] = value_ldtm_buf[i + 1];//�Ƚ��ȳ���������Ԫ�������ƣ���λ������
		sum += value_ldtm_buf[i];
	}
	return (int)(sum / N_lddtm);
}

float get_data2() {
	return  2.0+(float)(rand() % 100)*0.01;
}
int get_data() {

	return 1+ rand() / ((RAND_MAX) / 100); // 0-100
}
void delay_ms(int ms) {
	int i, j;
	for (i = 0; i < ms; i++) {
		for (j = 0; j < 200; j++);
		for (j = 0; j < 102; j++);
	}
}