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
