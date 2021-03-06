#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "makeast.h"
#include "edu4.tab.h"

#define MAXBUF 10000


Node* build_node1(NType t, Node* p1){
  Node *p;
  p = (Node *)malloc(sizeof(Node));
  if(p == NULL){
    yyerror("out of memory");
  }
  p->type=t;
  p->child = p1;
  p->brother = NULL;

  return p;
};

Node* build_node2(NType t, Node* p1, Node* p2){
  Node *p;
  p = (Node *)malloc(sizeof(Node));
  if(p == NULL){
    yyerror("out of memory");
  }
  p->type=t;
  p->child = p1;
  p1->brother = p2;
  p->brother = NULL;

  return p;
};

Node* build_node3(NType t, Node* p1, Node* p2, Node* p3){
  Node *p;
  p = (Node *)malloc(sizeof(Node));
  if(p == NULL){
    yyerror("out of memory");
  }
  p->type=t;
  p->child = p1;
  p1->brother = p2;
  p2->brother = p3;
  p->brother = NULL;

  return p;
};

Node* build_node4(NType t, Node* p1, Node* p2, Node* p3, Node* p4){
  Node *p;
  p = (Node *)malloc(sizeof(Node));
  if(p == NULL){
    yyerror("out of memory");
  }
  p->type=t;
  p->child = p1;
  p1->brother = p2;
  p2->brother = p3;
  p3->brother = p4;
  p->brother = NULL;

  return p;
};

Node* build_num_node(NType t, int n){
  Node *p;
  p = (Node *)malloc(sizeof(Node));
  if(p == NULL){
    yyerror("out of memory");
  }
  p->type=t;
  p->ivalue = n;
  p->child = NULL;
  p->brother = NULL;

  return p;

};

Node* build_ident_node(NType t, char *s){
  Node *p;
  p=(Node *)malloc(sizeof(Node));
  if(p == NULL){
    yyerror("out of memory");
  }
  p -> type=t;
  p -> variable = (char *)malloc(sizeof(MAXBUF));
  if(p  == NULL){
      yyerror("out of memory");
    }
    strncpy(p -> variable, s, MAXBUF);
    p -> child = NULL;
    p -> brother = NULL;

    return p;
}

int count = 0;
int main_flag = 1;
int valnum = 0;
char* hensu[1000];

/* Node の表示*/
void printstate(Node *p){
  switch(p->type){
  case PROGRAM:
    /* printf("プログラム\n"); */
    //初期化の宣言をここに書くはず
    printf("\n");
    printf("\tINITIAL_GP = 0x10008000\t\t# initial value of global pointer\n");
    printf("\tINITIAL_SP = 0x7ffffffc\t\t# initial value of stack pointer\n");
    //#system call service number
    printf("\tstop_service = 99\n");

    printf("\n\t.text\t0x00001000\n");

    printf("\ninit:\n");
    
    //#initialize $gp and $sp
    printf("\tla\t$gp, INITIAL_GP\n");
    printf("\tla\t$sp, INITIAL_SP\n");
    
    printf("\tjal\tmain\n");
    printf("\tnop\n");

    printf("\tli\t$v0, stop_service\n");
    printf("\tsyscall\n");
    printf("\tnop\n");

    /* printstate(p->child); */
    /* printstate(p->child->brother); */
    break;
  case UNIONS:
    // printf("変数宣言部\n");
    break;
  case DECSEN:
    // printf("宣言文\n");
    printf("\tla\t$t%d, _%s\n", count, p->child->variable);
    printf("\tlw\t$t%d, 0($t%d)\n", count, count);
    count++;
    hensu[valnum] = p->child->variable;
    valnum++;
    
    break;
  case IDENT:
    /* printf("識別子\n"); */
    /* printf("%s\n", p->variable); */
    break;
  case NUM:
    /* printf("数値\n"); */
    /* printf("%d\n", p->ivalue); */
    break;
  case SENS:
    // printf("文集合\n");
    if(main_flag == 1){
    printf("main:\n");
    main_flag--;
    }
    break;
  case SEN:
    // printf("文\n");
    break;
  case ASSIGN:
    // printf("代入文=\n");
    if(p->child->brother->type == NUM){
    printf("\tli\t$t%d,%d\n", count, p->child->brother->ivalue);
    count++;
    }else{
      break;
    }
    break;
  case ARRAY:
    printf("配列\n");
    break;
  case EXP:
    printf("算術式\n");
    break;
  case TERM:
    printf("項\n");
    break;
  case FACT:
    printf("因子\n");
    break;
  case ADD:
    /* printf("+\n"); */
    if(p->child->brother->type == NUM){
    printf("\taddi\t$t%d, $t%d, %d\n", count, count, p->child->brother->ivalue);
    count++;
    }else if(p->child->brother->type == IDENT){
      printf("\taddu\t$t%d, $t%d, $t%d\n", count, count, count); //3番目の引数なおす
      count++;
    };
    break;
  case SUB:
    printf("-\n");
    break;
  case MUL:
    printf("*\n");
    break;
  case DIV:
    printf("÷\n");
    break;
  case KOTI_INCRI:
    printf("koti++\n");
    break;
  case KOTI_DECRI:
    printf("koti--\n");
    break;
  case ZEN_INCRI:
    printf("zen++\n");
    break;
  case ZEN_DECRI:
    printf("zen--\n");
    break;
  case WHILE_N: 
    //  printf("while\n");
    printf("LOOP:\n");
    break;
  case IF_N:
    printf("if\n");
    break;
  case FOR_N:
    printf("for\n");
    break;
  case DEQ:
    printf("==\n");
    break;
  case LT:
    // printf("<\n");
    printf("\tslt\t$t%d, $t%d, $t%d\n", count, count, count); //count
    printf("\tbne\t$t%d, $zero, LOOP\n", count);
    printf("\tnop\n");
    break;
  case GT:
    printf(">\n");
    break;
  case LE:
    printf("<=\n");
    break;
  case GE:
    printf(">=\n");
    break;
  default:
    printf("その他\n");
  }
}


void printNodes(Node *p){
  if (p != NULL) {
    printstate(p);
      if (p->child != NULL) {
	printNodes(p->child);
      }
      if (p->brother != NULL) {
	printNodes(p->brother);
      }
  }
}

Node *parse_result = NULL;

int main(){
  
  int result,i;
  
  
  result = yyparse();
  if(!result){
    printNodes(parse_result);
  }

  printf("\n.data\t0x10004000\n");
  for(i=0;i<valnum;i++){
   printf("_%s\t.word\t0x0000\n", hensu[i]);
  }
  return 0;

}
