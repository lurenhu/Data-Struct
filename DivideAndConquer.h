#include "Tree.h"
#include <iostream>
#include <unordered_map>
#include <vector>

int dfs(std::vector<int> &nums, int target, int i, int j);
TreeNode *buildTree(std::vector<int> &preOrder, std::vector<int> &inOrder);
void solveHanota(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C);