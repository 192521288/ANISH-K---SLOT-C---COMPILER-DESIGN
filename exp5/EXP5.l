%{
#include <stdio.h>

int spaces = 0, lines = 0;
%}

%%

" "     { spaces++; }

\n      { lines++; }

\t      ;

.       ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the text (Press Ctrl+Z then Enter to stop):\n\n");
    yylex();

    printf("\nNumber of White Spaces = %d\n", spaces);
    printf("Number of New Lines = %d\n", lines);

    return 0;
}