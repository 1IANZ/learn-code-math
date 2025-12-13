#include "include/graph_adjacency_list.h"

void GraphAdjList::remove(vector<Vertex*>& vec, Vertex* vet) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (*it == vet) {
            vec.erase(it);
            break;
        }
    }
}

vector<int> GraphAdjList::vetsToVals(const vector<Vertex*>& vets) {
    vector<int> vals;
    for (Vertex* vet : vets) {
        vals.push_back(vet->val);
    }
    return vals;
}

void GraphAdjList::printVector(const vector<int>& vec) {
    cout << "[ ";
    for (int v : vec) {
        cout << v << " ";
    }
    cout << "]" << endl;
}

GraphAdjList::GraphAdjList(const vector<vector<Vertex*>>& edges) {
    for (const auto& edge : edges) {
        addVertex(edge[0]);
        addVertex(edge[1]);
        addEdge(edge[0], edge[1]);
    }
}

int GraphAdjList::size() const {
    return adjList.size();
}

void GraphAdjList::addVertex(Vertex* vet) {
    if (adjList.count(vet))
        return;
    adjList[vet] = vector<Vertex*>();
}

void GraphAdjList::removeVertex(Vertex* vet) {
    if (!adjList.count(vet))
        return;

    adjList.erase(vet);

    for (auto& adj : adjList) {
        remove(adj.second, vet);
    }
}

void GraphAdjList::addEdge(Vertex* vet1, Vertex* vet2) {
    if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
        return;

    adjList[vet1].push_back(vet2);
    adjList[vet2].push_back(vet1);
}

void GraphAdjList::removeEdge(Vertex* vet1, Vertex* vet2) {
    if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
        return;

    remove(adjList[vet1], vet2);
    remove(adjList[vet2], vet1);
}

void GraphAdjList::print() {
    cout << "邻接表 =" << endl;
    for (const auto& adj : adjList) {
        cout << adj.first->val << ": ";
        printVector(vetsToVals(adj.second));
    }
}

void GraphAdjList::test() {
    Vertex* v1 = new Vertex(1);
    Vertex* v2 = new Vertex(2);
    Vertex* v3 = new Vertex(3);
    Vertex* v4 = new Vertex(4);

    vector<vector<Vertex*>> edges = {{v1, v2}, {v1, v3}, {v2, v4}, {v3, v4}};

    GraphAdjList graph(edges);
    graph.print();

    cout << "顶点数量: " << graph.size() << endl;

    graph.removeEdge(v1, v2);
    graph.print();

    graph.removeVertex(v3);
    graph.print();
}
