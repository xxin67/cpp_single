#include<iostream>
#include<cmath>
using namespace std;

typedef double funtype(double);
funtype circleperimeter;
funtype circlearea;
funtype ballarea;
funtype ballvolume;
double call(funtype *,double);

int main()
{
    double r;
    cout<<"enter radius:";
    cin>>r;
    cout<<"the perimeter is:"<<call(circleperimeter,r)<<endl;
    cout<<"the circlearea is:"<<call(circlearea,r)<<endl;
    cout<<"enter the radius of ball:";
    cin>>r;
    cout<<"the ballarea is:"<<call(ballarea,r)<<endl;
    cout<<"the ballvolume is:"<<call(ballvolume,r)<<endl;
    system("pause");
}

const double pi = 3.14159;
double circleperimeter(double r)
{
    return 2 * pi * r;
}
double circlearea(double r)
{
    return pi * r * r;
}
double ballarea(double r)
{
    return 4 * pi * r * r;
}
double ballvolume(double r)
{
    return 4.0 / 3 * pi * pow(r,3);
}
double call(funtype *qf,double r)
{
    return qf(r);
}