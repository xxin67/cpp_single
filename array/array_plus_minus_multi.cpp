#include<iostream>
#include<iomanip>
using namespace std;

int multi(int *,int ,int ,int *,int ,int ,int *,int ,int );
void plus_1(int *,int ,int ,int *,int ,int ,int *);
void minus_1(int *,int ,int ,int *,int ,int ,int *);

int main()
{
    int i,j,*p;
    char calu;
    judge1:cout<<"请输入运算类型：";
    cin>>calu;
    if(calu == '+'  || calu == '-')
    {   
        int row,col;
        judge2:cout<<"请输入a矩阵与b矩阵的行数:";
        cin>>row;
        cout<<"请输入a矩阵与b矩阵的列数:";
        cin>>col;
        if(row != col)
        {
            cout<<"矩阵"<<"相"<<calu<<"维度必须相等,请重新输入！"<<endl;
            goto judge2;
        }
        int arow = row,acol = col,brow = row,bcol = col,crow = row ,ccol = col;
        int a[arow][acol],b[arow][acol],c[arow][acol];
        cout<<"请输入a矩阵的元素:\n";
        for (i=0;i<arow;i++)
        {
            for(j=0;j<acol;j++)
            {
                cin>>a[i][j];
            }
        }
        cout<<"\n请输入b矩阵的元素:\n";
        for (i=0;i<brow;i++)
        {
            for(j=0;j<bcol;j++)
            {
                cin>>b[i][j];
            }
        }
        if(calu == '+')
        {
            plus_1(a[0],arow,acol,b[0],brow,bcol,c[0]);
            cout<<"结果为:"<<endl;
            for(i=0;i<crow;i++)
            {
                for(j=0;j<ccol;j++)
                {
                    cout<<c[i][j]<<"  ";
                }
                cout<<endl;
            }           
        }
        else
        {
            minus_1(a[0],arow,acol,b[0],brow,bcol,c[0]);
            cout<<"结果为:"<<endl;
            for(i=0;i<crow;i++)
            {
                for(j=0;j<ccol;j++)
                {
                    cout<<c[i][j]<<"  ";
                }
                cout<<endl;
            }
        }
        
    }
    else if(calu == '*')
    {
        int m,p,n,*t;
        cout<<"请输入a矩阵(c矩阵)的行数:";
        cin>>m;
        cout<<"请输入a矩阵的列数(b矩阵的行数):";
        cin>>p;
        cout<<"请输入b矩阵(c矩阵)的列数:";
        cin>>n;
        int arow = m,acol = p,brow = p,bcol = n,crow = m ,ccol = n;        
        int a[arow][acol],b[brow][bcol],c[crow][ccol];
        cout<<"请输入a矩阵的元素:\n";
        for (i=0;i<arow;i++)
        {
            for(j=0;j<acol;j++)
            {
                cin>>a[i][j];
            }
        }
        cout<<"\n请输入b矩阵的元素:\n";
        for (i=0;i<brow;i++)
        {
            for(j=0;j<bcol;j++)
            {
                cin>>b[i][j];
            }
        }
        if(multi(a[0],arow,acol,b[0],brow,bcol,c[0],crow,ccol))
        {
            cout<<"结果为:"<<endl;
            for(i=0;i<crow;i++)
            {
                for(j=0;j<ccol;j++)
                {
                    cout<<c[i][j]<<"  ";
                }
                cout<<endl;
            }
        }
        else
            cout<<"a矩阵的行数与b矩阵的列数不相等,不合法操作无法相乘。";
    }
    else
    {
        cout<<"请输入+,-,*三者之一！"<<endl;
        goto judge1;
    }
    system("pause");
}

void plus_1(int *a,int ar,int ac,int *b,int br,int bc,int *c)
{   
    int *p,*n,*t;
    for(p = a,n = b,t = c;p<a + ar * ac,n<b+ br*bc;p++,n++,t++)
    {
        *t = *p + *n;
    }
}

void minus_1(int *a,int ar,int ac,int *b,int br,int bc,int *c)
{   
    int *p,*n,*t;
    for(p = a,n = b,t = c;p<a + ar * ac,n<b+ br*bc;p++,n++,t++)
    {
        *t = *p - *n;
    }
}

int multi(int *a,int ar,int ac,
           int *b,int br,int bc,
           int *c,int cr,int cc)
{   int *p,*n,*t;
    int sum;
    if(ac != br) return 0;
    for(int i = 0;i<ar;i++)
    {
        for(int j = 0;j<bc;j++)
        {  
            sum = 0;
            for(p = a + i,n = b + j;p<a + ar * ac,n<b+ br*bc;p++,n = n + bc)
            {
                sum += *p * *n;
            }
            t = c + ((i == 0)? 0:i * bc) + j;
            *t = sum;
        }
    }
    return 1;
}