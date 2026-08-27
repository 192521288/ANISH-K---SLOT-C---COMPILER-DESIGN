%{
#include<stdio.h>
#include<string.h>

char w[100][30];
int n=0;
%}

%%
[A-Za-z]+    { strcpy(w[n++],yytext); }
[ \t]+       ;
\n           ;
.            ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    int i,j,c;

    printf("Enter text (type END to finish):\n");

    yylex();

    printf("\nWord Frequency:\n");

    for(i=0;i<n;i++)
    {
        if(w[i][0]=='\0') continue;

        c=1;

        for(j=i+1;j<n;j++)
        {
            if(strcmp(w[i],w[j])==0)
            {
                c++;
                w[j][0]='\0';
            }
        }

        printf("%s : %d\n",w[i],c);
    }

    return 0;
}