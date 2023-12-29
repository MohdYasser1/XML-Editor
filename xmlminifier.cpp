#include <iostream>
#include <algorithm>

using namespace std;

void xmlMinifier(string& xml_string) {
    xml_string.erase(remove_if(xml_string.begin(), xml_string.end(), ::isspace), xml_string.end());
}
