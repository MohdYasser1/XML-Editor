#ifndef CONSISTENCY_CHECK_H
#define CONSISTENCY_CHECK_H

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <fstream>
#include <utility>
#include <sstream>
#include <algorithm>

#include "xmlminifier.cpp"

#include "xmlprettifier.cpp"

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

std::vector<std::string> splitString(const std::string& input);

std::string markErrorLines(const string& xmlContent, const vector<pair<int, string>>& errorsFound);

std::string checkXML(const string& xmlContent);

std::string correctXML(const std::string& xmlContent);


#endif
