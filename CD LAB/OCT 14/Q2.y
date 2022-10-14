%{
/* Definition section */
#include<stdio.h>
#include<stdlib.h>
void yyerror(char *s);
%}
%token ZERO ONE MINUS

/* Rule Section */
%%
N: L {printf("\n%d\n", $$);}
L: L B {$$=$1*$2;}
	| B {$$=$1;}
	| MINUS {$$=$1;}
B:B C {$$=$1*2+$2;}
	| C {$$=$1;}
C:ZERO {$$=$1;}
	|ONE {$$=$1;};
%%

//driver code
int main()
{
	while(yyparse());
}

yyerror(char *s)
{
	fprintf(stdout, "\n%s", s);
}

