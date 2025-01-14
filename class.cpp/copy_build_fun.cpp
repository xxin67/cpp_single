#include<iostream>
using namespace std;

class point
{
    private:
        int x,y;
    
    public:
        point(int a0,int b=0);
        point(const point &p);
        void print()
        {
            cout<<x<<" "<<y<<endl;
        }
};



void fun1(point p);
point fun2();

int main()
{
    point p1(30,40);
    p1.print();
    point p2(p1);
    p2.print();
    
    point p3 = p1;
    p3.print();

    fun1(p1);
    cout<<"已定义的类去承接返回值前类的地址:"<<&p2<<endl;
    p2 = fun2();
    cout<<"承接后类的地址:"<<&p2<<endl;

/*                     
与教材不同,当函数返回类时不会调用拷贝构造函数.原因是RVO(return valve optimization)
如果返回的类被一个新建的类承接,则此新建的类的地址就会直接变为返回的类的地址.若是赋给
已定义的类,则地址不会改变.*/ 

    
    point p5 = fun2();
    cout<<"新建的类承接返回值后的地址:"<<&p5;
    return 0;
}

point::point(int a,int b)
{
    x = a;
    y = b;
    cout<<"using normal constructor:"<<endl;
}

point::point(const point &p)
{
    x = 2 * p.x;
    y = 2 * p.y;
    cout<<"using copy constructor:"<<endl;
}

void fun1(point p)
{
    p.print();
}

point fun2()
{
    point p4(10,30);
    cout<<"返回的类的地址:"<<&p4<<endl;
    return p4;
}

