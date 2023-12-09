
// Function to prettify XML content by organizing tags
// One opening and one closing tag per line at most
void prettifyXmlContent(vector<string>& xmlLines)
{
    mergeOpeningClosingTags(xmlLines);
    mergeNonTagLines(xmlLines);
}

// Function to merge opening and closing tags on separate lines
void mergeOpeningClosingTags(vector<string>& xmlLines)
{
    for (int i = 1; i < xmlLines.size(); i++)
    {
        if (xmlLines[i][0] == '<' && xmlLines[i][1] == '/' && xmlLines[i - 1][0] != '<')
        {
            xmlLines[i - 1].append(xmlLines[i]);
            xmlLines.erase(xmlLines.begin() + i, xmlLines.begin() + i + 1);
        }
    }
}

// Function to merge non-tag lines with the previous line
void mergeNonTagLines(vector<string>& xmlLines)
{
    for (int i = 1; i < xmlLines.size(); i++)
    {
        if (xmlLines[i][0] != '<')
        {
            xmlLines[i - 1].append(xmlLines[i]);
            xmlLines.erase(xmlLines.begin() + i, xmlLines.begin() + i + 1);
        }
    }
}

// Function to determine the indentation level of each line in XML content
void determineXmlIndentation(vector<string>& xmlContent, vector<int>& linesIndentation)
{
    linesIndentation[0] = 0;

    // Iterate through the XML content to determine indentation levels
    for (int i = 1; i < xmlContent.size(); i++)
    {
        if (xmlContent[i].find('<') != -1 && xmlContent[i - 1].find('<') != -1)
        {
            determineIndentationLevel(xmlContent, linesIndentation, i);
        }
    }
}

// Function to determine the indentation level based on conditions
void determineIndentationLevel(vector<string>& xmlContent, vector<int>& linesIndentation, int index)
{
    if (xmlContent[index - 1][xmlContent[index - 1].find_last_of('<') + 1] != '/' &&
        xmlContent[index - 1][xmlContent[index - 1].find_last_of('>') - 1] != '/' &&
        xmlContent[index][xmlContent[index].find('<') + 1] != '/' &&
        xmlContent[index][xmlContent[index].find('>') - 1] != '/')
    {
        linesIndentation[index] = linesIndentation[index - 1] + 1;
    }
    else if (xmlContent[index - 1][xmlContent[index - 1].find_last_of('<') + 1] == '/' &&
             xmlContent[index][xmlContent[index].find('<') + 1] == '/')
    {
        linesIndentation[index] = linesIndentation[index - 1] - 1;
    }
    // ... (similar conditions for other cases)
    else
    {
        linesIndentation[index] = linesIndentation[index - 1];
    }
}

// Function to add indentation to each line based on the determined levels
void addIndentation(vector<string>& xmlContent, const vector<int>& linesIndentation)
{
    // Iterate through each line and add appropriate indentation
    for (int i = 0; i < xmlContent.size(); i++)
    {
        for (int j = 0; j < linesIndentation[i]; j++)
        {
            xmlContent[i] = "\t" + xmlContent[i];
        }
    }
}
