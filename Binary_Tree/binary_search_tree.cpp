#include <iostream>
#include <assert.h>
using namespace std;

// 二叉树抽象基类
template <typename E>
class BinNode
{
public:
    virtual ~BinNode() {} 
    virtual E &element() = 0;               // 返回Value纯虚函数
    virtual void SetElement(const E &) = 0; // 设置value纯虚函数
    virtual BinNode *left() const = 0;      // 返回左节点纯虚函数
    virtual void SetLeft(BinNode *) = 0;    // 设置左节点纯虚函数
    virtual BinNode *right() const = 0;     // 返回右节点纯虚函数
    virtual void SetRight(BinNode *) = 0;   // 设置右节点纯虚函数
    virtual bool IsLeaf() = 0;              // 判断叶节点纯虚函数
};

// 二叉树结点基类
template <typename Key, typename E>
class BSTNode : public BinNode<E> // 二叉检索树的结点基类,包含键值对的功能
{
private:
    Key k;
    E it;
    BSTNode *lc;
    BSTNode *rc;

public:
    BSTNode() { lc = rc = NULL; }
    BSTNode(Key K, E e, BSTNode *l = NULL, BSTNode *r = NULL)
    {
        k = K;
        it = e;
        lc = l;
        rc = r;
    }
    ~BSTNode() {}
    E &element() { return it; }
    void SetElement(const E &e) { it = e; }
    Key &key() { return k; } // 返回关键码
    void SetKey(const Key &K) { k = K; }
    inline BSTNode *left() const { return lc; }
    void SetLeft(BinNode<E> *b) { lc = (BSTNode *)b; }
    inline BSTNode *right() const { return rc; }
    void SetRight(BinNode<E> *b) { rc = (BSTNode *)b; }
    bool IsLeaf() { return lc == NULL && rc == NULL; }
};

// 字典基类
template <typename Key, typename E>
class Dictionary
{
public:
    Dictionary() {}
    virtual ~Dictionary() {}
    virtual void clear() = 0;                          // 清空字典纯虚函数
    virtual void insert(const Key &k, const E &e) = 0; // 插入数据纯虚函数
    virtual E remove(const Key &k) = 0;                // 清除k关键码对应的数据
    virtual E RemoveAny() = 0;                         // 随机访问数据并在之后清除
    virtual E find(const Key &k) const = 0;            // 寻找k关键码对应的数据内容
    virtual int size() = 0;                            // 返回字典大小
};

// 二叉检索树
template <typename Key, typename E>
class BST : public Dictionary<Key, E>
{
private:
    BSTNode<Key, E> *root;
    int nodecount;

    void clearhelp(BSTNode<Key, E> *);
    BSTNode<Key, E> *inserthelp(BSTNode<Key, E> *, const Key &, const E &); // 在适合的位置插入结点
    BSTNode<Key, E> *deletemin(BSTNode<Key, E> *);                          // 删除当前子树最小结点,rt用于指定子树
    BSTNode<Key, E> *getmin(BSTNode<Key, E> *);                             // 获取当前子树的最小结点
    BSTNode<Key, E> *removehelp(BSTNode<Key, E> *, const Key &);            // 删除特定k的结点
    E findhelp(BSTNode<Key, E> *, const Key &) const;                       // 搜索关键码为k的结点
    void printhelp(BSTNode<Key, E> *, int) const;

public:
    BST()
    {
        root = NULL;
        nodecount = 0;
    }
    ~BST() { clearhelp(root); }
    void clear() // 初始化树
    {
        clearhelp(root);
        root = NULL;
        nodecount = 0;
    }
    void insert(const Key &k, const E &e) // 将一个数据插入树中,k为关键码,e为内容
    {
        root = inserthelp(root, k, e);
        nodecount++;
    }
    E remove(const Key &k) // 除去一个数据并返回,如果为空返回NULL
    {
        E temp = findhelp(root, k);
        if (temp != NULL)
        {
            root = removehelp(root, k);
            nodecount--;
        }
        return temp;
    }
    E RemoveAny() // 除去并返回根结点
    {
        if (root != NULL)
        {
            E temp = root->element();
            root = removehelp(root, root->key());
            nodecount--;
            return temp;
        }
        else
            return NULL;
    }
    // 返回关键码k对应的数据,找到返回true和随机一个符合的数据,否则返回false
    E find(const Key &k) const { return findhelp(root, k); }
    int size() { return nodecount; } // 返回结点数
    void print() const               // 返回BST的内容
    {
        if (root == NULL)
            cout << "The BST is empty.\n";
        else
            printhelp(root, 0);
    }
};

// 搜索关键码为k的结点
template <typename Key, typename E>
E BST<Key, E>::findhelp(BSTNode<Key, E> *root, const Key &k) const
{
    if (root == NULL)
        return NULL;
    if (k < root->key())
        return findhelp(root->left(), k); // 若k小于root所指的关键码则root指向左结点并迭代
    else if (k > root->key())
        return findhelp(root->right(), k); // 若k大于root所指的关键码则root指向右结点并迭代
    else
        return root->element(); // 相等则返回
}

// 在适合的位置插入结点
template <typename Key, typename E>
BSTNode<Key, E> *BST<Key, E>::inserthelp(BSTNode<Key, E> *root, const Key &k, const E &it)
{
    if (root == NULL)
        return new BSTNode<Key, E>(k, it, NULL, NULL); // 如果为结点为空直接新建结点并记录k,it
    if (k < root->key())
        root->SetLeft(inserthelp(root->left(), k, it)); // 若k小于此分支结点关键码,在其左结点插入,inserthelp的迭代保证其左结点为空.
    else
        root->SetRight(inserthelp(root->right(), k, it)); // 若k大于或等于此分支结点关键码,在其右结点插入,inserthelp的迭代保证其右结点为空.
    return root;                                          // 返回插入的结点
}

// 删除当前子树最小结点,rt用于指定子树
template <typename Key, typename E>
BSTNode<Key, E> *BST<Key, E>::deletemin(BSTNode<Key, E> *rt)
{
    if (rt->left() == NULL)
        return rt->right(); // 迭代终止条件
    else                    // 若还未到最小结点,调用函数进行迭代
    {
        rt->SetLeft(deletemin(rt->left()));
        // 找到最小结点后如果其有右分支,将右结点地址设为最小结点父结点的左结点,
        // 而其他调用了函数的结点的左指针不变,但在此逻辑下会进行无意义的重新赋值
        return rt;
    }
}

// 获取当前子树的最小结点
template <typename Key, typename E>
BSTNode<Key, E> *BST<Key, E>::getmin(BSTNode<Key, E> *rt)
{
    if (rt->left() == NULL)
        return rt;
    else
        return getmin(rt->left()); // 进行迭代搜索
}

// 删除特定k的结点
template <typename Key, typename E>
BSTNode<Key, E> *BST<Key, E>::removehelp(BSTNode<Key, E> *rt, const Key &k)
{
    if (rt == NULL)
        return NULL; // 树中不存在关键码为k的结点
    else if (k < rt->key())
        rt->SetLeft(removehelp(rt->left(), k));
    else if (k > rt->key())
        rt->SetRight(removehelp(rt->right(), k)); // 搜索过程
    else                                          // 找到了
    {
        BSTNode<Key, E> *temp = rt;
        if (rt->left() == NULL) // 若待删除结点左结点为空,则可直接将其父结点和右结点链接即可保证二叉树平衡
        {
            rt = rt->right();
            delete temp;
        }
        else if (rt->right() == NULL) // 若待删除结点右结点为空,则可直接将其父结点和左结点链接即可保证二叉树平衡
        {
            rt = rt->left();
            delete temp;
        }
        else // 若待删除结点两子结点都不为空
        {
            BSTNode<Key, E> *temp = getmin(rt->right()); // 寻找其右子树中最小值
            rt->SetElement(temp->element());
            rt->SetKey(temp->key());              // 用此最小值覆盖待删除结点
            rt->SetRight(deletemin(rt->right())); // 再把此最小值删除
            delete temp;
        }
    }
    return rt;
}

// clearhelp函数定义,算法方法为后序遍历
template <typename Key, typename E>
void BST<Key, E>::clearhelp(BSTNode<Key, E> *root)
{
    if (root == NULL)
        return;
    clearhelp(root->left());
    clearhelp(root->right());
    delete root;
}
// 后序遍历的过程为:从最左下的叶节点开始遍历,访问结束后迭代回其父结点执行体,
// 并执行右子树遍历,当把此父结点的左右子树都遍历完后,遍历此结点,重复此操作

// printhelp函数定义,算法方法为中序遍历
template <typename Key, typename E>
void BST<Key, E>::printhelp(BSTNode<Key, E> *root, int level) const
{
    if (root == NULL)
        return;
    printhelp(root->left(), level + 1);
    for (int i = 0; i < level; i++)
    {
        cout << "  ";
    }
    cout << root->key() << "\n"; // 此语句是将后序遍历与中序遍历区别的关键,此语句将会在遍历完root左子树后会先遍历root再遍历root的右子树
    printhelp(root->right(), level + 1);
}
// 中序遍历与后序遍历的区别是中序遍历在遍历完root左子树后遍历右子树前会先遍历root