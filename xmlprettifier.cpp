#include <iostream>
#include <vector>

using namespace std;

// Function declarations
string prettifyXmlContent(const string& xmlContent);
void mergeOpeningClosingTags(string& xmlContent);
void mergeNonTagLines(string& xmlContent);
string determineXmlIndentation(const string& xmlContent);

string xmlPrettifier(const string& inputXml) {
    // Prettify XML content
    string prettifiedXml = prettifyXmlContent(inputXml);

    // Determine and add indentation
    string indentedXml = determineXmlIndentation(prettifiedXml);

    return indentedXml;
}

// Function to prettify XML content by organizing tags
// One opening and one closing tag per line at most
string prettifyXmlContent(const string& xmlContent) {
    string result = xmlContent;
    mergeOpeningClosingTags(result);
    mergeNonTagLines(result);
    return result;
}

// Function to merge opening and closing tags on separate lines
void mergeOpeningClosingTags(string& xmlContent) {
    for (size_t i = 1; i < xmlContent.size(); i++) {
        if (xmlContent[i] == '/' && xmlContent[i - 1] == '>') {
            size_t lastOpeningBracket = xmlContent.rfind('<', i - 1);
            if (lastOpeningBracket != string::npos) {
                xmlContent.erase(lastOpeningBracket, i - lastOpeningBracket + 1);
                i = lastOpeningBracket;  // Move i back to process the merged line again
            }
        }
    }
}

// Function to merge non-tag lines with the previous line
void mergeNonTagLines(string& xmlContent) {
    for (size_t i = 1; i < xmlContent.size(); i++) {
        if (xmlContent[i] != '<') {
            size_t lastNewline = xmlContent.rfind('\n', i - 1);
            if (lastNewline != string::npos) {
                xmlContent.erase(lastNewline, 1);  // Remove the newline
                i = lastNewline;  // Move i back to process the merged line again
            }
        }
    }
}

// Function to determine the indentation of XML content
string determineXmlIndentation(const string& xmlContent) {
    string indentedXml;
    int indentationLevel = 0;

    for (size_t i = 0; i < xmlContent.size(); i++) {
        if (xmlContent[i] == '<') {
            if (i < xmlContent.size() - 1 && xmlContent[i + 1] == '/') {
                indentationLevel--;
                indentedXml += '\n';
                for (int j = 0; j < indentationLevel; j++) {
                    indentedXml += '\t';
                }
            } else {
                indentedXml += '\n';
                for (int j = 0; j < indentationLevel; j++) {
                    indentedXml += '\t';
                }
                if (i < xmlContent.size() - 1 && xmlContent[i + 1] != '/') {
                    indentationLevel++;
                }
            }
        }

        indentedXml += xmlContent[i];
    }

    return indentedXml;
}
