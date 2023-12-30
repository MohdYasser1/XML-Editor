
#include "consistency_check.h"

using namespace std;

// Constructor for XMLLabel class
XMLLabel::XMLLabel(std::string n, int line, int pos) : name(n), lineNumber(line), insertionPosition(pos) {}


std::vector<std::string> splitString(const std::string& input) {
    std::vector<std::string> result;
    std::istringstream iss(input);

    std::string line;
    while (std::getline(iss, line)) {
        result.push_back(line);
    }

    return result;
}


// Function to mark error lines in the XML content
string markErrorLines(const string& xmlContent, const vector<pair<int, string>>& errorsFound) {
    stringstream markedXmlContent;
    istringstream lines(xmlContent);
    string line;
    int currentLine = 1;

    while (getline(lines, line)) {
        markedXmlContent << line;
        for (const auto& error : errorsFound) {
            if (error.first == currentLine) {
                markedXmlContent << " <-- " << error.second;
            }
        }
        markedXmlContent << '\n';
        ++currentLine;
    }

    return markedXmlContent.str();
}

// Function to check XML content and capture errors
string checkXML(const string& xmlContent) {

    int currentLine = 0;
    int totalLines = count(xmlContent.begin(), xmlContent.end(), '\n') + 1;
    std::stack<XMLLabel> labelStack;
    vector<pair<int, string>> errorsFound;

    stringstream checkedXmlContent(xmlPrettifier(xmlMinifier(xmlContent)));

    // Loop through each line of the XML content
    string currentLineContent;
    while (getline(checkedXmlContent, currentLineContent)) {
        int currentCharIndex = 0;

        // Loop through each character in the line
        while (currentCharIndex < currentLineContent.size()) {
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
    if(errorsFound.empty()){
        return "The XML file is Consistent";
    }
    else{
            return markErrorLines(xmlPrettifier(xmlMinifier(xmlContent)), errorsFound);
    }


}

// Function to correct XML content
std::string correctXML(const std::string& xmlContent) {
    vector<string> correctedXmlContent = splitString(xmlPrettifier(xmlMinifier(xmlContent)));
    int currentLine = 0;
    int totalLines = correctedXmlContent.size();
    std::stack<XMLLabel> labelStack;



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

    // Convert the vector of strings back to a single string
    std::string result;
    for (const auto& line : correctedXmlContent) {
        result += line + '\n';
    }

    return result;
}




