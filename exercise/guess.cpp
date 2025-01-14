#include<iostream>
#include<random>
using namespace std;

int random_n(int,int);
int main()
{
    static int range_min = 1,range_max = 100;
    int n,j;
    n = random_n(range_min,range_max);
    cout<<"我猜是"<<n<<endl;
    cout<<"猜中了吗？(猜大了输1,猜小了输-1,猜中了输0):";
    cin>>j;
    if(j == 0)
    {
        cout<<"猜中了！"<<endl;
        system("pause");
    }
    if(j == 1)
    {   
        cout<<"猜的太大了！"<<endl;
        range_max = n - 1;
        main();
    }
    if(j == -1)
    {   
        cout<<"猜的太小了！"<<endl;
        range_min = n + 1;
        main();
    }
}

int random_n(int a,int b)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(a,b);
    return dis(gen);
}