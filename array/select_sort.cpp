#include<iostream>
#include<ctime>
using namespace std;
void sort(int [],int);

int main()
{
    int i,a[100];
    srand(int(time(0)));
    for(i=0;i<100;i++)
    {
        a[i] = rand() % 1000;
    }
    for(i=0;i<100;i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
    sort(a,100);
    cout<<"order1:"<<endl;
    for(i=0;i<100;i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
    system("pause");
}

void sort(int x[],int n)
{
    int min,t;
    for(int i = 0;i<n;i++)
    {
        t = i;
        for(int j = i+1;j<n;j++)
        {
            if(x[t]>x[j])
                t = j;
        }
        if(t!=i)
        {
            min = x[i];
            x[i] = x[t];
            x[t] = min;
        }
    }
    return;
}