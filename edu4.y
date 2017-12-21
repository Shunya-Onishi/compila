%{
#include <stdio.h>
#include "edu4.tab.h"
#include "makeast.h"
  extern int yylex();
  extern int yyerror();
  extern char *yytext;
  %}
%union{
  struct node *node;
  int ival;
  char *sval;
  int *dummy;
 }

%token <sval> IDEN 
%token <ival> NUMBER
%token <dummy> array
%token <node> define
%token <dummy> ELSE
%token <dummy> IF
%token <dummy> WHILE
%token <dummy> adsub
%token <dummy> muldiv
%token <dummy> compari
%token <node> cricri
%token <dummy> FOR

%type <node> decsen
%type <node> sentences
%type <node> sentence
%type <node> asastate
%type <node> incri
%type <node> assignment
%type <node> expression
%type <node> term
%type <node> fact
%type <node> variable
%type <node> identyan
%type <node> loopsen
%type <node> brasen
%type <node> forsen
%type <node> condition


%%

program: union sentences;

union: decsen union 
| decsen;

decsen: define IDEN ';' 
| array identyan'['NUMBER']' ';' {$$ = build_node2(ARRAY, $2, $4);}
| array identyan'['identyan']' ';' {$$ = build_node2(ARRAY, $2, $4);}
| array identyan'['NUMBER']''['NUMBER']'';' {$$ = build_node3(ARRAY, $2, $4, $7);}
| array identyan'['identyan']''['identyan']'';' {$$ = build_node3(ARRAY, $2, $4, $7);};

sentences: sentence sentences {$$ = build_node2(SENS, $1, $2;}
| sentence {$$ = bulid_node1($1);};

sentence: asastate {$$ = bulid_node($1);}
| loopsen {$$ = bulid_node($1);}
| brasen {$$ = bulid_node($1);}
| forsen {$$ = bulid_node($1);};

asastate: IDEN '=' expression ';' {$$ = build_node2(ASSIGN, $1, $3);}
  | assignment '=' expression ';' {$$ = build_node2(ASSIGN, $1, $3);}
  | incri;

incri: identyan cricri
| cricri identyan;

 assignment:identyan'['NUMBER']' {$$ = build_node2(ARRAY, $1, $3);}
| identyan'['identyan']' {$$ = build_node2(ARRAY, $1, $3);}
| identyan'['NUMBER']''['NUMBER']' {$$ = build_node3(ARRAY, $1, $3, $6);}
| identyan'['identyan']''['identyan']'  {$$ = build_node3(ARRAY, $1, $3, $6);};

expression : expression adsub term {$$ = build_node2(ADSUB, $1, $3);}
| term {$$ = build_node1($1);}; 

term : term muldiv fact {$$ = build_node2(MULDIV, $1, $3);}
| fact {$$ = build_node1($1);};

fact : variable {$$ = build_node1($1);}
  | '('expression')' {$$ = build_node1($2);};

  //adsub: '+' | '-'; //?????
  //muldiv:'*' | '/'; //?????

variable: identyan {$$ = build_node1($1);}
| NUMBER {$$ = build_num_node(NUM, $1);} 
| identyan'['NUMBER']' {$$ = build_node2(ARRAY, $1, $3);}
| identyan'['identyan']' {$$ = build_node2(ARRAY, $1, $3);}
| identyan'['NUMBER']''['NUMBER']' {$$ = build_node3(ARRAY, $1, $3, $6);}
| identyan'['identyan']''['identyan']'{$$ = build_node3(ARRAY, $1, $3, $6);};

identyan:IDEN {$$ = build_ident_node(IDENT, yytext);};

loopsen: WHILE '('condition')''{'sentences'}'{$$ = build_node2(WHILE_N, $3, $6);};

brasen: IF'('condition')''{'sentences'}'{$$ = build_node2(IF_N, $3, $6);};
| IF'('condition')''{'sentences'}'ELSE'{'sentences'}'{$$ = build_node3(IF_N, $3, $6, $10);};

forsen: FOR '('asastate  condition ';' asastate ')' '{'sentences'}'{$$ = build_node4(FOR_N, $3, $4, $6, $9);};

condition: expression compari expression {$$ = build_node2(compari_N, $1, $3);};

//compari: '=''=' | '<' | '>' | '<''=' | ">=";

%%
int main(void)
{
  if(yyparse()){
    fprintf(stderr, "Error\n");
    return 1;
  }
}
