#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <bits/stdc++.h>
#include <deque>
#include<algorithm>
using namespace std;
using ll = long long;
bool hasUnterminatedComment(char code[]) {
    bool inComment = false;
    int length = strlen(code);

    for (int i = 0; i < length - 1; i++) {
        if (code[i] == '/' && code[i + 1] == '*') {
            inComment = true;
            i++;
        } else if (code[i] == '*' && code[i + 1] == '/') {
            inComment = false;
            i++;
        }
    }

    return inComment;
}

int main() {
    int n;
    cin>>n;
    char expression[100];
    for(int i=0;i<n;i++){
        cin>>expression[i];
    }
   
1
    if (hasUnterminatedComment(expression)) {
        printf("Error: Unterminated multi-line comment found.\n");
    } else {
        printf("No unterminated multi-line comments found.\n");
    }

    return 0;
}
