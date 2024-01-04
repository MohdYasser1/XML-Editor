#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include "utils.cpp"
#include "XmlToJson.cpp"
#include "jsonprettifier_jsonminifier.cpp"
#include "huffman.cpp"
#include "json2XML.cpp"
#include "xmlprettifier.cpp"

using namespace std;

string keyCompression(string file){
    /**
     * This function performs key compression to the given JSON file.
     * It makes a vector of strings containing non-duplicate field names and ecnoding the field name to the index 
     * 
     * @param file JSON file to perform key compression after converting it to string
     * @return a string containing the compressed file added to it the keys a the end
     */

    int file_length = file.length();
    vector<string> keys;

    for(int i = 1; i < file_length; i++){
        bool found = false; // A flag to check if there is a dublicate of the field name
        // Find begining of field name
        file_length = file.length();
        if(file[i] == '"' && file[i+1] == ':'){
            // Find word length
            int j = i-1;
            int field_name_length = 0; 
            while(file[j] != '"'){
                field_name_length++;
                j--;
            }
            // Get field name
            string field_name = file.substr(j+1, field_name_length);

            // Check if field name already exists
            for(int k = 0; k < keys.size(); k++){
                if(keys[k] == field_name){
                    file.replace(j+1, field_name_length, to_string(k));
                    i-=(field_name_length-to_string(k).length());
                    found = true;        
                }
            }
            if (found == false){
                keys.push_back(field_name);
                //Replace the field name with the index
                file.replace(j+1, field_name_length, to_string(keys.size()-1));
                i-=(field_name_length-to_string(keys.size()-1).length());
            }
        }
    }
    // Add the keys to the end of file
    string keys_to_file = "#"; // A special character that signals the beginning of the keys
    for (int i = 0; i < keys.size()-1; i++)
    {
        keys_to_file += (keys[i]+',');
    }
    keys_to_file += keys[keys.size()-1];
    file += keys_to_file;
     
    return file;
}

void huffmanCoding(string file_content){ //Do we name the compressed file by its name?
    huffman h(file_content, "CompressedXML.huf");
    h.create_pq();
    h.create_huffman_tree();
    h.calculate_huffman_codes();
    h.coding_save();
}
string keyDecompress(string file){
    /**
     * This function reverses the actions done in keyCompress funtion by getting the keys from the file
     * and placing the field names in its place
     * 
     * @param file This compressed file
     * @return the decompressed files
     */

    //Get field names in a vector
    vector<string> keys;
    int i = file.length() - 1;
    int j;
    while(file[i] != '#'){
        int field_name_length = 0;
        j = i;
        while(file[j] != ',' && file[j] != '#'){
            field_name_length++;
            j--;
        }
        if(file[j] == '#'){
            keys.push_back(file.substr(j+1, field_name_length));
            break;
        }
        i=j-1;
        keys.push_back(file.substr(j+1, field_name_length));
    }
    file = file.substr(0, j);
    keys = reverseVectorString(keys);    
    for(int i = 1; i < file.length(); i++){
        // cout << file[i] << endl;    
        if(file[i] == '"' && file[i+1] == ':'){
            int num_length = 0;
            int k=i;
            while(file[k-1] !='"'){
                num_length++;
                k--;
            }
        if (k >= 0) {
            string numStr = file.substr(k, num_length);
            // cout << numStr << endl;
            // if (!numStr.empty() && numStr.find_first_not_of("0123456789") == string::npos) {

                int num = stoi(numStr);
                // if (num >= 0 && static_cast<size_t>(num) < keys.size()) {
                std::string field_name = keys[num];
                file.replace(k, num_length, field_name);
                // cout << num_length << endl;
                i += (field_name.length() - num_length);
                // }
            // }
        }
            
        }
    }
    return file;
}

//We need to select the files
string huffmanDecoding(string file_name){
    huffman h(file_name);
    h.recreate_huffman_tree();
    return h.decoding_save();
}


//OLD XML 2 JSON Functions
class SString {
public:
    static vector<string> stringToList(string str, char sep = ' ', bool greedy = true);
 
    static string insert_taps(int level);
};
string insert_tapsOLD(int level) {
    string taps = "";
    for (int i = 0; i < level; i++) {
        taps += "\t";
    }
    return taps;
}
std::string jsonFormatOLD(const Node* node, int level) {
    std::string result;

    if (!node->getChildren().empty()) {
        bool hasSameTagName = false;
        for (size_t i = 1; i < node->getChildren().size(); ++i) {
            if (node->getChildren()[i]->getTagName() == node->getChildren()[0]->getTagName()) {
                hasSameTagName = true;
                break;
            }
        }

        result += insert_tapsOLD(level) + "\"" + node->getTagName() + "\" : ";
        if (hasSameTagName) {
            result += "[\n";
            for (size_t i = 0; i < node->getChildren().size(); ++i) {
                if (i != 0) {
                    result += "\n";
                }

                const Node* child = node->getChildren()[i];
                result += jsonFormatOLD(child, level + 1);
            }
            result += "\n" + insert_tapsOLD(level) + "]";
        } else {
            result += "{\n";
            for (size_t i = 0; i < node->getChildren().size(); ++i) {
                if (i != 0) {
                    result += "\n";
                }

                const Node* child = node->getChildren()[i];
                result += jsonFormatOLD(child, level + 1);
            }
            result += "\n" + insert_tapsOLD(level) + "}";
        }
    } else {
        result += insert_tapsOLD(level) + "\"" + node->getTagName() + "\" : ";
        result += "\"" + node->getTagValue() + "\" , ";
    }

    return result;
}
std::string print_jsonOLD(const Node* node, int level ) {
    std::string json = "{\n";
    json += jsonFormatOLD(node, level);
    json += "\n}\n";
    return json;
}

string XML_2_JsonOLD(string XMLcontent){
    Node* root = parseXML(XMLcontent);
    string jsonString = print_jsonOLD(root, 0);
    return jsonString;
}
