#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "../../compression.cpp"

using namespace std;

int Test(void)
{
    //Simple JSON
    string test1 ="\'{\"name\":\"John\", \"age\":30, \"car\":null}\'";
    //cout<<keyCompression(test1); 
    //PASSED

    //1 Duplicate
    string test2 = "{\"glossary\":{\"title\":\"exampleglossary\",\"GlossDiv\":{\"title\":\"S\",\"GlossList\":{\"GlossEntry\":{\"ID\":\"SGML\",\"SortAs\":\"SGML\",\"GlossTerm\":\"StandardGeneralizedMarkupLanguage\",\"Acronym\":\"SGML\",\"Abbrev\":\"ISO8879:1986\",\"GlossDef\":{\"para\":\"Ameta-markuplanguage,usedtocreatemarkuplanguagessuchasDocBook.\",\"GlossSeeAlso\":[\"GML\",\"XML\"]},\"GlossSee\":\"markup\"}}}}}";
    //cout<<keyCompression(test2);
    //PASSED
    
    //Multiple duplicate
    string test3 = "{\"menu\":{\"id\":\"file\",\"value\":\"File\",\"popup\":{\"menuitem\":[{\"value\":\"New\",\"onclick\":\"CreateNewDoc()\"},{\"value\":\"Open\",\"onclick\":\"OpenDoc()\"},{\"value\":\"Close\",\"onclick\":\"CloseDoc()\"}]}}}";
    cout<<keyCompression(test3);
    //PASSED
}
