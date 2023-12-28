#include "json.cpp"
#include <stack>

using namespace std;

string json2XML_Converter(string jsonContent){

    string XMLContent = "";
    stack<string> brackets;

    for (int i = 0; i < jsonContent.size(); i++)
    {
        if (jsonContent[i] == '"' && jsonContent[i+1] == ':')
        {
            //get tag name length
            int j = i - 1;
            int tag_name_length = 0;
            while (jsonContent[j] != '"'){
                tag_name_length++;
                j--;
            }
            //get tag name
            string tag_name = jsonContent.substr(j+1, tag_name_length);

            //check the type of tag
            if (jsonContent[i+2] == '"')
            {
                XMLContent += "<" + tag_name + ">\n";
                //get tag value
                int j = i + 3;
                while(jsonContent[j] != '"'){
                    XMLContent += jsonContent[j];
                    j++;
                }
                XMLContent += "\n</" + tag_name + ">\n";
            }
            else if (jsonContent[i+2] == '[' || jsonContent[i+2] == '{'){
                //get tag name length
                int j = i - 1;
                int tag_name_length = 0;
                while (jsonContent[j] != '"'){
                    tag_name_length++;
                    j--;
                }
                //get tag name
                string tag_name = jsonContent.substr(j+1, tag_name_length);
                brackets.push(jsonContent[i+2] + tag_name);
                XMLContent += "<" + tag_name + ">\n";
            }
            
        }
        if (jsonContent[i] == ']' || jsonContent[i] == '}'){
            XMLContent += "</"+ brackets.top().substr(1) + ">\n";
            brackets.pop();        
        }
        
    }
    return XMLContent;
    
}

