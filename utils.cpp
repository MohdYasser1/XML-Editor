#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * @brief This file contains functions that may be useful accross the project
 * 
 */

vector<string> reverseVectorString(vector<string> v){
    /**
     * @brief This function is used to reverse the order of a vector of strings
     * 
     * @param v The vector to reverse
     * @return The reverse vector
     */
    stack<string> stack;

    for(int i = 0; i < v.size();i++){

        stack.push(v[i]);
    }
    for(int i = 0; i < v.size(); i++){
        v[i] = stack.top();
        stack.pop();
    }
    return v;

}

vector<string> readXmlFile(const string& inputFile) {
    vector<string> xmlContent;

    // Read XML content from the input file
    ifstream input(inputFile);
    if (!input) {
        cerr << "Error: Unable to open input file." << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(input, line)) {
        xmlContent.push_back(line);
    }

    return xmlContent;
}

//function to read content of an XML file and return as string.
string readFileToString(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return "";
    }

    stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}

vector<string> splitStringByNewline(const string& input) {
    vector<string> lines;
    istringstream iss(input);

    // Split the string by newline character and store each line
    string line;
    while (getline(iss, line)) {
        lines.push_back(line);
    }

    return lines;
}

string newLinesinString(string input) {
    string result;
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == '\n') {
            result += "\r\n";
           
        }
        else {
            result += input[i];
        }
    }
    return result; 
}

string vector2string(vector<string> text){
    string str = "";
    for (int i = 0; i < text.size()-1; i++)
    {
        str += text[i] + "\n";
    }
    str += text[text.size()-1];
    return str;
}
