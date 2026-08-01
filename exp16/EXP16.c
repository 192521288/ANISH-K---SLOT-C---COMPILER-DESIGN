#include <stdio.h>

int main()
{
    char op, a, b;

    printf("Enter expression (Example: A+B): ");
    scanf("%c%c%c", &a, &op, &b);

    printf("\nTarget Code:\n");
    printf("MOV R0, %c\n", a);

    switch(op)
    {
        case '+':
            printf("ADD R0, %c\n", b);
            break;
        case '-':
            printf("SUB R0, %c\n", b);
            break;
        case '*':
            printf("MUL R0, %c\n", b);
            break;
        case '/':
            printf("DIV R0, %c\n", b);
            break;
        default:
            printf("Invalid Operator\n");
    }

    printf("MOV RESULT, R0\n");

    return 0;
}