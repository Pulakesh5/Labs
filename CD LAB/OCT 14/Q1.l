
%{
    /* Definition section */
    #include "y.tab.h"
%}

/* Rule Section */
%%
"a"+|"b"+|"c"+|.|\n { yylval = yyleng; return *yytext; }
%%

int yywrap()
{
return 1;
}
