#include<iostream>
#include<cmath>
using namespace std;
typedef double funtype(double);

double t(funtype *fun,double,double,int);
funtype fun1;
funtype fun2;
funtype fun3;

int main ()
{
    cout<<"fun1:"<<t(fun1,0,1,10000)<<endl;
    cout<<"fun2:"<<t(fun2,1,2,10000)<<endl;
    cout<<"fun3:"<<t(fun3,0,M_PI_2,10000)<<endl;
    system("pause");
}

double fun1(double x)
{   
    return 4 / (1 + x * x);
}
double fun2(double x)
{
    return sqrt((1 + x * x));
}
double fun3(double x)
{
    return sin(x);
}
double t(funtype *fun,double a,double b,int n)
{
    double t2 = 0;
    double h = (b - a) / n;
    for(int i = 1;i<=n-1;i++)
    {
        t2 += fun(a + i * h);
    }
    return (h * (fun(a) + fun(b))) / 2 + h * t2;
}