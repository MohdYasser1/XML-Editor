#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

struct huffman_node{
    /**
     * @brief A huffman node
     * 
     */
    char id;
    int freq;
    string code;
    huffman_node* left;
    huffman_node* right;
    huffman_node(){
        //Constructor
        left = right = NULL;
    }
};
typedef huffman_node* node_ptr;

class huffman{
protected:
    node_ptr node_array[128];
    string input;
    string out_file_name, decoded_file_name;
    string decoded_text = "";
    fstream out_file;
    fstream decoded_file;
    node_ptr child, parent, root;
    char id;
    class compare{
    public:
        bool operator()(const node_ptr& c1, const node_ptr& c2) const{
            return c1->freq > c2->freq;
        }
    };
    priority_queue<node_ptr, vector<node_ptr>, compare> pq;

    void create_node_array(){
        for(int i=0; i< 128; i++){
            node_array[i] = new huffman_node;
            node_array[i]->id = i;
            node_array[i]->freq = 0;
        }
    }
    void traverse(node_ptr node, string code){
        if(node->left == NULL && node->right == NULL){
            node->code = code;
        }
        else{
            traverse(node->left, code + '0');
            traverse(node->right, code + '1');
        }
    }
    int binary_to_decimal(const string& in){
        int result = 0;
        for(int i = 0; i < in.size(); i++){
            result = result * 2 + in[i] - '0';
        }
        return result;
    }
    string decimal_to_binary(int in){
        string temp = "";
        string result = "";
        while (in){
            temp += ('0' + in % 2);
            in /= 2;
        }
        result.append(8 - temp.size(), '0');
        for(int i = temp.size() - 1; i >= 0; i--){
            result += temp[i];
        }
        return result;
    }
    inline void build_tree(string& path, char a_code){
        //build a new brach according to the input code and ignore the already existing branchs
        node_ptr current = root;
        for(int i = 0; i < path.size(); i++){
            if(path[i] == '0'){
                if(current->left == NULL){
                    current->left = new huffman_node;
                }
                current = current->left;
            }
            else if (path[i] == '1'){
                if(current->right == NULL){
                    current->right = new huffman_node;
                }
                current = current->right;
            }
        }
        current->id = a_code;
    }
public:
    huffman(string json_string, string out){
        input = json_string;
        out_file_name = out;
        create_node_array();
    }
    //A contructor to decode
    huffman(string file_name){
        decoded_file_name = file_name;
        create_node_array();
    }
    void create_pq() {
    // Reset frequency counts in node_array to zero
    string file_contents = input;
    for (int i = 0; i < 128; ++i) {
        node_array[i]->freq = 0;
    }

    for (char id : file_contents) {
        node_array[id]->freq++;
    }

    // Clear the existing priority queue
    while (!pq.empty()) {
        pq.pop();
    }

    // Create priority queue
    for (int i = 0; i < 128; ++i) {
        if (node_array[i]->freq > 0) {
            pq.push(node_array[i]);
        }
    }
    }
    void create_huffman_tree(){
        priority_queue<node_ptr, vector<node_ptr>, compare> temp(pq);
        while (temp.size() > 1){
            //create the huffman tree with highest frequecy characher being leaf from bottom to top
            root = new huffman_node;
            root->freq = 0;
            root->left = temp.top();
            root->freq += temp.top()->freq;
            temp.pop();
            root->right = temp.top();
            root->freq += temp.top()->freq;
            temp.pop();
            temp.push(root);
        }
    }
    void calculate_huffman_codes(){
        traverse(root, "");
    }
    void coding_save(){
        out_file.open(out_file_name, ios::out | ios::binary);
        string in = "", s = "";

        in += (char)pq.size();
        priority_queue<node_ptr, vector<node_ptr>, compare> temp(pq);
        while (!temp.empty()){
            //get all characters and their huffman codes for output
            node_ptr current = temp.top();
            in += current->id;
            s.assign(127 - current->code.size(), '0');
            s += '1';
            s.append(current->code);

            in += (char) binary_to_decimal(s.substr(0, 8));
            for(int i = 0; i < 15; i++){
                //cut into 8-bit binary codes that can convert into saving char needed for binary file
                s = s.substr(8);
                in += (char) binary_to_decimal(s.substr(0, 8));
            }
            temp.pop();
        }
        s.clear();
        for (char id: input){
            s += node_array[id]->code;
            while(s.size() >= 8){
                in+= (char) binary_to_decimal(s.substr(0,8));
                s = s.substr(8);
            }
        }

        int count = 8 - s.size();
        if(s.size() < 8){
            s.append(count, '0');
        }
        in += (char) binary_to_decimal(s);
        in+= (char) count;

        cout << "File name: " << out_file_name << endl;
        cout << "Data to write: " << in << endl;

        out_file.write(in.c_str(), in.size());
        // Check for errors in file write operation
        if (out_file.fail()) {
         cout << "Error writing to file!" << endl;
        } else {
           cout << "Data successfully written to file." << endl;
        }
        out_file.close();
    }
    void recreate_huffman_tree(){
        unsigned int size = 0;
        decoded_file.open(decoded_file_name, ios::in | ios::binary);
        decoded_file.read(reinterpret_cast<char*>(&size), 1);
        root = new huffman_node;
        for(int i = 0; i < size; i++){
            char a_code;
            unsigned char h_code_c[16] = {};
            decoded_file.read(&a_code, 1);
            decoded_file.read(reinterpret_cast<char*>(h_code_c), 16);
            string h_code_s = "";
            for(int k = 0; k < 16; k++){
                //obtain the original 128-bit binary string
                h_code_s += decimal_to_binary(h_code_c[k]);
            }
            int j = 0;
            while (h_code_s[j] == '0'){
                //delete the added '000¡­¡­1' to get the real huffman code
                j++;
            }
            h_code_s = h_code_s.substr(j + 1);
            build_tree(h_code_s, a_code);
        }
        decoded_file.close();
    }
    string decoding_save(){
        decoded_file.open(decoded_file_name, ios::in | ios::binary);
        unsigned char size;
        decoded_file.read(reinterpret_cast<char*>(&size), 1);
        decoded_file.seekg(-1, ios::end);
        char count0;
        decoded_file.read(&count0, 1);
        decoded_file.seekg(1 + 17 * size, ios::beg);

        vector<unsigned char> text((istreambuf_iterator<char>(decoded_file)), {});

        node_ptr current = root;
        string path;
        for (int i = 0; i < text.size() - 1; i++) {
            path = decimal_to_binary(text[i]);
            if (i == text.size() - 2)
                path = path.substr(0, 8 - count0);
            for (char bit : path) {
                if (bit == '0')
                    current = current->left;
                else
                    current = current->right;
                if (current->left == nullptr && current->right == nullptr) {
                    decoded_text += current->id;
                    current = root;
                }
            }
        }

        decoded_file.close();
        return decoded_text;
    }
};