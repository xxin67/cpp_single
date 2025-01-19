#include<iostream>
using namespace std;

//运算符重载成员函数
/*
友元重载与成员重载的区别为成员重载会将本类调用此成员函数的对象自动视为函数的一个实参,因此相对友元重载函数定义只需要一个形参.
但因此对双目运算符而言,运算符两侧的元素不能随意的调换位置,特别是在元素的类型不相同时需特别注意.
*/

class Complex
{
    private:
        double real;
        double imag;
    public:
        Complex(double r=0,double i=0):real(r),imag(i)
        {}
        void print();
        Complex operator*(Complex &);
        Complex operator/(Complex &);   //双目运算符重载成员函数
        Complex operator++();           //单目运算符重载成员函数,对有前后缀之分的运算符,在函数声明时在形参加上一个int形参编译器会自动识别为后缀形式.
        Complex operator++(int);
};

int main()
{
    Complex a1(2.3,4.6),a2(3.6,2.8),a3,a4,a5,a6;
    a3 = a1 * a2; //显示引用的格式为a3 = a1.operator*(a2)
    a4 = a1 / a2; //当写作:a3 = a2 * a1,其显示引用为:a3 = a2.operator*(a1),若a1的类型不是operator*的形参类型就会报错
    a5 = a1;
    ++a5;    
    cout<<"a5:\n";       //显示引用格式为:a5.operator++();
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

Complex Complex::operator*(Complex &c2)
{
    return Complex(real*c2.real-imag*c2.imag,imag*c2.real+real*c2.imag);
}

Complex Complex::operator/(Complex &b)
{
    Complex temp;
    double t;
    t = 1 / (b.real*b.real+b.imag*b.imag);
    temp.real = (real*b.real + imag*b.imag) *t;
    temp.imag = (b.real*imag - real*b.imag) *t;
    return temp;
}

Complex Complex::operator++()   //前缀形式
{
    ++real;
    ++imag;
    return *this;
}

Complex Complex::operator++(int)    //后缀形式
{   
    Complex temp(*this);
    real++,imag++;
    return temp;
}