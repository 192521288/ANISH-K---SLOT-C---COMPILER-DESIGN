%{
#include <stdio.h>
%}

%%
"//".*                               { printf("Single Line Comment\n"); }
"/*"([^*]|\*+[^*/])*\*+"/"           { printf("Multi Line Comment\n"); }
.+                                   { printf("Not a Comment\n"); }
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter a line:\n");
    yylex();
    return 0;
}%{
#include <stdio.h>
%}

%%
"//".*                                  ;
"/*"([^*]|\*+[^*/])*\*+"/"              ;

"int"|"float"|"char"|"if"|"else"|"return"
                                        { printf("%s : Keyword\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*                  { printf("%s : Identifier\n", yytext); }

[0-9]+                                  { printf("%s : Constant\n", yytext); }

"+"|"-"|"*"|"/"|"="                     { printf("%s : Operator\n", yytext); }

";"|","|"("|")"|"{"|"}"                 { printf("%s : Symbol\n", yytext); }

[ \t\n]+                                ;

.                                       ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter C program:\n");
    yylex();
    return 0;
}