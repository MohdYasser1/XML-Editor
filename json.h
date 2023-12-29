#include "parsingXml.h"
using namespace std;
class SString {
public:
    static vector<string> stringToList(string str, char sep = ' ', bool greedy = true);
 
    static string insert_taps(int level);
};
string jsonFormat(const Node* node, int level);
string insert_taps(int level);
