#include <iostream>
#include <assert.h>
using namespace std;

// 队列基类
template <typename E>
class Quene
{
public:
    Quene() {}
    virtual ~Quene() {}
    virtual void clear() = 0;
    virtual void enquene(const E &it) = 0;
    virtual E dequene() = 0;
    virtual const E &FrontValue() const = 0;
    virtual int Length() const = 0;
};

// 链表结点类
template <typename E>
class Link
{
public:
    E element;
    Link *next;

    Link(const E &elemval, Link *nextval = NULL)
    {
        element = elemval;
        next = nextval;
    }
    Link(Link *nextval = NULL)
    {
        next = nextval;
    }
};

// 顺序队列
template <typename E>
class Array_Quene : public Quene<E>
{
private:
    int maxSize;
    int front;
    int rear;
    E *listarray;

public:
    Array_Quene(int size = 100)
    {
        maxSize = size + 1;
        rear = 0;
        front = 1;
        listarray = new E[maxSize];
    }
    ~Array_Quene() { delete[] listarray; }
    void clear()
    {
        rear = 0;
        front = 1;
    }
    void enquene(const E &it)
    {
        assert((rear + 2) % maxSize != front);
        rear = (rear + 1) % maxSize;
        listarray[rear] = it;
    }
    E dequene()
    {
        assert(Length() != 0);
        E it = listarray[front];
        front = (front + 1) % maxSize;
        return it;
    }
    const E &FrontValue() const
    {
        assert(Length() != 0);
        return listarray[front];
    }
    int Length() const
    {
        return ((rear + maxSize) - front + 1) % maxSize;
    }
};

template <typename E>
class Link_Quene : public Quene<E>
{
private:
    Link<E> *front;
    Link<E> *rear;
    int size;

public:
    Link_Quene(int sz = 100)
    {
        front = rear = new Link<E>(); // 使用空头结点
        size = sz;
    }
    ~Link_Quene()
    {
        clear();
        delete front;
    }
    void clear()
    {
        while (front->next != NULL)
        {
            rear = front;
            front = front->next;
            delete rear;
        }
        rear = front;
        size = 0;
    }
    void enquene(const E &it)
    {
        rear->next = new Link<E>(it, NULL);
        rear = rear->next;
        size++;
    }
    E dequene()
    {
        assert(size != 0);
        E it = front->next->element;
        Link<E> *ltemp = front->next;
        front->next = ltemp->next;
        if (rear == ltemp)
            rear = front;
        delete ltemp;
        size--;
        return it;
    }
    const E &FrontValue() const
    {
        assert(size != 0);
        return front->next->element;
    }
    int Length() const
    {
        return size;
    }
};