#include <bits/stdc++.h>
using namespace std;

int tempVarNum = 1;

bool isOperator(const char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^');
}

bool isOperator(string op) {
    return (op == "+" || op == "-" || op == "*" || op == "/" || op == "^");
}

bool isAlphaNum(const char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '.' || c == '_');
}

bool isAlphaNum(string s) {
    for (char c : s) {
        if (!isAlphaNum(c)) {
            return false;
        }
    }
    return true;
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string infixToPostfix(string &infix) {
    string postfix = "";
    stack<char> st;
    bool newOperand = false;

    for (int i = 0; i < infix.length(); ++i) {
        if (infix[i] == ' ') {
            continue;
        }
        if (isAlphaNum(infix[i])) {
            if (newOperand) {
                postfix += " ";
            }
            newOperand = false;
            postfix += infix[i];
        } else if (isOperator(infix[i])) {
            newOperand = true;
            if (!st.empty()) postfix += " ";
            while (!st.empty() && precedence(st.top()) >= precedence(infix[i])) {
                postfix += " ";
                postfix += st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }

    while (!st.empty()) {
        postfix += " ";
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

vector<string> tokenizer(string s, char del = ' ') {
    vector<string> tokens;
    stringstream ss(s);
    string word;

    while (!ss.eof()) {
        getline(ss, word, del);
        tokens.push_back(word);
    }

    return tokens;
}

void generateThreeAddressCode(string& expression) {
    stack<string> st;
    vector<string> tokens = tokenizer(expression);

    for (string token : tokens) {
        if (token.size() && isAlphaNum(token)) {
            st.push(token);
        } else if (token.size() && isOperator(token)) {
            string rightOperand = st.top();
            st.pop();
            string leftOperand = st.top();
            st.pop();
            string result = "t" + to_string(tempVarNum) + " = " + leftOperand + " " + token + " " + rightOperand;
            cout << result << endl;
            st.push("t" + to_string(tempVarNum));
            tempVarNum++;
        }
    }
}

int main() {
    string inputString;
    cout << "Enter the expression\n" << "> ";
    getline(cin, inputString);

    // Extracting the right-hand side of the expression
    int index = inputString.find('=');
    string infix = inputString.substr(index + 1);
    string postfix = infixToPostfix(infix);

    cout << "\nThree address code:" << endl;
    generateThreeAddressCode(postfix);

    // Printing the assignment statement
    cout << inputString.substr(0, index) << " = t" << tempVarNum - 1 << endl;

    return 0;
}
