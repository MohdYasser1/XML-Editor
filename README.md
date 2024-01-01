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

### Converting xml to json:
The function recursively traverses the XML tree structure and builds a JSON-formatted string.It takes a Node pointer and an integer level as parameters.
The indentation for formatting is calculated based on the level parameter.If a node has children, it checks if they have the same tag name. If yes, it formats them as an array; otherwise, it formats them as an object.The result is built by appending key-value pairs or array elements to the string.then print_json Function:
This function wraps the output of jsonFormat in curly braces to create a complete JSON object.It takes a Node pointer and an integer level as parameters.
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
