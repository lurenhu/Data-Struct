#include "DeQueue.h"
#include <stdexcept>

DoubleLinkedListQueue::LinkedListQueue()
{
    front = nullptr;
    rear = nullptr;
    queSize = 0;
}

DoubleLinkedListQueue::~LinkedListQueue()
{
    DoubleListNode *cur = front, *pre;
    while (cur != nullptr)
    {
        pre = cur;
        cur = cur->next;
        delete pre;
    }
}

int DoubleLinkedListQueue::Size()
{
    return queSize;
}

bool DoubleLinkedListQueue::IsEmpty()
{
    return queSize == 0;
}

void DoubleLinkedListQueue::Push(int num, bool isFront)
{
    DoubleListNode *node = new DoubleListNode(num);
    if (IsEmpty())
    {
        front = node;
        rear = node;
    }
    else if (isFront)
    {
        node->next = front;
        front->prev = node;
        front = front->prev;
    }
    else
    {
        node->prev = rear;
        rear.next = node;
        rear = rear->next;
    }
    queSize++;
}

void DoubleLinkedListQueue::PushFirst(int num)
{
    Push(num, true);
}

void DoubleLinkedListQueue::PushLast(int num)
{
    Push(num, false);
}

int DoubleLinkedListQueue::Pop(bool isFront)
{
    int num;
    if (IsEmpty())
    {
        throw std::out_of_range("双向队列为空");
    }
    else if (isFront)
    {
        num = front->value;
        DoubleListNode *node = front->next;
        if (node != nullptr)
        {
            node->prev = nullptr;
            front->next = nullptr;
        }
        delete front;
        front = node;
    }
    else
    {
        num = rear->value;
        DoubleListNode *node = rear->prev;
        if (node != nullptr)
        {
            node->next = nullptr;
            rear->prev = nullptr;
        }
        delete rear;
        rear = node;
    }
    return num;
}

int DoubleLinkedListQueue::PopFirst()
{
    return Pop(true);
}

int DoubleLinkedListQueue::PopLast()
{
    return Pop(false);
}

int DoubleLinkedListQueue::PeekFirst()
{
    if (IsEmpty())
    {
        throw std::out_of_range("双向队列为空");
    }
    return front->value;
}

int DoubleLinkedListQueue::PeekLast()
{
    if (IsEmpty())
    {
        throw std::out_of_range("双向队列为空");
    }
    return rear->value;
}

std::vector<int> DoubleLinkedListQueue::ToVector()
{
    DoubleListNode *node = front;
    std::vector<int> res(Size());
    for (int i = 0; i < Size(); i++)
    {
        res[i] = node->value;
        node = node->next;
    }
    return res;
}

ArrayDequeue::ArrayDequeue(int capacity)
{
    nums.resize(capacity);
    front = queSize = 0;
}

ArrayDequeue::~ArrayDequeue()
{
}

int ArrayDequeue::Size()
{
    return queSize;
}

bool ArrayDequeue::IsEmpty()
{
    return queSize == 0;
}

int ArrayDequeue::Capacity()
{
    return nums.size();
}

int ArrayDequeue::index(int i)
{
    return (i + Capacity()) & Capacity();
}

void ArrayDequeue::PushFirst(int num)
{
    if (queSize == Capacity())
    {
        throw std::out_of_range("双向队列已满");
    }
    front = index(front - 1);
    nums[front] = num;
    queSize++;
}

void ArrayDequeue::PushLast(int num)
{

    int rear = front + queSize;
    nums[rear] = num;
    queSize++;
}

int ArrayDequeue::PopFirst()
{
    int num = PeekFirst();
    front = index(front + 1);
    queSize--;
    return num;
}

int ArrayDequeue::PopLast()
{
    int num = PeekLast();
    queSize--;
    return num;
}

int ArrayDequeue::PeekFirst()
{
    if (queSize == Capacity())
    {
        throw std::out_of_range("双向队列已满");
    }
    return nums[front];
}

int ArrayDequeue::PeekLast()
{
    if (queSize == Capacity())
    {
        throw std::out_of_range("双向队列已满");
    }
    int last = index(front + queSize - 1);
    return nums[last];
}

std::vector<int> ArrayDequeue::ToVector()
{
    std::vector<int> res(queSize);
    for (int i = 0, j = front; i < Size(); i++, j++)
    {
        res[i] = nums[index(j)];
    }
    return res;
}
