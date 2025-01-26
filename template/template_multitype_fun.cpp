#include<iostream>
using namespace std;

//多类型函数模板实例

template<typename T1,typename T2>
void fun(T1 x,T2 y)
{
    cout<<x<<" "<<y<<endl;
}

int main()
{
    fun(10,"hao");
    fun(0.123,10L);
    return 0;
}