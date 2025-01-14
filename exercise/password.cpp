#include<iostream>
using namespace std;
static int n = 0;
int password(const int &key);
int main()
{
    for(int i=1;i<=3;i++)
    {    
        if(password(123456))
        {    
            cout<<"welcome!"<<endl;
            break;
        }
        else
            if(n<3) 
            {    cout<<"wrong,you still have "<<3-n<<" chances to input password"<<endl;
            }
            else
                cout<<"wrong!"<<endl;
    }
    system("pause");
}

int password(const int &key)
{
    int k;
    cout<<"please input your password:";
    cin>>k;
    n++;
    if(k==key)
        return 1;
    else
        return 0;

}