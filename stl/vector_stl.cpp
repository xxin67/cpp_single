#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//vector容器实例
class Vect
{   
    public:
        void push_pop();
        void at_erase();
        void constructor();
};

int main()
{   
    Vect v;
    cout<<"vector函数push与pop实例:\n";
    v.push_pop();
    cout<<"\nvecto函数at与erase实例:\n";
    v.at_erase();
    cout<<"\nvector的构造函数:\n";
    v.constructor();
    return 0;
}   

void Vect::push_pop()
{
    vector<char>alphavector;
    for(int i=0;i<10;i++)
    {
        alphavector.push_back(i+'1');   //在容器alphavector末尾位置插入.
    }
    int size = alphavector.size();
    vector<char>::iterator theiterator;
    for(int j=0;j<size;j++)
    {
        alphavector.pop_back();         //删去容器末尾的元素
        for(theiterator=alphavector.begin();theiterator!=alphavector.end();theiterator++)
        {
            cout<<*theiterator;
        }
        cout<<endl;
    }
}

void Vect::at_erase()
{
    unsigned int i;
    vector<int>number;
    number.insert(number.begin(),99);   
    number.insert(number.begin(),98);
    number.insert(number.end(),97);         //指定位置插入元素
    cout<<"删除前:\n";
    for(i=0;i<number.size();i++)
    {
        cout<<number.at(i)<<endl;           //输出指定位置的元素
    }
    number.erase(number.begin());
    number.erase(number.end());
    cout<<"删除后:\n";
    for(i=0;i<number.size();i++)
    {
        cout<<number.at(i)<<endl;
    }
}

void Vect::constructor()
{
    unsigned int i;
    vector<int>number(5,99);        //vector(num,val),num为元素个数,val为元素的值
    for(i=0;i<number.size();i++)
    {
        cout<<number.at(i)<<"  ";
    }
    cout<<endl;
    vector<int>number1(number);     //vector(vector type)拷贝构造函数
    for(i=0;i<number1.size();i++)
    {
        cout<<number1.at(i)<<"  ";
    }
    cout<<endl;
    vector<int>number2(number.begin(),number.end());    //vector(start,end)给容器赋予从某个量起始到终止的所有值.
    for(i=0;i<number2.size();i++)
    {
        cout<<number2.at(i)<<"  ";
    }
    cout<<endl;
}