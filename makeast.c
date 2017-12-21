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

NType t;

Node* build_node1(Node* p1){
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
      
