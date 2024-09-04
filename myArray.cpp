#include "myArray.h"
#include <iostream>

using namespace std;

/// @brief 随机获取数组中的一个元素
/// @param nums 数组
/// @param size 数组长度
/// @return
int randomAccess(int *nums, int size) {
    int randomIndex = rand() % size;
    int randomValue = nums[randomIndex];
    return randomValue;
}

/// @brief 插入元素
/// @param nums 数组
/// @param size 数组长度
/// @param num 插入元素
/// @param index 插入索引
void insert(int *nums, int size, int num, int index) {
    for (int i = size - 1; i > index; i--) {
        nums[i] = nums[i - 1];
    }

    nums[index] = num;
}

/// @brief 删除元素
/// @param nums 数组
/// @param size 数组长度
/// @param index 删除元素索引
void remove(int *nums, int size, int index) {
    for (int i = index; i < size - 1; i++) {
        nums[i] = nums[i + 1];
    }
}

/// @brief 便利数组求和
/// @param nums 数组
/// @param size 数组长度
/// @return 数组总和
int traverse(int *nums, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += nums[i];
    }
    return sum;
}

/// @brief 查找
/// @param nums 数组
/// @param size 数组长度
/// @param target 目标元素
/// @return 目标元素索引
int find(int *nums, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}

/// @brief 扩展数组
/// @param nums 数组
/// @param size 数组长度
/// @param enlarge 扩展长度
/// @return
int *extend(int *nums, int size, int enlarge) {
    int *res = new int[size + enlarge];
    for (int i = 0; i < size; i++) {
        res[i] = nums[i];
    }
    delete[] nums;
    return res;
}