#ifndef _STRING_H_
#define _STRING_H_


//class String
//{
//public:
//	String(const char* cstr);
//	char* get_c_str() const { return m_data; }
//	//copy ctor 1
//	String(const String& str);
//	// copy assign 2
//	String& operator = (const String& str);
//	//dtor 3
//	~String();
//
//private:
//	char* m_data;
//};
//
//inline String::String(const char* cstr = 0)
//{
//	if (cstr)
//	{
//		m_data = new char[strlen(cstr) + 1];
//		strcpy(m_data, cstr);
//	}
//	else
//	{
//		m_data = new char[1];
//		*m_data = '\0';
//	}
//}
//inline String::String(const String& str)// 赋值构造函数，临时变量（深拷贝）使用默认的是浅拷贝
//{
//	m_data = new char[strlen(str.get_c_str())+ 1];
//	strcpy(m_data, str.get_c_str());
//}
//inline String& String::operator= (const String& str)
//{
//	if (this == &str)
//	{
//		return *this;
//	}
//	delete[] m_data;
//	m_data = new char[strlen(str.get_c_str()) + 1];
//	strcpy(m_data, str.get_c_str());
//	return *this;
//}
//
//inline String::~String()
//{
//	if (m_data)
//		delete[] m_data;
//}
//
//inline std::ostream& operator << (std::ostream& os, const String& str)
//{
//	return os << str.get_c_str();
//}
#endif 
