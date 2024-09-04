#include "Tree.h"
#include <queue>

/// @brief 层序遍历
/// @param root 根节点
/// @return
std::vector<int> LevelOrder(TreeNode *root) {
    std::vector<int> res;
    std::queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty()) {
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
void PreOrder(TreeNode *root, std::vector<int> &res) {
    if (root == nullptr) {
        return;
    }
    res.push_back(root->val);
    PreOrder(root->left, res);
    PreOrder(root->right, res);
}

/// @brief 中序遍历
/// @param root 根节点
/// @param res 数组的引用
void InOrder(TreeNode *root, std::vector<int> &res) {
    if (root == nullptr) {
        return;
    }
    InOrder(root->left, res);
    res.push_back(root->val);
    InOrder(root->right, res);
}

/// @brief 后序遍历
/// @param root 根节点
/// @param res 数组的引用
void PostOrder(TreeNode *root, std::vector<int> &res) {
    if (root == nullptr) {
        return;
    }
    InOrder(root->left, res);
    InOrder(root->right, res);
    res.push_back(root->val);
}

void ArrayBinaryTree::dfs(int i, std::string order, std::vector<int> &res) {
    if (Val(i) == INT_MAX) {
        return;
    }
    if (order == "pre") {
        res.push_back(Val[i]);
    }
    dfs(Left(i), order, res);
    if (order == "in") {
        res.push_back(Val(1));
    }
    dfs(Right(i), order, res);
    if (order == "post") {
        res.push_back(Val(i));
    }
}

ArrayBinaryTree::ArrayBinaryTree(std::vector<int> res) {
    tree = res;
}

int ArrayBinaryTree::Size() {
    return tree.size();
}

int ArrayBinaryTree::Val(int i) {
    if (i < 0 || i >= Size()) {
        return INT_MAX;
    }
    return tree[i];
}

int ArrayBinaryTree::Left(int i) {
    return 2 * i + 1;
}

int ArrayBinaryTree::Right(int i) {
    return 2 * i + 2;
}

int ArrayBinaryTree::Parent(int i) {
    return (i - 1) / 2;
}

std::vector<int> ArrayBinaryTree::LevelOrder() {
    std::vector<int> res;
    for (int i = 0; i < Size(); i++) {
        if (Val(i) != INT_MAX) {
            res.push_back(Val[i]);
        }
    }
    return res;
}

std::vector<int> ArrayBinaryTree::PreOrder() {
    std::vector<int> res;
    dfs(0, "pre", res);
    return res;
}

std::vector<int> ArrayBinaryTree::InOrder() {
    std::vector<int> res;
    dfs(0, "in", res);
    return res;
}

std::vector<int> ArrayBinaryTree::PostOrder() {
    std::vector<int> res;
    dfs(0, "post", res);
    return res;
}

int Height(AVLTreeNode *node) {
    return node == nullptr ? -1 : node->height;
}

void UpdateHeight(AVLTreeNode *node) {
    node->height = std::max(Height(node->right), Height(node->left)) + 1;
}

int BalanceFactor(AVLTreeNode *node) {
    if (node == nullptr) {
        return 0;
    }
    return Height(node->left) - Height(node->right);
}

AVLTreeNode *RightRotate(AVLTreeNode *node) {
    AVLTreeNode *child = node->left;
    AVLTreeNode *grandChild = node->right;

    child->right = node;
    node->left = grandChild;

    UpdateHeight(node);
    UpdateHeight(child);
    return child;
}

AVLTreeNode *LeftRotate(AVLTreeNode *node) {
    AVLTreeNode *child = node->right;
    AVLTreeNode *grandChild = node->left;

    child->left = node;
    node->right = grandChild;

    UpdateHeight(node);
    UpdateHeight(child);
    return child;
}

AVLTreeNode *Rotate(AVLTreeNode *node) {
    int balanceFactor = BalanceFactor(node);
    if (balanceFactor > 1) {
        if (BalanceFactor(node->left) >= 0) {
            return RightRotate(node);
        } else {
            node->left = LeftRotate(node->left);
            return RightRotate(node);
        }
    }
    if (balanceFactor < -1) {
        if (BalanceFactor(node->right) <= 0) {
            return LeftRotate(node);
        } else {
            node->right = RightRotate(node->right);
            return LeftRotate(node);
        }
    }

    return node;
}

void AVLInsert(AVLTreeNode *root, int val) {
    root = AVLInsertHelper(root, val);
}

AVLTreeNode *AVLInsertHelper(AVLTreeNode *node, int val) {
    if (node == nullptr) {
        return new AVLTreeNode(val);
    }
    if (val > node->val) {
        AVLInsertHelper(node->right, val);
    } else if (val < node->left) {
        AVLInsertHelper(node->left, val);
    } else {
        return node;
    }

    UpdateHeight(node);
    node = Rotate(node);
    return node;
}

void AVLRemove(AVLTreeNode *root, int val) {
    root = AVLRemoveHelper(root, val);
}

AVLTreeNode *AVLRemoveHelper(AVLTreeNode *node, int val) {
    if (node == nullptr) {
        return nullptr;
    }
    if (val > node->val) {
        AVLRemoveHelper(node->right, val);
    } else if (val < node->val) {
        AVLRemoveHelper(node->left, val);
    } else {
        if (node->left == nullptr || node->right == nullptr) {
            AVLTreeNode *child = node->left == nullptr ? node->left : node->right;
            if (child == nullptr) {
                delete node;
                return nullptr;
            } else {
                delete node;
                node = child;
            }
        } else {
            AVLTreeNode *temp = node->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            int tempVal = temp->val;
            node->right = removeHelper(node->right, temp->val);
            node->val = tempVal;
        }
    }

    UpdateHeight(node);
    node = Rotate(node);
    return node;
}
