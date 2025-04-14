#include <iostream>
using namespace std;

/*
2-3树特点:
1.每个节点有一个或两个键值对
2.若有一个键值对,其只有两个子节点,左子节点关键码小于结点关键码,右结点大于等于
3.若有左右键值对,则左子节点关键码小于,中间子节点关键码大于等于左关键码小于有关键码,右子节点大于等于有关键码
4.所有叶结点在树的同一层
*/

// 节点类
template <typename Key, typename E>
class TTNode
{
public:
    E lval;         // 结点左值
    Key lkey;       // 结点左关键值
    E rval;         // 结点右值
    Key rkey;       // 结点右关键值
    TTNode *left;   // 结点左子节点
    TTNode *right;  // 结点右子节点
    TTNode *center; // 结点中间子节点
    TTNode()
    {
        center = left = right = NULL;
        lkey = rkey = 0;
    }
    TTNode(Key lk, E lv, E rv, Key rk, TTNode<KEy, E> *p1, TTNode<Key, E> *p2, TTNode<Key, E> *p3)
    {
        lkey = lk;
        rkey = rk;
        lval = lv;
        rval = rv;
        left = p1;
        center = p2;
        right = p3;
    }
    ~TTNode() {}
    bool isLeaf() { return left == NULL; }
    TTNode<Key, E> *add(TTNode<Key, E> *it);
};
