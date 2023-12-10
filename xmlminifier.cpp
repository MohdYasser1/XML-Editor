#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Function declarations
string minifyFileContent(const vector<string>& fileLines);
void removeLeadingWhitespace(vector<string>& lines);

string xmlMinifier(const string& inputFile) {
    // Read content from the input file
    ifstream input(inputFile);
    if (!input) {
        cerr << "Error: Unable to open input file." << endl;
        return "";
    }

    vector<string> fileContent;
    string line;
    while (getline(input, line)) {
        fileContent.push_back(line);
    }

    // Minify file content
    string minifiedContent = minifyFileContent(fileContent);

    return minifiedContent;
}

// Function to minify a vector of strings representing a file
string minifyFileContent(const vector<string>& fileLines) {
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
