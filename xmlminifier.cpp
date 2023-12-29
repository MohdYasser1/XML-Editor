#include <iostream>
#include <algorithm>

using namespace std;

string xmlMinifier(const string& xml_string) {
    string minified_xml = xml_string;
    minified_xml.erase(remove_if(minified_xml.begin(), minified_xml.end(), [](char c) { return ::isspace(c) && c != '\n'; }), minified_xml.end());
    return minified_xml;
}
