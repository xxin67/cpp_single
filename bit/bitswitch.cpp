#include<iostream>
using namespace std;

int main()
{
    double a = 123.456,b = 456.789;
    int *ap,*bp;
    ap = (int*)(&a);
    bp = (int*)(&b);
    cout<<"a="<<a<<"\tb="<<b<<endl;
    *ap = *ap ^ *bp;
    *bp = *ap ^ *bp;
    *ap = *ap ^ *bp;
    cout<<"a="<<a<<"\tb="<<b<<endl;
    ap++,bp++;
    *ap = *ap ^ *bp;
    *bp = *ap ^ *bp;
    *ap = *ap ^ *bp;
    cout<<"a="<<a<<"\tb="<<b<<endl;
    system("pause");
}