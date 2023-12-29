#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <sstream>

using namespace std;

class TagValuePair {
public:
    TagValuePair(const string& tag, const string& value) : tag(tag), value(value) {}

    const string& getTag() const {
        return tag;
    }

    const string& getValue() const {
        return value;
    }

private:
    string tag;
    string value;
};

class Node {

private:
    string tagName;
    string tagValue;
    vector<Node*> children;
    Node* parent = nullptr;

public:
    Node(const string& tagName, const string& tagValue = "") : tagName(tagName), tagValue(tagValue) {}

    const string& getTagName() const {
        return tagName;
    }

    const string& getTagValue() const {
        return tagValue;
    }

    void setTagValue(const string& value) {
        tagValue = value;
    }

    void addChild(Node* child) {
        children.push_back(child);
    }

    const vector<Node*>& getChildren() const {
        return children;
    }

    void setParent(Node* parent) {
        this->parent = parent;
    }

    Node* getParent() const {
        return parent;
    }

    int getDepth() const {
        int depth = 0;
        const Node* current = this;
        while (current->getParent() != nullptr) {
            current = current->getParent();
            ++depth;
        }
        return depth;
    }
};
//defining function used
string extractTagName(const string& line);
string extractTagValue(const std::string& line, const std::string& tagName);
string printTree(const Node* node, int level);
Node* parseXML(const std::string& xml);
