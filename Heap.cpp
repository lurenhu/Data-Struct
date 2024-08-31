#include "Heap.h"

/// @brief 获取该节点的左子节点
/// @param i
/// @return
int MaxHeap::Left(int i)
{
    return 2 * i + 1;
}

MaxHeap::MaxHeap(std::vector<int> nums)
{
    maxHeap = nums;
    for (int i = Parent(maxHeap.size() - 1); i >= 0; i--)
    {
        SiftDown(i);
    }
}

/// @brief 判断该堆是否为空
/// @return
bool MaxHeap::IsEmpty()
{
    return maxHeap.size() == 0;
}

/// @brief 获取该节点的右子节点
/// @param i
/// @return
int MaxHeap::Right(int i)
{
    return 2 * i + 2;
}

/// @brief 获取该节点的父节点
/// @param i
/// @return
int MaxHeap::Parent(int i)
{
    return (i - 1) / 2;
}

/// @brief 获取堆顶元素
/// @return
int MaxHeap::Peek()
{
    return maxHeap[0];
}

/// @brief 入堆
/// @param val
void MaxHeap::Push(int val)
{
    maxHeap.push_back(val);
    SiftUp(maxHeap.size() - 1);
}

/// @brief 自该索引向上堆化
/// @param i
void MaxHeap::SiftUp(int i)
{
    while (true)
    {
        int p = Parent(i);
        if (p < 0 || maxHeap[i] <= maxHeap[p])
        {
            break;
        }
        std::swap(maxHeap[i], maxHeap[p]);
        i = p;
    }
}

/// @brief 出堆
void MaxHeap::Pop()
{
    if (IsEmpty())
    {
        throw std::__throw_out_of_range("堆为空");
    }
    std::swap(maxHeap[0], maxHeap[maxHeap.size() - 1]);
    maxHeap.pop_back();
    SiftDown(0);
}

/// @brief 自该索引向下堆化
/// @param i
void MaxHeap::SiftDown(int i)
{
    while (true)
    {
        int l = Left(i), r = Right(i), ma = i;
        if (l < maxHeap.size() && maxHeap[l] > maxHeap[ma])
        {
            ma = l;
        }
        if (r < maxHeap.size() && maxHeap[r] > maxHeap[ma])
        {
            ma = r;
        }
        if (ma == i)
        {
            break;
        }
        std::swap(maxHeap[i], maxHeap[ma]);
        i = ma;
    }
}
