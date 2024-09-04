#include "Search.h"

int BinarySearch(std::vector<int> &nums, int target) {
    int i = 0, j = nums.size() - 1;
    while (i < j) {
        int m = i + (j - i) / 2;
        if (nums[m] < target) {
            i = m + 1;
        } else if (nums[m] > target) {
            j = m - 1;
        } else {
            return m;
        }
    }
    return -1;
}

int BinarySearchLCRO(std::vector<int> &nums, int target) {
    int i = 0, j = nums.size() - 1;
    while (i < j) {
        int m = i + (j - i) / 2;
        if (nums[m] < target) {
            i = m + 1;
        } else if (nums[m] > target) {
            j = m;
        } else {
            return m;
        }
    }
    return -1;
}

int BinarySearchInsertionSimple(std::vector<int> &nums, int target) {
    int i = 0, j = nums.size() - 1;
    while (i < = j) {
        int m = i + (j - i) / 2;
        if (nums[m] < target) {
            i = m + 1;
        } else if (nums[m] > target) {
            j = m - 1;
        } else {
            return m;
        }
    }
    return i;
}

int BinarySearchInsertion(std::vector<int> &nums, int target) {
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
        int m = i + (j - 1) / 2;
        if (nums[m] < target) {
            i = m + 1;
        } else if (nums[m] > target) {
            j = m - 1;
        } else {
            j = m - 1;
        }
    }
    return i;
}

int BinarySearchLeftEdge(std::vector<int> &nums, int target) {
    int i = BinarySearchInsertion(nums, target);
    if (i == nums.size() || nums[i] != target) {
        return -1;
    }
    return i;
}

int BinarySearchRightEdge(std::vector<int> &nums, int target) {
    int i = BinarySearchInsertion(nums, target + 1);
    int j = i - 1;
    if (j == -1 || nums[j] != target) {
        return -1;
    }
    return j;
}

std::vector<int> TwoSumBruteForce(std::vector<int> &nums, int target) {
    int size = nums.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
}

std::vector<int> TwoSumBruteTable(std::vector<int> &nums, int target) {
    int size = nums.size();
    std::unordered_map<int, int> dic;
    for (int i = 0; i < size; i++) {
        if (dic.find(target - nums[i]) != dic.end()) {
            return {dic[target - nums[i]], i};
        }
        dic.emplace(nums[i], i);
    }
    return {};
}
