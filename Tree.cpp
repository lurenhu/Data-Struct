#include "Tree.h"
#include <queue>

/// @brief 层序遍历
/// @param root 根节点
/// @return
std::vector<int> LevelOrder(TreeNode *root)
{
    std::vector<int> res;
    std::queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        TreeNode *node = queue.front();
        queue.pop();
        res.push_back(node->val);
        if (node->left != nullptr)
            queue.push(node->left);
        if (node->right != nullptr)
            queue.push(node->right);
    }
    return res;
}

/// @brief 前序遍历
/// @param root 根节点
/// @param res 数组的引用
void PreOrder(TreeNode *root, std::vector<int> &res)
{
    if (root == nullptr)
    {
        return;
    }
    res.push_back(root->val);
    PreOrder(root->left, res);
    PreOrder(root->right, res);
}

/// @brief 中序遍历
/// @param root 根节点
/// @param res 数组的引用
void InOrder(TreeNode *root, std::vector<int> &res)
{
    if (root == nullptr)
    {
        return;
    }
    InOrder(root->left, res);
    res.push_back(root->val);
    InOrder(root->right, res);
}

/// @brief 后序遍历
/// @param root 根节点
/// @param res 数组的引用
void PostOrder(TreeNode *root, std::vector<int> &res)
{
    if (root == nullptr)
    {
        return;
    }
    InOrder(root->left, res);
    InOrder(root->right, res);
    res.push_back(root->val);
}

void ArrayBinaryTree::dfs(int i, std::string order, std::vector<int> &res)
{
    if (Val(i) == INT_MAX)
    {
        return;
    }
    if (order == "pre")
    {
        res.push_back(Val[i]);
    }
    dfs(Left(i), order, res);
    if (order == "in")
    {
        res.push_back(Val(1));
    }
    dfs(Right(i), order, res);
    if (order == "post")
    {
        res.push_back(Val(i));
    }
}

ArrayBinaryTree::ArrayBinaryTree(std::vector<int> res)
{
    tree = res;
}

int ArrayBinaryTree::Size()
{
    return tree.size();
}

int ArrayBinaryTree::Val(int i)
{
    if (i < 0 || i >= Size())
    {
        return INT_MAX;
    }
    return tree[i];
}

int ArrayBinaryTree::Left(int i)
{
    return 2 * i + 1;
}

int ArrayBinaryTree::Right(int i)
{
    return 2 * i + 2;
}

int ArrayBinaryTree::Parent(int i)
{
    return (i - 1) / 2;
}

std::vector<int> ArrayBinaryTree::LevelOrder()
{
    std::vector<int> res;
    for (int i = 0; i < Size(); i++)
    {
        if (Val(i) != INT_MAX)
        {
            res.push_back(Val[i]);
        }
    }
    return res;
}

std::vector<int> ArrayBinaryTree::PreOrder()
{
    std::vector<int> res;
    dfs(0, "pre", res);
    return res;
}

std::vector<int> ArrayBinaryTree::InOrder()
{
    std::vector<int> res;
    dfs(0, "in", res);
    return res;
}

std::vector<int> ArrayBinaryTree::PostOrder()
{
    std::vector<int> res;
    dfs(0, "post", res);
    return res;
}
