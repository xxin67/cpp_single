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
        Data_rec(string n,string s,int a)
        {
            name = n;
            sex = s;
            age = a;
        }
        void print()
        {
            cout<<"name:"<<name<<endl;
            cout<<"sex:"<<sex<<endl;
            cout<<"age:"<<age<<endl;
        }
};
class Student:virtual public Data_rec
{
    protected:
        string major;
        double score;
    public:
        Student(string n,string s,int a,string m,double sco):Data_rec(n,s,a)
        {
            major = m;
            score = sco;
        }
        void print()
        {
            Data_rec::print();
            cout<<"major:"<<major<<endl;
            cout<<"score:"<<score<<endl;
        }
};
class Employee:virtual public Data_rec
{
    protected:
        string dept;
        double salary;
    public:
        Employee(string n,string s,int a,string d,double sa):Data_rec(n,s,a)
        {
            dept = d;
            salary = sa;
        }
        void print()
        {
            Data_rec::print();
            cout<<"departmrnt:"<<dept<<endl;
            cout<<"salary:"<<salary<<endl;
        }
};
class Teacher:public Employee
{
    protected:
        string title;
    public:
        Teacher(string n,string s,int a,string d,double sa,string t):Data_rec(n,s,a),Employee(n,s,a,d,sa)
        {
            title = t;
        }
        void print()
        {
            Employee::print();
            cout<<"title:"<<title<<endl;
        }
};
class E_student:public Student,public Employee
{   
    public:
        E_student(string n,string s,int a,string m,double sco,string d,double sa):Data_rec(n,s,a),Student(n,s,a,m,sco),Employee(n,s,a,d,sa)
        {}
        void print()
        {
            Student::print();
            cout<<"department:"<<dept<<endl;
            cout<<"salary:"<<salary<<endl;
        }
};

int main()
{
    Student my_stu("李晓敏","女",22,"应用数学",90);
    cout<<"Student:"<<endl;
    my_stu.print();
    cout<<endl;

    Employee my_em("黄柏松","男",55,"科研处",5000);
    cout<<"Employee:"<<endl;
    my_em.print();
    cout<<endl;

    Teacher my_t("王世明","男",50,"管理学院",8000,"教授");
    cout<<"Teacher:"<<endl;
    my_t.print();
    cout<<endl;

    E_student my_es("张达明","男",34,"计算机",95,"教务处",3500);
    cout<<"E_student:"<<endl;
    my_es.print();
    return 0;
}