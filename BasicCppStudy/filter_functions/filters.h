#pragma once



/********�˲�����*********/
extern int filter_limit();//�޷��˲��� // extern �ɼӿɲ��� ������
extern int filter_mid();//��λֵ�˲���
extern int filter_mean();//����ƽ���˲���
extern int filter_dtmean();//����ƽ���˲���
extern int filter_midmean();//��λֵƽ���˲���
extern int filter_limdtm();//�޷�ƽ���˲���
extern float get_data2();
extern const int SIZE;// const int ��������ⲿ�ģ�������ʼ������������������Ҫ��extern


class baseFilter
{
public:
	virtual float Filter_Output(float ori_data) = 0;
	virtual ~baseFilter(){}
};

/*1.�޷��˲���������*/
/*
1���޷��˲������ֳƳ����ж��˲�����
A��������
���ݾ����жϣ�ȷ�����β�����������ƫ��ֵ����ΪA��
ÿ�μ�⵽��ֵʱ�жϣ�
�������ֵ���ϴ�ֵ֮��<=A,�򱾴�ֵ��Ч
�������ֵ���ϴ�ֵ֮��>A,�򱾴�ֵ��Ч,��������ֵ,���ϴ�ֵ���汾��ֵ
B���ŵ㣺
����Ч�˷���żȻ����������������
C��ȱ��
�޷��������������Եĸ���
ƽ���Ȳ�
*/
// Dale : �Ƿ����������������� or RE��·�ڶ�ʧ(���߱��ڵ���)�����⣿
// Yes: -30 Ϊ��Чֵ������Ч����Ч���ܴ󣬺������ж�
// No�� 1s���ҵĶ�ʧ��ʹ��1sǰ�����ݣ��Ƿ�̫׼ȷ
// ���ܿ�����������/ RE �����½���Ԥ�⵽��ǰ���г�������ʱ������ǰ����
class LimitFilter:public baseFilter
{
public:
	LimitFilter(): m_CurValue(2), m_lastValue(2){}
	virtual float Filter_Output(float ori_data)
	{
		m_CurValue = ori_data;
		std::cout << "get_data����������:" << m_CurValue << std::endl;
		if (abs(m_CurValue - m_lastValue) >= 0.4)
			return m_lastValue;// ����ٶ�����������ϴ�ֵ
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
class MidFilter
{
public:
	virtual int Filter_Output(int ori_data)
	{
		

	}

};


