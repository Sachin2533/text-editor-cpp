//Text Editor c++

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class TextEditor {
private:
    string text;
    stack<string> undoStack;
    stack<string> redoStack;

public:
    void insert(const string& newText) {
        undoStack.push(text);
        text += newText;
        redoStack = std::stack<std::string>(); // Clear redo stack after any insert
    }

    void deleteChars(int count) {
        if (count <= text.length()) {
            undoStack.push(text);
            text.erase(text.length() - count, count);
            redoStack = stack<string>(); // Clear redo stack after any delete
        }
    }

    void undo() {
        if (!undoStack.empty()) {
            redoStack.push(text);
            text = undoStack.top();
            undoStack.pop();
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            undoStack.push(text);
            text = redoStack.top();
            redoStack.pop();
        }
    }

    void display() {
        cout << "Text: " << text << endl;
    }
};

int main() {
    TextEditor editor;
    char choice;

cout<<"\t-----------------------\n\t";

cout<<"***** Text Editor *****\n\t";
cout<<"-----------------------\n\t";
cout<<"_______________________\n";
    do {
        cout << "Menu:\n";
        cout << "1. Insert text\n";
        cout << "2. Delete text\n";
        cout << "3. Undo\n";
        cout << "4. Redo\n";
        cout << "5. Display text\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                string newText;
                cout << "Enter text to insert: ";
                cin.ignore(); // Clear the newline character
                getline(cin, newText);
                editor.insert(newText);
                break;
            }
            case '2': {
                int count;
                cout << "Enter the number of characters to delete: ";
                cin >> count;
                editor.deleteChars(count);
                break;
            }
            case '3':
                editor.undo();
                break;
            case '4':
                editor.redo();
                break;
            case '5':
                editor.display();
                break;
            case '6':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (choice != '6');

    return 0;
}
