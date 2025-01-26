#include<iostream>
#include<string>
using namespace std;

//多类型类模板定义

template<typename T1,typename T2>
class Myclass
{
    private:
        T1 i;
        T2 j;
    public:
        Myclass(T1 a,T2 b)
        {
            i = a;
            j = b;
        }
        void show()
        {
            cout<<"i="<<i<<"\t"<<"j="<<j<<endl;
        }
};

int main()
{
    Myclass<int,double>ob1(12,0.15);
    Myclass<char,string>ob2('x',"This is a test.");
    ob1.show();
    ob2.show();
    return 0;
}
