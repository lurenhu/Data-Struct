#include "Hashmap.h"

ArrayHashMap::ArrayHashMap()
{
    buckets = std::vector<Pair *>(100);
}

ArrayHashMap::~ArrayHashMap()
{
    for (auto bucket : buckets)
    {
        delete bucket;
    }
    buckets.clear();
}

int ArrayHashMap::HashFunc(int key)
{
    return key % 100;
}

std::string ArrayHashMap::Get(int key)
{
    int index = HashFunc(key);
    Pair *pair = buckets[index];
    if (pair->val == nullptr)
    {
        return "该键无对应值";
    }
    return pair->val;
}

void ArrayHashMap::Put(int key, std::string val)
{
    Pair *pair = Pair(key, val);
    int index = HashFunc(key);
    buckets[index] = pair;
}

void ArrayHashMap::Remove(int key)
{
    int index = HashFunc(key);
    delete buckets[index];
    buckets[index] = nullptr;
}

std::vector<Pair *> ArrayHashMap::PairSet()
{
    std::vector<Pair *> PairSet;
    for (auto bucket : buckets)
    {
        if (bucket != nullptr)
        {
            PairSet.push_back(bucket);
        }
    }
    return PairSet;
}

std::vector<int> ArrayHashMap::KeySet()
{
    std::vector<int> KeySet;
    for (auto bucket : buckets)
    {
        if (bucket != nullptr)
        {
            KeySet.push_back(bucket->key);
        }
    }
    return KeySet;
}

std::vector<std::string> ArrayHashMap::ValueSet()
{
    std::vector<std::string> ValueSet;
    for (auto bucket : buckets)
    {
        if (bucket != nullptr)
        {
            ValueSet.push_back(bucket->val);
        }
    }
    return ValueSet;
}

void ArrayHashMap::Print()
{
    for (auto pair : PairSet())
    {
        std::cout << pair->key << " -> " << pair->val << std::endl;
    }
}
