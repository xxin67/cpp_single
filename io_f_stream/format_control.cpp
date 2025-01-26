#include<iostream>
#include<iomanip>   //操作符头文件
using namespace std;

void fun1();
void fun2();
ostream &output(ostream &stream);   //自定义输出操作符
istream &input(istream &stream);    //自定义输入操作符

int main()
{
    cout<<"流函数格式控制:\n";
    fun1();
    cout<<"操作符格式控制:\n";
    fun2();
    cout<<"自定义操作符格式控制:\n";
    cout<<123<<endl;
    cout<<output<<123<<endl;
    cout<<endl;
    int i;
    cin>>input>>i;
    cout<<"hex:"<<hex<<i<<"---------dec:"<<dec<<i<<endl;
    return 0;
}

void fun1()
{
    cout<<"-------1-------\n";
    cout.width(10);     //设置域宽10
    cout<<123<<endl;    //默认右对齐

    cout<<"-------2-------\n";
    cout<<123<<endl;    //域宽设置只作用一次.

    cout<<"-------3-------\n";
    cout.fill('&');     //域宽空白的地方填充字符&,默认域宽一般为输出字符的总域宽.fill函数可以作用多次直到取消设置.
    cout.width(10);
    cout<<123<<endl;

    cout<<"-------4--------\n";
    cout.setf(ios::left);
    cout.width(10);
    cout<<123<<endl;

    cout<<"-------5--------\n";
    cout.precision(4);  //精度控制,若没有设置定点格式或指数格式,函数参数表示有效数字.会一直作用知道重新设置.
    cout<<123.45678<<endl;

    cout<<"-------6--------\n";
    cout.setf(ios::fixed);//设置定点格式.
    cout<<123.45678<<endl; 
    
    cout<<"-------7--------\n";
    cout.width(15);
    cout.unsetf(ios::fixed);
    cout.setf(ios::scientific);
    cout<<123.45678<<endl;  //科学计数法表示

    cout<<"-------8--------\n";
    int a=21;
    cout.setf(ios::showbase);    //显示进制符号
    cout.unsetf(ios::dec);      //取消十进制输出
    cout.setf(ios::hex);        //以十六进制输出.
    cout<<a<<endl;
}   

void fun2()
{
    cout.fill(' ');
    cout.setf(ios::dec);
    cout<<resetiosflags(ios::left);
    cout<<setw(10)<<123<<567<<endl; //setw与width作用一致,并且也只能作用一次.
    cout<<123<<setiosflags(ios::scientific)<<setw(20)<<123.456789<<endl;
    cout<<123<<setw(10)<<hex<<123<<endl;
    cout<<123<<setw(10)<<oct<<123<<endl;
    cout<<123<<setw(10)<<dec<<123<<endl;    //hex的作用会持续到输出进制重新定义的时候. 
    cout<<resetiosflags(ios::scientific)<<setprecision(4)<<123.456789<<endl;
    cout<<setiosflags(ios::fixed)<<123.456789<<endl;
    cout<<setiosflags(ios::left)<<setfill('#')<<setw(8)<<123<<endl;
    cout<<resetiosflags(ios::left)<<setfill('$')<<setw(8)<<123<<endl;
  
}

ostream &output(ostream &stream)
{
    stream.setf(ios::left);
    stream<<setw(10)<<hex<<setfill('&');
    return stream;
}

istream &input(istream &in)
{
    in>>hex;    
    cout<<"Enter number using hex format:";
    return in;
}