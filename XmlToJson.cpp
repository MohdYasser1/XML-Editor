#include "XmlToJson.h"

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
std::string print_json(const Node* node, int level ) {
    std::string json = "{\n";
    json += jsonFormat(node, level);
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

    return 0;
}*/
