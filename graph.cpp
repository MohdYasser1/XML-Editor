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

    vector<int> getFollower(int id){
        vector<int> followers;
        for (int i = 0; i < numVertices; i++)
        {
            if (adjacencyMatrix[id-1][i])
            {
                followers.push_back(i+1);
            }     
        } 
        return followers;  
    }

    vector<int> getFollowing(int id){
        vector<int> following;
        for (int i = 0; i < numVertices; i++)
        {
            if (adjacencyMatrix[i][id-1])
            {
                following.push_back(i+1);
            }  
        }  
        return following; 
    }
};

class User {
public:
    int id;
    std::string name;
    std::vector<int> followers;

    void addFollower(int followerId) {
        followers.push_back(followerId);
    }
};

void followers_list(Node* node, std::vector<User>& users) {
    for (const auto& userNode : node->getChildren()) {
        User user;
        for (const auto& userAttr : userNode->getChildren()) {
            if (userAttr->getTagName() == "id") {
                user.id = std::stoi(userAttr->getTagValue());
            } else if (userAttr->getTagName() == "name") {
                user.name = userAttr->getTagValue();
            } else if (userAttr->getTagName() == "followers") {
                for (const auto& follower : userAttr->getChildren()) {
                    const auto& followerIdNode = follower->getChildren()[0];
                    user.addFollower(std::stoi(followerIdNode->getTagValue()));
                }
            }
        }
        users.push_back(user);
    }
}
