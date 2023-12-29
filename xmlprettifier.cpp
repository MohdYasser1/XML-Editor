#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void xmlPrettifier(string& xml_string) {
    vector<string> lines;
    istringstream ss(xml_string);
    string line;

    int indent_level = 0;
    while (getline(ss, line)) {
        size_t pos = line.find_first_not_of(" \t");
        if (pos != string::npos) {
            line = line.substr(pos);
        }

        if (line.find("</") == 0) {
            indent_level--;
        }

        string indented_line(indent_level * 4, ' ');
        lines.push_back(indented_line + line);

        if (line.find("<") == 0 && line.find("</") == string::npos && line.find("/>") == string::npos) {
            indent_level++;
        }
    }

    xml_string = "";
    for (const auto& formatted_line : lines) {
        xml_string += formatted_line + "\n";
    }
}
