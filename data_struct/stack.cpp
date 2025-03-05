#include<iostream>
#include<assert.h>
using namespace std;

//LIFO后进先出类型数据结构
//栈基类
template<typename E>
class Stack
{
    public:
        Stack() {}
        ~Stack() {}
        virtual void clear()=0;
        virtual void push(const E& it)=0;
        virtual E pop()=0;
        virtual const E& TopValue() const=0;
        virtual int Length()=0;
};

//链表结点类
template<typename E>
class Link
{
    public:
        E element;
        Link* next;

        Link(const E& elemval,Link* nextval = NULL)
        {
            element = elemval;
            next = nextval;
        }
        Link(Link* nextval = NULL)
        {
            next = nextval;
        }
};

//顺序栈
template<typename E>
class Array_Stack:public Stack<E>
{
    private:
        int maxsize;
        int top;
        E* listarray;
    public:
        Array_Stack(int size = 100)
        {
            maxsize = size;
            top = 0;
            listarray = new E[size];
        }
        ~Array_Stack() {delete [] listarray;}
        void clear() {top = 0;}
        void push(const E& it)
        {
            assert(top!=maxsize);
            listarray[top++] = it;
        }
        E pop()
        {
            assert(top!=0);
            return listarray[--top];
        }
        const E& TopValue() const
        {
            assert(top!=0);
            return listarray[top-1];
        }
        int Length() const
        {
            return top;
        }
};

//链式栈
template<typename E>
class Link_Stack:public Stack<E>,public Link<E>
{
    private:
        Link<E>* top;
        int size;
    public:
        Link_Stack(int sz=100)
        {
            top=NULL;
            size = 0;
        }
        ~Link_Stack() {clear();}
        void clear()
        {
            while(top!=NULL)
            {
                Link<E>* temp = top;
                top = top->next;
                delete temp;
            }
            size=0;
        }
        void push(const E& it)
        {
            top = new Link<E>(it,top);
            size++;
        }
        E pop()
        {
            assert(top!=NULL);
            E it = top->element;
            Link<E>* ltemp = top->next;
            delete top;
            top = ltemp;
            size--;
            return it;
        }
        const E& TopValue() const
        {
            assert(top!=0);
            return top->element;
        }
        int Length() const {return size;}
};