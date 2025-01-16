#include<iostream>
using namespace std;

class Base
{
    protected:
        int a;
    public:
        Base()
        {
            a = 5;
            cout<<"Base a="<<a<<endl;
        }
};
class Base1:public Base
{
    public:
        Base1()
        {
            a = a + 10;
            cout<<"Base1 a="<<a<<endl;
        }
};
class Base2:public Base
{
    public:
        Base2()
        {
            a = a + 20;
            cout<<"Base2 a="<<a<<endl;
        }
};
class Derived:public Base1,public Base2
{
    public:
        Derived()
        {
            cout<<"Base1::a="<<Base1::a<<endl;
            cout<<"Base2::a="<<Base2::a<<endl;
        }
};

int main()
{
    Derived obj;
    return 0;
}
/*
因为类Derived的继承的两个类有着相同的基类Base,而这两个类因此有着相同的Base数据成员a,
因此在类Derived中不能直接调用a,必须加上调用的类的类名前缀"类名::",才能防止二义性引起报错.
而若想使a只有一个复制值,即Base1与Base2的a值联通,因此引入虚基类.即是对Static机制的继承扩展.
*/