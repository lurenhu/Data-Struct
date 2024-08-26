#include <iostream>
#include <vector>

#ifndef MAXHEAP
#define MAXHEAP

class MaxHeap
{
private:
    std::vector<int> maxHeap;

public:
    MaxHeap(std::vector<int> nums);

    bool IsEmpty();

    int Left(int i);
    int Right(int i);
    int Parent(int i);
    int Peek();

    void Push(int val);
    void SiftUp(int i);

    void Pop();
    void SiftDown(int i);
}

#endif MAXHEAP
