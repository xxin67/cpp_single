#include<iostream>
using namespace std;

class Small_cat
{
    private:
        double weight;
        static double total_weight;
        static double total_number;
    public:
        Small_cat(double w);
        static void display(Small_cat &w); //静态成员函数一般不能直接调用非静态数据参数
        static void total_disp();          //只有借助指针参数和引用参数才能实现函数调用.
};
double Small_cat::total_weight = 0;
double Small_cat::total_number = 0;

int main()
{
    Small_cat w1(0.5),w2(0.6),w3(0.4);
    Small_cat::display(w1);
    Small_cat::display(w2);
    Small_cat::display(w3);
    Small_cat::total_disp();
    return 0;
}

Small_cat::Small_cat(double weigth1)
{
    weight = weigth1;
    total_weight += weight;
    total_number++;
}

void Small_cat::display(Small_cat &w)
{
    cout<<"这只小猫的质量为:"<<w.weight<<"kg\n";
}

void Small_cat::total_disp()
{
    cout<<total_number<<"只小猫的总质量为:";
    cout<<total_weight<<"kg"<<endl;
}