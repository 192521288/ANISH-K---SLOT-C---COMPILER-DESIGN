%{
#include<stdio.h>
%}

%%
"int"|"float"|"char"|"if"|"else"|"while"|"return"    { printf("%s : Keyword\n", yytext); }

[0-9]+                                                { printf("%s : Constant\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*                                { printf("%s : Identifier\n", yytext); }

"+"|"-"|"*"|"/"|"="|"%"|"<"|">"                       { printf("%s : Operator\n", yytext); }

[ \t\n]+                                              ;

.                                                     ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the input:\n");
    yylex();
    return 0;
}