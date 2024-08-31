#include <iostream>
#include <vector>

#ifndef PAIR
#define PAIR

struct Pair
{
    int key;
    std::string val;
    Pair(int key, std::string val) : key(key), val(val) {};
};

#endif PAIR

#ifndef ARRAYHASHMAP_H
#define ARRAYHASHMAP_H

// 哈希冲突：从本质上看，哈希函数就是将所有的key所构建的输入空间映射到数组所有索引构成的输出空间，
// 而这里的输入空间是一定大于输出空间的，所有在理论上一定存在两个不一样的key值对应同一个输出value
// 这种情况就被称为哈希冲突



class ArrayHashMap
{
private:
    std::vector<Pair *> buckets;

public:
    ArrayHashMap();
    ~ArrayHashMap();
    int HashFunc(int key);
    std::string Get(int key);
    void Put(int key, std::string val);
    void Remove(int key);
    std::vector<Pair *> PairSet();
    std::vector<int> KeySet();
    std::vector<std::string> ValueSet();
    void Print();
};

#endif ARRAYHASHMAP_H