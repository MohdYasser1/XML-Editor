#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <fstream>

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

// Function to correct XML content and capture errors
std::vector<std::string> correctXML(std::vector<std::string>& xmlContent, std::vector<std::string>& errorsFound) {
    int currentLine = 0;
    int totalLines = xmlContent.size();
    std::vector<std::string> discoveredMistakes;
    std::string currentLineContent;
    std::stack<XMLLabel> labelStack;

    std::vector<std::string> correctedXmlContent;

    // Loop through each line of the XML file
    while (currentLine < totalLines) {
        currentLineContent = xmlContent[currentLine];
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
                                    std::string tempLine = xmlContent[tempLabel.lineNumber];
                                    tempLabel.name = "</" + tempLabel.name;
                                    tempLine.insert(tempLabel.insertionPosition, tempLabel.name);
                                    xmlContent[tempLabel.lineNumber] = tempLine;

                                    // Save the error message
                                    discoveredMistakes.push_back("Line " + to_string(tempLabel.lineNumber + 1) +
                                                                   ": Closing tag is not found" + tempLabel.name + "\r\n");
                                    absentOpenTag = 0;
                                    goto CheckOnLabel;
                                }
                                tempLabelStack.pop();
                            }
                            if (absentOpenTag == 1) {
                                // Correct the missing opening tag
                                XMLLabel tempLabel = labelStack.top();
                                std::string tempLine = xmlContent[tempLabel.lineNumber];
                                labelName = "<" + labelName;
                                tempLine.insert(tempLabel.insertionPosition, labelName);
                                xmlContent[tempLabel.lineNumber] = tempLine;

                                // Save the error message
                                discoveredMistakes.push_back("Line " + to_string(currentLine + 1) +
                                                               ": Opening tag is not found" + labelName + "\r\n");
                            }
                        }
                    } else {
                        // While the stack is empty, correct the absent opening tags
                        std::string tempLine = xmlContent[0];
                        labelName = "<" + labelName;
                        tempLine.insert(0, labelName);
                        xmlContent[0] = tempLine;

                        // Save the error message
                        discoveredMistakes.push_back("Line " + to_string(currentLine + 1) +
                                                       ": Opening tag is not found" + labelName + "\r\n");
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
        xmlContent.push_back(tempLabel);

        // Save the error message
        discoveredMistakes.push_back("Line " + to_string(currentLine) +
                                       ": Closing tag is not found " + tempLabel + "\r\n");
    }

    // Create corrected XML content in the new vector
    currentLine = 0;  // Reset line number
    for (const auto& line : xmlContent) {
        correctedXmlContent.push_back(line);
        currentLine++;
    }

    // Save errors found
    errorsFound = discoveredMistakes;

    // Return the corrected XML content
    return correctedXmlContent;
}

// Main function
int main() {
    // Example usage with reading XML content from a file
    string filename = "sample_test.xml"; // Replace with your XML file name
    vector<string> xmlContent = readXmlFile(filename);

    // Call the function to check XML consistency and capture errors
    vector<string> errors_found;
    vector<string> correctedXmlContent = correctXML(xmlContent, errors_found);

    // Print the corrected XML content
    cout << "Corrected XML content:\n";
    for (const auto& line : correctedXmlContent) {
        cout << line << endl;
    }

    // Print errors found
    cout << "\nErrors found:\n";
    for (const auto& error : errors_found) {
        cout << error;
    }

    return 0;
}
