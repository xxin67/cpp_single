#include <iostream>
#include <cassert>
#include <assert.h>
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
    virtual void pre() = 0;                 // 指向前一位
    virtual void next() = 0;                // 指向后一位
    virtual int length() const = 0;         // 线性表的长度
    virtual int currPos() const = 0;        // 返回当前位置
    virtual void MoveToPos(int Pos) = 0;    // 将线性表当前位置设为Pos
    virtual const E &getValue() const = 0;  // 返回当前位置的数据
};

// 顺序线性表类定义
template <typename E>
class Array_List : public List<E>
{
public:
    int maxSize;  // 顺序表最大容量
    int curr;     // 当前位置
    E *listArray; // 顺序表容纳数据的数组
    int listSize; // 当前数据个数
public:
    Array_List(int size = 100)
    {
        maxSize = size;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }
    ~Array_List()
    {
        delete[] listArray;
    }
    void clear() // 清除顺序表
    {
        delete[] listArray;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }
    void insert(const E &it) // 在当前位置插入it
    {
        assert(listSize < maxSize);           // 错误检验
        for (int i = listSize; i > curr; i--) // 使用循环将curr的和之后的数据后移一位
        {
            listArray[i] = listArray[i - 1];
        }
        listArray[curr] = it; // 插入
        listSize++;
    }
    void append(const E &it) // 在顺序表末尾添加it
    {
        assert(listSize < maxSize);
        listArray[listSize++] = it;
    }
    E remove() // 删除并返回当前位置数据
    {
        assert(curr >= 0 && curr - 1 < listSize);
        E it = listArray[curr - 1];
        for (int i = curr - 1; i < listSize; i++)
        {
            listArray[i] = listArray[i + 1]; // 将curr后的数据都前移一位
        }
        listSize--; // 表总存储量减一
        return it;
    }
    void MoveToStart() { curr = 0; }      // 位置光标移到开头
    void MoveToEnd() { curr = listSize; } // 位置光标移到末尾
    void pre()
    {
        if (curr != 0)
            curr--;
    } // 光标前移一位
    void next()
    {
        if (curr != listSize)
            curr++;
    } // 光标后移一位
    int length() const { return listSize; } // 返回表的数据个数
    int currPos() const { return curr; }    // 返回当前光标位置
    void MoveToPos(int Pos)                 // 将光标移到Pos处
    {
        assert(Pos >= 0 && Pos <= listSize);
        curr = Pos;
    }
    const E &getValue() const // 返回当前光标的数据
    {
        assert(curr >= 0 && curr - 1 < listSize);
        return listArray[curr - 1];
    }
};

int main()
{
    Array_List<int> list1(50);
    List<int> *ptr;
    ptr = &list1;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++)
    {
        ptr->insert(a[i]);
    }
    cout << ptr->length() << endl;

    ptr->append(1);
    cout << ptr->length() << endl;
    ptr->MoveToEnd();
    cout << ptr->currPos() << endl;
    cout << ptr->remove() << endl;

    ptr->MoveToStart();
    cout << ptr->currPos() << endl;
    ptr->next();
    cout << ptr->currPos() << endl;

    ptr->MoveToPos(7);
    ptr->pre();
    cout << ptr->currPos() << endl;

    cout << ptr->getValue() << endl;
}