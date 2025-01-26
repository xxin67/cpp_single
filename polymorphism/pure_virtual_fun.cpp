#include<iostream>
using namespace std;

//纯虚函数实例

class Circle
{
    protected:
        int r;
    public:
        void setr(int x)
        {
            r = x;
        }
        virtual void show() = 0;    //纯虚函数定义
};
class Area:public Circle
{
    public:
        virtual void show()
        {
            cout<<"这个圆的面积:"<<3.14 * r * r<<endl;
        }
};
class Perimeter:public Circle
{
    public:
        void show()
        {
            cout<<"这个圆的周长:"<<3.14 * 2 *r<<endl;
        }
};

int main()
{
    Circle *p;
    Area ob1;
    Perimeter ob2;
    ob1.setr(10);
    ob2.setr(10);
    p = &ob1;
    p->show();
    p = &ob2;
    p->show();
    return 0;
}

/*
纯虚函数用于在基类中创造一个公共接口,其功能根据子类的需求定义.
*/