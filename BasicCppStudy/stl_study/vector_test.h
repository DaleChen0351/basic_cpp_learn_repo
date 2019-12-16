#pragma once
class point
{
public:
	point() :m_p(1) {}
private:
	int m_p; // ���û��Ĭ��ctor �� ÿ��ֵ�����int��ctor����ʼ��Ϊ0��
};
// ������ϵ�ĸ��Ϲ�ϵ
class Lane
{
public:
	point pp;// �����point�ĸ��ϲ�����Ĺ��캯��   
};
void test_array()
{
// ����
	std::array<int, 5> a;// �ڴ���stack�Ϸ��䵫��û�г�ʼ�� Ϊ���룬����size = 5��
	std::array <int, 5> b = {};// ��ʼ��Ϊ0�� ����int�Ĺ��캯��
	std::array<int, 5> c = { 1,2,3 };
// ���Զ�����Ԫ�صĹ��캯�����������m_p��ֵ������ʼ��Ϊ��1��
	std::array <point, 5> p = {}; 
// ���� �� empty����
	int d = c.size();
	bool bt = a.empty(); // ��Զ����Ϊtrue
// �������
	c.at(1) = 99;
	//c.at(5) = 2;//  0x769D35D2 ��(λ�� stl_study.exe ��)��δ��������쳣: Microsoft C++ �쳣: std::out_of_range��λ���ڴ�λ�� 0x009AF5F0 ��
	// c[30] = 3; // ϵͳ�쳣
	c[2] = 88;
// ����
	std::swap(a, c);
	c.swap(a);
// front and back
	int& ayin = a.front();// front ��back�������ص�������
	ayin = 66;
// ������
	a.end();//���һ��Ԫ�ص���һ��λ�� // �����* ��ȡֵ�������out of range
	int retb = *a.begin();// 
	*a.begin() = 77; // ��ֵ����
	a.cbegin();// const iterator
// C�ӿ�
	// ��vectorһ��
	a.data();
}
void test_vector()
{
// ����
	typedef std::vector<float> Group;
	std::vector<int> Students(10);
	Group a;// size = 0;
	Group b(10); //
	Group c(a);// c = a. copy ctor
	Group e(10, 5.0f);
	Group f(e.begin(), e.end());
	Group g({ 1.0f, 2.0f, 3.0f });// ?
	Group h = { 1.0f, 3.0f, 4.0f };

	bool flat_b = b.empty();
	int cap_int = b.capacity(); // ���ط����ڴ�֮ǰ�����Բ������ݵ��������

	//assign 3��
	h.assign(5, 2.4);// ����֮ǰ�����ʲô����
	h.assign({ 3.2f, 2.1f, 3.1f });// ?

	// ����
	// ֱ�ӽ���ָ���, ��arrayЧ�ʸ�
	b.swap(g);
	std::swap(a, b); 

	// Ԫ�ط���
	if (b.empty()) // ע�⣺��array��һ����array�ڶ����ʱ���Ѿ�ȷ�����˴�С��һ�㲻��ı䡣��vector��һ��������assign���������Զ�̬�ı�ģ�
	{
		b.front();
		b.back();// ע�� ȡvector��back��front��ʱ��һ��Ҫ���ж��Ƿ�Ϊ��
	}
	// array �� vector�ĵ�������һ����
	// ...
   // pop 
	if (!b.empty())
	{
		b.pop_back();// �������һ��Ԫ��
	}
	// erase
	b.erase(b.begin());// Ч����Σ�
	b.erase(b.begin(), b.end());// ���һ������, �������һ��ɾ��Ԫ����һ��λ�õĵ�������

	// insert
	auto iter = b.insert(b.end(), 100.0f); // ���ز���λ�õ�Ԫ�صĵ�����
	iter = b.insert(b.end(), 10, -10.0f);
	b.insert(b.end(), a.begin(), a.end());

	// emplace
	b.emplace(b.end(), 10.0); // ���ڻ�������Ԫ�أ���inert��һ���ġ������Զ�������ͣ�&&�� move, copy&; C++11
	// risize
	b.resize(10);// ��ǰ��100 �ĳ�10����ʣ��90�����ɵ��ˡ�
	b.resize(20, 1.0);// ԭ���ĳ���Ϊ10������resizeΪ20�������λ�õ�Ԫ����1.0����

	b.clear();// ��������е�Ԫ�ء�����cap �����С��Ԫ�ص�dtor������
	b.shrink_to_fit();// ʹcap��sizeһ�£�C++11������

	// ��C�Ľӿ�
	std::vector<char> carr(100, 0);
//	strcpy(&carr[0], "hello world!\n");
	//printf("%s", carr.data());// ����const char* ���飬��vector ����carr���ڴ��е��׵�ַ

	// ������÷�
	printf("%s", carr.begin());// ��Ȼ˵�������󲿷�ʱ�򷵻صľ���Ԫ������λ�õ�ָ�룬���ǲ�Ҫ������

	// �쳣
	// push back ����������쳣
	// ?
	// std::vector<bool> never use it
}
