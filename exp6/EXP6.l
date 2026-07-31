%{
#include <stdio.h>
%}

%%

[a-zA-Z_][a-zA-Z0-9_]*    { printf("%s : Valid Identifier\n", yytext); }

[0-9][a-zA-Z0-9_]*        { printf("%s : Invalid Identifier\n", yytext); }

[ \t\n]+                  ;

.                         { printf("%s : Invalid Identifier\n", yytext); }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter an identifier:\n");
    yylex();
    return 0;
}