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

void BucketSort(std::vector<float> &nums)
{
    int k = nums.size() / 2;
    std::vector<std::vector<float>> buckets(k);
    for (float num : nums)
    {
        int i = num * k;
        buckets[i].push_back(num);
    }
    for (std::vector<float> &bucket : buckets)
    {
        std::sort(bucket.begin(), bucket.end());
    }
    i = 0;
    for (std::vector<float> &bucket : buckets)
    {
        for (float num : bucket)
        {
            nums[i++] = num;
        }
    }
}

void CountingSort(std::vector<int> &nums)
{
    int m = 0;
    for (int num : nums)
    {
        m = std::max(m, num);
    }
    std::vector<int> counter(m + 1, 0);
    for (int num : nums)
    {
        counter[num]++;
    }
    for (int i = 0; i < m; i++)
    {
        counter[i + 1] += counter[i];
    }
    int n = nums.size();
    std::vector<int> res(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int num = nums[i];
        res[counter[num] - 1] = num;
        counter[num]--;
    }
    nums = res;
}

int Digit(int num, int exp)
{
    return (num / exp) % 10;
}

void countingSortDigit(vector<int> &nums, int exp)
{
    // 十进制的位范围为 0~9 ，因此需要长度为 10 的桶数组
    vector<int> counter(10, 0);
    int n = nums.size();
    // 统计 0~9 各数字的出现次数
    for (int i = 0; i < n; i++)
    {
        int d = digit(nums[i], exp); // 获取 nums[i] 第 k 位，记为 d
        counter[d]++;                // 统计数字 d 的出现次数
    }
    // 求前缀和，将“出现个数”转换为“数组索引”
    for (int i = 1; i < 10; i++)
    {
        counter[i] += counter[i - 1];
    }
    // 倒序遍历，根据桶内统计结果，将各元素填入 res
    vector<int> res(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int d = digit(nums[i], exp);
        int j = counter[d] - 1; // 获取 d 在数组中的索引 j
        res[j] = nums[i];       // 将当前元素填入索引 j
        counter[d]--;           // 将 d 的数量减 1
    }
    // 使用结果覆盖原数组 nums
    for (int i = 0; i < n; i++)
        nums[i] = res[i];
}

void RadixSort(std::vector<int> &nums)
{
    // 获取数组的最大元素，用于判断最大位数
    int m = *max_element(nums.begin(), nums.end());
    // 按照从低位到高位的顺序遍历
    for (int exp = 1; exp <= m; exp *= 10)
        // 对数组元素的第 k 位执行计数排序
        // k = 1 -> exp = 1
        // k = 2 -> exp = 10
        // 即 exp = 10^(k-1)
        countingSortDigit(nums, exp);
}
