#include "Graph.h"

GraphAdjMat::GraphAdjMat(const std::vector<int> &vertices, const std::vector<std::vector<int>> &edges)
{
    for (int i : vertices)
    {
        AddVertex(i);
    }

    for (const std::vector<int> &edge : edges)
    {
        AddEdge(edge[0], edge[1]);
    }
}

int GraphAdjMat::Size() const
{
    return vertices.size();
}

void GraphAdjMat::AddVertex(int val)
{
    int n = Size();
    vertices.push_back(val);
    adjMat.emplace_back(std::vector<int>(n, 0));
    for (std::vector<int> &row : adjMat)
    {
        row.push_back(0);
    }
}

void GraphAdjMat::RemoveVertex(int index)
{
    if (index >= Size())
    {
        throw std::out_of_range("不存在顶点");
    }
    vertices.erase(vertices.begin() + index);
    adjMat.erase(adjMat.begin() + index);
    for (std::vector<int> &row : adjMat)
    {
        row.erase(row.begin() + index);
    }
}

void GraphAdjMat::AddEdge(int i, int j)
{
    if (i < 0 || j < 0 || i == j || i >= Size() || j >= Size())
    {
        throw std::out_of_range("索引越界");
    }
    adjMat[i][j] = 1;
    adjMat[j][i] = 1;
}

void GraphAdjMat::RemoveEdge(int i, int j)
{
    if (i < 0 || j < 0 || i == j || i >= Size() || j >= Size())
    {
        throw std::out_of_range("索引越界");
    }
    adjMat[i][j] = 0;
    adjMat[j][i] = 0;
}

void GraphAdjMat::Print()
{
}

GraphAdjList::GraphAdjList(std::vector<std::vector<Vertex *>> edges)
{
    for (const &edge : edges)
    {
        AddVertex(edge[0]);
        AddVertex(edge[1]);
        AddEdge(edge[0], edge[1]);
    }
}

int GraphAdjList::Size() const
{
    return adjList.size();
}

void GraphAdjList::Remove(std::vector<Vertex *> &vec, Vertex *vet)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] = vet)
        {
            vec.erase(vec.begin() + i);
            break;
        }
    }
}

void GraphAdjList::AddEdge(Vertex *vet1, Vertex *vet2)
{
    if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
    {
        throw std::out_of_range("顶点不存在");
    }
    adjList[vet1].push_back(vet2);
    adjList[vet2].push_back(vet1);
}

void GraphAdjList::RemoveEdge(Vertex *vet1, Vertex *vet2)
{
    if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
    {
        throw std::out_of_range("顶点不存在");
    }
    Remove(adjList[vet1], vet2);
    Remove(adjList[vet2], vet1);
}

void GraphAdjList::AddVertex(Vertex *vet)
{
    if (adjList.count(vet))
    {
        return;
    }
    adjList[vet] = std::vector<Vertex *>();
}

void GraphAdjList::RemoveVertex(Vertex *vet)
{
    if (!adjList.count(vet))
    {
        throw std::out_of_range("顶点不存在");
    }
    adjList.erase(vet);
    for (auto &adj : adjList)
    {
        Remove(adj.second, vet);
    }
}

std::vector<Vertex *> GraphBFS(GraphAdjList &graph, Vertex *startVet)
{
    std::vector<Vertex *> res;
    std::unordered_set<Vertex *> visited = {startVet};
    std::queue<Vertex *> que;
    que.push(startVet);
    while (!que.empty())
    {
        Vertex *vet = que.front();
        que.pop();
        res.push_back(vet);
        for (auto adjVet : graph.adjList[vet])
        {
            if (visited.count(adjVet))
            {
                continue;
            }
            que.push(adjVet);
            visited.emplace(adjVet);
        }
    }
    return res;
}

void dfs(GraphAdjList &graph, std::unordered_set<Vertex *> &visited, std::vector<Vertex *> &res, Vertex *vet)
{
    res.push_back(vet);
    visited.emplace(vet);
    for (auto *adjVet : graph.adjList[vet])
    {
        if (visited.count(adjVet))
        {
            continue;
        }
        dfs(graph, visited, res, adjVet);
    }
}

std::vector<Vertex *> GraphDFS(GraphAdjList &graph, Vertex *startVet)
{
    std::vector<Vertex *> res;
    std::unordered_set<Vertex> visited;
    dfs(graph, visited, res, startVet);
    return res;
}
