// smart_pointer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// auto_pointer (not used）
// shard_ptr
// unique_ptr 一个指针只能一个人使用
// weake_ptr 搭配与 shard_ptr

#include "pch.h"
using namespace myPoint;
#include <memory>

// smart points test
class Entity {
public:
    Entity() { 
        puts("Entity created"); 
        id_m = 0;
    }
    ~Entity() { puts("Entity destroyed"); }
    int id_m;

};


void ex1()
{
    puts("--------------");
    puts("Entering ex1");

    {
        puts("Entering ex1_scope1");
        auto e1 = std::make_unique<Entity>();// stack heap?

        puts("Leaving ex1::scope1");// 智能指针在离开作用域后就调用析构函数，然后指向为空
    }

    puts("leaving ex1");
}
void foo(std::unique_ptr<Entity> ae) {
    puts("Entering foo");
    ae->id_m = 1;
    std::cout << "id_m: " << ae->id_m << std::endl;
    puts("Leaving foo");
}

void ex2() {
    puts("-----------");
    puts("Entering ex2");
    auto e1 = std::make_unique<Entity>();
    foo(std::move(e1));

    puts("Leaving ex2");
}

void ex3()
{
    puts("-----------");
    puts("Entering ex3");
    auto e1 = std::make_shared<Entity>();
    std::cout << e1.use_count() << std::endl;//1?
    {
        puts("Entering ex3::scope1");
        auto e2 = e1;//copy 2
        std::cout << e1.use_count() << std::endl;//2?
        auto e3 = std::move(e2);
        std::cout << e1.use_count() << std::endl;//2?
        puts("Leaving ex3::scope1");
    }
    std::cout << e1.use_count() << std::endl;//1
    puts("Leaving ex3");

}

// 智能指针作为参数的传入
//void print(ObjectPtr obj)// 作为值传入 拷贝（指针引用计数的改变），零时变量
//{
//	std::cout <<"count:"<< obj.use_count() << std::endl;
//}
void print(const ObjectPtr& obj)// 作为引用传入，效率高。没有特殊情况下，使用const 引用形式
{
	std::cout << "ref_count:" << obj.use_count() << std::endl;
}
//
void print(const Object& obj) // 传入 可以是 （*objptr）也可以是一个object对象，这样设计的接口更加灵活
{

}

// 自定义智能指针的析构函数
void deleteOfObject(Object* obj)
{
	if (obj)
	{
		std::cout << " do other things"<< std::endl;// 可以对默认的智能指针的析构函数进行添加和修改
		delete obj;
	}	
}
void useDeleter()
{
	ObjectPtr obj(new Object(3), deleteOfObject);// ctor 的时候传入两个参数
	// eg： handle 编程
}



int main()
{
    std::cout << "Hello World!\n"; 
    //ex1();
    //ex2();
    ex3();
    std::cout << __cplusplus << std::endl;
	ObjectPtr null;// ?
	ObjectPtr obj(new Object(1));
	std::cout << obj.use_count() << std::endl;// 引用计数的原理？
	// copy ctor
	ObjectPtr obj2(obj);
	print(obj2);// 2
	// operator =
	ObjectPtr obj3 = obj;
	print(obj3);//3
// 如果某个智能指针不再使用
	obj2.reset(); // obj2 = nullptr;
	print(obj);//2
// swap
	ObjectPtr obj4;
	obj3.swap(obj4);
	std::swap(obj3, obj4);
// 判断智能指针是否在管理资源
	auto p = obj.get();// 返回的是裸指针
	if (p)
	{
		std:: cout << "luo point id = " << p->GetID() << std::endl; //对裸的指针操作 ， 万不得已才使用
	}

	if (obj) // operator bool 
	{
		std::cout << "smart_ptr id = " <<obj->GetID() << std::endl; // operator ->
		std::cout << "smart_ptr id = " << (*obj).GetID() << std::endl;// operator * 
	}

// unique
	if (! obj.unique()) // 是否只有一个使用者
	{
		std::cout << "the smart_ptr is not only one used" << std::endl;
	}
	useDeleter();
}


// sumup:
// 出了定义域 智能指针的析构函数一定会被自动调用到。就是利用构造和析构的特性的
// 即使抛出了异常

// 智能指针注意事项和局限性