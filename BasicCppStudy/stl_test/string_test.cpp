#include "test.h"


namespace string_test
{
    //初始化
    void test_01_cp()
    {
        string s1 = "hello, world!";
        string s2("hello, world!");
        string s3(s1);// copy ctor 
        string s4(10, 'a');// 10 个a

        cout << s1 << endl;
        cout << s2 << endl;
        cout << s3 << endl;
        cout << s4 << endl;
    }
    // 遍历
    void test_02()
    {
        string s = "hello, world!";
    //数组方式
        for (int i = 0; i < s.length(); i++)
        {
            cout << s[i] << "";
        }
        cout << endl;
    // 迭代器
        for (string::iterator iter = s.begin(); iter != s.end(); iter++)
        {
            cout << *iter << "";
        }
        cout << endl;

    // 使用at 可以抛出异常 相比较 []
        int i = 0;
        try
        {
            for (; i < s.length() + 3; i++)
            {
                cout << s.at(i) << endl;
                //cout << s[i] << endl;
            }
        }
        catch (...)// 注意 ...
        {
            cout << "error out" << endl;
            cout << i << endl;
        }

    }
    // 字符指针和string的转化
    void test_03()
    {
        //string -> char
        string s("helloooooooooooooo");
        printf("%s \n", s.c_str());

        //s的内容copy到 buf中
        char buf[128] = { 0 };// C风格字符串

            //1
        const char* buf22 = s.c_str();
        cout << buf22 << endl;
            // 2
        s.copy(buf, 5, 0);// only copy 3 字符，不会编程C风格的字符串（\n 结尾的字符串）
        cout << buf << endl;
    }
    // 连接字符串
    void test_04()
    {
        // + 
        string s1 = "aaa";
        string s2("bbb");
        //cout << s1 + s2 << endl;
        s1 += s2;
        cout << s1 << endl;

        // apend()
        string s3 = s1.append(s2);
        cout << s3 << endl;

        string s4 = "hello ";
        string s5 = "Dale Chen";
        string greeting = s4.append(s5, 4);// s5 及希望拼接的长度
        cout << greeting << endl;

    }
    // 查找和替换
    void test_05()
    {
        string s = "dale 111 dale 222 dale 333 444";
        int offindex = s.find("dale", 0);
        while (offindex != string ::npos)
        {
            cout << "offindex = " << offindex << " ";
            s.replace(offindex, 4, "DALE");// remove posindex 4 , and adding DALE
            offindex += 4;
            offindex = s.find("dale", offindex);   
        }
        cout << endl;
        cout << s << endl;   

        int ret = strlen("abc");
        int rettt = 0;
    }
    // 删除和插入
    void test_06()
    {
        //insert
        string s1 = "BBB";
        s1.insert(0, "AAA");
        string s3("CCC");
        auto iter = s1.end();
        s1.insert(s1.length(), s3);
        cout << s1 << endl;

        //erase
        string ss = "hello";
        auto iter2 = find(ss.begin(), ss.end(), 'l');
        if (iter2 != ss.end())
        {
            ss.erase(iter2);
            cout <<ss  << endl;
        }
    }
    //transform 算法
    void test_07()
    {
        string s = "chen DALE";
        string s3;
        s3.resize(100);// 空间要预先分配,并调用默认的构造函数
        
        transform(s.begin(), s.end(), s3.begin(), toupper);
 
        cout << s << endl;
        cout << s3 << endl;
    }
    
}