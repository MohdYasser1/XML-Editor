#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
using namespace std;
struct Node {

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


};

class TagValuePair {
private:
    std::string tag;
    std::string value;

public:
    TagValuePair(const std::string& tag, const std::string& value) : tag(tag), value(value) {}

    const std::string& getTag() const {
        return tag;
    }

    const std::string& getValue() const {
        return value;
    }


};

void printTree(const Node* node, int level);
Node* parseXML(const std::string& xml);
string extractTagName(const std::string& line);
string extractTagValue(const std::string& line, const std::string& tagName);





Node* parseXML(const std::string& xml) {
    Node* root = nullptr;
    Node* currentNode = nullptr;
    std::string currentText;
    std::istringstream iss(xml);

    std::string line;
    while (std::getline(iss, line)) {
        if (line.find('<') != std::string::npos) {
            std::string tagName = extractTagName(line);
            if (tagName[0] == '/') {
                currentNode->setTagValue(currentText);
                currentNode = currentNode->getParent();
            } else {
                if (line.find("</") != std::string::npos) {
                    std::string tagValue = extractTagValue(line, tagName);
                    Node* newNode = new Node(tagName, tagValue);
                    if (currentNode != nullptr) {
                        currentNode->addChild(newNode);
                    } else {
                        root = newNode;
                    }
                } else {
                    if (line.find('>') != std::string::npos) {
                        std::string tagValue = extractTagValue(line, tagName);
                        Node* newNode = new Node(tagName, tagValue);
                        newNode->setParent(currentNode);
                        if (currentNode != nullptr) {
                            currentNode->addChild(newNode);
                        } else {
                            root = newNode;
                        }
                        currentNode = newNode;
                    } else {
                        Node* newNode = new Node(tagName);
                        newNode->setParent(currentNode);
                        if (currentNode != nullptr) {
                            currentNode->addChild(newNode);
                        } else {
                            root = newNode;
                        }
                        currentNode = newNode;
                    }
                }
            }
            currentText.clear();
        } else {
            currentText += line;
        }
    }

    return root;
}

 string extractTagName(const std::string& line) {
    std::regex pattern("<(.*?)>");
    std::smatch matcher;
    if (std::regex_search(line, matcher, pattern)) {
        return matcher[1];
    }
    return "";
}

std::string extractTagValue(const std::string& line, const std::string& tagName) {
    std::regex pattern("<" + tagName + ">(.*?)<\\/" + tagName + ">");
    std::smatch matcher;
    if (std::regex_search(line, matcher, pattern)) {
        return matcher[1];
    }
    return "";
}

void printTree(const Node* node, int level) {
    std::string indent(level, ' ');
    std::cout << indent << "Tag: " << node->getTagName() << ", Value: " << node->getTagValue() << std::endl;

    for (const auto& child : node->getChildren()) {
        printTree(child, level + 1);
    }
}

//test
/*int main() {
    // Sample XML content
    std::string xmlContent = R"(
        <root>
            <person>
                <name>John Doe</name>
                <age>25</age>
            </person>
            <person>
                <name>Jane Doe</name>
                <age>30</age>
            </person>
        </root>
    )";
    // Parse the XML
    Node* root = parseXML(xmlContent);

    // Print the tree structure
    std::cout << "Tree structure:\n";
    printTree(root, 0);
  // Clean up memory
    delete root;

    return 0;
}*/
