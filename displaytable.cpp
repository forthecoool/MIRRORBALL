#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <bits/stdc++.h>
#include <deque>
#include<algorithm>
using namespace std;
using ll = long long;
#define MAX_SYMBOLS 100

typedef struct {
    char name[20];
    int value;
} Symbol;

Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

bool findSymbol(char name[]) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return true;  // Symbol found
        }
    }
    return false;  // Symbol not found
}

void addSymbol(char name[], int value) {
    int index;

    if (findSymbol(name)) {
        printf("Symbol %s already exists in the table ", name);
    } 
    else {
        if (symbolCouant < MAX_SYMBOLS) {
            strcpy(symbolTable[symbolCount].name, name);
            symbolTable[symbolCount].value = value;
            symbolCount++;
           // printf("Symbol %s added to the table with a value of %d.\n", name, value);
        } else {
            printf("Error: Symbol table is full.\n");
        }
    }
}

void displaySymbolTable() {
    printf("Symbol Table:\n");
    printf("%-10s%-10s\n", "Name", "Value");

    for (int i = 0; i < symbolCount; i++) {
        printf("%-10s%-10d\n", symbolTable[i].name, symbolTable[i].value);
    }
}

int main() {
    // addSymbol("x", 1);
    // addSymbol("y", 2);
    // addSymbol("z", 3);

    // displaySymbolTable();

    // addSymbol("y", 4);  // Try adding a symbol that already exists
    // addSymbol("w", 5);  // Try adding a new symbol
int n;
cin>>n;
for(int i=0;i<n;i++){
    char name[100];
    int x;
    cin>>name;
    cin>>x;
    addSymbol(name, x);
}
    displaySymbolTable();

    return 0;
}
