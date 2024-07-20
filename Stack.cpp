#include "Stack.h"
#include <stdexcept>

LinkedListStack::LinkedListStack()
{
    stackTop = new ListNode(0);
    stackSize = 0;
}

LinkedListStack::~LinkedListStack()
{
    FreeMemoryLinkedList(stackTop);
}

int LinkedListStack::Size()
{
    return stackSize;
}

bool LinkedListStack::IsEmpty()
{
    return stackSize == 0;
}

void LinkedListStack::Push(int num)
{
    ListNode *node = new ListNode(num);
    node->next = stackTop;
    stackTop = node;
    stackSize++;
}

int LinkedListStack::Pop()
{
    int num = Top();
    ListNode *node = stackTop;
    stackTop = stackTop->next;
    delete node;
    stackSize--;
    return num;
}

int LinkedListStack::Top()
{
    if (IsEmpty())
    {
        throw std::out_of_range("栈为空");
    }

    return stackTop->value;
}

std::vector<int> LinkedListStack::ToVector()
{
    ListNode *node = stackTop;
    std::vector<int> res(stackSize);
    for (int i = stackSize - 1; i >= 0; i--)
    {
        res[i] = node->value;
        node = node->next;
    }
    return res;
}

ArrayStack::ArrayStack()
{
}

ArrayStack::~ArrayStack()
{
}

int ArrayStack::Size()
{
    return arrayStack.size();
}

bool ArrayStack::IsEmpty()
{
    return Size() == 0;
}

void ArrayStack::Push(int num)
{
    arrayStack.push_back(num);
}

int ArrayStack::Pop()
{
    int num = Top();
    arrayStack.pop_back();
    return num;
}

int ArrayStack::Top()
{
    if (IsEmpty())
    {
        throw std::out_of_range("栈为空");
    }
    return arrayStack.back();
}

std::vector<int> ArrayStack::ToVector()
{
    return arrayStack;
}
