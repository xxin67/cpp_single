#include<iostream>
using namespace std;
class R
{
    private:
        static int total;
    public:
        R()
        {
            total++;
        }
        ~R()
        {
            total--;
            cout<<"Destruction.\n";
        }
        int gettotal()
        {
            return total;
        }
};

int R::total = 0;

int main()
{
    R a,b,c;
    cout<<a.gettotal()<<"\n"<<"objects in existence\n";
    R *p;
    p = new R;
    if(!p)
    {
        cout<<"allocation error\n";
        return 1;
    }
    cout<<a.gettotal()<<endl;
    cout<<"objects in existence after allocation.\n";
    delete p;
    cout<<a.gettotal()<<endl;
    cout<<"objects in existence after deletion.\n";
    return 0;
}