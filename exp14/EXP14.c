#include <stdio.h>
#include <string.h>

int main()
{
    char exp[20];
    int i;
    char t = 'A';

    printf("Enter Expression: ");
    scanf("%s", exp);

    for(i = strlen(exp) - 1; i > 0; i -= 2)
    {
        printf("%c = %c %c %c\n", t, exp[i-1], exp[i], exp[i+1]);
        exp[i-1] = t;
        t++;
    }

    return 0;
}