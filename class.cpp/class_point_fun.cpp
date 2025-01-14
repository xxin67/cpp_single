#include<iostream>
using namespace std;
class tr
{
    private:
        int i;
    public:
        tr(int n)
        {
            i = n;
        }
        void set_i(int n)
        {
            i = n;
        }
        int get_i()
        {
            return i;
        }
};

void sqr_it_0(tr ob)
{
    ob.set_i(ob.get_i() * ob.get_i());
    cout<<"在函数sqr_it内,形参对象ob的数据成员i的值为:"<<ob.get_i();
    cout<<endl;
}

void sqr_it(tr *ob)
{
    ob->set_i(ob->get_i() * ob->get_i());
    cout<<"在函数sqr_it内,形参对象ob的数据成员i的值为:"<<(*ob).get_i();
    cout<<endl;
}

void sqr_it(tr &ob)
{
    ob.set_i(ob.get_i() * ob.get_i());
    cout<<"在函数sqr_it内,形参对象ob的数据成员i的值为:"<<ob.get_i();
    cout<<endl;
}

int main()
{
    tr obj(10);
    cout<<"调用对象作为函数参数:"<<endl;
    cout<<"调用sqr_it前,实参对象obj的数据成员i的值为:";
    cout<<obj.get_i()<<endl;
    sqr_it_0(obj);
    cout<<"调用函数sqr_hou后,实参对象obj的数据成员i的值为:";
    cout<<obj.get_i()<<endl;
    cout<<endl;

    cout<<"调用对象指针作为函数参数:"<<endl;
    cout<<"调用sqr_it前,实参对象obj的数据成员i的值为:";
    cout<<obj.get_i()<<endl;
    sqr_it(&obj);
    cout<<"调用函数sqr_hou后,实参对象obj的数据成员i的值为:";
    cout<<obj.get_i()<<endl;
    cout<<endl;

    obj.set_i(10);
    cout<<"调用对象引用作为函数参数:"<<endl;
    cout<<"调用sqr_it前,实参对象obj的数据成员i的值为:";
    cout<<obj.get_i()<<endl;
    sqr_it(obj);
    cout<<"调用函数sqr_hou后,实参对象obj的数据成员i的值为:";
    cout<<obj.get_i()<<endl;
    cout<<endl;
    return 0;
}