#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#include <deque>
#include<algorithm>
using namespace std;
using ll = long long;

bool isValidIfStatement(const char *line) {
    int length = strlen(line);
    bool foundIfKeyword = false;
    bool foundOpeningBrace = false;
    bool foundClosingBrace = false;
    int equal=0;
    for (int i = 0; i < length; i++) {
        char c = line[i];

        if (c == ' ' || c == '\t') {
            continue;
        }

        if (!foundIfKeyword) {
            if (c == 'i' && line[i + 1] == 'f') {
                foundIfKeyword = true;
                i++;
                continue;
            } else {
                return false;
            }
        }

        if (foundIfKeyword && !foundOpeningBrace) {
            if (c == '(') {
                foundOpeningBrace = true;
                continue;
            } else {
                return false;
            }
        }

        if (foundIfKeyword && foundOpeningBrace && !foundClosingBrace) {
             if (c == '=') {
               equal++;
                continue;
            }
            if (c == ')') {
                foundClosingBrace = true;
                continue;
            }
            else{
                return false;
            }
        }
    }

    return foundIfKeyword && foundOpeningBrace && foundClosingBrace && equal==2;
}

int main() {
    char line[100];
    std::cout << "Enter a line of C code: ";
    std::cin.getline(line, sizeof(line));

    if (isValidIfStatement(line)) {
        std::cout << "Valid if statement.\n";
    } else {
        std::cout << "Invalid if statement.\n";
    }

    return 0;
}
