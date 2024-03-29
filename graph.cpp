#include <iostream>
#include <vector>
#include <fstream>
//#include "parsingXml.cpp"
using namespace std;

class Graph
{
public: string text;
private:
    vector<vector<int>> adjacencyMatrix;
    int numVertices;

public:
    Graph(){}
    // Constructor to initialize the graph with a specific number of vertices
    Graph(int n)
    {
        numVertices = n;
        // Initialize the adjacency matrix with all 0s initially
        adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
    }

    // Function to add an edge to the graph
    void follow(int src, int dest)
    {
        // For undirected graph, mark both src to dest and dest to src as 1
        adjacencyMatrix[src - 1][dest - 1] = 1;
    }

    vector<int> getFollower(int id)
    {
        vector<int> followers;
        for (int i = 0; i < numVertices; i++)
        {
            if (adjacencyMatrix[id - 1][i])
            {
                followers.push_back(i + 1);
            }
        }
        return followers;
    }

    vector<int> getFollowing(int id)
    {
        vector<int> following;
        for (int i = 0; i < numVertices; i++)
        {
            if (adjacencyMatrix[i][id - 1])
            {
                following.push_back(i + 1);
            }
        }
        return following;
    }
    int getNumVertices()
    {
        return numVertices;
    }
    int getMostInfluencerUser(Graph graph)
    {
        int maxFollowers = 0;
        int mostInfluencerUserId = 0;
        for (int i = 1; i <= graph.numVertices; i++)
        {
            int followers = graph.getFollower(i).size();
            if (followers > maxFollowers)
            {
                maxFollowers = followers;
                mostInfluencerUserId = i;
            }
        }
        return mostInfluencerUserId;
    }
    int getMostActiveUser(Graph graph)
    {
        int maxTotal = 0;
        int mostActiveUserId = 0;
        for (int i = 1; i <= graph.numVertices; i++)
        {
            int followingNum = graph.getFollowing(i).size();
            int followersNum = graph.getFollower(i).size();
            int totalNum = followingNum + followersNum;
            for (int followers : graph.getFollower(i))
            {
                for (int following : graph.getFollowing(i))
                {
                    if (followers == following)
                    {
                        totalNum--;
                    }
                }
            }
            if (totalNum > maxTotal)
            {
                maxTotal = totalNum;
                mostActiveUserId = i;
            }
        }
        return mostActiveUserId;
    }
    vector<int> getMutualFollowers(int userId1, int userId2)
    {
        vector<int> mutualFollowers;

        vector<int> followers1 = getFollower(userId1);
        vector<int> followers2 = getFollower(userId2);

        for (int i = 0; i < followers1.size(); i++)
        {
            int follower1 = followers1[i];

            for (int j = 0; j < followers2.size(); j++)
            {
                int follower2 = followers2[j];

                if (follower1 == follower2)
                {
                    mutualFollowers.push_back(follower1);
                    break;
                }
            }
        }

        return mutualFollowers;
    }
    vector<int> suggestUsersToFollow(int userId)
    {
        vector<int> suggestedUsers;

        vector<int> followers = getFollower(userId);

        for (int follower : followers)
        {
            vector<int> followersOfFollower = getFollower(follower);

            for (int i = 0; i < followersOfFollower.size(); ++i)
            {
                int suggestedUser = followersOfFollower[i];
                if (suggestedUser != userId) {
                    bool dub = false;
                    for (int dubFollower : followers) {
                        if (suggestedUser == dubFollower) {
                            dub = true;
                            break;
                        }

                    }

                    if (!dub) {
                        for (int dubFollower : suggestedUsers) {
                            if (suggestedUser == dubFollower) {
                                dub = true;
                                break;
                            }
                        }
                    }
                    if (!dub) suggestedUsers.push_back(suggestedUser);
                }
            }
        }
        return suggestedUsers;
    }

};



class User
{
public:
    int id;
    std::string name;
    std::vector<int> followers;

    void addFollower(int followerId)
    {
        followers.push_back(followerId);
    }
};

void followers_list(Node* node, std::vector<User>& users)
{
    for (const auto& userNode : node->getChildren())
    {
        User user;
        for (const auto& userAttr : userNode->getChildren())
        {
            if (userAttr->getTagName() == "id")
            {
                user.id = std::stoi(userAttr->getTagValue());
            }
            else if (userAttr->getTagName() == "name")
            {
                user.name = userAttr->getTagValue();
            }
            else if (userAttr->getTagName() == "followers")
            {
                for (const auto& follower : userAttr->getChildren())
                {
                    const auto& followerIdNode = follower->getChildren()[0];
                    user.addFollower(std::stoi(followerIdNode->getTagValue()));
                }
            }
        }
        users.push_back(user);
    }
}

Graph buildGraph(string XMLcontent)
{

    Node* node = parseXML(XMLcontent);
    vector<User> users;

    followers_list(node, users);

    Graph SocialNetwork(users.size());
    SocialNetwork.text = XMLcontent; 
    for (int i = 0; i < users.size(); i++)
    {
        for (int j = 0; j < users[i].followers.size(); j++)
        {
            SocialNetwork.follow(users[i].id, users[i].followers[j]);
        }
    }
    return SocialNetwork;
}

void GraphViz(Graph SN)
{
    string fileContents = "digraph Network {\n\n";
    for (int i = 0; i < SN.getNumVertices(); i++)
    {
        vector<int> followers = SN.getFollower(i + 1);
        if (followers.size() > 0)
        {
            fileContents += to_string(i + 1) + " -> {";
        }



        for (int j = 1; j < followers.size(); j++)
        {
            fileContents += to_string(followers[j - 1]) + " ,";
        }
        if (followers.size() > 0) {
            fileContents += to_string(followers[followers.size() - 1]) + "}\n";
        }
    }
    fileContents += "}";
    ofstream GraphVizFile("Network.dot");
    GraphVizFile << fileContents;
    GraphVizFile.close();
    system("dot -Tpng -O Network.dot");
    system("Network.dot.png");
}
Graph globalGraph; 
