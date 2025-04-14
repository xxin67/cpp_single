#include<iostream>
using namespace std;

//最大堆实现
//堆为完全二叉树
template<typename E,typename Comp>
class heap
{
    private:
        E* Heap; //堆指针
        int maxsize; //堆的最大尺寸
        int n;  //堆中现存的元素个数

        void SiftDown(int pos)  //将元素向下比较
        {
            while(!IsLeaf(pos))
            {
                int j = LeftChild(pos);
                int rc = RightChild(pos);
                if(rc<n && Comp::prior(Heap[rc],Heap[j])) j = rc; //如果右结点应该排在左结点之前,交换左右结点
                if(Comp::prior(Heap[pos],Heap[j])) return; //如果根结点值大于左结点,不做任何事
                swap(Heap,pos,j); //否则交换根结点和左结点
                pos = j; //向前进继续重复操作以确保整个堆平衡
            }
        }
    public:
        heap(E* h,int num,int max)
        {
            Heap = h;
            n = num;
            maxsize = max;
            BuildHeap();
        }
        int size() const    //返回堆元素个数
        {
            return n;
        }
        bool IsLeaf(int pos) const  //判断当前位置是否为叶结点
        {
            return (pos >= n/2) && (pos<n); //n为元素个数,而根结点从0开始,故当pos>=n/2就能确保pos是完全二叉树的叶结点
        }
        int LeftChild(int pos) const    //返回pos的左结点
        {
            return 2*pos +1;
        }
        int RightChild(int pos) const //返回pos右结点
        {
            return 2*pos + 2;
        }
        int parent(int pos) const //返回pos父结点
        {
            return (pos-1) / 2;
        }
        void BuildHeap()    //
        {
            for(int i=n/2 - 1;i>=0;i--)
            {
                SiftDown(i);
            }
        }
        void insert(const E& it)    //插入元素
        {
            int curr = n++;
            Heap[curr] = it;
            while((curr!=0) && (Comp::prior(Heap[curr],Heap[parent(curr)]))) //用于调整次序
            {
                swap(Heap,curr,parent(curr));
                curr = parent(curr);
            }
        }
        E RemoveFirst() //
        {
            swap(Heap,0,--n);   //交换根结点和最后一个元素
            if(n!=0) SiftDown(0); //从根结点开始重新调整堆
            return Heap[n]; //返回被删除元素
        }
        E remove(int pos)
        {
            if(pos == (n-1)) n--;
            else
            {
                swap(Heap,pos,--n);
                while((pos!=0)&&(Comp::prior(Heap[pos],Heap[parent(pos)]))) //第一次对堆向上整理
                {
                    swap(Heap,pos,parent(pos));
                    pos=parent(pos);
                }
                if(n!=0) SiftDown(pos); //再进行第二次向下整理
            }
            return Heap[n]; //返回被删除的值
        }

};