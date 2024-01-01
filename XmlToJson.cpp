#include "XmlToJson.h"

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

std::string jsonFormat(const Node* node, int level, int& flag) {
    std::string result;
    std::string indent(level, ' ');
    
    if (flag==true)  {      
    result += indent + "\"" + node->getTagName() + "\" :  ";
    }
    
 if (node->getChildren().size() == 0) {
       flag = true;
       //result+=indent;
        result += "\"" + node->getTagValue() + "\" , ";
        
    
    } else if (node->getChildren().size() == 1) {
       
        result+="{\n";
        const Node* child = node->getChildren()[0];
        flag = true;
        result += indent+jsonFormat(child, level + 1, flag);
       result+="\n"+ indent+ "},";
    
    }
    else {
        if(node->getChildren().size()>1){
        bool hasSameTagName = false;
        for (size_t i = 1; i < node->getChildren().size(); ++i) {
            if (node->getChildren()[i]->getTagName() == node->getChildren()[0]->getTagName()) {
                hasSameTagName = true;

                result += "{\n";
                result += indent+" \"" + node->getChildren()[0]->getTagName() + "\" : ";
                result += "[\n";
                flag = false;
                break;
            }
        }

        if (hasSameTagName) {
            
            for (size_t i = 0; i < node->getChildren().size(); ++i) {
                if (i != 0) {
                    result += "\n";
                }

                const Node* child = node->getChildren()[i];
                flag=false;
                result +=indent+ jsonFormat(child, level + 1, flag);
            }
       
            result += "\n" + indent + " ]";
             result += indent+"\n }";
        } else {
         result += "{\n";
          
            for (size_t i = 0; i < node->getChildren().size(); ++i) {
                if (i != 0) {
                    result += "\n";
                }

                const Node* child = node->getChildren()[i];
                flag = true;
                result +=indent+ jsonFormat(child, level + 1, flag);
            }
            result += "\n" + indent + "}";
        }
    }
    }
    return result;
}
std::string print_json(const Node* node, int level = 0) {
    std::string json = "{\n";
    int flag = 1; // added a flag variable
    json += jsonFormat(node, level, flag);
    json += "\n}\n";
    return json;
}
string XML_2_Json(string XMLcontent){
    Node* root = parseXML(XMLcontent);
    string jsonString = print_json(root, 0);
    return jsonString;
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

   std::string jsonString = print_json(root);
   std::cout << jsonString << std::endl;
 
    // Clean up memory (Implement a function to delete the XML tree nodes)
  delete root;
    return 0;
}*/
