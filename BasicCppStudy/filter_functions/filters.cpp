#include "pch.h"
using namespace std;
// 参数
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
const int N_ldtm = 4;//先限幅滤波幅度在+-4
int value_ldtm = 50;
const int N_lddtm = 5;//再进行递推滤波
int i_lddtm = 0;
int value_ldtm_buf[N_lddtm + 1] = { 0 };

const int SIZE = 20;


void delay_ms(int intms);//延时函数
int get_data();//模拟采样数据的函数rand()获取的随机数

/********滤波函数*********/
int filter_limit();//限幅滤波器
int filter_mid();//中位值滤波法
int filter_mean();//算术平均滤波法
int filter_dtmean();//递推平均滤波法
int filter_midmean();//中位值平均滤波法
int filter_limdtm();//限幅平均滤波法

/*1.限幅滤波法函数体*/
/*
1、限幅滤波法（又称程序判断滤波法）
A、方法：
根据经验判断，确定两次采样允许的最大偏差值（设为A）
每次检测到新值时判断：
如果本次值与上次值之差<=A,则本次值有效
如果本次值与上次值之差>A,则本次值无效,放弃本次值,用上次值代替本次值
B、优点：
能有效克服因偶然因素引起的脉冲干扰
C、缺点
无法抑制那种周期性的干扰
平滑度差
*/
int filter_limit() {
	int new_value;
	new_value = get_data();
	cout << "get_data产生的数据:" << new_value << endl;
	if ((new_value - value_lim > N_limit) || (value_lim - new_value > N_limit))
		return value_lim;// 这里假定这个参数是上次值
	return new_value;
}

/*2.中位值滤波法函数体*/
/*
2、中位值滤波法
A、方法：
连续采样N次（N取奇数）
把N次采样值按大小排列
取中间值为本次有效值
B、优点：
能有效克服因偶然因素引起的波动干扰
对温度、液位的变化缓慢的被测参数有良好的滤波效果
C、缺点：
对流量、速度等快速变化的参数不宜
*/
int filter_mid() {
	int value_buf[N_mid];// 中值滤波的窗口宽度
	int count, i, j, temp;
	cout << "随机抽样N_mid次的数据是：" << endl;
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
	cout << "排序后的N_mid次采样数据是：" << endl;
	for (int i = 0; i < N_mid; i++)
	{
		cout << value_buf[i] << ",";
	}
	return value_buf[(N_mid - 1) / 2];
}

/*3.均值滤波法函数体*/
/*
3、算术平均滤波法
A、方法：
连续取N个采样值进行算术平均运算
N值较大时：信号平滑度较高，但灵敏度较低
N值较小时：信号平滑度较低，但灵敏度较高
N值的选取：一般流量，N=12；压力：N=4
B、优点：
适用于对一般具有随机干扰的信号进行滤波
这样信号的特点是有一个平均值，信号在某一数值范围附近上下波动
C、缺点：
对于测量速度较慢或要求数据计算速度较快的实时控制不适用
比较浪费RAM
*/
int filter_mean() {
	int sum = 0;
	cout << "采样N_mean次数据的是：" << endl;
	for (int count = 0; count < N_mean; count++)
	{
		cout << get_data() << ",";
		sum += get_data();
		delay_ms(5);
	}
	cout << "均值为：" << (int)(sum / N_mean) << endl;
	return (int)(sum / N_mean);
}

/*4.递推均值滤波法（滑动均值滤波法）函数体*/
/*
4、递推平均滤波法（又称滑动平均滤波法）
A、方法：
把连续取N个采样值看成一个队列
队列的长度固定为N
每次采样到一个新数据放入队尾,并扔掉原来队首的一次数据.(先进先出原则)
把队列中的N个数据进行算术平均运算,就可获得新的滤波结果
N值的选取：流量，N=12；压力：N=4；液面，N=4~12；温度，N=1~4
B、优点：
对周期性干扰有良好的抑制作用，平滑度高
适用于高频振荡的系统
C、缺点：
灵敏度低
对偶然出现的脉冲性干扰的抑制作用较差
不易消除由于脉冲干扰所引起的采样值偏差
不适用于脉冲干扰比较严重的场合
比较浪费RAM
*/
int filter_dtmean() {
	int sum = 0, count;
	value_buf[N_dtm] = get_data();
	cout << "采样第" << i_dtm++ << "次的数据的是：" << value_buf[N_dtm] << endl;
	for (count = 0; count < N_dtm; count++)
	{
		value_buf[count] = value_buf[count + 1];
		sum += value_buf[count];
	}
	cout << "均值为：" << (int)(sum / N_dtm) << endl;
	return (int)(sum / N_dtm);

}

/*5.中位值均值滤波法函数体*/
/*
5、中位值平均滤波法（又称防脉冲干扰平均滤波法）
A、方法：
相当于“中位值滤波法”+“算术平均滤波法”
连续采样N个数据，去掉一个最大值和一个最小值
然后计算N-2个数据的算术平均值
N值的选取：3~14
B、优点：
融合了两种滤波法的优点
对于偶然出现的脉冲性干扰，可消除由于脉冲干扰所引起的采样值偏差
C、缺点：
测量速度较慢，和算术平均滤波法一样
比较浪费RAM
*/
int filter_midmean() {
	int count, i, j, temp;
	int value_buf[N_mm];
	int sum = 0;
	cout << "随机抽样N_mm次的数据是：" << endl;
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
	cout << "去掉最大值和最小值之后的由小到大排序为：" << endl;
	for (count = 1; count < N_mm - 1; count++)
	{
		cout << value_buf[count] << ",";
		sum += value_buf[count];
	}
	cout << endl;
	return (int)(sum / (N_mm - 2));
}

/*6.限幅平均滤波法函数体*/
/*
6、限幅平均滤波法
A、方法：
相当于“限幅滤波法”+“递推平均滤波法”
每次采样到的新数据先进行限幅处理，
再送入    队列进行递推平均滤波处理
B、优点：
融合了两种滤波法的优点
对于偶然出现的脉冲性干扰，可消除由于脉冲干扰所引起的采样值偏差
C、缺点：
比较浪费RAM
*/
int filter_limdtm() {
	int new_value;
	int i;
	int sum = 0;
	new_value = get_data();
	cout << "数据采样第" << i_lddtm++ << "次读取的数据为：" << new_value << endl;
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
		value_ldtm_buf[i] = value_ldtm_buf[i + 1];//先进先出所有数组元素向左移，首位舍弃。
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