#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjacencyMatrix;
    int numVertices;

public:
    // Constructor to initialize the graph with a specific number of vertices
    Graph(int n){
        numVertices = n;
        // Initialize the adjacency matrix with all 0s initially
        adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest) {
        // For undirected graph, mark both src to dest and dest to src as 1
        adjacencyMatrix[src][dest] = 1;
    }
};