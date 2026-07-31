#include <stdio.h>

struct symbol
{
    char name[20], type[20];
    int addr;
} s[10];

int main()
{
    int n, i;

    printf("Enter number of symbols: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Name Type Address: ");
        scanf("%s %s %d", s[i].name, s[i].type, &s[i].addr);
    }

    printf("\nSymbol Table\n");
    printf("Name\tType\tAddress\n");

    for(i = 0; i < n; i++)
        printf("%s\t%s\t%d\n", s[i].name, s[i].type, s[i].addr);

    return 0;
}