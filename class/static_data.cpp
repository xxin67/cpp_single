#include<iostream>
#include<string>
using namespace std;

class Student
{
    private:
        string name;
        string stu_no;
        float score;
        static int count;
        static float sum;
        static float ave;
    public:
        Student(string name1,string stu_no1,float score);
        ~Student();
        void show();
        void show_count_sum_ave();
};

int Student::count = 0;
float Student::sum = 0;
float Student::ave = 0;

int main()
{
    Student stu1("李明","08150201",90);
    stu1.show();
    stu1.show_count_sum_ave();
    cout<<"\n---------------\n";
    Student stu2("张大伟","08150202",80);
    stu2.show();
    stu2.show_count_sum_ave();
    return 0;
}

Student::Student(string name1,string stu_no1,float score1)
{
    name = name1;
    stu_no = stu_no1;
    score = score1;
    ++count;
    sum += score;
    ave = sum / count;
}

Student::~Student()
{
    --count;
    sum -=score;
}

void Student::show()
{
    cout<<"\n姓名:"<<name;
    cout<<"\n学号:"<<stu_no;
    cout<<"\n成绩:"<<score;
}

void Student::show_count_sum_ave()
{
    cout<<"\n学生人数:"<<count;
    cout<<"\n平均成绩:"<<ave<<endl;
}