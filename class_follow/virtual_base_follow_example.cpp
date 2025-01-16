#include<iostream>
#include<string>
using namespace std;

class Data_rec
{
    protected:
        string name;
        string sex;
        int age;
    public:
        Data_rec(string name1,string sex1,int age1):name(name1),sex(sex1),age(age1)
        {}
};
class Student:virtual public Data_rec
{
    protected:
        string major;
        float score;
    public:
        Student(string name1,string sex1,int age1,string major1,float score1):Data_rec(name1,sex1,age1)
        {
            major = major1;
            score = score1;
        }
};
class Employee:virtual public Data_rec
{
    protected:
        string dept;
        double salary;
    public:
        Employee(string name1,string sex1,int age1,string dept1,double salary1):Data_rec(name1,sex1,age1)
        {
            dept = dept1;
            salary = salary1;
        }
};
class E_student:public Student,public Employee
{   
    public:
        E_student(string name1,string sex1,int age1,string dept1,
        double salary1,string major1,float score1):Data_rec(name1,sex1,age1),Student(name1,sex1,age1,major1,score1),
        Employee(name1,sex1,age1,dept1,salary1)
        {}
        void print();
};

int main()
{
    E_student my_e_student("张大明","男",30,"教务处",3500,"计算机",95);
    my_e_student.print();
    return 0;
}

void E_student::print()
{
    cout<<"name:"<<name<<endl;
    cout<<"sex:"<<sex<<endl;
    cout<<"age:"<<age<<endl;
    cout<<"dept:"<<dept<<endl;
    cout<<"salary:"<<salary<<endl;
    cout<<"major:"<<major<<endl;
    cout<<"score:"<<score<<endl;
}