#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long c,p = 0,t;
    int j = 0;
    cout<<"原码:";
    cin>>c;
    do
    {
        if(c == 333333)
        {
            cout<<"it can't be this number.Please take a new one."<<endl;
            cout<<"code:";
            cin>>c;
        }
        else
            j = 1;
    }while (j ==0);
   
    for(int i=1;i<=6;i++)
    {
        t = (c % 10 +7) % 10;
        c /= 10;
        p += t * pow(10,(6-i));
    }
    cout<<"password:"<<p<<endl;

    system("PAUSE");
}