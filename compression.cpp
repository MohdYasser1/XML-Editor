#include <stdio.h>
#include <string>
#include <vector>

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
                    found = true;        
                }
            }
            if (found == false){
                keys.push_back(field_name);
                //Replace the field name with the index
                file.replace(j+1, field_name_length, to_string(keys.size()-1));
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

string compress(string file){
    /**
     * This function compresses the given JSON file after converting it to a string
     * There are 3 steps to the compression:
     * 1. Minify the JSON file
     * 2. Use Key-Compression to compress the field names
     * 3. Use Huffman-encoding to compress the final output
     * 
     * @param file JSON file to be compressed after converting it to a string
     * @return a string containing the compressed file contents to be made into a txt-file
     */

    // TODO: Implement Key-Compression
    string compressedFile;
    compressedFile = keyCompression(file);
    // TODO: Implement Huffman-encoding

    return compressedFile;
}

string decompress(string compressed_file){
    /**
     * This function decompresses the compressed doing the inverse of the compress function.
     * 
     * @param compressed_file the compressed file to be decompressed after converting it to a string
     * @return a string containing the decompressed file contents to be made into a XML-file
     */

    // TODO: Decompress the file

    return compressed_file;
}