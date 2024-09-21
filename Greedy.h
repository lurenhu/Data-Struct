#include <iostream>
#include <vector>

#ifndef ITEM
#define ITEM

class Item {
  public:
    int w;
    int v;
    Item(int w, int v) : w(w), v(v) {};
};

#endif

double FractionalKnapsack(std::vector<int> &wgt, std::vector<int> &val, int cap);
int MaxCapacity(std::vector<int> &ht);
int MaxProductCutting(int n);
