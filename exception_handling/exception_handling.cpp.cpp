#include<iostream>
using namespace std;

//异常处理实例

int Dev(int x,int y);

int main()
{
    try //异常处理第二部分,对作用域的语句是否返回类型进行检验
    {
        cout<<"7/3="<<Dev(7,3)<<endl;
        cout<<"5/0="<<Dev(5,0)<<endl;
    }
    catch(int)  //第三部分,若try语句返回了catch对应的参数类型,则执行对应catch函数的作用域.catch(...)则表示接受所有类型的异常.
    {
        cout<<"除数为0,错误."<<endl;
    }
    cout<<"end"<<endl;
    return 0;
}

int Dev(int x,int y)
{
    if(y == 0)
    {
        throw y;    //第一部分,判断异常的出现条件和和返回的类型,将结果throw给try语句.
    }
    return x/y;
}