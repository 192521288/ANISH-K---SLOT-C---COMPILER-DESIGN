#include <stdio.h>
#include <string.h>
#include <ctype.h>

char prod[20][50];
char nonterm[20];
char trailing[20][20];
int n;

int indexNT(char c)
{
    for(int i=0;i<n;i++)
        if(nonterm[i]==c)
            return i;
    return -1;
}

void addTrailing(int row,char c)
{
    if(c=='\0')
        return;

    for(int i=0;trailing[row][i];i++)
        if(trailing[row][i]==c)
            return;

    int len=strlen(trailing[row]);
    trailing[row][len]=c;
    trailing[row][len+1]='\0';
}

void findTrailing(int row,char *rhs)
{
    int len=strlen(rhs);
    int i=len-1;

    while(i>=0)
    {
        if(rhs[i]==' ')
        {
            i--;
            continue;
        }

        if(!isupper(rhs[i]))
        {
            addTrailing(row,rhs[i]);
            return;
        }
        else
        {
            int k=indexNT(rhs[i]);

            if(i-1>=0 && !isupper(rhs[i-1]) && rhs[i-1]!='/')
                addTrailing(row,rhs[i-1]);

            if(k!=-1)
            {
                for(int j=0;trailing[k][j];j++)
                    addTrailing(row,trailing[k][j]);
            }
            return;
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of productions: ");
    scanf("%d",&n);

    printf("Enter productions (Example: E=E+T/T)\n");

    for(i=0;i<n;i++)
    {
        scanf("%s",prod[i]);
        nonterm[i]=prod[i][0];
        trailing[i][0]='\0';
    }

    for(int pass=0;pass<n;pass++)
    {
        for(i=0;i<n;i++)
        {
            char rhs[50];
            strcpy(rhs,prod[i]+2);

            char *token=strtok(rhs,"/");

            while(token!=NULL)
            {
                findTrailing(i,token);
                token=strtok(NULL,"/");
            }
        }
    }

    printf("\nTRAILING Sets\n");

    for(i=0;i<n;i++)
    {
        printf("TRAILING(%c) = { ",nonterm[i]);

        for(j=0;trailing[i][j];j++)
            printf("%c ",trailing[i][j]);

        printf("}\n");
    }

    return 0;
}