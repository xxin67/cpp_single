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

void sort(int a[],int size)
{
    int i,temp,work;
    for(int pass = 1;pass<size;pass++)
    {
        work = 1;
        for(i = 0;i<size-pass;i++)
        {
            if(a[i]>a[i+1])
            {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                work = 0;
            }
        }
        if(work) break;
    }
}