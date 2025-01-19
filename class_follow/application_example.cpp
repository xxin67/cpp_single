#include<iostream>
#include<string>
using namespace std;

class Building
{
    protected:
        int floors;
        int rooms;
        double area;
    public:
        Building(int f=0,int r=0,double a=0)
        {
            floors = f;
            rooms = r;
            area = a;
        }
        void show_info();
};
class Home_Arch:public Building
{
    private:
        int bedrooms;
        int parlor;
        int toliets;
        int kitchens;
    public:
        Home_Arch(int f=0,int r=0,double a=0,int b=1,int p=1,int to=1,
        int k=1):Building(f,r,a)
        {
            bedrooms = b;
            parlor = p;
            toliets = to;
            kitchens = k;
        }
        void show();
};
class Office_Building:public Building
{
    private:
        int office;
        int assembly_room;
    public:
        Office_Building(int f=0,int r=0,double a=0,int o=0,int a_r=0):Building(f,r,a)
        {
            office = o;
            assembly_room = a_r;
        }
        void show();
};
class Hospital:public Building
{
    private:
        int sickrooms;
        int operating_rooms;
    public:
        Hospital(int f=0,int r=0,double a=0,int s=0,int o=0):Building(f,r,a)
        {
            sickrooms = s;
            operating_rooms = o;
        }
        void show();
};

int main()
{
    Home_Arch home(7,100,12000,3,1,1,1);
    Office_Building off(4,80,3500,40,12);
    Hospital hosp(10,300,25000,200,20);
    home.show();
    off.show();
    hosp.show();
    return 0;
}

void Building::show_info()
{
    cout<<"楼房层数:"<<floors<<"层"<<endl;
    cout<<"房间数:"<<rooms<<"间"<<endl;
    cout<<"楼房总面积:"<<area<<"平方米"<<endl;
    cout<<"其中:";
}
void Home_Arch::show()
{
    cout<<endl;
    cout<<"住宅楼:"<<endl;
    Building::show_info();
    cout<<"卧室数:"<<bedrooms<<"间"<<endl;
    cout<<"     客厅数:"<<parlor<<"间"<<endl;
    cout<<"     卫生间数:"<<toliets<<"间"<<endl;
    cout<<"     厨房数:"<<kitchens<<"间"<<endl;
}
void Office_Building::show()
{
    cout<<endl;
    cout<<"办公楼:"<<endl;
    Building::show_info();
    cout<<"办公室数:"<<office<<"间"<<endl;
    cout<<"     会议室数:"<<assembly_room<<"个"<<endl;
}
void Hospital::show()
{
    cout<<endl;
    cout<<"医 院:"<<endl;
    Building::show_info();
    cout<<"病房数:"<<sickrooms<<"间"<<endl;
    cout<<"     手术室数:"<<operating_rooms<<"间"<<endl;
}