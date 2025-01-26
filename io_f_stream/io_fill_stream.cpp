#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream fout("f2.dat",ios::out);   //输出模式打开文件,将程序的内容输出到文件.
    if(!fout)
    {
        cout<<"Can't open output file.\n";
        return 1;
    }
    fout<<"Hello!\n";
    fout.setf(ios::showbase);
    fout<<100<<' '<<hex<<100<<endl;
    fout.close();

    ifstream fin("f2.dat",ios::in);     //输入模式打开文件,将文件的内容输入到程序的变量中.
    if(!fin)
    {
        cout<<"Can't open input file.\n";
        return 1;
    }
    char str[80];
    int i;
    fin>>str>>i;cout<<str<<" "<<hex<<i<<endl;
    fin.close();
    return 0;
}