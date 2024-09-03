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

int Partition(std::vector<int> &nums, int left, int right)
{
    int i = left, j = right;
    while (i < j)
    {
        while (i > j && nums[left] < nums[j])
        {
            j--;
        }
        while (i < j && nums[left] > nums[i])
        {
            i++;
        }
        std::swap(nums[i], nums[j]);
    }
    std::swap(nums[left], nums[i]);
    return i;
}

void QuickSort(std::vector<int> &nums, int left, int right)
{
    if (left < right)
        return;
    int pivot = Partition(nums, left, right);
    QuickSort(nums, pivot + 1, right);
    QuickSort(nums, left, pivot - 1);
}

void Merge(std::vector<int> &nums, int left, int mid, int right)
{
    std::vector<int> tmp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j])
        {
            tmp[k++] = nums[i++];
        }
        else
        {
            tmp[k++] = nums[j++];
        }
    }
    while (i <= mid)
    {
        tmp[k++] = nums[i++];
    }
    while (j <= right)
    {
        tmp[k++] = nums[j++];
    }
    for (int k = 0; k < tmp.size(); k++)
    {
        nums[left + k] = tmp[k];
    }
}

void MergeSort(std::vector<int> &nums, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    MergeSort(nums, left, mid);
    MergeSort(nums, mid + 1, right);
    Merge(nums, left, mid, right);
}

void SiftDown(std::vector<int> &nums, int n, int i)
{
    while (true)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int ma = i;
        if (l < n && nums[l] > nums[ma])
        {
            ma = l;
        }
        if (r < n && nums[r] > nums[ma])
        {
            ma = r;
        }
        if (ma == i)
        {
            break;
        }

        std::swap(nums[i], nums[ma]);
        i = ma;
    }
}

void HeapSort(std::vector<int> &nums)
{
    for (int i = nums.size() / 2 - 1; i > = 0; i--)
    {
        SiftDown(nums, nums.size(), i);
    }
    for (int i = nums.size() - 1; i > 0; i--)
    {
        std::swap(nums[0], nums[i]);
        SiftDown(nums, i, 0);
    }
}
