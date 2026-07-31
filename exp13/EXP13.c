#include <stdio.h>

char str[20];
int i = 0;

void S()
{
    if(str[i] == 'a')
    {
        i++;
        if(str[i] == 'a')
            S();
        if(str[i] == 'b')
            i++;
    }
}

int main()
{
    printf("Enter string: ");
    scanf("%s", str);

    S();

    if(str[i] == '\0')
        printf("String Accepted");
    else
        printf("String Rejected");

    return 0;
}