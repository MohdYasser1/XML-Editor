#include "PostSearch.h"

void SocialNetwork::pushPostsIntoVector(Node* root) {
    for (Node* user : root->children) {
        if (user == nullptr) throw invalid_argument("Not a valid Social network tree");
        for (Node* userTag : user->children) {
            if (userTag == nullptr) throw invalid_argument("Not a valid Social network tree");
            if (userTag->TagName == "posts") {
                for (Node* postNode : userTag->children) {
                    if (postNode == nullptr) throw invalid_argument("Not a valid Social network tree");
                    if (postNode->TagName == "post") {
                        posts.push_back(postNode);
                    }
                }
            }
        }
    }
}

string SocialNetwork::getPostBody(Node* postNode) {
    for (Node* child : postNode->children) {
        if (child == nullptr) throw invalid_argument("Not a valid Social network tree");
        if (child->TagName == "body") {
            return child->TagValue;
        }
    }
    return "";
}

string SocialNetwork::searchPosts(const string& key) {
    string postsBodies = "";
    int counter = 1;
    for (Node* postNode : posts) {
        for (Node* child : postNode->children) {
            if (child->TagName == "topics") {
                for (Node* topicNode : child->children) {
                    if (topicNode->TagValue.find(key) != string::npos) {
                        postsBodies += "Post number: " + to_string(counter++) + getPostBody(postNode) + "\n";
                        break;
                    }
                }
            }
            else if (child->TagName == "body" && child->TagValue.find(key) != string::npos) {
                postsBodies += "Post number: " + to_string(counter++) + child->TagValue + "\n";
                break;
            }
        }
    }
    return postsBodies;
}
