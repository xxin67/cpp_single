#include<iostream>
using namespace std;

//虚函数的简单示范

class B0
{
    public:
        virtual void print()
        {
            cout<<"B0::print()"<<endl;  //虚函数定义
        }
        void print1()
        {
            cout<<"B0::print1()"<<endl; //非虚函数定义
        }
};
class B1:public B0
{
    public:
        virtual void print()
        {
            cout<<"B1::print()"<<endl;
        }
        void print1()
        {
            cout<<"B1::print1()"<<endl;
        }
};
class B2:public B1
{
    public:
        virtual void print()
        {
            cout<<"B2::print()"<<endl;
        }
        void print1()
        {
            cout<<"B2::print1()"<<endl;
        }
};

int main()
{
    B0 ob0,*op; //op指针动态变化
    cout<<"若函数为虚函数:\n";
    op = &ob0;
    op->print();
    B1 ob1;
    op = &ob1;
    op->print();
    B2 ob2;
    op = &ob2;
    op->print();    

    cout<<"若函数为非虚函数:\n";
    op = &ob0;
    op->print1();
    op = &ob1;
    op->print1();
    op = &ob2;
    op->print1();

    //基类指针指向派生类对象时,若此时调用的为虚函数,则能够直接调用该派生类重新定义的同名同类型的函数.
    //若为非虚函数,则即使基类指针指向派生类对象,其调用的函数依旧是基类中的同名函数,而不是派生类中重新定义的同名函数.
    return 0;
}

/*
虚函数是实现动态联编的关键,其作用就是能让基类指针指向派生类对象调用函数时能使用派生类自身重定义的函数,完成用单一指针循环重复调用不同函数,
从而实现多态性.

若B1是B0的派生类,B2又是B1的派生类,若在B0定义了虚函数,而在B1中的同名函数的返回类型,形参类型的顺序,形参数量,有一个与
基类的同名函数不同,则不会当作虚函数,而是一个重载函数,就失去了虚函数的特点,而对于公有派生类,其会直接继承其直接基类的虚函数.

基类的虚函数必须为公有成员,同时派生类派生类型必须为公有类型.
*/