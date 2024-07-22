#include <iostream>
#include "myArray.h"
#include "ListNode.h"
#include "MyList.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{
#pragma region 数组
// int arr[] = {1, 2, 3, 4, 5};
// int size = sizeof(arr) / sizeof(arr[0]);

// int rand = randomAccess(arr, size);

// remove(arr, size, 2);
// insert(arr, size, 1, 2);

// int sum = traverse(arr, size);
// int num = find(arr, size, 2);

// int *myExtend = extend(arr, size, 2);
#pragma endregion

    //--------------------------------------------

#pragma region 链表
// ListNode *n0 = new ListNode(0);
// ListNode *n1 = new ListNode(1);
// ListNode *n2 = new ListNode(2);
// ListNode *n3 = new ListNode(3);
// ListNode *n4 = new ListNode(4);
// n0->next = n1;
// n1->next = n2;
// n2->next = n3;
// n3->next = n4;

// insert(n0, new ListNode(5));

// remove(n0);

// ListNode *nodeAccess = access(n0, 2);

// int index = find(n0, 2);
#pragma endregion

    //--------------------------------------------

#pragma region 列表
    // MyList myList;
    // myList.Add(1);
    // myList.Add(2);
    // myList.Add(3);

    // myList.Insert(1, 4);
    // myList.Get(1);
    // myList.Set(2, 5);
    // myList.Remove(1);
    // myList.ToVector();
#pragma endregion

    //--------------------------------------------

#pragma region 栈
    // LinkedListStack LinkedListStack;
    // LinkedListStack.Push(1);
    // LinkedListStack.Push(2);
    // LinkedListStack.Push(3);
    // LinkedListStack.Push(4);
    // int ListTop = LinkedListStack.Top();
    // LinkedListStack.Pop();
    // int ListSize = LinkedListStack.Size();
    // bool ListIsEmpty = LinkedListStack.IsEmpty();

    // ArrayStack ArrayStack;
    // ArrayStack.Push(1);
    // ArrayStack.Push(2);
    // ArrayStack.Push(3);
    // ArrayStack.Push(4);
    // int ArrayTop = ArrayStack.Top();
    // ArrayStack.Pop();
    // int ArraySize = ArrayStack.Size();
    // bool ArrayIsEmpty = ArrayStack.IsEmpty();

#pragma endregion 栈

    //--------------------------------------------

#pragma region 队列

    // LinkedListQueue LinkedListQueue;
    // LinkedListQueue.Push(1);
    // LinkedListQueue.Push(2);
    // LinkedListQueue.Push(3);
    // LinkedListQueue.Push(4);
    // LinkedListQueue.Push(5);
    // int listSize = LinkedListQueue.Size();
    // bool listIsEmpty = LinkedListQueue.IsEmpty();
    // int listPop = LinkedListQueue.Pop();

    // ArrayQueue ArrayQueue(10);
    // ArrayQueue.Push(1);
    // ArrayQueue.Push(2);
    // ArrayQueue.Push(3);
    // ArrayQueue.Push(4);
    // ArrayQueue.Push(5);
    // int arraySize = ArrayQueue.Size();
    // bool arrayIsEmpty = ArrayQueue.IsEmpty();
    // int arrayPop = ArrayQueue.Pop();

#pragma endregion 队列
}