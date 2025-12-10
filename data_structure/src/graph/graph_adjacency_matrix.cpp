#include "include/graph_adjacency_matrix.h"

GraphAdjmat::GraphAdjmat(const vector<int>& vertices, const vector<vector<int>>& edges) {
    for (int value : vertices) {
        addVertex(value);
    }
    for (const vector<int>& edge : edges) {
        addEdge(edge[0], edge[1]);
    }
}
int GraphAdjmat::size() const {
    return vertices.size();
}
void GraphAdjmat::addVertex(int value) {
    int n = size();
    // 向顶点列表中添加新顶点的值
    vertices.push_back(value);
    // 在邻接矩阵中添加一行
    adjMat.emplace_back(vector<int>(n, 0));
    // 在邻接矩阵中添加一列
    for (vector<int>& row : adjMat) {
        row.push_back(0);
    }
}
void GraphAdjmat::removeVertex(int index) {
    if (index >= size()) {
        return;
    }
    // 在顶点列表中移除索引 index 的顶点
    vertices.erase(vertices.begin() + index);
    // 在邻接矩阵中删除索引 index 的行
    adjMat.erase(adjMat.begin() + index);
    // 在邻接矩阵中删除索引 index 的列
    for (vector<int>& row : adjMat) {
        row.erase(row.begin() + index);
    }
}
void GraphAdjmat::addEdge(int i, int j) {
    if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
        return;
    }
    adjMat[i][j] = 1;
    adjMat[j][i] = 1;
}

void GraphAdjmat::removeEdge(int i, int j) {
    if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
        return;
    }
    adjMat[i][j] = 0;
    adjMat[j][i] = 0;
}

void GraphAdjmat::print() {
    cout << "顶点列表 = ";
    printVector(vertices);
    cout << "邻接矩阵 =" << endl;
    printVectorMatrix(adjMat);
}
void GraphAdjmat::printVector(const vector<int>& vec) {
    cout << "[ ";
    for (int x : vec)
        cout << x << " ";
    cout << "]" << endl;
}
void GraphAdjmat::printVectorMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }
}
void GraphAdjmat::test() {
    vector<int> vertices = {10, 20, 30, 40};
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};
    GraphAdjmat graph(vertices, edges);
    cout << "=== 初始无向图 ===" << endl;
    graph.print();
    cout << endl;
    cout << "=== 添加顶点 50 ===" << endl;
    graph.addVertex(50);
    graph.print();
    cout << endl;
    cout << "=== 添加边 0 - 4 (10 - 50) ===" << endl;
    graph.addEdge(0, 4);
    graph.print();
    cout << endl;
    cout << "=== 删除顶点 index = 1 (即顶点值 20) ===" << endl;
    graph.removeVertex(1);
    graph.print();
    cout << endl;
    cout << "=== 删除边 1 - 2 ===" << endl;
    graph.removeEdge(1, 2);
    graph.print();
    cout << endl;
}
