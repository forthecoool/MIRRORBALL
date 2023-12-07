#include <bits/stdc++.h>
using namespace std;

int main() {
    char str[10];

    cout << "\nThe grammar is as follows:\n";
    cout << "S -> bS\n";
    cout << "S -> Sa\n";
    cout << "S -> ba\n";

    cout << "Enter a string -> ";
    cin >> str;

    // Check if the first character is 'b'
    if (str[0] != 'b') {
        cout << "String is invalid because of incorrect first character\n";
        exit(0);
    }

    int n = 1;

    // Count consecutive 'b's
    while (str[n] == 'b')
        n++;

    // Check if the next character after 'b's is 'a'
    if (str[n] != 'a') {
        cout << "String does not belong to grammar\n";
        exit(0);
    }

    n++;

    // Count consecutive 'a's
    while (str[n] == 'a')
        n++;

    // Check if there are no other characters after 'a's
    if (str[n] != '\0') {
        cout << "String does not belong to grammar\n";
        exit(0);
    }

    cout << "String is valid\n";
    return 0;
}
