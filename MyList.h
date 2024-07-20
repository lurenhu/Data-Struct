#include <vector>

#ifndef MYLIST_H
#define MYLIST_H

class MyList
{
private:
    int *arr;
    int arrCapacity = 10;
    int arrSize = 0;
    int extendRation = 2;

public:
    MyList();
    ~MyList();
    int Size();
    int Capacity();
    int Get(int index);
    void Set(int index, int num);
    void Add(int num);
    void Insert(int index, int num);
    int Remove(int index);
    void ExtendCapacity();
    std::vector<int> ToVector();
};

#endif