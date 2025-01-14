#include<iostream>
using namespace std;
int main()
{
    char s1[80];
    cout<<"input string:";
    cin>>s1;
    cout<<"ouput string:\t"<<s1<<endl;
    char s2[] = "hello world!";
    int i;
    for(i=0;i<6;i++)
        cout<<s2[i];
    cout<<endl;  
    for(i=6;i<12;i++)
    {
        cout<<s2[i];
    }
    cout<<endl;
    system("pause");
}