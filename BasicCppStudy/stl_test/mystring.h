#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class MyString
{
    friend std::ostream& operator<< (std:: ostream& os, MyString& s);
public:
    MyString();
    MyString(const char* p);
    MyString(const MyString& s);
    ~MyString();

    // operator = 
    MyString& operator=(const char* p);
    MyString& operator=(const MyString& s);
    char& operator[](int index);
    bool operator==(const char* p);
    bool operator!=(const char* p);
    bool operator==(const MyString& s);

private:
    int m_len;
    char* m_p;
};
