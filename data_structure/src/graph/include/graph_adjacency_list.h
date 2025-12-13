#include <iostream>
#include <unordered_map>
#include <vector>

#include "vertex.h"
using namespace std;

class GraphAdjList {
  private:
    unordered_map<Vertex*, vector<Vertex*>> adjList;
    void remove(vector<Vertex*>& vec, Vertex* vet);
    vector<int> vetsToVals(const vector<Vertex*>& vets);
    void printVector(const vector<int>& vec);

  public:
    GraphAdjList(const vector<vector<Vertex*>>& edges);
    int size() const;
    void addVertex(Vertex* vet);
    void removeVertex(Vertex* vet);
    void addEdge(Vertex* vet1, Vertex* vet2);
    void removeEdge(Vertex* vet1, Vertex* vet2);
    void print();
    static void test();
};
