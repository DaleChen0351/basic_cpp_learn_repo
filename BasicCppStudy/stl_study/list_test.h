#pragma once


inline void test_list()
{
	std::list<int> mlist;
// ����
	// �� vector ��һ��

// ����
	// ��֧�� capacity, reserve, shrink_to_fit() ��ΪԪ��֮���Ƕ����ģ�ͨ��ָ������������Ҫ��ǰ�����ڴ�ռ�
    // ��֧���������
	// �޷� e.at(2)  or  e[2] = 1;

// ͨ������������
	// ��ʽ1
	auto iter = mlist.begin();
	for (size_t i = 0; i < 5; ++i)
	{
		(*++iter);// ++ ��������أ�ָ����һ��node��* Ҳ����������أ����أ��������а�����node��node�а�����data��ֵ
	}
	// ��ʽ��
	std::advance(iter, 4);// �õ������λ�õĵ�����
	// ��ʽ�� C++11
	auto iter2 = std::next(iter, 4);
// ������vectorһ��


	// �㷨
	
}

class object
{
public:
	object(int x, int y) : dx(x), dy(y) { isVaild = false; }
	int dx;
	int dy;
	bool isVaild;
};
inline void algorithm_list()
{
	std::list<object> l;
	l.emplace_back(10, 2);// ������ʱ����Ĳ���
	l.emplace_back(12, 2);
	l.emplace_back( 51, 2);
	l.emplace_back(14, 2);
	l.emplace_back(80, 2);
	l.emplace_back(30, 2);
	l.emplace_back(29, 2);

	auto iter = l.begin();// һ��Ҫ����ɾֲ�����
	while (iter != l.end() )
	{
		std::cout << (*iter).dx << std::endl;
		if ((*iter).dx < 50)
		{
			(*iter).isVaild = true;
			iter->dx = 20;
		}
		++iter;
	}
	// remove_if and remove()
	l.remove_if([](object v) { return (!v.isVaild); });
	//std::cout << (*iter).dx << std::endl;// ����remove_if�޸�֮��ָ����ָ�ĵ�ַ�޸��ˣ����Ա������Чֵ
	//reverse
	l.reverse();
	l.sort();// < ��������غ���ô��
	// �ź���֮��
	//b.merge();
	// unique // �����ź���ĺ���������ȥ���м���ظ�ֵ
	// splice(c.begin(),b); // ��b�е�Ԫ���ƶ���c.begin()��
	
}
// Ϊ��list�����˺ܶ���㷨�ĳ�Ա����
// 1 ����list���ڴ�ռ䲢�������������޷�ֻͨ��������β����������������  std::sort ��list����֧��
// 2 ���ԣ�����list��Ӧ������ʹ���ڲ����㷨

// ��ʱ���ϣ�����list�Ľڵ��ٶȱ�vector�����ռ���ռ�ÿռ�ࣨ��ΪҪ��ǰ��ͺ���ָ�� �� new������
// ���磬ĳЩ������