#pragma once



/********滤波函数*********/
extern int filter_limit();//限幅滤波器 // extern 可加可不加 都可以
extern int filter_mid();//中位值滤波法
extern int filter_mean();//算术平均滤波法
extern int filter_dtmean();//递推平均滤波法
extern int filter_midmean();//中位值平均滤波法
extern int filter_limdtm();//限幅平均滤波法
extern float get_data2();
extern const int SIZE;// const int 如果不是外部的，则必须初始化常量，所以这里需要加extern


class baseFilter
{
public:
	virtual float Filter_Output(float ori_data) = 0;
	virtual ~baseFilter(){}
};

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
// Dale : 是否可以用来解决车道线 or RE在路口丢失(或者被遮挡的)的问题？
// Yes: -30 为无效值，且有效和无效差距很大，很容易判断
// No： 1s左右的丢失，使用1s前的数据，是否不太准确
// 功能开启：车道线/ RE 质量下降，预测到右前方有车辆经过时，可提前开启
class LimitFilter:public baseFilter
{
public:
	LimitFilter(): m_CurValue(2), m_lastValue(2){}
	virtual float Filter_Output(float ori_data)
	{
		m_CurValue = ori_data;
		std::cout << "get_data产生的数据:" << m_CurValue << std::endl;
		if (abs(m_CurValue - m_lastValue) >= 0.4)
			return m_lastValue;// 这里假定这个参数是上次值
		else
		{
			m_lastValue = m_CurValue;
			return m_CurValue;
		}
		
	}
private:
	float m_lastValue;
	float m_CurValue;
};

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
class MidFilter
{
public:
	virtual int Filter_Output(int ori_data)
	{
		

	}

};


