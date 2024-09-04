#include "ListNode.h"
#include <vector>

#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H

class LinkedListStack {
  private:
    ListNode *stackTop;
    int stackSize;

  public:
    LinkedListStack();
    ~LinkedListStack();
    int Size();
    bool IsEmpty();
    void Push(int num);
    int Pop();
    int Top();
    std::vector<int> ToVector();
};

#endif LINKEDLISTSTACK_H

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

class ArrayStack {
  private:
    std::vector<int> arrayStack;

  public:
    ArrayStack();
    ~ArrayStack();
    int Size();
    bool IsEmpty();
    void Push(int num);
    int Pop();
    int Top();
    std::vector<int> ToVector();
};

#endif ARRAYSTACK_H