#include <iostream>
#include<cmath>
#include<bitset>
using namespace std;

int main()
{   
    long p,c,t;
    cout<<"密码:";
    cin>>p;
    for(int i=1;i<=6;i++)
    {
        if(p%10 ==0)
        {
            t = 3;
            p /= 10;
            c += t * pow(10,(6-i)); 
        }
        else if(p % 10 >= 7)
        {
            t = p % 10 - 7;
            p /= 10;
            c += t * pow(10,(6-i));
        }
        else
        {
            t = p % 10 + 3;
            p /= 10;
            c += t * pow(10,(6-i));
        }
        
    }
    cout<<"原码:"<<c<<endl;
    system("pause");
    return 0;
}

