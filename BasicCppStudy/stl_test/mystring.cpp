#include "mystring.h"
#include "test.h"


//构造函数
MyString::MyString()
{
    m_len = 0;
    m_p = new char[1];
    strcpy(m_p, "");
}
//有参构造
MyString::MyString(const char* p)
{
    if (p == NULL)
    {
        m_len = 0;
        m_p = new char[1];
        strcpy(m_p, "");
    }
    else {
        m_len = strlen(p);
        m_p = new char[m_len + 1];
        strcpy(m_p, p);
    }
    
}
MyString::MyString(const MyString& s)
{
    m_len = s.m_len;
    m_p = new char[m_len + 1];
    strcpy(m_p, s.m_p);
}
MyString::~MyString()
{
    if (m_p != NULL)
    {
        delete[] m_p;
        m_p = NULL;
        m_len = 0;
    }
}

std::ostream& operator<<(std::ostream& os, MyString& s)
{
    os << s.m_p;
    return os;
}
MyString& MyString::operator=(const char* p)
{
    //清空本身的内容
    if (this->m_p != NULL)
    {
        delete[] m_p;
        m_len = 0;
    }
    // 构造新内存空间
    if (p == NULL)
    {
        m_p = new char[1];
        strcpy(m_p, "");
    }
    else {
        m_len = strlen(p);
        m_p = new char[m_len + 1];
        strcpy(m_p, p);
    }
    return *this;
}

MyString& MyString::operator=(const MyString& s)
{
    //清空本身的内容
    if (this->m_p != NULL)
    {
        delete[] m_p;
        m_len = 0;
    }
    //构造新内存空间
    m_len = s.m_len;
    m_p = new char[m_len + 1];
    strcpy(m_p, s.m_p);
    return *this;
}



char& MyString::operator[](int index)
{
    return m_p[index];
}

bool MyString ::operator==(const char* p)
{
    if (p == NULL)
    {
        return this->m_len == 0;
    }
    else {
        if (this->m_len == strlen(p))
        {
            return !strcmp(this->m_p, p);
        }
        else {
            return false;
        }
    }
}
bool MyString ::operator!=(const char* p)
{
    return !(*this == p);
}

bool MyString ::operator==(const MyString& s)
{
    if (this->m_len != s.m_len)
    {
        return false;
    }
    return !(strcmp(m_p, s.m_p));

}



namespace string_test
{
    void test_mystring()
    {
        //构造
        MyString s1;
        MyString s2("abc");
        MyString s3 = s2;
        int s = 0;

        // 赋值
        MyString s4 = "s4";
        s4 = s2;
        s4 = "abb";

        // []
        //s4[1] = '4';
        cout << "hello" << endl;
        printf("%c", s4[1]);

        // <<
        MyString s5 = "12345abc";
        cout << s5 << endl;

        // ==
        MyString s6 = "12345";
        MyString s7 = s6;

        if (s6 == "12345")
        {
            cout << "equal to 12345" << endl;
        }

        if (s7 == s6)
        {
            cout << "s7 == s6" << endl;
        }
    }
}