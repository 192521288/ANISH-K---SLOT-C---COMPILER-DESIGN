#include <stdio.h>
#include <ctype.h>
#include <string.h>

char prod[20][20];
char follow[26][100];
int n;

void addFollow(char ch, char val)
{
    int i = ch - 'A';
    if (strchr(follow[i], val) == NULL)
    {
        int l = strlen(follow[i]);
        follow[i][l] = val;
        follow[i][l + 1] = '\0';
    }
}

void FOLLOW(char ch)
{
    if (ch == prod[0][0])
        addFollow(ch, '$');

    for (int i = 0; i < n; i++)
    {
        char *rhs = strchr(prod[i], '>');
        rhs++;

        for (int j = 0; rhs[j] != '\0'; j++)
        {
            if (rhs[j] == ch)
            {
                if (rhs[j + 1] != '\0')
                {
                    if (islower(rhs[j + 1]))
                        addFollow(ch, rhs[j + 1]);
                    else if (rhs[j + 1] == '#')
                        FOLLOW(prod[i][0]);
                    else if (isupper(rhs[j + 1]))
                    {
                        int k = rhs[j + 1] - 'A';
                        if (prod[k][3] == '#')
                            FOLLOW(prod[i][0]);
                    }
                }
                else
                {
                    if (prod[i][0] != ch)
                        FOLLOW(prod[i][0]);
                }
            }
        }
    }
}

int main()
{
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (use # for epsilon):\n");
    for (int i = 0; i < n; i++)
        scanf("%s", prod[i]);

    for (int i = 0; i < 26; i++)
        follow[i][0] = '\0';

    for (int i = 0; i < n; i++)
        FOLLOW(prod[i][0]);

    printf("\nFOLLOW Sets:\n");
    for (int i = 0; i < n; i++)
    {
        printf("FOLLOW(%c) = { ", prod[i][0]);
        for (int j = 0; follow[prod[i][0]-'A'][j] != '\0'; j++)
            printf("%c ", follow[prod[i][0]-'A'][j]);
        printf("}\n");
    }

    return 0;
}