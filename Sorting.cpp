#include "Sorting.h"

void SelectionSort(std::vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[k])
            {
                k = j;
            }
        }
        std::swap(nums[i], nums[k]);
    }
}

void BubbleSort(std::vector<int> &nums)
{
    for (int i = nums.size() - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                std::swap(nums[j], nums[j + 1]);
            }
        }
    }
}

void InsertSort(std::vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        int base = nums[i], j = i + 1;
        while (nums[j] > base && j >= 0)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j] = base;
    }
}
