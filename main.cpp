#include <iostream>
#include "myArray.h"
#include "ListNode.h"

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
    ListNode *n0 = new ListNode(0);
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    insert(n0, new ListNode(5));

    remove(n0);

    ListNode *nodeAccess = access(n0, 2);

    int index = find(n0, 2);
    #pragma endregion

}