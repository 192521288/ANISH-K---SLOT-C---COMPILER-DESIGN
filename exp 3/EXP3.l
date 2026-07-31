%{
#include<stdio.h>
%}

%%

"//".*                  ;

[ \t\n]+                ;

"int"|"float"|"char"|"if"|"else"|"return"    { printf("%s : Keyword\n",yytext); }

[a-zA-Z_][a-zA-Z0-9_]*  { printf("%s : Identifier\n",yytext); }

[0-9]+                  { printf("%s : Constant\n",yytext); }

"+"|"-"|"*"|"/"|"="     { printf("%s : Operator\n",yytext); }

";"|"("|")"|"{"|"}"|"," { printf("%s : Symbol\n",yytext); }

.                       ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    yylex();
    return 0;
}