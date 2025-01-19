#include<iostream>
using namespace std;

//运算符重载友元函数

class Complex
{
    private:
        double real;
        double imag;
    public:
        Complex(double r=0,double i=0):real(r),imag(i)
        {}
        void print();
        friend Complex operator*(Complex &,Complex&);
        friend Complex operator/(Complex &,Complex&);   //双目运算符友元函数
        friend Complex operator++(Complex &);           //单目运算符友元函数,,对有前后缀之分的运算符,在函数声明时在形参加上一个int形参编译器会自动识别为后缀形式.
        friend Complex operator++(Complex &,int);
};

int main()
{
    Complex a1(2.3,4.6),a2(3.6,2.8),a3,a4,a5,a6;
    a3 = a1 * a2;   //显示引用格式为:a3 = operator*(a1,a2);
    a4 = a1 / a2;
    a5 = a1;
    ++a5;    
    cout<<"a5:\n";       //显示引用格式为:operator++(a5);
    a5.print();
    a6 = a5++;
    cout<<"a5:\n";
    a5.print();
    cout<<"a6:\n";
    a6.print();
    cout<<"a1:\n";
    a1.print();
    cout<<"a2:\n";
    a2.print();
    cout<<"a3:\n";
    a3.print();
    cout<<"a4:\n";
    a4.print();
    return 0;
}

void Complex::print()
{
    cout<<real;
    if(imag>0) cout<<'+';
    if(imag!=0) cout<<imag<<'i'<<endl;
}

Complex operator*(Complex &c1,Complex &c2)
{
    return Complex(c1.real*c2.real-c1.imag*c2.imag,c1.imag*c2.real+c1.real*c2.imag);
}

Complex operator/(Complex &a,Complex &b)
{
    Complex temp;
    double t;
    t = 1 / (b.real*b.real+b.imag*b.imag);
    temp.real = (a.real*b.real + a.imag*b.imag) *t;
    temp.imag = (b.real*a.imag - a.real*b.imag) *t;
    return temp;
}

Complex operator++(Complex &a)      //前缀形式
{
    ++a.real;
    ++a.imag;
    return a;
}

Complex operator++(Complex &a,int)  //后缀形式
{
    Complex temp(a);
    a.real++;
    a.imag++;
    return temp;
}