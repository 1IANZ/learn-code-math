#include "include/graph_traversal.h"

#include <queue>
#include <unordered_set>
using namespace std;
vector<Vertex*> graphBFS(GraphAdjList& graph, Vertex* startVet) {
    vector<Vertex*> res;
    unordered_set<Vertex*> visited;
    visited.insert(startVet);
    queue<Vertex*> que;
    que.push(startVet);

    while (!que.empty()) {
        Vertex* vet = que.front();
        que.pop();
        res.push_back(vet);

        for (Vertex* adjVet : graph.getNeighbors(vet)) {
            if (!visited.count(adjVet)) {
                visited.insert(adjVet);
                que.push(adjVet);
            }
        }
    }
    return res;
}
void dfs(GraphAdjList& graph, Vertex* vet, unordered_set<Vertex*>& visited, vector<Vertex*>& res) {
    visited.insert(vet);
    res.push_back(vet);

    for (Vertex* adjVet : graph.getNeighbors(vet)) {
        if (!visited.count(adjVet)) {
            dfs(graph, adjVet, visited, res);
        }
    }
}
vector<Vertex*> graphDFS(GraphAdjList& graph, Vertex* startVet) {
    vector<Vertex*> res;
    unordered_set<Vertex*> visited;

    dfs(graph, startVet, visited, res);
    return res;
}

void printTraversal(const string& name, const vector<Vertex*>& res) {
    cout << name << " = [ ";
    for (Vertex* v : res) {
        cout << v->val << " ";
    }
    cout << "]" << endl;
}

void graphTest() {
    Vertex* v1 = new Vertex(1);
    Vertex* v2 = new Vertex(2);
    Vertex* v3 = new Vertex(3);
    Vertex* v4 = new Vertex(4);
    Vertex* v5 = new Vertex(5);

    vector<vector<Vertex*>> edges = {{v1, v2}, {v1, v3}, {v2, v4}, {v3, v4}, {v4, v5}};

    GraphAdjList graph(edges);

    cout << "=== 邻接表 ===" << endl;
    graph.print();

    cout << endl << "=== BFS 从 1 开始 ===" << endl;
    vector<Vertex*> bfsRes = graphBFS(graph, v1);
    printTraversal("BFS", bfsRes);

    cout << endl << "=== DFS 从 1 开始 ===" << endl;
    vector<Vertex*> dfsRes = graphDFS(graph, v1);
    printTraversal("DFS", dfsRes);
}
