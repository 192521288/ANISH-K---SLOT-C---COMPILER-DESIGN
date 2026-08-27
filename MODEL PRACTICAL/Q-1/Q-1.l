%{
#include <stdio.h>
%}

%%
hello       { printf("hi"); }
\n          { printf("\n"); }
.           { ECHO; }
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter text:\n");
    yylex();

    return 0;
}