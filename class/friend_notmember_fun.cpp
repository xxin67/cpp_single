#include<iostream>
#include<string>
using namespace std;
//非成员友元函数实例
//可用于需要调用多个类的私有数据的情况.
class Girl;

class Boy
{
    private:
        string name;
        int age;
        static int test;
    public:
        Boy(string n,int a);
        friend void prdata(const Girl &,const Boy &); 
};
class Girl
{
    private:
        string name;
        int age;
    public:
        Girl(string n,int a);
        friend void prdata(const Girl &,const Boy &);
};

void prdata(const Girl &g,const Boy &b);

int main()
{
    Girl g1("郑晓书",12),g2("李芳",13),g3("王红",12);
    Boy b1("陈大林",11),b2("赵超",13),b3("白小光",12);
    prdata(g1,b1);
    prdata(g2,b2);
    prdata(g3,b3);
    return 0;
}

Girl::Girl(string n,int a)
{
    name = n;
    age = a;
}

Boy::Boy(string n,int a)
{
    name = n;
    age = a;
}

void prdata(const Girl &g,const Boy &b)
{
    cout<<"女孩的姓名:"<<g.name<<endl;
    cout<<"女孩的年龄:"<<g.age<<endl;
    cout<<"男孩的姓名:"<<b.name<<endl;
    cout<<"男孩的年龄:"<<b.age<<endl;
}