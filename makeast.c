#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "makeast.h"

#define MAXBUF 10000

/*
void test(){
  Node *p;
  p = (Node *)malloc(sizeof(Node));
  p->type = WHILE;
  p->child = p1;
  p1->brother = p2; // p->child->brother = p2 でもよい
  p->brother = NULL;

  return p;
};
*/


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

/* Node の表示*/
void printstate(Node *p){
  switch(p->type){
  case PROGRAM:
    printf("プログラム\n");
    break;
  case UNIONS:
    printf("変数宣言部\n");
    break;
  case IDENT:
    printf("識別子\n");
    break;
  case NUM:
    printf("数値\n");
    break;
  case SENS:
    printf("文集合\n");
    break;
  case ASSIGN:
    printf("代入文\n");
    break;
  case ARRAY:
    printf("配列\n");
    break;
  case ADSUB:
    printf("加減算\n");
    break;
  case MULDIV:
    printf("乗除算\n");
    break;
  case INCRI:
    printf("インクリメント\n");
    break;
  case WHILE_N:
    printf("while\n");
    break;
  case IF_N:
    printf("if\n");
    break;
  case FOR_N:
    printf("for\n");
    break;
  case compari_N:
    printf("compari\n");
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
