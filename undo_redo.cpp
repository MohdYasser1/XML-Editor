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
Operation globalOperation;
