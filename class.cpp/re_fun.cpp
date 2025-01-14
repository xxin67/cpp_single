#include<iostream>
#include<cmath>
using namespace std;

class Complex
{
    public:
        Complex(double r = 0.0,double i=0):real(r),imag(i)
        {}
        ~Complex()
        {
            cout<<"destructor called."<<endl;
        }
        double abscomplex()
        {
            double t;
            t = real * real + imag *imag;
            return sqrt(t);
        }
    
    private:
        double real;
        double imag;
};

int main()
{
    Complex com[3] = {
        Complex(1.1,2.2),
        Complex(3.3,4.4),
        Complex(5.5,6.6)
    };
    for(int i=0;i<3;i++)
    {
        cout<<"复数1的绝对值为:"<<com[i].abscomplex()<<endl;
    }
    return 0;
}