# XML-Editor

Language: C++

Brief explanation:

## Level 1

### GUI:
This code appears to be a C++/CLI Windows Forms application using the .NET framework. It defines a graphical user interface (GUI) window named `MyForm` that allows users to perform various operations on XML and JSON data. Here's a brief description of the GUI components and functionality:
### XML-Editor Form

![photo_2024-01-07_04-52-21](https://github.com/MohdYasser1/XML-Editor/assets/132142327/1750b19c-ad16-49f2-892d-58891f7b85bf)

### Components:
1. **Text Boxes:**
   - `textBox1`: Used for displaying and editing XML content.
   - `textBox2`: Used for displaying the result of operations on XML content.

2. **Panel:**
   - Contains buttons for various operations.

3. **Buttons:**
   - `button1`: Open XML file.
   - `button2`: Perform error detection on XML.
   - `button3`: Perform correction on XML.
   - `button4`: Convert XML to JSON.
   - `button5`: Prettify XML.
   - `button6`: Compress XML using Huffman coding.
   - `button7`: Decompress Huffman-encoded XML.
   - `button8`: Save result to a file.
   - `button9`: Open a separate form (`MyForm1`) to perform additional operations.
   - `button10`: Minify XML.
   - `button11`: Undo the last operation.
   - `button12`: Redo the last undone operation.

### Functionality:
- **File Operations:**
  - `button1`: Opens a file dialog to load XML content into `textBox1`.
  - `button8`: Saves the content of `textBox2` to a file.

- **XML Operations:**
  - `button2`: Performs error detection on XML content in `textBox1`.
  - `button3`: Performs correction on XML content in `textBox1`.
  - `button4`: Converts XML content in `textBox1` to JSON.
  - `button5`: Prettifies XML content in `textBox1`.
  - `button6`: Compresses XML content in `textBox1` using Huffman coding.
  - `button7`: Decompresses Huffman-encoded XML content and updates `textBox1`.
  - `button10`: Minifies XML content in `textBox1`.
  - `button3`: Corrects XML content in `textBox1`.

- **Undo and Redo Operations:**
  - `button11`: Undoes the last operation.
  - `button12`: Redoes the last undone operation.

- **Additional Operations:**
  - `button9`: Opens a separate form (`MyForm1`) to perform additional operations.

### Notes:
- The code utilizes the `Operation` class for undo and redo functionality.
- It includes error detection, correction, conversion between XML and JSON, prettifying, compression, and minification operations.

Please note that some functionality, such as `globalOperation.UNDO()` and `globalOperation.REDO()`, depends on the implementation of the `Operation` class, which is not provided in the code snippet.


### Graph Analysis Form 
![photo_2024-01-07_04-52-19](https://github.com/MohdYasser1/XML-Editor/assets/132142327/43661f5f-72ff-49a7-a76b-2a54463c7a21)

The provided code is a C++/CLI Windows Forms application that creates a GUI window using the Windows Forms library. The application seems to be related to a graph-based analysis of social network data. Here's a brief description of the key components in the provided code:

1. **Header and Includes:**
   ```cpp
   #pragma once
   #include <msclr\marshal_cppstd.h> // to convert std::string to String ^ and vice versa
   #include "../consistency_check.cpp"
   #include "../compression.cpp"
   #include <iostream>
   #include "../graph.cpp"
   #include <stdio.h> /* printf, fgets */
   #include <stdlib.h>
   #include "../PostSearch.cpp"
   ```

2. **Namespace and Classes:**
   ```cpp
   namespace GUIDS {
       using namespace System;
       using namespace System::ComponentModel;
       using namespace System::Collections;
       using namespace System::Windows::Forms;
       using namespace System::Data;
       using namespace System::Drawing;
   ```

3. **Main Form Class (MyForm1):**
   - Constructor that initializes the form.
   - A secondary constructor that takes a string parameter and performs some initializations based on that data.
   - Various UI components like buttons, textboxes, labels, etc.

4. **Constructor and UI Initialization:**
   ```cpp
   MyForm1(void) {
       InitializeComponent();
       // Additional constructor code can be added here.
   }

   MyForm1(String^ data) {
       // Initialization using data parameter.
   }
   ```

5. **UI Components:**
   - Buttons (`button1`, `button2`, `button3`, `button4`).
   - Textboxes (`textBox1`, `textBox2`, `textBox3`, `textBox4`, `textBox5`).
   - Labels (`label2`, `label3`, `label4`).
   - Panel (`panel1`) containing various UI elements.

6. **Event Handlers:**
   - Methods like `button1_Click`, `button2_Click`, `button3_Click`, `button4_Click` are event handlers for button clicks.
   - `textBox1_TextChanged` and `textBox4_TextChanged` are event handlers for text changes in corresponding textboxes.

7. **Graph Operations:**
   - The code appears to perform operations on a global graph object (`globalGraph`), which is assumed to be an instance of a graph class.

8. **Graph Visualization:**
   - There is a button (`button2`) that triggers a graph visualization function (`GraphViz`) with a warning message.

9. **Post Search:**
   - There is a button (`button4`) that triggers a post search function (`searchPosts`) using some input data.

10. **Miscellaneous:**
    - The GUI layout is defined using the `InitializeComponent` method.
    - The code uses `msclr::interop::marshal_as` to convert between C++ `std::string` and .NET `String^` types.

Keep in mind that this is a high-level description, and understanding the exact functionality would require knowledge of the implementations in the associated files (`consistency_check.cpp`, `compression.cpp`, `graph.cpp`, `PostSearch.cpp`).


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
Function jsonFormat:
It takes three parameters: a pointer to a Node (node), an integer level indicating the current indentation level, and a reference to an integer flag.The function recursively processes the XML-like tree and builds a JSON-formatted string.It starts by checking if the flag is true (which indicates whether it's the first element at a particular level). If true, it adds the JSON key with the tag name.If the node has no children, it adds the JSON value corresponding to the tag value.
If the node has a single child, it opens a JSON object, recursively processes the child, and closes the object.If the node has multiple children, it checks if any children have the same tag name. If yes, it assumes an array structure and organizes the children accordingly. If no common tag name is found, it treats the children as separate objects.then the print_json function print the json string between curly brackets.
### Compressing the Data:
This feature aims to reduce the size of the XML file and store in a compacted .huf file.  
This compression technique follows a three-step process:
1. **XML to JSON Minified:** Converts the XML into JSON formart and minifies it using a special JSON minifier to remove whitespaces.
2.  **Key Compression:** All object keys are replaced with index of array stored at the end of the file. The More same key appears in the original JSON, the more better compression.
This technique is influenced by a technique used in the famous compressed-json package. [Compressed-json package](https://www.npmjs.com/package/compressed-json)
3. **Huffman Encodeing:** The previous 2 processes helped to reduce the XML format and field names, Huffman Encoding aimed to reduce the size taken by large texts in Tag values. This is a straight implementation of [Huffman Coding](https://en.wikipedia.org/wiki/Huffman_coding).

**Results:** When this compression technique is applied on a small 2.78KB XML file it manages to reduce its size by approx. **46%**.
![Compression Example](images/Compression_size_comparison.png)

### Decompressing:
This feature just reverses the compression process by performing the following steps:  
1. **Huffman Decoding:** Retrieves the Huffman-encoded data.
2. **Key Decompression:** Reverts the compressed field names to their original form within the JSON structure.
3. **JSON to XML Conversion:** Converts the JSON content back to XML format.
## File Storage


### GUI

The GUIDS.exe:

```
XML-Editor\GUIDS\x64\Debug
```

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
The system conducts network analysis, identifying the most influential and active users. It also determines mutual followers between two users and suggests a list of users to follow, leveraging the followers of followers.

### Graph:
#### Network Visualization:
This feature allows you to visualize your network in a graph structure.
![GraphViz Example](images/Network.dot.png)  
**NOTE** Make sure you have [GraphViz](https://graphviz.org/download/) downloaded and correctly added to PATH to be able to use this feature.
### Post Search:
This feature allows user to perform targeted searches for posts containing specific words or topics. The search results are displayed with relevant post information, facilitating quick access to desired content.
### Undo/Redo operations:
The program introduces Undo and Redo operations to enhance user flexibility. Users can easily revert to a previous state (Undo) or reapply operations (Redo), providing a dynamic and interactive experience.
