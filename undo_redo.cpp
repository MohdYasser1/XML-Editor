#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Operation {
private:
    stack<string> undo;
    stack<string> redo;

public:
    void addOperation(const string& output) {
        undo.push(output);

    }

    string UNDO() {
        if (undo.empty()) {
            return "There are no operations to undo";
        }
        else {
            string stacktop = undo.top();
            redo.push(stacktop);
            undo.pop();
            return stacktop;
        }
    }

    string REDO() {
        if (redo.empty()) {
            return "There are no operations to redo";
        }
        else {
            string stacktop = redo.top();
            undo.push(stacktop);
            redo.pop();
            return stacktop;
        }
    }

};


int main() {
    Operation operation;

    // Add some operations
    operation.addOperation("Operation 1");
    operation.addOperation("Operation 2");
    operation.addOperation("Operation 3");

    // Undo operations
    cout << operation.UNDO() << endl;  // Undo successful: Operation 3
    cout << operation.UNDO() << endl;  // Undo successful: Operation 2
    cout << operation.UNDO() << endl;  // Undo successful: Operation 1


    // Redo operations
    cout << operation.REDO() << endl;  // Redo successful: Operation 2
    cout << operation.REDO() << endl;  // Redo successful: Operation 3

    // Try to undo when there are no more operations
    cout << operation.REDO() << endl;  // There are no operations to undo

    std::cout << std::endl;

    return 0;
}

