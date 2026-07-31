#include <stdio.h>
#include <string.h>

char s[20];
int i = 0;

void E(), E1(), T(), T1(), F();

void E() { T(); E1(); }

void E1() {
    if (s[i] == '+') {
        i++;
        T();
        E1();
    }
}

void T() { F(); T1(); }

void T1() {
    if (s[i] == '*') {
        i++;
        F();
        T1();
    }
}

void F() {
    if (s[i] == '(') {
        i++;
        E();
        if (s[i] == ')')
            i++;
    }
    else if (s[i] == 'i' && s[i+1] == 'd')
        i += 2;
}

int main() {
    printf("Enter expression: ");
    scanf("%s", s);

    E();

    if (s[i] == '\0')
        printf("String Accepted\n");
    else
        printf("String Rejected\n");

    return 0;
}