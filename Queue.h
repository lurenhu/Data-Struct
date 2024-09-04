#include "ListNode.h"
#include <vector>

#ifndef LINKEDLISTQUEUE_H
#define LINKEDLISTQUEUE_H

class LinkedListQueue {
  private:
    ListNode *front, *rear;
    int queSize;

  public:
    LinkedListQueue();
    ~LinkedListQueue();
    int Size();
    bool IsEmpty();
    void Push(int num);
    int Pop();
    int Peek();
    std::vector<int> ToVector();
};

#endif LINKEDLISTQUEUE_H

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

class ArrayQueue {
  private:
    int *nums;
    int front;
    int queSize;
    int queCapacity;

  public:
    ArrayQueue(int capacity);
    ~ArrayQueue();
    int Capacity();
    int Size();
    bool IsEmpty();
    void Push(int num);
    int Pop();
    int Peek();
    std::vector<int> ToVector();
};

#endif ARRAYQUEUE_H
