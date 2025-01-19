#include<iostream>
using namespace std;

//类的继承里的赋值兼容规则.

class Base
{
    public:
        int i;
        Base(int x)
        {
            i = x;
        }
        void show()
        {
            cout<<"Base i="<<i<<endl;
        }
};
class Derived:public Base
{
    public:
        Derived(int x):Base(x)
        {}
};

void fun(Base &bb);

int main()
{
    Base b1(100);
    b1.show();
    Derived d1(11);
    b1 = d1;        //派生对象直接向基类对象赋值
    b1.show();
    Derived d2(22);
    Base &b2 = d2;  //派生对象可以初始化基类对象的引用
    b2.show();
    Derived d3(33);
    Base *b3 = &d3; //派生对象的地址可以赋给基类对象的指针
    b3->show();
    Derived d4(44);
    fun(d4);        //若函数的形参是基类的对象或对象的引用,则可以直接用派生类的对象直接作为函数的实参.
    return 0;
}

void fun(Base &b)
{
    cout<<b.i<<endl;
}