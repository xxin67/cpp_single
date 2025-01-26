#include<iostream>
#include<string>
using namespace std;

template<typename T>
struct quenode
{
    T nodedata;
    quenode *next;
};

template<typename T>
class quene
{
    protected:
        int quesize;
        quenode<T> *head;
        quenode<T> *tail;
        bool allocateeror;
        quene& copy(quene &q);
    public:
        quene();
        quene(quene &q)
        {
            head = NULL;
            tail = NULL;
            copy(q);
        }
        ~quene()
        {
            clearque();
        }
        bool getallocaateeror()
        {
            return allocateeror;
        }
        void push(T &);
        bool pop(T &);
        bool isempty()
        {
            return (quesize == 0)?true:false;
        }
        void clearque();
        quene &operator=(quene &q)
        {
            copy(q);
            return *this;
        }
};

template<typename T>
quene<T>::quene()
{
    quesize = 0;
    allocateeror = false;
    head = NULL;
    tail = NULL;
}
template<typename T>
quene<T>& quene<T>::copy(quene<T>& que)
{
    quenode<T> *p,*q,*r;
    if(head)
    {
        clearque();
    }
    quesize = que.quesize;
    allocateeror = false;
    head = NULL;tail = NULL;
    if(!que.head)
    {
        return *this;
    }
    head = new quenode<T>;
    if(!head)
    {
        allocateeror = true;
        return *this;
    }
    head->nodedata = que.head->nodedata;
    head->next = NULL;
    tail = head;
    r = NULL;
    p = head;
    q = que.head->next;
    while(q)
    {
        r = new quenode<T>;
        if(!r)
        {
            allocateeror = true;
            return *this;
        }
        r->nodedata = q->nodedata;
        r->next = NULL;
        p->next = r;
        tail = r;
        p = p->next;
        q = q->next;
    }
    return *this;
}
template<typename T>
void quene<T>::push(T &x)
{
    quenode<T> *p;
    p = new quenode<T>;
    if(!p)
    {
        allocateeror = true;
        return;
    }
    p->nodedata = x;
    if(tail)
    {
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
    else
    {
        p->next = NULL;
        tail = p;
        head = p;
    }
    quesize++;
}
template<typename T>
bool quene<T>::pop(T &x)
{
    quenode<T> *p;
    if(head)
    {
        x = head->nodedata;
        p = head;
        head = head->next;
        if(head == NULL)
        {
            tail = NULL;
        }
        delete p;
        quesize--;
        return true;
    }
    return false;
}
template<typename T>
void quene<T>::clearque()
{
    T p;
    allocateeror = false;
    while(pop(p));
    head = tail = NULL;
}

class staff
{
    public:
        string name;
        int age;
        float salary;
        string sex;
        void assign(string n,int a,float s,string sex1)
        {
            name = n;
            age = a;
            salary = s;
            sex = sex1;
        }
        void print()
        {
            cout.width(8);
            cout.setf(ios::left);
            cout<<name<<"  "<<age<<"  "<<salary<<"  "<<sex<<endl;
        }
};

void viewque(quene<staff> &que)
{
    int i=1;staff p;
    quene<staff>quecopy(que);
    system("cls");
    while(quecopy.pop(p))
    {
        cout<<i++<<":";
        p.print();
        cout<<endl;
    }
}

int main()
{
    quene<staff>que;
    staff p;
    p.assign("陈伟临",47,1500,"男");
    que.push(p);
    p.assign("王玲",34,2500,"男");
    que.push(p);
    p.assign("张达灵",25,1000,"男");
    que.push(p);    
    p.assign("方家惠",38,2500,"女");
    que.push(p);
    viewque(que);
    return 0;
}
