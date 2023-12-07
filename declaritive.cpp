#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool isDeclarativeStatement(const string &line) {
    regex varDeclaration("\\s*\\w+\\s+\\w+\\s*;"); // e.g., int x;
    regex funcDeclaration("\\s*\\w+\\s+\\w+\\s*\\(.*\\)\\s*;"); // e.g., void func()
    
    return regex_match(line, varDeclaration) || regex_match(line, funcDeclaration);
}

int main() {
    cout << "Enter C++ code. Enter 'exit' to quit." << endl;
    string line;

    while (true) {
        cout << "> ";
        getline(cin, line);

        if (line == "exit") {
            break;
        }

        if (isDeclarativeStatement(line)) {
            cout << "This is a declarative statement." << endl;
        } else {
            cout << "This is not a declarative statement." << endl;
        }
    }

    return 0;
}
