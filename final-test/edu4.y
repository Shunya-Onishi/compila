%{
  
#include <stdio.h>
#include "edu4.tab.h"
#include "makeast.h"
  extern int yylex();
  extern int yyerror();
  extern void printNodes(Node *p);
  extern char *yytext;
  %}
%union{
  struct node *node;
  int ival;
  char *sval;
  int *dummy;
  double dval;
 }

%token <sval> IDEN 
%token <ival> NUMBER
%token <dummy> array
%token <node> define
%token <dummy> ELSE
%token <dummy> IF
%token <dummy> WHILE
%token <dummy> add
%token <dummy> sub
%token <dummy> mul
%token <dummy> divi
%token <dummy> eq
%token <dummy> deq
%token <dummy> lt
%token <dummy> gt
%token <dummy> le
%token <dummy> ge
%token <node> incri
%token <node> decri
%token <dummy> FOR

%type <node> program
%type <node> unions
%type <node> decsen
%type <node> sentences
%type <node> sentence
%type <node> asastate
%type <node> cricri
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
%type <node> ntyan


%%

program: unions sentences {
  $$ = build_node2(PROGRAM, $1, $2);
  printNodes($$);
};

unions: decsen unions  {$$ = build_node2(UNIONS, $1, $2);}
| decsen  {$$ = build_node1(UNIONS, $1);}; 

//decsen: define IDEN ';' {$$ = build_node1(IDENT, $1);} //identyan DEC? 

decsen: define identyan ';' {$$ = build_node1(DECSEN, $2);} //identyan DEC? 
| array identyan'['ntyan']' ';' {$$ = build_node2(ARRAY, $2, $4);}
| array identyan'['identyan']' ';' {$$ = build_node2(ARRAY, $2, $4);}
| array identyan'['ntyan']''['ntyan']'';' {$$ = build_node3(ARRAY, $2, $4, $7);}
| array identyan'['identyan']''['identyan']'';' {$$ = build_node3(ARRAY, $2, $4, $7);};

sentences: sentence sentences {$$ = build_node2(SENS, $1, $2);}
| sentence {$$ = build_node1(SENS, $1);};

sentence: asastate {$$ = build_node1(SEN, $1);}
| loopsen {$$ = build_node1(SEN, $1);} 
| brasen {$$ = build_node1(SEN, $1);} 
| forsen {$$ = build_node1(SEN, $1);};

asastate: identyan '=' expression ';' {$$ = build_node2(ASSIGN, $1, $3);}
  | assignment '=' expression ';' {$$ = build_node2(ASSIGN, $1, $3);}
| cricri  {$$ = build_node1(ASSIGN, $1);};//????????????

cricri: identyan incri {$$ = build_node1(KOTI_INCRI, $1);}
| incri identyan {$$ = build_node1(ZEN_INCRI, $2);}
| identyan decri {$$ = build_node1(KOTI_DECRI, $1);}
| decri identyan {$$ = build_node1(ZEN_DECRI, $2);};

 assignment:identyan'['ntyan']' {$$ = build_node2(ARRAY, $1, $3);}
| identyan'['identyan']' {$$ = build_node2(ARRAY, $1, $3);}
| identyan'['ntyan']''['ntyan']' {$$ = build_node3(ARRAY, $1, $3, $6);}
| identyan'['identyan']''['identyan']'  {$$ = build_node3(ARRAY, $1, $3, $6);};

expression : expression add term {$$ = build_node2(ADD, $1, $3);}
| expression sub term {$$ = build_node2(SUB, $1, $3);}
| term {$$ = $1;}; //????
//| term {$$ = build_node1(EXP, $1);}; //????

term : term mul fact {$$ = build_node2(MUL, $1, $3);}
| term divi fact {$$ = build_node2(DIV, $1, $3);}
| fact {$$ = $1;}; //????
//| fact {$$ = build_node1(TERM, $1);}; //????

fact : variable {$$ = $1;} //?????
| '('expression')' {$$ = $2 ;};  //?????
//fact : variable {$$ = build_node1(FACT, $1);} //?????
//| '('expression')' {$$ = build_node1(FACT, $2);};  //?????
  //adsub: '+' | '-'; //?????
  //muldiv:'*' | '/'; //?????

variable: identyan {$$ = $1;} //?????
| ntyan {$$ = $1;} //?????
| identyan'['ntyan']' {$$ = build_node2(ARRAY, $1, $3);}
| identyan'['identyan']' {$$ = build_node2(ARRAY, $1, $3);}
| identyan'['ntyan']''['ntyan']' {$$ = build_node3(ARRAY, $1, $3, $6);}
| identyan'['identyan']''['identyan']'{$$ = build_node3(ARRAY, $1, $3, $6);};

identyan:IDEN {$$ = build_ident_node(IDENT, yytext);};

ntyan:NUMBER {$$ = build_num_node(NUM, $1);}; 

loopsen: WHILE '('condition')''{'sentences'}'{$$ = build_node2(WHILE_N, $3, $6);};

brasen: IF'('condition')''{'sentences'}'{$$ = build_node2(IF_N, $3, $6);};
| IF'('condition')''{'sentences'}'ELSE'{'sentences'}'{$$ = build_node3(IF_N, $3, $6, $10);};

forsen: FOR '('asastate  condition ';' asastate ')' '{'sentences'}'{$$ = build_node4(FOR_N, $3, $4, $6, $9);};

condition: expression deq expression {$$ = build_node2(DEQ, $1, $3);};
|expression lt expression {$$ = build_node2(LT, $1, $3);}
|expression gt expression {$$ = build_node2(GT, $1, $3);}
|expression le expression {$$ = build_node2(LE, $1, $3);}
|expression ge expression {$$ = build_node2(GE, $1, $3);}

//compari: '=''=' | '<' | '>' | '<''=' | ">=";

%%


int main(void)
{
  if(yyparse()){
    fprintf(stderr, "Error\n");
    return 1;
  }

  return 0;
}
