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

class SString {
public:
    static vector<string> stringToList(string str, char sep = ' ', bool greedy = true);
 
    static string insert_taps(int level);
};

string extractTagName(const string& line);
string extractTagValue(const std::string& line, const std::string& tagName);
void printTree(const Node* node, int level);
Node* parseXML(const std::string& xml);
std::string jsonFormat(const Node* node, int level);

Node* parseXML(const std::string& xml) {
    Node* root = nullptr;
    Node* currentNode = nullptr;
    string currentText;
    istringstream iss(xml);

    string line;
    while (std::getline(iss, line)) {
        if (line.find('<') != std::string::npos) {
            string tagName = extractTagName(line);
            if (tagName[0] == '/') {
                currentNode->setTagValue(currentText);
                currentNode = currentNode->getParent();
            } else {
                if (line.find("</") != std::string::npos) {
                    string tagValue = extractTagValue(line, tagName);
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

std::string extractTagName(const std::string& line) {
    std::regex pattern("<(.*?)>");
    std::smatch matcher;
    if (std::regex_search(line, matcher, pattern)) {
        return matcher[1];
    }
    return "";
}

string extractTagValue(const std::string& line, const std::string& tagName) {
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

string insert_taps(int level) {
    string taps = "";
    for (int i = 0; i < level; i++) {
        taps += "\t";
    }
    return taps;
}
std::string jsonFormat(const Node* node, int level) {
    std::string result;

    if (!node->getChildren().empty()) {
        bool hasSameTagName = false;
        for (size_t i = 1; i < node->getChildren().size(); ++i) {
            if (node->getChildren()[i]->getTagName() == node->getChildren()[0]->getTagName()) {
                hasSameTagName = true;
                break;
            }
        }

        result += insert_taps(level) + "\"" + node->getTagName() + "\" : ";
        if (hasSameTagName) {
            result += "[\n";
            for (size_t i = 0; i < node->getChildren().size(); ++i) {
                if (i != 0) {
                    result += "\n";
                }

                const Node* child = node->getChildren()[i];
                result += jsonFormat(child, level + 1);
            }
            result += "\n" + insert_taps(level) + "]";
        } else {
            result += "{\n";
            for (size_t i = 0; i < node->getChildren().size(); ++i) {
                if (i != 0) {
                    result += "\n";
                }

                const Node* child = node->getChildren()[i];
                result += jsonFormat(child, level + 1);
            }
            result += "\n" + insert_taps(level) + "}";
        }
    } else {
        result += insert_taps(level) + "\"" + node->getTagName() + "\" : ";
        result += "\"" + node->getTagValue() + "\" , ";
    }

    return result;
}
//for testing
/*int main() {
    // Example XML data
    string xmlData = R"(
        <users>
            <user>
                <id>1</id>
                <name>Ahmed Ali</name>
                <posts>
                    <post>
                        <body> Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. </body>
                        <topics>
                            <topic> economy </topic>
                            <topic> finance </topic>
                        </topics>
                    </post>
                    <post>
                        <body> Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. </body>
                        <topics>
                            <topic> solar_energy </topic>
                        </topics>
                    </post>
                </posts>
                <followers>
                    <follower>
                        <id>2</id>
                    </follower>
                    <follower>
                        <id>3</id>
                    </follower>
                </followers>
            </user>
            <user>
                <id>2</id>
                <name>Yasser Ahmed</name>
                <posts>
                    <post>
                        <body> Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. </body>
                        <topics>
                            <topic> education </topic>
                        </topics>
                    </post>
                </posts>
                <followers>
                    <follower>
                        <id>1</id>
                    </follower>
                </followers>
            </user>
            <user>
                <id>3</id>
                <name>Mohamed Sherif</name>
                <posts>
                    <post>
                        <body> Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. </body>
                        <topics>
                            <topic> sports </topic>
                        </topics>
                    </post>
                </posts>
                <followers>
                    <follower>
                        <id>1</id>
                    </follower>
                </followers>
            </user>
        </users>
    )";

    // Parse XML
    Node* root = parseXML(xmlData);

    // Convert XML to JSON
    string jsonOutput = jsonFormat(root, 0);

    // Output JSON to console
    cout << jsonOutput << endl;

    // Clean up memory (Implement a function to delete the XML tree nodes)

    return 0;
}*/
