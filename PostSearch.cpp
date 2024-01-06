#include "PostSearch.h"


using namespace std;

vector<Node*> pushPostsIntoVector(Node* root) {
    vector<Node*> posts;
    for (Node* user : root->getChildren()) {
        if (user == nullptr) throw invalid_argument("Not a valid Social network tree");
        for (Node* userTag : user->getChildren()) {
            if (userTag == nullptr) throw invalid_argument("Not a valid Social network tree");
            if (userTag->getTagName() == "posts") {
                for (Node* postNode : userTag->getChildren()) {
                    if (postNode == nullptr) throw invalid_argument("Not a valid Social network tree");
                    if (postNode->getTagName() == "post") {
                        posts.push_back(postNode);
                    }
                }
            }
        }
    }
    return posts;
}

string getPostBody(Node* postNode) {
    for (Node* child : postNode->getChildren()) {
        if (child == nullptr) throw invalid_argument("Not a valid Social network tree");
        if (child->getTagName() == "body") {
            return child->getTagValue();
        }
    }
    return "";
}

string searchPosts(string XMLContent, const string& key) {
    Node* root = parseXML(XMLContent);
    vector<Node*> posts = pushPostsIntoVector(root);
    string postsBodies = "";
    int counter = 1;
    for (Node* postNode : posts) {
        for (Node* child : postNode->getChildren()) {
            if (child->getTagName() == "topics") {
                for (Node* topicNode : child->getChildren()) {
                    if (topicNode->getTagValue().find(key) != string::npos) {
                        postsBodies += "Post number: " + to_string(counter++) + getPostBody(postNode) + "\n";
                        break;
                    }
                }
            }
            else if (child->getTagName() == "body" && child->getTagValue().find(key) != string::npos) {
                postsBodies += "Post number: " + to_string(counter++) + child->getTagValue() + "\n";
                break;
            }
        }
    }
    return postsBodies;
}
