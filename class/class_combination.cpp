#include<iostream>
#include<string>
using namespace std;

//类与类的组合

class Score
{
    private:
        float computer;
        float english;
        float maths;
    public:
        Score(float c = 0,float e=0,float m=0);
        void show();
};
class Student
{
    private:
        string name;
        string stu_no;
        Score score1;
    public:
        Student(string n,string stu,float s1,float s2,float s3);
        void show();
};

int main()
{
    Student stu1("李小明","990201",90,80,70);
    stu1.show();
    cout<<"\n-------------\n";
    Student stu2("张永生","990202",95,85,75);
    stu2.show();
    return 0;
}

Score::Score(float c,float e,float m)
{
    computer = c;
    english = e;
    maths = m;
}
void Score::show()
{
    cout<<"\n计算机成绩:"<<computer;
    cout<<"\n英语成绩:"<<english;
    cout<<"\n数学成绩:"<<maths<<endl;
}

Student::Student(string n,string stu,float s1,float s2,float s3):score1(s1,s2,s3)//类组合的构造函数赋值.
{
    name = n;
    stu_no = stu;
}
void Student::show()
{
    cout<<"\n姓名:"<<name;
    cout<<"\n学号:"<<stu_no;
    score1.show();
}