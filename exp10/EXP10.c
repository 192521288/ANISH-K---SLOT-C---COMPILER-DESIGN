#include <stdio.h>
#include <string.h>

int main() {
    int n, i;
    char prod[10][100];

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (Example: S=iEtS/iEtSeS/a):\n");

    for(i = 0; i < n; i++)
        scanf("%s", prod[i]);

    printf("\nGrammar after Left Factoring:\n\n");

    for(i = 0; i < n; i++) {
        char lhs = prod[i][0];
        char rhs[100];
        strcpy(rhs, strchr(prod[i], '=') + 1);

        char *p1 = strtok(rhs, "/");
        char *p2 = strtok(NULL, "/");
        char *p3 = strtok(NULL, "/");

        if(p1 && p2) {
            int j = 0;
            while(p1[j] && p2[j] && p1[j] == p2[j])
                j++;

            if(j > 0) {
                char prefix[50], rem1[50], rem2[50];
                strncpy(prefix, p1, j);
                prefix[j] = '\0';

                strcpy(rem1, p1 + j);
                strcpy(rem2, p2 + j);

                printf("%c -> %s%c'", lhs, prefix, lhs);

                if(p3)
                    printf(" | %s", p3);

                printf("\n");

                printf("%c' -> %s | %s\n\n",
                       lhs,
                       strlen(rem1) ? rem1 : "e",
                       strlen(rem2) ? rem2 : "e");
            }
            else {
                printf("%s\n\n", prod[i]);
            }
        }
        else {
            printf("%s\n\n", prod[i]);
        }
    }

    return 0;
}