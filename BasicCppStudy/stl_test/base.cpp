#include "test.h"

namespace base_test
{
    class Teacher
    {
    public:
        Teacher(int age)
        {
            m_age = age;
        }
        int m_age;
    };
    void test_01()
    {
    // push into build-in type data
        vector<int>v;
        v.push_back(1);

    // push into user-defined type
        vector<Teacher>t;
        t.push_back(Teacher(11));
        t.push_back(Teacher(12));
        t.push_back(Teacher(13)); 
        for (vector<Teacher>::iterator iter = t.begin(); iter != t.end(); iter++)
        {
            cout << "age = " << iter->m_age << " ";
        }
        
        cout << endl;
    // push pointer of user-defined type
        vector<Teacher*>p;
        Teacher t1(22);
        p.push_back(&t1);
        for (vector<Teacher*>::iterator iter = p.begin(); iter != p.end(); iter++)
        {
            cout << "age = " << (*iter)->m_age<< " ";
        }



    }
}