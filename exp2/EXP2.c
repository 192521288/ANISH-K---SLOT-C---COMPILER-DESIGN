#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];

    printf("Enter a line: ");
    fgets(str, sizeof(str), stdin);

    if (str[0] == '/' && str[1] == '/')
        printf("Single Line Comment\n");

    else if (str[0] == '/' && str[1] == '*' &&
             strstr(str, "*/") != NULL)
        printf("Multi Line Comment\n");

    else
        printf("Not a Comment\n");

    return 0;
}