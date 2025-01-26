#include<iostream>
using namespace std;

//类模板的实例

template<typename T>    //类模板定义
class Compare
{
    private:
        T x,y,z;
    public:
        Compare(T a,T b)    //双参数构造函数并不必要,但为了显示类外定义而保留.
        {
            x = a;
            y = b;
        }
        T Max_2()
        {
            return (x>y)?x:y;
        }
        Compare(T a,T b,T c);
        T Max_3();
};

int main()
{
    Compare<int> com1(3,7);
    Compare<double>com2(12.34,56.78);
    Compare<char>com3('a','x');
    Compare<int>com4(5,8,10);
    cout<<"其中的最大值是:"<<com1.Max_2()<<endl;
    cout<<"其中的最大值是:"<<com2.Max_2()<<endl;
    cout<<"其中的最大值是:"<<com3.Max_2()<<endl;
    cout<<"其中的最大值是:"<<com4.Max_3()<<endl;
}

template<typename T>        //类外定义类模板构造函数.
Compare<T>::Compare(T a,T b,T c)
{
    x = a; y = b; z = c;
}

template<typename T>        //类外定义类模板函数
T Compare<T>::Max_3()
{
    T t;
    t = (x>y)?x:y;
    return (t>z)?t:z;
}