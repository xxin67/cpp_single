#include<iostream>
#include<string>
using namespace std;

class Student
{
    protected:
        int number;
        string name;
        float score;
    public:
        Student(int number1,string name1,float score1)
        {
            number = number1;
            name = name1;
            score = score1;
        }
        void print()
        {
            cout<<"学号为:"<<number<<endl;
            cout<<"姓名为:"<<name<<endl;
            cout<<"成绩为:"<<score<<endl;
        }
};
class Ustudent:public Student
{
    private:
        string major;
        Student audi1;
        Student audi2;
    public:
        Ustudent(int number1,string name1,float score1,int number2,string name2,float score2,
        int number3,string name3,float score3,string major1):Student(number1,name1,score1),audi1(number2,
        name2,score2),audi2(number3,name3,score3)
        {
            major = major1;
        }
        void print1()
        {
            cout<<"正式生:\n";
            print();
            cout<<"专业:"<<major;
        }
        void print_audi1()
        {
            cout<<"\n--------------------\n";
            cout<<"旁听生:\n";
            audi1.print();
            cout<<"专业:"<<major<<endl;
        }
        void print_audi2()
        {
            audi2.print();
            cout<<"专业:"<<major<<endl;
        }
};

int main()
{
    Ustudent stu(2001,"张志",95,3001,"王大宾",66,3002,"李倩倩",50,"信息安全");
    stu.print1();
    stu.print_audi1();
    stu.print_audi2();
    return 0;
}