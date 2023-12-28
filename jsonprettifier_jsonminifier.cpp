#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

// Function declarations
void prettifyJsonContent(vector<string>& jsonLines);
void addIndentation(vector<string>& jsonLines, int indentLevel);

string jsonPrettifier(string content) {

    vector<string> jsonContent = splitStringByNewline(content);

    // Prettify JSON content
    prettifyJsonContent(jsonContent);

    // Concatenate the prettified lines into a single string
    stringstream ss;
    for (const auto& line : jsonContent) {
        ss << line << endl;
    }

    // Return the prettified JSON string
    return ss.str();
}

void prettifyJsonContent(vector<string>& jsonLines) {
    vector<string> prettifiedLines;
    int indentLevel = 0;

    for (const auto& line : jsonLines) {
        for (char ch : line) {
            if (ch == '{' || ch == '[') {
                prettifiedLines.push_back(string(4 * indentLevel, ' ') + ch);
                indentLevel++;
            } else if (ch == '}' || ch == ']') {
                indentLevel--;
                prettifiedLines.push_back(string(4 * indentLevel, ' ') + ch);
            } else {
                prettifiedLines.back().push_back(ch);
            }
        }
    }

    jsonLines = prettifiedLines;
}

string jsonMinifier(const string& input) {

    string line;
    istringstream iss(input);

    string jsonContent;
    while (getline(iss, line)) {
        jsonContent += line;
    }

    // Remove whitespaces and newlines from JSON content
    stringstream ss;
    for (char ch : jsonContent) {
        if (!isspace(ch)) {
            ss << ch;
        }
    }

    // Return the minified JSON string
    return ss.str();
}
