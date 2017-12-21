%{
#include <stdio.h>
#include "p-m.tab.h"
  extern int yylex();
  extern int yyerror();
  %}
%token NUMBER
%%
statement: expression
{printf("=%d\n",$1);};
expression : expression '+' term {$$ = $1 + $3;}
| expression '-' term {$$ = $1 - $3;}
| term{$$=$1;}
;

term : term '*' fact {$$ = $1 * $3;}
| term '/' fact {$$ = $1 / $3;}
| fact{$$=$1;}
;

fact : NUMBER
| '('expression')' {$$ = $2;}
;

%%
int main(void)
{
  if(yyparse()){
    fprintf(stderr,"Error\n");
    return 1;
  }
}
