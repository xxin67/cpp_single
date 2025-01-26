#include<iostream>
using namespace std;

//多重继承下的虚函数示范

class Base1 //虚函数基类
{
    public:
        virtual void fun()
        {
            cout<<"--Base1--\n";
        }
};
class Base2 //非虚函数基类
{
    public:
        void fun()
        {
            cout<<"--Base2--\n";
        }
};
class Derived:public Base1,public Base2
{
    public:
        void fun()
        {
            cout<<"--Derived--\n";
        }
};

int main()
{
    Base1 *p1;
    Base2 *p2;
    Derived obj;
    p1 = &obj;
    cout<<"虚函数基类结果:\n";
    p1->fun();

    cout<<"普通基类:\n";
    p2 = &obj;
    p2->fun();
    return 0;
}

/*
对于多重继承派生类Derived,当用含虚函数的基类指针时调用函数,呈现虚函数的特性,当用普通基类的指针时就不呈现虚函数的特性.
*/