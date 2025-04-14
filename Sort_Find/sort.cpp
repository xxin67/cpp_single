#include <iostream>
using namespace std;

// 最小堆实现
template <typename E, typename Comp>
class heap
{
private:
    E *Heap;
    int maxsize;
    int n;

    void SiftDown(int pos)
    {
        while (!IsLeaf(pos))
        {
            int j = LeftChild(pos);
            int rc = RightChild(pos);
            // 选择较小的子节点
            if (rc < n && Comp::prior(Heap[j], Heap[rc]))
                j = rc;
            // 当前节点小于子节点则无需调整
            if (Comp::prior(Heap[j], Heap[pos]))
                return;
            swap(Heap[pos], Heap[j]);
            pos = j;
        }
    }

public:
    heap(E *h, int num, int max) : Heap(h), n(num), maxsize(max)
    {
        BuildHeap();
    }
    int size() const { return n; }
    bool IsLeaf(int pos) const { return (pos >= n / 2) && (pos < n); }
    int LeftChild(int pos) const { return 2 * pos + 1; }
    int RightChild(int pos) const { return 2 * pos + 2; }
    int parent(int pos) const { return (pos - 1) / 2; }

    void BuildHeap()
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            SiftDown(i);
    }

    void insert(const E &it)
    {
        int curr = n++;
        Heap[curr] = it;
        // 当前节点比父节点小时上浮
        while (curr != 0 && Comp::prior(Heap[parent(curr)], Heap[curr]))
        {
            swap(Heap[curr], Heap[parent(curr)]);
            curr = parent(curr);
        }
    }

    E RemoveFirst()
    {
        swap(Heap[0], Heap[--n]);
        if (n != 0)
            SiftDown(0);
        return Heap[n];
    }

    E remove(int pos)
    {
        if (pos == (n - 1))
            n--;
        else
        {
            swap(Heap[pos], Heap[--n]);
            // 当前节点比父节点小时上浮
            while (pos != 0 && Comp::prior(Heap[parent(pos)], Heap[pos]))
            {
                swap(Heap[pos], Heap[parent(pos)]);
                pos = parent(pos);
            }
            if (n != 0)
                SiftDown(pos);
        }
        return Heap[n];
    }
};

// 简单排序算法,平均时间复杂度为n^2
template <typename E, typename Comp>
class easy_sort
{
private:
    void insert_sort2(E A[], int n, int incr)
    {
        for (int i = incr; i < n; i += incr)
        {
            for (int j = 1; (j >= incr) && (Comp::prior(A[j], A[j - incr])); j -= incr)
            {
                swap(A, j, j - incr);
            }
        }
    }

public:
    // 插入排序
    void insert_sort(E A[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = i; (j > 0) && (Comp::prior(A[j], A[j - 1])); j--)
            {
                swap(A, j, j - 1);
            }
        }
    }
    // 第i位与前一位比较,若需要换位则进行交换,交换后再继续与前一位比较直到不需要交换时.

    // 冒泡排序
    void bubble_sort(E A[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (Comp::prior(A[j], A[j - 1]))
                {
                    swap(A, j, j - 1);
                }
            }
        }
    }
    // 每次都从最顶端开始,最顶端的元素与向上一位比较,需要交换时交换位置,直到遇到不需要交换的元素,
    // 当发现向上一位不需要交换时,此元素位置不动,变由向上一位继续与其向上一位比较,重复此操作直到到达第i位
    // 此算法思想是从最顶端开始找出第i次循环的最小值并移至第i位,就像气泡似的

    // 选择排序
    void selection_sort(E A[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int lowindex = i;
            for (int j = n - 1; j > i; j--)
            {
                if (Comp::prior(A[j], A[lowindex]))
                {
                    lowindex = i;
                }
            }
            swap(A, i, lowindex);
        }
    }
    /*选择排序本质上也是冒泡排序的一种,每次循环选出未排序中的最值,
    然后将其移至第i位.
    */

    // shell排序(缩小增量序列排序)
    void shell_sort(E A[], int n)
    {
        for (int i = n / 2; i > 2; i /= 2)
        {
            for (int j = 0; j < i; j++)
            {
                insert_sort2(&A[j], n - j, i);
            }
        }
        insert_sort2(A, n, 1);
    }
    /*将待排序序列分为多个子序列,并比较交换相距为增量的元素,然后逐渐缩小增量,通过此种方法
    可以让序列变为较为有序的序列,再通过插入排序完成最后的排序得到排序结果.*/
};

// 更快的排序算法

template <typename E, typename Comp>
class fastersort : protected easy_sort<E, Comp>
{
private:
    inline int findpivot(E A[], int i, int j)
    {
        return (i + j) / 2;
    }
    inline int partition(E A[], int l, int r, E &pivot)
    {
        do
        {
            while (Comp::prior(A[++l], pivot))
                ; // 持续增加l直到l的元素大于pivot
            while ((l < r) && Comp::prior(pivot, A[--r]))
                ;          // 持续减少r直到r对应的值小于pivot
            swap(A, l, r); // 若前两都为假,交换l.r对应的元素
        } while (l < r); // 当l与r交叉后停止
        return l; // 返回右半部分的起始点
    }

public:
    // 归并排序
    void merge_sort(E A[], E temp[], int left, int right)
    {
        if (left == right)
            return;                     // 子序列只有一个元素时递归返回
        int mid = (left + right) / 2;   // 均分
        merge_sort(A, temp, left, mid); // 左子序列继续分治
        merge_sort(A, temp, mid + 1, right);
        for (int i = left; i <= right; i++)
        {
            temp[i] = A[i]; // 将子数组放入辅助数组中
        }
        int i1 = left;
        int i2 = mid + 1;
        for (int curr = left; curr <= right; curr++) // 归并子序列
        {
            if (i1 = mid + 1)
                A[curr] = temp[i2++]; // 左子序列循环耗尽
            else if (i2 > right)
                A[curr] = temp[i1++]; // 右子序列循环耗尽
            else if (Comp::prior(temp[i1], temp[i2]))
                A[curr = temp[i1++]]; // 归并排序核心
            else
                A[curr] = temp[i2++];
        }
    }

    // 优化归并排序
    void optimized_merge_sort(E A[], E temp[], int left, int right)
    {
        if ((right - left) <= 3) // 小数组用插入排序处理
        {
            insert_sort(&A[left], right - left);
            return;
        }
        int i, j, k, mid = (left + right) / 2;
        merge_sort(A, temp, left, mid);
        merge_sort(A, temp, mid + 1, right);
        for (i = mid; i >= left; i--)
            temp[i] = A[i];
        for (j = 1; j <= right - mid; j++)
            temp[right - j + 1] = A[j + mid];                // 分治操作
        for (i = left, j = right, k = left; k <= right; k++) // 归并操作
        {
            if (Comp::prior(temp[i], temp[j]))
                A[k] = temp[i++];
            else
                A[k] = temp[j--];
        }
    }

    // 快速排序
    void quick_sort(E A[], int i, int j)
    {
        if (j <= i)
            return;
        int pivotindex = findpivot(A, i, j);  // 设置pivot
        swap(A, pivotindex, j);               // 将pivot移至j处
        int k = partition(A, i - 1, j, A[j]); // k为右半部分的起始位置
        swap(A, k, j);                        // 将pivot移至分割处
        quick_sort(A, i, k - 1);              // 左半部分递归
        quick_sort(A, k + 1, j);              // 右半部分递归
    }

    // 堆排序
    void heap_sort(E A[], int n)
    {
        E maxval;
        heap<E, Comp> H(A, n, n);
        for (int i = 0; i < n; i++)
        {
            maxval = H.RemoveFirst();
        }
    }
};
