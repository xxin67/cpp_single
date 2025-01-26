#include<iostream>
using namespace std;

int main()
{
    //put函数,其用于输出一个字符.
    cout.put(65),cout.put(66),cout.put(67),cout.put('\n');

    //get函数,其能够接受空白字符.输入ctrl+z或回车时程序读入的值为EOF,终止输入.
    char ch;
    cout<<"Input:";
    cin.get(ch);
    cout.put(ch);
    
    //getline函数,格式为cin.getline(字符数组,字符个数,终止字符).
    char line[20];
    cout<<"输入一行字符:\n";
    cin.get(line,20,'t');   //输入19个字符或遇到t时停止
    cout<<line;

    //ignore函数,功能为跳过输入流中的n个字符,遇到终止字符时停止跳过.格式为cin.ignore(n,终止字符).
    //cin.ignore()默认为拿n=1,终止字符为EOF.
    return 0;
}