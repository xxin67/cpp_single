#include<iostream>
using namespace std;
//多重继承
class X
{
    private:
        int a;
    public:
        X(int sa)
        {
            a = sa;
        }
        int getX()
        {
            return a;
        }
        ~X()
        {
            cout<<"X_Destructor called."<<endl;
        }
};
class Y
{
    private:
        int b;
    public:
        Y(int sb)
        {
            b = sb;
        }
        int getY()
        {
            return b;
        }
        ~Y()
        {
            cout<<"Y_Destructor called."<<endl;
        }
};
class Z:public X,private Y
{
    private:
        int c;
    public:
        Z(int sa,int sb,int sc):X(sa),Y(sb)
        {
            c = sc;
        }
        int getZ()
        {
            return c;
        }
        int getY()
        {
            return Y::getY();//Z对Y是私有继承,因此Y的公有函数getY在Z中是私有的
                             //因此Z类的对象想要调用getY需要使用Z类中的成员函数.
        }
        ~Z()
        {
            cout<<"Z_Destructor called."<<endl;
        }
};

int main()
{
    Z obj(2,4,6);
    int ma = obj.getX();
    cout<<"a="<<ma<<endl;
    int mb = obj.getY();
    cout<<"b="<<mb<<endl;
    int mc = obj.getZ();
    cout<<"c="<<mc<<endl;
    return 0;
}