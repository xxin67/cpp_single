#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

class List
{
    public:
        void reverse();
};

int main()
{   
    List l;
    cout<<"list逆转函数实例:\n";
    l.reverse();
    return 0;
}

void List::reverse()
{
    list<int>number;
    list<int>::iterator numberIterator;
    number.insert(number.begin(),99);
    number.insert(number.begin(),98);
    number.insert(number.end(),97);
    cout<<"链表内容:"<<endl;
    for(numberIterator=number.begin();numberIterator!=number.end();numberIterator++)
    {
        cout<<*numberIterator<<endl;
    }
    number.reverse();
    cout<<"逆转后的链表:\n";
    for(numberIterator=number.begin();numberIterator!=number.end();numberIterator++)
    {
        cout<<*numberIterator<<endl;
    }
}
