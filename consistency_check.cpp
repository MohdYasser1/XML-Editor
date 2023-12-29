#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <fstream>
#include <utility>  // for std::pair

using namespace std;

// Class to represent labels (tags) in XML
class XMLLabel {
public:
    int lineNumber;         // Line number where the label is found
    int insertionPosition;  // Position in the line where the label should be inserted
    std::string name;       // The label itself

public:
    XMLLabel(std::string n, int line, int pos);
};

// Constructor for XMLLabel class
XMLLabel::XMLLabel(std::string n, int line, int pos) : name(n), lineNumber(line), insertionPosition(pos) {}


// Function to read XML content from a file
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

// Function to mark error lines in the XML content
vector<string> markErrorLines(const vector<string>& xmlContent, const vector<pair<int, string>>& errorsFound) {
    vector<string> markedXmlContent = xmlContent;

    // Mark each line with error information
    for (const auto& error : errorsFound) {
        int lineNumber = error.first - 1;  // Adjust to 0-based index
        if (lineNumber >= 0 && lineNumber < markedXmlContent.size()) {
            markedXmlContent[lineNumber] += " <-- " + error.second;
        }
    }

    return markedXmlContent;
}

// Function to check XML content and capture errors
vector<string> checkXML(vector<string>& xmlContent) {
    int currentLine = 0;
    int totalLines = xmlContent.size();
    std::stack<XMLLabel> labelStack;
    vector<pair<int, string>> errorsFound;

    // Loop through each line of the XML file
    while (currentLine < totalLines) {
        string currentLineContent = xmlContent[currentLine];
        int currentCharIndex = 0;

        // Loop through each character in the line
        while (currentLineContent[currentCharIndex] != '\0') {
            // Check if the character is the beginning of a tag
            if (currentLineContent[currentCharIndex] == '<') {
                std::string labelName;
                // Check if it's a closing tag
                if (currentLineContent[currentCharIndex + 1] == '/') {
                    currentCharIndex = currentCharIndex + 2;
                    // Extract the label from the closing tag
                    while (currentLineContent[currentCharIndex - 1] != '>') {
                        labelName.push_back(currentLineContent[currentCharIndex++]);
                    }
                CheckOnLabel:
                    if (!labelStack.empty()) {
                        if (labelName == (labelStack.top()).name) {
                            labelStack.pop(); // Closing tag matches an open tag, pop from stack
                        } else {
                            bool absentOpenTag = 1;
                            std::stack<XMLLabel> tempLabelStack = labelStack;
                            tempLabelStack.pop();
                            while (!(tempLabelStack.empty())) {
                                // Check if the absent tag is a closing one
                                if (labelName == ((tempLabelStack.top()).name)) {
                                    // Correct the absent closing tag
                                    XMLLabel tempLabel = labelStack.top();
                                    labelStack.pop();
                                    tempLabel.name = "</" + tempLabel.name;
                                    errorsFound.push_back({tempLabel.lineNumber + 1, "Closing tag is not found" + tempLabel.name});
                                    absentOpenTag = 0;
                                    goto CheckOnLabel;
                                }
                                tempLabelStack.pop();
                            }
                            if (absentOpenTag == 1) {
                                // Correct the missing opening tag
                                XMLLabel tempLabel = labelStack.top();
                                labelName = "<" + labelName;
                                errorsFound.push_back({currentLine + 1, "Opening tag is not found" + labelName});
                            }
                        }
                    } else {
                        // While the stack is empty, correct the absent opening tags
                        labelName = "<" + labelName;
                        errorsFound.push_back({currentLine + 1, "Opening tag is not found" + labelName});
                    }
                } else {
                    if (currentLineContent[currentCharIndex + 1] != '?') {
                        // Push the opening tag onto the stack with its data
                        XMLLabel *ptr;
                        currentCharIndex = currentCharIndex + 1;
                        while (currentLineContent[currentCharIndex - 1] != '>') {
                            if (currentLineContent[currentCharIndex] == ' ') {
                                labelName.push_back('>');
                                break;
                            }
                            labelName.push_back(currentLineContent[currentCharIndex++]);
                        }

                        labelStack.push(XMLLabel(labelName, currentLine, currentCharIndex));

                    } else {
                        break;
                    }
                }
            } else {
                currentCharIndex++;
            }
        }

        // Increment the line number for the next iteration
        currentLine++;
    }

    // Correcting the absent closing tags in the stack
    while (!(labelStack.empty())) {
        // Correcting the absent closing tags
        std::string tempLabel = (labelStack.top()).name;
        labelStack.pop();
        tempLabel = "</" + tempLabel;
        errorsFound.push_back({currentLine, "Closing tag is not found " + tempLabel});
    }

    return markErrorLines(xmlContent, errorsFound);
}


// Function to correct XML content and capture errors
vector<string> correctXML(const vector<string>& xmlContent) {
    int currentLine = 0;
    int totalLines = xmlContent.size();
    std::stack<XMLLabel> labelStack;

    vector<string> correctedXmlContent = xmlContent;

    // Loop through each line of the XML file
    while (currentLine < totalLines) {
        std::string currentLineContent = correctedXmlContent[currentLine];
        int currentCharIndex = 0;

        // Loop through each character in the line
        while (currentLineContent[currentCharIndex] != '\0') {
            // Check if the character is the beginning of a tag
            if (currentLineContent[currentCharIndex] == '<') {
                std::string labelName;
                // Check if it's a closing tag
                if (currentLineContent[currentCharIndex + 1] == '/') {
                    currentCharIndex = currentCharIndex + 2;
                    // Extract the label from the closing tag
                    while (currentLineContent[currentCharIndex - 1] != '>') {
                        labelName.push_back(currentLineContent[currentCharIndex++]);
                    }
                CheckOnLabel:
                    if (!labelStack.empty()) {
                        if (labelName == (labelStack.top()).name) {
                            labelStack.pop(); // Closing tag matches an open tag, pop from stack
                        } else {
                            bool absentOpenTag = 1;
                            std::stack<XMLLabel> tempLabelStack = labelStack;
                            tempLabelStack.pop();
                            while (!(tempLabelStack.empty())) {
                                // Check if the absent tag is a closing one
                                if (labelName == ((tempLabelStack.top()).name)) {
                                    // Correct the absent closing tag
                                    XMLLabel tempLabel = labelStack.top();
                                    labelStack.pop();
                                    std::string tempLine = correctedXmlContent[tempLabel.lineNumber];
                                    tempLabel.name = "</" + tempLabel.name;
                                    tempLine.insert(tempLabel.insertionPosition, tempLabel.name);
                                    correctedXmlContent[tempLabel.lineNumber] = tempLine;
                                    absentOpenTag = 0;
                                    goto CheckOnLabel;
                                }
                                tempLabelStack.pop();
                            }
                            if (absentOpenTag == 1) {
                                // Correct the missing opening tag
                                XMLLabel tempLabel = labelStack.top();
                                std::string tempLine = correctedXmlContent[tempLabel.lineNumber];
                                labelName = "<" + labelName;
                                tempLine.insert(tempLabel.insertionPosition, labelName);
                                correctedXmlContent[tempLabel.lineNumber] = tempLine;
                            }
                        }
                    } else {
                        // While the stack is empty, correct the absent opening tags
                        std::string tempLine = correctedXmlContent[0];
                        labelName = "<" + labelName;
                        tempLine.insert(0, labelName);
                        correctedXmlContent[0] = tempLine;
                    }
                } else {
                    if (currentLineContent[currentCharIndex + 1] != '?') {
                        // Push the opening tag onto the stack with its data
                        XMLLabel *ptr;
                        currentCharIndex = currentCharIndex + 1;
                        while (currentLineContent[currentCharIndex - 1] != '>') {
                            if (currentLineContent[currentCharIndex] == ' ') {
                                labelName.push_back('>');
                                break;
                            }
                            labelName.push_back(currentLineContent[currentCharIndex++]);
                        }

                        labelStack.push(XMLLabel(labelName, currentLine, currentCharIndex));

                    } else {
                        break;
                    }
                }
            } else {
                currentCharIndex++;
            }
        }

        // Increment the line number for the next iteration
        currentLine++;
    }

    // Correcting the absent closing tags in the stack
    while (!(labelStack.empty())) {
        // Correcting the absent closing tags
        std::string tempLabel = (labelStack.top()).name;
        labelStack.pop();
        tempLabel = "</" + tempLabel;
        correctedXmlContent.push_back(tempLabel);
    }

    return correctedXmlContent;
}


// Main function
int main() {
    // Example usage with reading XML content from a file
    string filename = "sample_test.xml"; // Replace with your XML file name
    vector<string> xmlContent =readXmlFile(filename);


    // Call the function to check XML consistency and capture errors
    vector<string> markedXmlContent = checkXML(xmlContent);

    // Print the marked XML content
    cout << "Original XML with Error Lines Marked:\n";
    for (const auto& line : markedXmlContent) {
        cout << line << endl;
    }

     vector<string> correctedXmlContent = correctXML(xmlContent);

    // Print the corrected XML content
    cout << "Corrected XML content:\n";
    for (const auto& line : correctedXmlContent) {
        cout << line << endl;
    }


    return 0;
}
