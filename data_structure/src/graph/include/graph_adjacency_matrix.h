#include <iostream>
#include <vector>
using namespace std;
class GraphAdjmat {
  private:
    vector<int> vertices;       // 顶点列表，元素代表“顶点值”，索引代表“顶点索引”
    vector<vector<int>> adjMat; // 邻接矩阵，行列索引对应“顶点索引”
    void printVector(const vector<int>& vec);
    void printVectorMatrix(const vector<vector<int>>& mat);

  public:
    GraphAdjmat(const vector<int>& vertices, const vector<vector<int>>& edges);
    int size() const;
    void addVertex(int value);
    void removeVertex(int index);
    void addEdge(int i, int j);
    void removeEdge(int i, int j);
    void print();
    static void test();
};
