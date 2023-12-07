#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <bits/stdc++.h>
#include <deque>
#include<algorithm>

int main() {
    int n, i, flag = 0;
    char vari[15], typ[15], expr[100], c;

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    // Input variable names and types
    for (i = 0; i < n; i++) {
        printf("Enter variable[%d]: ", i);
        scanf(" %c", &vari[i]);

        printf("Enter variable-type[%d] (float-f, int-i): ", i);
        scanf(" %c", &typ[i]);

        // Validate input type
        if (typ[i] != 'f' && typ[i] != 'i') {
            printf("Invalid variable type. Please enter 'f' or 'i'.\n");
            exit(EXIT_FAILURE);
        }

        if (typ[i] == 'f') {
            flag = 1;
        }
    }

    // Input expression
    printf("Enter the expression (end with $): ");
    i = 0;
    getchar(); // Consume the newline character left in the buffer
    while ((c = getchar()) != '$') {
        expr[i] = c;
        i++;
    }
    expr[i] = '\0'; // Null-terminate the expression string

    // Check for division operation in the expression
    for (i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '/') {
            flag = 1;
            break;
        }
    }

    // Check variable types
    for (i = 0; i < n; i++) {
        if (expr[0] == vari[i]) {
            if (flag == 1) {
                if (typ[i] == 'f') {
                    printf("\nThe datatype is correctly defined!\n");
                } else {
                    printf("Identifier %c must be a float type!\n", vari[i]);
                }
            } else {
           printf("\nThe datatype is correctly defined!\n");
            }
            break;
        }
    }

    return 0;
}