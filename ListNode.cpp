#include "ListNode.h"
#include <iostream>

using namespace std;

/// @brief 插入节点
/// @param root 插入处根节点
/// @param node 插入节点
void insert(ListNode *root, ListNode *node) {
    ListNode *nextNode = root->next;
    root->next = node;
    node->next = nextNode;
}

/// @brief 删除该节点的下个节点
/// @param root 根节点
void remove(ListNode *root) {
    if (root->next == nullptr) {
        return;
    }
    ListNode *nextNode = root->next;
    ListNode *nextNextNode = nextNode->next;
    root->next = nextNextNode;
    delete nextNode;
}

/// @brief 访问节点
/// @param head 头节点
/// @param index 索引
/// @return
ListNode *access(ListNode *head, int index) {
    for (int i = 0; i < index; i++) {
        if (head == nullptr)
            return nullptr;
        head = head->next;
    }
    return head;
}

/// @brief 查找与target值相同的节点
/// @param root 根节点
/// @param target 查找值
/// @return
int find(ListNode *root, int target) {
    int index = 0;
    while (root != nullptr) {
        if (root->value == target) {
            return index;
        }
        index++;
        root = root->next;
    }
    return -1;
}

void FreeMemoryLinkedList(ListNode *root) {
    while (root->next != nullptr) {
        remove(root);
    }
    delete root;
}