#include "Queue.h"
#include <stdexcept>

LinkedListQueue::LinkedListQueue()
{
    front = nullptr;
    rear = nullptr;
    queSize = 0;
}

LinkedListQueue::~LinkedListQueue()
{
    FreeMemoryLinkedList(front);
}

int LinkedListQueue::Size()
{
    return queSize;
}

bool LinkedListQueue::IsEmpty()
{
    return front == nullptr;
}

void LinkedListQueue::Push(int num)
{
    ListNode *node = new ListNode(num);
    if (front == nullptr || rear == nullptr || queSize == 0)
    {
        front = node;
        rear = node;
    }
    else
    {
        rear->next = node;
        rear = rear->next;
    }

    queSize++;
}

int LinkedListQueue::Pop()
{
    int num = Peek();
    ListNode *tmp = front;
    front = front->next;
    delete tmp;
    queSize--;
    return num;
}

int LinkedListQueue::Peek()
{
    if (front == nullptr || queSize == 0)
    {
        throw std::out_of_range("队列为空");
    }
    return front->value;
}

std::vector<int> LinkedListQueue::ToVector()
{
    ListNode *node = front;
    std::vector<int> res(queSize);
    for (int i = 0; i < queSize; i++)
    {
        res[i] = node->value;
        node = node->next;
    }
    return res;
}

ArrayQueue::ArrayQueue(int capacity)
{
    nums = new int[capacity];
    queCapacity = capacity;
    front = queSize = 0;
}

ArrayQueue::~ArrayQueue()
{
    delete[] nums;
}

int ArrayQueue::Capacity()
{
    return queCapacity;
}

int ArrayQueue::Size()
{
    return queSize;
}

bool ArrayQueue::IsEmpty()
{
    return queSize == 0;
}

void ArrayQueue::Push(int num)
{
    if (queSize == queCapacity)
    {
        std::out_of_range("队列已满");
    }
    int rear = (front + queSize) % queCapacity;
    nums[rear] = num;
    queSize++;
}

int ArrayQueue::Pop()
{
    int num = Peek();
    front = (front + 1) % queCapacity;
    queSize--;

    return num;
}

int ArrayQueue::Peek()
{
    if (queSize == 0)
    {
        throw std::out_of_range("队列为空");
    }
    return nums[front];
}

std::vector<int> ArrayQueue::ToVector()
{
    std::vector<int> res(queSize);
    for (int i = 0, j = front; i < queSize; i++, j++)
    {
        res[i] = nums[j % queCapacity];
    }
    return res;
}
