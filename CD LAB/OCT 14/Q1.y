
%{
    #include<stdio.h>
    #include<stdlib.h>
%}


/* Rule Section */
%%
start: line
     | start line
     ;

line: 'a' 'b' 'c' '\n' { if ($1 == $2 && $2 == $3)
                           printf("Good!\n", stderr);
                         else
                           printf("Bad!\n", stderr);
                       }
%%


int yyerror(char *msg)
{
    printf("invalid string\n");
    exit(0);
}

main()
{
    printf("enter the string\n");
    yyparse();
}
