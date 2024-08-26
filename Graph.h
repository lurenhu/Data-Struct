#include <iostream>
#include <vector>
#include <unordered_map>

#ifndef GRAPH
#define GRAPH

class GraphAdjMat
{
private:
    std::vector<int> vertices;
    std::vector<std::vector<int>> adjMat;

public:
    GraphAdjMat(const std::vector<int> &vertices, const std::vector<std::vector<int>> &edges);
    int Size() const;
    void AddVertex(int val);
    void RemoveVertex(int index);
    void AddEdge(int i, int j);
    void RemoveEdge(int i, int j);
    void Print();
};

struct Vertex
{
    int value;
    Vertex *next;
    Vertex(int x) : value(x), next(nullptr) {};
};

class GraphAdjList
{
private:
    std::unordered_map<Vertex *, std::vector<Vertex *>> adjList;

public:
    GraphAdjList(std::vector<std::vector<Vertex *>> edges);
    int Size() const;
    void Remove(std::vector<Vertex *> &ves, Vertex *vet);
    void AddEdge(Vertex *vet1, Vertex *vet2);
    void RemoveEdge(Vertex *vet1, Vertex *vet2);
    void AddVertex(Vertex *vet);
    void RemoveVertex(Vertex *vet);
};

#endif GRAPH