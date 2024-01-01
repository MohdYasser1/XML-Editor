#ifndef SOCIAL_NETWORK_H
#define SOCIAL_NETWORK_H

#include <string>
#include <vector>

struct Node {
    std::string TagName;
    std::string TagValue;
    std::vector<Node*> children;
};

class SocialNetwork {
public:
    void pushPostsIntoVector(Node* root);
    std::string searchPosts(const std::string& key);

private:
    std::vector<Node*> posts;

    std::string getPostBody(Node* postNode);
};

#endif  // SOCIAL_NETWORK_H
