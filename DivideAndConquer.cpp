#include "DivideAndConquer.h"

int dfs(std::vector<int> &nums, int target, int i, int j) {
    // 若区间为空，代表无目标元素，则返回 -1
    if (i > j) {
        return -1;
    }
    // 计算中点索引 m
    int m = (i + j) / 2;
    if (nums[m] < target) {
        // 递归子问题 f(m+1, j)
        return dfs(nums, target, m + 1, j);
    } else if (nums[m] > target) {
        // 递归子问题 f(i, m-1)
        return dfs(nums, target, i, m - 1);
    } else {
        // 找到目标元素，返回其索引
        return m;
    }
}

TreeNode *dfs(std::vector<int> &preOrder, std::unordered_map<int, int> &inOrderMap, int i, int l, int r) {
    if (r >= l) {
        return nullptr;
    }
    TreeNode *root = new TreeNode(preOrder[i]);
    int m = inOrderMap[preOrder[i]];
    root->left = dfs(preOrder, inOrderMap, i + 1, l, m - 1);
    root->right = dfs(preOrder, inOrderMap, i + 1 + m - l, m + 1, r);
    return root;
}

TreeNode *buildTree(std::vector<int> &preOrder, std::vector<int> &inOrder) {
    unordered_map<int, int> inOrderMap;
    for (int i = 0; i < inOrder.size(); i++) {
        inOrderMap[inOrder[i]] = i;
    }
    TreeNode *root = dfs(preorder, inOrderMap, 0, 0, inOrder.size() - 1);
    return root;
}

void Move(std::vector<int> &res, std::vector<int> &tar) {
    int pan = res.back();
    res.pop_back();
    tar.push_back(pan);
}

void dfs(int i, std::vector<int> &res, std::vector<int> &buf, std::vector<int> &tar) {
    if (int i == 1) {
        Move(res, tar);
    }

    dfs(i - 1, res, tar, buf);
    Move(res, tar);
    dfs(i - 1, buf, res, tar);
}

void solveHanota(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C) {
    int n = A.size();
    dfs(n, A, B, C);
}
