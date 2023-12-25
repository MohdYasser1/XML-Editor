#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

void Undo(vector<string>& fileContent) {
    // Store the original XML content
    string originalContent = "";
    for (const auto& line : fileContent) {
        originalContent += line + "\n";
    }

    // Create a stack to store the original XML content
    stack<string> undoStack;
    undoStack.push(originalContent);

    // Undo the operations and restore the original XML
    string restoredContent = undoStack.top();
    undoStack.pop();
    cout << "Restored XML:" << endl;
    cout << restoredContent << endl;

}
