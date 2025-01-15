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
        Student(int num,string n,float s)
        {
            number = num;
            name = n;
            score = s;
        }
        void print()
        {
            cout<<"number:"<<number<<endl;
            cout<<"name:"<<name<<endl;
            cout<<"score:"<<score<<endl;
        }
};
class Ustudent:public Student
{
    private:
        string major;
    public:
        Ustudent(int num,string n,float s,string m):Student(num,n,s)
        {
            major = m;
        }
        void print1()
        {  
            print();
            cout<<"major:"<<major<<endl;
        }
};

int main()
{
    Ustudent stu(22116,"张志",95,"信息安全");
    stu.print1();
    return 0;
}