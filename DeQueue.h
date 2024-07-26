#include <vector>

#ifndef DOUBLELISTNODE_H
#define DOUBLELISTNODE_H

struct DoubleListNode
{
    int value;
    DoubleListNode *next;
    DoubleListNode *prev;
    DoubleListNode(int x) : value(x), next(nullptr), prev(nullptr) {}
};

#endif DOUBLELISTNODE_H

#ifndef LINKEDLISTDEQUEUE_H
#define LINKEDLISTDEQUEUE_H

class DoubleLinkedListQueue
{
private:
    DoubleListNode *front, *rear;
    int queSize;

public:
    LinkedListQueue();
    ~LinkedListQueue();
    int Size();
    bool IsEmpty();
    void Push(int num, bool isFront);
    void PushFirst(int num);
    void PushLast(int num);
    int Pop(bool isFront);
    int PopFirst();
    int PopLast();
    int PeekFirst();
    int PeekLast();
    std::vector<int> ToVector();
};

#endif LINKEDLISTDEQUEUE_H

#ifndef ARRAYDEQUEUE_H
#define ARRAYDEQUEUE_H

class ArrayDequeue
{
private:
    std::vector<int> nums;
    int front;
    int queSize;

public:
    ArrayDequeue(int capacity);
    ~ArrayDequeue();
    int Size();
    bool IsEmpty();
    int Capacity();
    int index(int i);
    void PushFirst(int num);
    void PushLast(int num);
    int PopFirst();
    int PopLast();
    int PeekFirst();
    int PeekLast();
    std::vector<int> ToVector();
};

#endif ARRAYDEQUEUE_H