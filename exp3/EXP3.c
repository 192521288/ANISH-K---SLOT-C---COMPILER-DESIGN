#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    char ch, next;

    fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        printf("File not found");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        // Ignore spaces, tabs and newlines
        if (isspace(ch))
            continue;

        // Ignore comments
        if (ch == '/')
        {
            next = fgetc(fp);

            if (next == '/')
            {
                while ((ch = fgetc(fp)) != '\n' && ch != EOF);
                continue;
            }
            else if (next == '*')
            {
                while ((ch = fgetc(fp)) != EOF)
                {
                    if (ch == '*' && (next = fgetc(fp)) == '/')
                        break;
                }
                continue;
            }
            else
            {
                printf("/ -> Operator\n");
                ungetc(next, fp);
            }
        }

        // Identifier
        else if (isalpha(ch))
        {
            printf("%c -> Identifier\n", ch);
            while (isalnum(ch = fgetc(fp)));
            ungetc(ch, fp);
        }

        // Constant
        else if (isdigit(ch))
        {
            printf("%c -> Constant\n", ch);
            while (isdigit(ch = fgetc(fp)));
            ungetc(ch, fp);
        }

        // Operators
        else if (ch=='+' || ch=='-' || ch=='*' || ch=='=')
        {
            printf("%c -> Operator\n", ch);
        }
    }

    fclose(fp);
    return 0;
}