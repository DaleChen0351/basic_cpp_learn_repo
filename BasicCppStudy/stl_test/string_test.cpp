#include "test.h"


namespace string_test
{
    //��ʼ��
    void test_01_cp()
    {
        string s1 = "hello, world!";
        string s2("hello, world!");
        string s3(s1);// copy ctor 
        string s4(10, 'a');// 10 ��a

        cout << s1 << endl;
        cout << s2 << endl;
        cout << s3 << endl;
        cout << s4 << endl;
    }
    // ����
    void test_02()
    {
        string s = "hello, world!";
    //���鷽ʽ
        for (int i = 0; i < s.length(); i++)
        {
            cout << s[i] << "";
        }
        cout << endl;
    // ������
        for (string::iterator iter = s.begin(); iter != s.end(); iter++)
        {
            cout << *iter << "";
        }
        cout << endl;

    // ʹ��at �����׳��쳣 ��Ƚ� []
        int i = 0;
        try
        {
            for (; i < s.length() + 3; i++)
            {
                cout << s.at(i) << endl;
                //cout << s[i] << endl;
            }
        }
        catch (...)// ע�� ...
        {
            cout << "error out" << endl;
            cout << i << endl;
        }

    }
    // �ַ�ָ���string��ת��
    void test_03()
    {
        //string -> char
        string s("helloooooooooooooo");
        printf("%s \n", s.c_str());

        //s������copy�� buf��
        char buf[128] = { 0 };// C����ַ���

            //1
        const char* buf22 = s.c_str();
        cout << buf22 << endl;
            // 2
        s.copy(buf, 5, 0);// only copy 3 �ַ���������C�����ַ�����\n ��β���ַ�����
        cout << buf << endl;
    }
    // �����ַ���
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
        string greeting = s4.append(s5, 4);// s5 ��ϣ��ƴ�ӵĳ���
        cout << greeting << endl;

    }
    // ���Һ��滻
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
    // ɾ���Ͳ���
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
    //transform �㷨
    void test_07()
    {
        string s = "chen DALE";
        string s3;
        s3.resize(100);// �ռ�ҪԤ�ȷ���,������Ĭ�ϵĹ��캯��
        
        transform(s.begin(), s.end(), s3.begin(), toupper);
 
        cout << s << endl;
        cout << s3 << endl;
    }
    
}