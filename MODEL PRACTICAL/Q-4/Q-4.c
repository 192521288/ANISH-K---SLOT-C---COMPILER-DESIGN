#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;
int tempCount = 1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    if (top == -1)
        return '\0';
    return stack[top];
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    return 0;
}

void generate(char op, char arg1[], char arg2[], char result[])
{
    printf("%-10c %-10s %-10s %-10s\n",
           op, arg1, arg2, result);
}

int main()
{
    char expr[100];
    char operands[100][20];
    char operators[100];
    int operandTop = -1;
    int operatorTop = -1;
    int i = 0;

    printf("Enter arithmetic expression: ");
    scanf("%s", expr);

    /* Find assignment operator */
    char lhs[20];
    char rhs[100];

    int equalPos = -1;

    for (i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == '=')
        {
            equalPos = i;
            break;
        }
    }

    if (equalPos == -1)
    {
        printf("Invalid expression!\n");
        return 0;
    }

    strncpy(lhs, expr, equalPos);
    lhs[equalPos] = '\0';

    strcpy(rhs, expr + equalPos + 1);

    printf("\nQuadruple Representation:\n");
    printf("-----------------------------------------------\n");
    printf("%-10s %-10s %-10s %-10s\n",
           "Operator", "Arg1", "Arg2", "Result");
    printf("-----------------------------------------------\n");

    i = 0;

    while (rhs[i] != '\0')
    {
        if (isalnum(rhs[i]))
        {
            char operand[20];
            int j = 0;

            while (isalnum(rhs[i]))
            {
                operand[j++] = rhs[i++];
            }

            operand[j] = '\0';

            strcpy(operands[++operandTop], operand);
        }
        else if (rhs[i] == '(')
        {
            operators[++operatorTop] = rhs[i];
            i++;
        }
        else if (rhs[i] == ')')
        {
            while (operatorTop >= 0 &&
                   operators[operatorTop] != '(')
            {
                char op = operators[operatorTop--];

                char arg2[20], arg1[20], result[20];

                strcpy(arg2, operands[operandTop--]);
                strcpy(arg1, operands[operandTop--]);

                sprintf(result, "t%d", tempCount++);

                generate(op, arg1, arg2, result);

                strcpy(operands[++operandTop], result);
            }

            if (operatorTop >= 0)
                operatorTop--;

            i++;
        }
        else if (rhs[i] == '+' || rhs[i] == '-' ||
                 rhs[i] == '*' || rhs[i] == '/')
        {
            char currentOp = rhs[i];

            while (operatorTop >= 0 &&
                   operators[operatorTop] != '(' &&
                   precedence(operators[operatorTop]) >=
                   precedence(currentOp))
            {
                char op = operators[operatorTop--];

                char arg2[20], arg1[20], result[20];

                strcpy(arg2, operands[operandTop--]);
                strcpy(arg1, operands[operandTop--]);

                sprintf(result, "t%d", tempCount++);

                generate(op, arg1, arg2, result);

                strcpy(operands[++operandTop], result);
            }

            operators[++operatorTop] = currentOp;
            i++;
        }
        else
        {
            i++;
        }
    }

    while (operatorTop >= 0)
    {
        char op = operators[operatorTop--];

        char arg2[20], arg1[20], result[20];

        strcpy(arg2, operands[operandTop--]);
        strcpy(arg1, operands[operandTop--]);

        sprintf(result, "t%d", tempCount++);

        generate(op, arg1, arg2, result);

        strcpy(operands[++operandTop], result);
    }

    /* Assignment */
    generate('=', operands[operandTop], "-", lhs);

    return 0;
}