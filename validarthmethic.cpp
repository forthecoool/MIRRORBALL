#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <bits/stdc++.h>
#include <deque>
#include<algorithm>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}
bool isaplha(char c) {
    return (c >= 'a' && c <= 'z');
}
bool isWhitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

bool isArithmeticExpression(char expression[],int n ) {

    bool expectingOperator = false; 

    for (int i = 0; i < n; i++) {
        char c = expression[i];
cout<<c<<endl;
        if (isWhitespace(c)) {
            continue;
        }

        if (isDigit(c)  || isaplha(c)) {
            if (expectingOperator) {
                return false;
            }
            expectingOperator = true;
        } else if (isOperator(c)) {
            if (!expectingOperator) {
                return false;
            }
            expectingOperator = false ;
        }
    }

    return expectingOperator;  // Return true only if the last character is a digit
}

int main() {
    int n;
    cin>>n;
    char expression[n];
    for(int i=0;i<n;i++){
        cin>>expression[i];
    }
    if (isArithmeticExpression(expression,n)) {
        printf("Valid arithmetic expression.\n");
    } else {
        printf("Invalid arithmetic expression.\n");
    }

    return 0;
}
