#include <stdio.h>

int main()
{
    FILE *fp;
    char ch;
    int spaces = 0, newlines = 0;

    fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        printf("File not found");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == ' ')
            spaces++;
        else if (ch == '\n')
            newlines++;
    }

    fclose(fp);

    printf("Number of Whitespaces = %d\n", spaces);
    printf("Number of Newline Characters = %d\n", newlines);

    return 0;
}