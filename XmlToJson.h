#include "parsingXml.cpp"
using namespace std;
class SString {
public:
    static vector<string> stringToList(string str, char sep = ' ', bool greedy = true);
 
    static string insert_taps(int level);
};
string jsonFormat(const Node* node, int level);
string insert_taps(int level);
string XML_2_Json(string XMLcontent);
string print_json(const Node* node, int level );
