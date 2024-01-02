# XML-Editor

Language: C++

Brief explanation:

## Level 1

### GUI:

### Checking xml Consistency:
The program incorporates a robust XML consistency checking mechanism designed to ensure the correct structure of XML files. Utilizing a stack-based approach, it validates the structure of XML tags, identifying missing or mismatched opening and closing tags. The program not only identifies but also visually highlights errors, providing users with a clear indication of potential issues within their XML documents.

Error Visualization:
Inconsistencies in the XML file, such as missing or mismatched tags, are visually highlighted within the GUI, allowing users to identify and understand the errors.

Automatic Correction: The program offers a functionality to automatically correct detected errors in the XML file. Users can choose to apply corrections, and the corrected XML will be displayed within the GUI.


### Prettifying xml:
The xmlPrettifier function utilizes a line-by-line approach to analyze the input XML string. It adds proper indentation based on XML tags, enhancing readability. The function tracks the nesting level of XML elements, adjusting the indentation accordingly.

### Minifying xml:
The xmlMinifier function employs the remove-erase idiom to eliminate unnecessary whitespace from the input XML string. It traverses the string, identifying and removing spaces, tabs, and line breaks, except for newline characters essential for maintaining structure. This results in a minified XML string suitable for more compact representation and reduced file size.

### Inserting xml to Tree:
Function parseXML:

The function takes an XML string (xml) as input and returns a pointer to the root of the XML tree (Node*).It initializes pointers for the root (root) and the current node being processed (currentNode).The XML string is processed line by line using an istringstream.If a line contains a '<' character, it is considered a potential XML tag.If the tag starts with '/', it indicates the end of an element, and the tag value is set for the current node, and the current node is set to its parent.
If the line contains "</", it signifies the end of an element with a closing tag. A new node is created, and it is either added as a child to the current node or set as the root if there is no current node.If the line contains '>', it indicates the start of an element. A new node is created, its parent is set to the current node, and it is added as a child to the current node. The current node is then updated to the newly created node.
If none of the above conditions are met, it implies the start of a new element without a closing tag on the same line. A new node is created similarly to the case with '>', and the current node is updated.The function returns the root of the constructed XML tree.

Function extractTagName:
This function extracts the tag name from an XML line using a regular expression.It searches for the pattern <anything> and returns the content inside the brackets.

Function extractTagValue:
This function extracts the tag value for a given tag name from an XML line using a regular expression.It searches for the pattern <tagName>anything</tagName> and returns the content between the opening and closing tags.

Note: The code assumes that the XML is well-formed, and there is no error handling for cases where the XML might be invalid.
### Converting xml to json:

### Compressing the Data:
1. Key-Compression logic
2. Huffman encoding for long strings

### Decompressing:

## File Storage

### Saved Files Location

The XML Editor saves files to the following directory:

```
XML-Editor\GUIDS\x64\Debug\Saved files
```

All files saved through the GUI will be stored in this directory.

### Compression File Location

The compression files (with a `.huf` extension) are saved to the following directory:

```
XML-Editor\GUIDS
```

Make sure not to modify or delete any essential files in this directory to ensure proper functionality.
## Level 2

### Network Analysis:

### Graph:

### Undo/Redo operations:
The program introduces Undo and Redo operations to enhance user flexibility. Users can easily revert to a previous state (Undo) or reapply operations (Redo), providing a dynamic and interactive experience.
