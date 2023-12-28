#include <iostream>
#include <vector>

using namespace std;

// Function declarations
string minifyStringContent(const vector<string>& fileLines);
void removeLeadingWhitespace(vector<string>& lines);

string xmlMinifier(const string& inputString) {
    // Convert the input string into a vector of lines
    vector<string> fileContent;
    size_t start = 0, end;
    while ((end = inputString.find('\n', start)) != string::npos) {
        fileContent.push_back(inputString.substr(start, end - start));
        start = end + 1;
    }
    fileContent.push_back(inputString.substr(start));

    // Minify string content
    string minifiedContent = minifyStringContent(fileContent);

    return minifiedContent;
}

// Function to minify a vector of strings representing a file
string minifyStringContent(const vector<string>& fileLines) {
    // Create a copy of fileLines to avoid modifying the original vector
    vector<string> minifiedLines = fileLines;

    // Remove leading whitespace in each line
    removeLeadingWhitespace(minifiedLines);

    // Concatenate the minified lines into a single string
    string minified = "";
    for (const auto& line : minifiedLines) {
        minified += line;
    }

    // Return the minified string
    return minified;
}

// Function to remove leading tabs and spaces in each line
void removeLeadingWhitespace(vector<string>& lines) {
    for (int i = 0; i < lines.size(); i++) {
        size_t found = lines[i].find_first_not_of("\t ");
        if (found != string::npos) {
            // Erase leading tabs and spaces in the current line
            lines[i].erase(0, found);
        }
    }
}
