#include<iostream>
#include<string>
using namespace std;
//友元类的成员函数可以调用类中的所有成员.
class Girl;
class Boy
{
    private:
        string name;
        int age;
    public:
        Boy(string n,int a)
        {
            name = n;
            age = a;
        }
        void disp1(Girl &);
        void disp2(Girl &);
};
class Girl
{
    private:
        string name;
        int age;
    public:
        Girl(string n,int a)
        {
            name = n;
            age = a;
        }
        friend Boy;
};

int main()
{
    Boy b1("陈大林",11);
    Girl g1("张晓好",12);
    b1.disp1(g1);
    b1.disp2(g1);
    return 0;
}

void Boy::disp1(Girl &g)
{
    cout<<"男孩的姓名:"<<name<<endl;
    cout<<"女孩的姓名:"<<g.name<<endl;
}

void Boy::disp2(Girl &g)
{
    cout<<"男孩的年龄:"<<age<<endl;
    cout<<"女孩的年龄:"<<g.age<<endl;
}