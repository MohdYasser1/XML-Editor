#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "../../compression.cpp"

using namespace std;

int main(void)
{
    //Simple JSON
    string test1 ="\'{\"name\":\"John\", \"age\":30, \"car\":null}\'";
    //string test11 = keyCompression(test1);
    //cout<<keyCompression(test1)<<endl; 
    //cout<<keyDecompress(test11);
    //PASSED

    //1 Duplicate
    string test2 = "{\"glossary\":{\"title\":\"exampleglossary\",\"GlossDiv\":{\"title\":\"S\",\"GlossList\":{\"GlossEntry\":{\"ID\":\"SGML\",\"SortAs\":\"SGML\",\"GlossTerm\":\"StandardGeneralizedMarkupLanguage\",\"Acronym\":\"SGML\",\"Abbrev\":\"ISO8879:1986\",\"GlossDef\":{\"para\":\"Ameta-markuplanguage,usedtocreatemarkuplanguagessuchasDocBook.\",\"GlossSeeAlso\":[\"GML\",\"XML\"]},\"GlossSee\":\"markup\"}}}}}";
    string test22 = keyCompression(test2);
    //cout<<keyCompression(test2)<<endl;
    //cout<<keyDecompress(test22);
    //PASSED
    
    //Multiple duplicate
    string test3 = "{\"menu\":{\"id\":\"file\",\"value\":\"File\",\"popup\":{\"menuitem\":[{\"value\":\"New\",\"onclick\":\"CreateNewDoc()\"},{\"value\":\"Open\",\"onclick\":\"OpenDoc()\"},{\"value\":\"Close\",\"onclick\":\"CloseDoc()\"}]}}}";
    string test33 = keyCompression(test3);
    //cout<<keyCompression(test3)<<endl;
    //cout<<keyDecompress(test33);
    //PASSED
}
