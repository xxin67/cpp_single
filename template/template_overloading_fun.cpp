#include<iostream>
using namespace std;

//函数模板与同名重载函数的关系

template<typename T>    //函数模板定义
T Max(T x,T y)
{
    cout<<"调用模板函数:\n";
    return (x>y)?x:y;
}

int Max(int x,int y)    //普通重载函数
{
    cout<<"调用非模板函数:\n";
    return (x>y)?x:y;
}

int main()
{
    int i1=10,i2=56,i_max;
    double d1=50.34,d2=4656.34,d_max;
    char c1='k',c2='n',c_max;
    i_max = Max(i1,i2);
    cout<<"\t"<<"较大的整数是:"<<i_max<<endl;
    d_max = Max(d1,d2);
    cout<<"\t较大的双精度浮点数是:"<<d_max<<endl;
    c_max = Max(c1,c2);
    cout<<"\t较大的字符是:"<<c_max<<endl;
    return 0;
}

/*
若同时存在函数模板和重载函数,调用函数时会先寻找完全符合参数要求的非模板函数的重载函数,找不到才会通过函数模板生成对应模板函数.
*/