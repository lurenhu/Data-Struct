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