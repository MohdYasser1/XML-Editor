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
    void follow(int src, int dest) {
        // For undirected graph, mark both src to dest and dest to src as 1
        adjacencyMatrix[src-1][dest-1] = 1;
    }

    vector<int> getFollowing(int id){
        vector<int> following;
        for (int i = 0; i < numVertices; i++)
        {
            if (adjacencyMatrix[id-1][i])
            {
                following.push_back(i+1);
            }     
        }   
    }

    vector<int> getFollowers(int id){
        vector<int> followers;
        for (int i = 0; i < numVertices; i++)
        {
            if (adjacencyMatrix[i][id-1])
            {
                followers.push_back(i+1);
            }  
        }   
    }
};