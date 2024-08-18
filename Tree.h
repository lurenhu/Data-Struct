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

class ArrayBinaryTree
{
private:
    std::vector<int> tree;
    void dfs(int i, std::string order, std::vector<int> &res);

public:
    ArrayBinaryTree(std::vector<int> res);
    int Size();
    int Val(int i);
    int Left(int i);
    int Right(int i);
    int Parent(int i);
    std::vector<int> LevelOrder();
    std::vector<int> PreOrder();
    std::vector<int> InOrder();
    std::vector<int> PostOrder();
};

#endif BINARYTREE

#ifndef AVLTREE
#define AVLTREE

struct AVLTreeNode
{
    int val{};
    int height = 0;
    AVLTreeNode *left{};
    AVLTreeNode *right{};
    AVLTreeNode() = default;
    explicit AVLTreeNode(int x) : val(x) {};
};

int Height(AVLTreeNode *node);
void UpdateHeight(AVLTreeNode *node);

int BalanceFactor(AVLTreeNode *node)

AVLTreeNode *Rotate(AVLTreeNode *node);
void AVLInsert(AVLTreeNode *root, int val);
void AVLRemove(AVLTreeNode *root, int val);

#endif AVLTREE