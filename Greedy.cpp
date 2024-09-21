#include "Greedy.h"
#include <algorithm>
#include <math.h>

double FractionalKnapsack(std::vector<int> &wgt, std::vector<int> &val, int cap) {
    std::vector<Item> items;
    for (int i = 0; i < wgt.size(); i++) {
        items.push_back(Item(wgt[i], val[i]));
    }
    std::sort(items.begin(), items.end(), [](Item &a, Item &b) { return (double)a.v / a.w > (double)b.v / b.w });
    double res = 0;
    for (auto &item : items) {
        if (item.w <= cap) {
            res += item.v;
            cap -= item.w;
        } else {
            res += (double)item.v / item.w * cap;
            break;
        }
    }
    return res;
}

int MaxCapacity(std::vector<int> &ht) {
    int i = 0, j = ht.size() - 1;
    int res = 0;
    while (i < j) {
        int cap = std::min(ht[i], ht[j]) * (j - i);
        res = std::max(cap, res);
        if (ht[i] < ht[j]) {
            i++;
        } else {
            j++;
        }
    }
    return res;
}

int MaxProductCutting(int n) {
    if (n <= 3) {
        return 1 * (n - 1);
    }

    int a = n / 3;
    int b = n % 3;
    if (b == 1) {
        return (int)pow(3, a - 1) * 2 * 2;
    }
    if (b == 2) {
        return (int)pow(3, a) * 2;
    }
    return (int)pow(3, a);
}
