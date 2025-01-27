#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

//stl例子

void Printline(string &stringline)
{
    cout<<stringline<<endl;
}

int main()
{
    cout<<"vector容器:\n";
    vector<string>Food;     //容器定义
    vector<string>::iterator Fooditerator;      //迭代器定义
    Food.insert(Food.end(),"---食物清单---");
    Food.insert(Food.end(),"    牛奶");
    Food.insert(Food.end(),"    蓝莓");
    Food.insert(Food.end(),"    香蕉");
    Food.insert(Food.end(),"    牛油果");
    Food.insert(Food.end(),"    草莓");
    Food.insert(Food.end(),"--------------");
    for(Fooditerator=Food.begin();Fooditerator!=Food.end();Fooditerator++)  //迭代循环输出
    {
        cout<<*Fooditerator<<endl;
    }

    cout<<"\nlist容器:\n";
    list<string>Food1;
    Food1.push_back("---食物清单---");
    Food1.push_back("    牛奶");
    Food1.push_back("    蓝莓");
    Food1.push_back("    香蕉");
    Food1.push_back("    牛油果");
    Food1.push_back("    草莓");
    Food1.push_back("--------------");
    for_each(Food1.begin(),Food1.end(),Printline);      //STL通用算法,格式为for_each(begin,end,fun),从begin到end对每个元素进行fun函数操作.
    return 0;
}