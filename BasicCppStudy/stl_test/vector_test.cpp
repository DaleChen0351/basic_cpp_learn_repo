#include "test.h"


namespace vector_test
{
    //
    void printVec(const vector<int>&v)
    {
        for (vector<int>::const_iterator iter = v.begin(); iter != v.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    class Person
    {
    public:
        Person() {
            cout << "defalut ctor" << endl;
        }
        Person(const Person& other){
            cout << "copy ctor is called" << endl;
        }
    };
    // vector base
    void test_01()
    {
        vector<int>v;
        v.push_back(11);
        v.push_back(22);
        v.push_back(33);
        v.front() = 1;
        while (v.size() > 0)
        {
            cout << v.back() << " ";
            v.pop_back();
        }
        
    }
    // defalut ctor and copy ctor
    void test_02()
    {
        vector<int>v2(10);// v2 -> v2(10)
        v2[0] = 10;// 没有初始化就访问，造成数组越界
     // defalut ctor test
        //vector<Person>p;
        //p.resize(10); // 调用默认构造函数
    // copy ctor test
        vector<Person>p2;
        p2.reserve(10);
        cout << "p2 capacity = " << p2.capacity();// 10 
        cout << "  size = " << p2.size() << endl;// 0
        Person person;// defalut ctor call
        p2.push_back(person); // copy ctor call
        cout << " size = " << p2.size() << endl;// 0
    }
    // iterator
    void test_03()
    {
        vector<int>v = { 1,2,3,4,5 };
        for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
        for (vector<int>::reverse_iterator iter = v.rbegin(); iter != v.rend(); iter++)
        {
            cout << *iter << " ";
        }
        //vector<int>::const_iterator // 只读
    }
    // erase and insert
    void test_04()
    {
        //区间删除
        vector<int>v1 = { 1,2,3,4,5 };
        auto ret = v1.erase(v1.begin() + 1, v1.begin() + 3);// 支持随机存储迭代器  删除[beg,end)区间的数据，返回下一个数据的位置。
        cout << *ret << endl;// 4
        printVec(v1);//1,4,5 
        // 指定位置删除
        v1.erase(v1.begin());
        printVec(v1);// 4,5

        
        v1.insert(v1.end(),3,2);
        v1.insert(v1.end(),3,6);
        printVec(v1);// 4,5
        // 根据元素的值的删除
        for (vector<int>::iterator iter = v1.begin(); iter != v1.end();)
        {
            if (*iter == 2)
            {
                iter = v1.erase(iter); // 当使用erase函数时，执行删除操作后，迭代器 iteration会自动++
            }
            else {
                iter++;
            }
        }
        printVec(v1);// 4,5,6,6,6
        // 清空
        v1.clear(); 

        // insert
        vector<int>v;
        v.insert(v.begin(),2, 10);// iter,count,val
        v.insert(v.end(), 11);
        vector<int>v3 = { 1,2,3,4,5 };
        v3.insert(v3.end(), v.begin(), v.end());
        printVec(v3);// 1 2 3 4 5 10 10 11
    }
}