#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<vector<int>>b(3,vector<int>(4,0));
    int m,n;
    for(m=0;m<b.size();m++)
    {
        for(n=0;n<b[m].size();n++)
        {
            b[m][n] = m + n;
        }
    }
    for(m=0;m<b.size();m++)
    {
        for(n=0;n<b[m].size();n++)
        {
            cout<<b[m][n]<<" ";
        }
        cout<<"\n";
    }
    system("pause");
}