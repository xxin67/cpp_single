#include<iostream>
using namespace std;

//虚析构函数的示范


//B与D为虚析构函数
class B
{
    public:
        virtual ~B()
        {
            cout<<"调用基类B的析构函数\n";
        }
};
class D:public B
{
    public:
        ~D()
        {
            cout<<"调用派生类D的析构函数\n";
        }
};

//B1与D1为普通析构函数
class B1
{
    public:
         ~B1()
        {
            cout<<"调用基类B1的析构函数\n";
        }
};
class D1:public B1
{
    public:
        ~D1()
        {
            cout<<"调用派生类D1的析构函数\n";
        }
};

int main()
{
    B *p;
    B1 *p1;

    p = new D;
    p1 = new D1;
    cout<<"delete p:\n";
    delete p;
    cout<<endl;
    cout<<"delete p1:\n";
    delete p1;
/*
对虚析构函数,其会先调用基类指针指向的派生对象的类的析构函数,再调用基类析构函数,效果与delete派生类对象一样.
而对普通析构函数,其只会调用基类的析构函数.
*/

    return 0;
}

/*
当基类的析构函数为虚函数,其所有派生类的析构函数自动变为虚函数.
构造函数没有虚函数.
*/