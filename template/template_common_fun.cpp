#include<iostream>
using namespace std;

//函数模板示例

template<typename T>    //函数模板定义
T Max(T x,T y) 
{
    return (x>y)?x:y;
}
template<typename T>    //函数模板重载
T Max(T x,T y,T z);     //函数模板声明


template<typename T>
T sum(T *array,int size=0)
{
    T total = 0;
    for(int i=0;i<size;i++)
    {
        total +=*(array + i);
        // total += array[i];
    }
    return total;
}

int main()
{   
    cout<<"比大小:\n";
    int m=10,n=20,Max2;
    double a=10.1,b=20.2,c=30.3,Max3;
    Max2 = Max(m,n);
    Max3 = Max(a,b,c);
    cout<<"Max("<<m<<","<<n<<")="<<Max2<<endl;
    cout<<"Max("<<a<<","<<b<<","<<c<<")="<<Max3<<endl;

    cout<<endl;
    cout<<"数组指针:\n";
    int i_array[] = {1,2,3,4,5,6,7,8,9,10};
    double d_array[] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10};
    int itotal = sum(i_array,10);
    double dtotal = sum(d_array,10);
    cout<<"这个整型数组的元素之和为:"<<itotal<<endl;
    cout<<"这个双精度型数组的元素之和为:"<<dtotal<<endl;
    return 0;
}

template<typename T>    //声明定义也要加上模板声明
T Max(T x,T y,T z)
{
    T t;
    t = (x>y)?x:y;
    return (t>z)?t:z;
}