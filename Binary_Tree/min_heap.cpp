#include<iostream>
using namespace std;

//最小堆实现
template<typename E,typename Comp>
class heap
{
private:
    E* Heap; 
    int maxsize; 
    int n;  

    void SiftDown(int pos)  
    {
        while(!IsLeaf(pos))
        {
            int j = LeftChild(pos);
            int rc = RightChild(pos);
            // 选择较小的子节点
            if(rc < n && Comp::prior(Heap[j], Heap[rc])) 
                j = rc; 
            // 当前节点小于子节点则无需调整
            if(Comp::prior(Heap[j], Heap[pos])) 
                return; 
            swap(Heap[pos], Heap[j]);
            pos = j; 
        }
    }
public:
    heap(E* h, int num, int max) : Heap(h), n(num), maxsize(max) 
    {
        BuildHeap();
    }
    int size() const { return n; }
    bool IsLeaf(int pos) const { return (pos >= n/2) && (pos < n); }
    int LeftChild(int pos) const { return 2*pos +1; }
    int RightChild(int pos) const { return 2*pos +2; }
    int parent(int pos) const { return (pos-1)/2; }

    void BuildHeap()
    {
        for(int i = n/2 -1; i >=0; i--)
            SiftDown(i);
    }

    void insert(const E& it)
    {
        int curr = n++;
        Heap[curr] = it;
        // 当前节点比父节点小时上浮
        while(curr !=0 && Comp::prior(Heap[parent(curr)], Heap[curr]))
        {
            swap(Heap[curr], Heap[parent(curr)]);
            curr = parent(curr);
        }
    }

    E RemoveFirst()
    {
        swap(Heap[0], Heap[--n]);
        if(n !=0) 
            SiftDown(0);
        return Heap[n];
    }

    E remove(int pos)
    {
        if(pos == (n-1)) 
            n--;
        else
        {
            swap(Heap[pos], Heap[--n]);
            // 当前节点比父节点小时上浮
            while(pos !=0 && Comp::prior(Heap[parent(pos)], Heap[pos]))
            {
                swap(Heap[pos], Heap[parent(pos)]);
                pos = parent(pos);
            }
            if(n !=0) 
                SiftDown(pos);
        }
        return Heap[n];
    }
};