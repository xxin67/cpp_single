#include<iostream>
using namespace std;

//Huffman树
//无法运行,缺少最小堆类定义

//Huffman树结点抽象基类
template<typename E>
class HuffNode
{
    public:
        virtual ~HuffNode() {}
        virtual int weight() = 0; //返回权重
        virtual bool IsLeaf() =0;   //判断是否为叶结点
};

//叶结点子类
template<typename E>
class LeafNode:public HuffNode<E>
{
    private:
        E it;
        int wgt;
    public:
        LeafNode(const E& val,int freq)
        {
            it = val;
            wgt = freq;
        }
        int weight() {return wgt;}
        E val() {return it;}
        bool IsLeaf() {return true;}
};

//内部结点子类
template<typename E>
class IntlNode:public HuffNode<E>
{
    private:
        HuffNode<E>* lc;
        HuffNode<E>* rc;
        int wgt;
    public:
        IntlNode(HuffNode<E>* l,HuffNode<E>* r)
        {
            wgt = l->weight() +r->weight();
            lc = l;
            rc = r;
        }
        int weight() {return wgt;}
        bool IsLeaf() {return false;}
        HuffNode<E>* left() const {return lc;}
        void SetLeft(HuffNode<E>* b)    //设置左结点
        {
            lc = (HuffNode<E>*)b;
        }
        HuffNode<E>* righr() const {return rc;} //设置右结点
        void SetRight(HuffNode<E>* b)
        {
            rc = (HuffNode<E>*)b;
        }
};

//Huffman树
template<typename E>
class HuffTree
{
    private:
        HuffNode<E>* Root;
    public:
        HuffTree(E& val,int freq)   //设置叶结点
        {
            Root =new LeafNode<E>(val,freq);
        }
        HuffTree(HuffTree<E>* l,HuffTree<E>* r) //设置为内部结点
        {
            Root = new IntlNode<E>(l->root(),r->root());
        }
        ~HuffTree() {}
        HuffTree<E>* root() {return Root;}
        int weight() {return Root->weight();}
};

template<typename E>
HuffTree<E>* BuildHuff(HuffTree<E>** TreeArray,int count)   //Huffman树的构造函数
{
    min_heap<HuffTree<E>*,minTreeComp>* forest = 
    new min_heap<HuffTree<E>*,minTreeComp>(TreeArray,count,count); //使用最小堆
    HuffTree<char> *temp1,*temp2,*temp3 = NULL;
    while(forest->size()>1)
    {
        temp1 = forest->RemoveFirst();
        temp2 = forest->RemoveFirst();
        temp3 =new HuffTree<E>(temp1,temp2);    \
        //挤出最小堆的根结点,确保其最小,然后由temp3链接形成父子结构
        //然后插入最小堆堆顶
        forest->insert(temp3);
        delete temp1;
        delete temp2;
    }
    //循环进行直到最小堆只有根结点,表明所有元素都被连接成Huffman树
    return temp3;
}