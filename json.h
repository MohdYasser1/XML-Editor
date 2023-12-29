#include "parsingXml.h"
class SString {
public:
    static vector<string> stringToList(string str, char sep = ' ', bool greedy = true);
 
    static string insert_taps(int level);
};
