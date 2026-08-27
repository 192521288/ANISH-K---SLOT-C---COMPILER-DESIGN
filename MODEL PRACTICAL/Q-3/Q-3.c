#include <stdio.h>
#include <ctype.h>

int main()
{
    char expr[100];
    int i = 0;
    int num;
    int value = 0;
    char op = '+';

    printf("Enter expression: ");
    scanf("%s", expr);

    while(expr[i] != '\0')
    {
        if(isdigit(expr[i]))
        {
            num = 0;

            while(isdigit(expr[i]))
            {
                num = num * 10 + (expr[i] - '0');
                i++;
            }

            if(op == '+')
                value = value + num;
            else if(op == '-')
                value = value - num;
        }
        else if(expr[i] == '+' || expr[i] == '-')
        {
            op = expr[i];
            i++;
        }
        else
        {
            printf("Invalid expression!\n");
            return 0;
        }
    }

    printf("\nValue of E = %d\n", value);

    return 0;
}