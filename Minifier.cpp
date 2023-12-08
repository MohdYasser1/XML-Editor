#include "xml_minifier.h"

// Function to minify a vector of strings representing a file
string minifyFileContent(vector<string> fileLines)
{
    // Variables
    size_t found;
    string minified = "";

    // Loop to remove leading tabs in each line
    for (int i = 0; i < fileLines.size(); i++)
    {
        // Find the position of the first character that is not a tab
        found = fileLines[i].find_first_not_of("\t");

        // Check if any non-tab character is found
        if (found != string::npos)
        {
            // Erase leading tabs in the current line
            fileLines[i].erase(0, found);
        }
    }

    // Loop to remove leading spaces in each line
    for (int i = 0; i < fileLines.size(); i++)
    {
        // Find the position of the first character that is not a space
        found = fileLines[i].find_first_not_of(" ");

        // Check if any non-space character is found
        if (found != string::npos)
        {
            // Erase leading spaces in the current line
            fileLines[i].erase(0, found);
        }
    }

    // Concatenate the minified lines into a single string
    for (int i = 0; i < fileLines.size(); i++)
    {
        minified += fileLines[i];
    }

    // Return the minified string
    return minified;
}
