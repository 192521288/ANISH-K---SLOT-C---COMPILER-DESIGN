#include <stdio.h>
#include <string.h>

int main() {
    int n, i;
    char prod[10][100];

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter the productions (Example: A=Aa/b):\n");
    for(i = 0; i < n; i++)
        scanf("%s", prod[i]);

    printf("\nGrammar after eliminating Left Recursion:\n\n");

    for(i = 0; i < n; i++) {
        char lhs = prod[i][0];
        char rhs[100];

        strcpy(rhs, strchr(prod[i], '=') + 1);

        char *alt = strtok(rhs, "/");
        char alpha[50] = "", beta[50] = "";

        while(alt != NULL) {
            if(alt[0] == lhs)
                strcpy(alpha, alt + 1);   // Remove left recursive symbol
            else
                strcpy(beta, alt);

            alt = strtok(NULL, "/");
        }

        if(strlen(alpha) > 0) {
            printf("%c -> %s%c'\n", lhs, beta, lhs);
            printf("%c' -> %s%c' | e\n\n", lhs, alpha, lhs);
        }
        else {
            printf("%s (No Left Recursion)\n\n", prod[i]);
        }
    }

    return 0;
}