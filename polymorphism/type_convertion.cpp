#include<iostream>
using namespace std;

//类型转换示例

class Complex
{
    private:
        int real,imag;
    public:
        Complex() {}
        Complex(int r,int i):real(r),imag(i) {}
        Complex(int i)  //转换构造函数,将整数型数据变为自定义类型Complex.
        {
            real = imag = i / 2;
        }
        operator int()  //类型转换成员函数,将该类的对象类型转换为整数型.只能为成员函数形式
        {
            return real + imag;
        }
        void print()
        {
            cout<<"real:"<<real<<"\t"<<"imag:"<<imag<<endl;
        }
};

int main()
{
    Complex a1(1,2),a2(3,4);
    Complex a3;
    a3 = a1 + a2;   //即使没有定义运算符重载函数,当定义了符合运算符预定义规则的类型转换函数,编译器自动进行隐式转换
    a3.print();     //显示转换格式为:int(a1).
    return 0;
}