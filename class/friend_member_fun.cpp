#include<iostream>
#include<string>
using namespace std;

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
        void disp(Girl &);
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
        friend void Boy::disp(Girl &);
};

int main()
{
    Boy b1("陈大林",11);
    Girl g1("张晓好",12);
    b1.disp(g1);
}

void Boy::disp(Girl &g)
{
    cout<<"男孩的姓名:"<<name<<endl;
    cout<<"男孩的年龄为:"<<age<<endl;
    cout<<"女孩的姓名为:"<<g.name<<endl;
    cout<<"女孩的年龄为:"<<g.age<<endl;
}