#include<iostream>
#include<assert.h>
using namespace std;

// 基类的定义
template <typename E>
class List
{
private:
    List(const List &) {}
    // 保护拷贝构造函数并重载赋值符号,这样会导致对象无法拷贝,完整代码会补充代码使得对象得以复制
public:
    List() {}

    virtual ~List() {}
    virtual void clear() = 0;               // 用以清空线性表
    virtual void insert(const E &item) = 0; // 将item插入当前位置
    virtual void append(const E &item) = 0; // 将item添加到线性表末尾
    virtual E remove() = 0;                 // 清楚当前位置数据并返回.
    virtual void MoveToStart() = 0;         // 跳转到线性表起始
    virtual void MoveToEnd() = 0;           // 跳转到线性表末尾
    virtual void prev() = 0;                 // 指向前一位
    virtual void next() = 0;                // 指向后一位
    virtual int length() const = 0;         // 线性表的长度
    virtual int CurrPos() const = 0;        // 返回当前位置
    virtual void MoveToPos(int Pos) = 0;    // 将线性表当前位置设为Pos
    virtual const E& GetValue() const = 0;  // 返回当前位置的数据
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


//可利用空间表类定义
template<typename E>
class Freelist:public Link<E>
{
    private:
        static  Link<E>* freelist;  //静态Link数据,对所有对象有效
    public:
        void* operator new(size_t)  //重载new函数
        {
            if(freelist = NULL) return ::new Link[100];
            Link<E>* temp = freelist;   //将freelist的首结点返回并移去
            freelist = freelist->next;  //指向freelist下一结点
            return temp;
        }
        void operator delete(void* ptr) //重载delete函数
        {
            ((Link<E>*)ptr)->next = freelist;  //将释放的Link数据结点next指针指向freelist中的首位
            freelist = (Link<E>*)ptr;   //将freelist的首位变为释放的结点
        }
};

template<typename E>
Link<E>* Freelist<E>::freelist = NULL;  //初始化freelist

template<typename E>
class LList:public List<E>,public Freelist<E>
{
    private:
        Link<E>* head;  //链表表头结点
        Link<E>* tail;  //链表终止结点
        Link<E>* curr;  //链表当前位置前一个结点
        int cnt;    //链表结点个数
        
        void init() //初始化函数
        {
            curr = tail = head = new Link<E>;   //初始化表头结点
            cnt = 0;
        }
        void removal()  //清空函数
        {
            while(head!=NULL)
            {
                curr = head;
                head = head->next;
                delete curr;        //从表头开始逐步删除链表
            }
        }

    public:
        LList(int size = 100) {init();}
        ~LList() {removal();}
        void print() const  //逐次打印链表
        {
            Link<E> temp = head;
            for(int i=0;i<cnt;i++)
            {
                cout<<temp->next->element<<endl;
                temp = temp->next;
            }
        }
        void clear() {removal(); init();}   //重建链表
        void insert(const E& it)    //在当前位置插入结点
        {
            curr->next = new Link<E>(it,curr->next);
            if(tail==curr) tail = curr->next;
            cnt++;
        }
        void append(const E& it)    //在末尾插入结点
        {
            tail = tail->next = new Link<E>(it,NULL);
            cnt++;
        }
        E remove()  //去除结点并返回结点内容
        {
            assert(curr->next != NULL);
            E it = curr->next->element;
            Link<E>* ltemp = curr->next;
            if(tail == curr->next)
            {
                tail = curr;
            }
            curr->next = curr->next->next;  //将被删除结点的前一结点和后一结点链接
            delete ltemp;
            cnt--;
            return it;
        }
        void MoveToStart() {curr = head;}   //返回表头
        void MoveToEnd() {curr = tail;}     //返回表尾
        void prev() //位置前移
        {
            if(curr == head) return;
            Link<E>* temp = head;
            while(temp->next!=curr) 
            {
                temp = temp->next;
            }
            curr = temp;
        }
        void next() //位置后移
        {
            if(curr !=tail) curr = curr->next;
        }
        int length() const {return cnt;}    //返回链表长度
        int CurrPos() const   //返回curr结点位置
        {
            Link<E>* temp = head;
            int pos = 0;
            while(temp!=curr)
            {
                temp = temp->next;
                pos++;
            }
            return pos;
        }
        void MoveToPos(int Pos) //移动到Pos位置
        {
            assert((Pos>=0)&&(Pos<=cnt));
            curr = head;
            for(int i=0;i<Pos;i++)
            {
                curr = curr->next;
            }
        }
        const E& GetValue() const   //返回当前位置内容
        {
            assert(curr->next !=NULL);
            if(curr==head) return head->element;
            else return curr->next->element;
        }
};

int main()
{
    LList<int> llist1;
    List<int>* ptr;
    
}