#include <iostream>
#include <vector>

#ifndef BINARYTREE
#define BINARYTREE

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> LevelOrder(TreeNode *root);
void PreOrder(TreeNode *root, std::vector<int> &res);
void InOrder(TreeNode *root, std::vector<int> &res);
void PostOrder(TreeNode *root, std::vector<int> &res);

#endif BINARYTREE
