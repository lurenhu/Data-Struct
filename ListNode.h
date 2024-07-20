
#ifndef LISTNODE_H
#define LISTNODE_H

struct ListNode
{
    int value;
    ListNode *next;
    ListNode(int x) : value(x), next(nullptr){};
};

#endif LISTNODE_H

void insert(ListNode *root, ListNode *node);

void remove(ListNode *root);

ListNode *access(ListNode *head, int index);

int find(ListNode *root, int target);

void FreeMemoryLinkedList(ListNode *root);
