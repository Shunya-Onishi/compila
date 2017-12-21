#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "edu4.tab.h"

extern int yyerror();

typedef enum {
  IDENT, //変数のノード型
  NUM, //整数のノード型
  SENS, //文集合のノード型
  ASSIGN, //代入文の　=　のノード型

  ARRAY, //配列だよ～～

  //PLUS, //加算演算子のノード型
  //MINUS, //減算演算子のノード型
  ADSUB, //加減算
  MULDIV, //乗除算

  WHILE_N, // whileのノード型
  IF_N, // ifのノード型
  FOR_N, // forのノード型

  compari_N, //
  

} NType;

typedef struct node{
  NType type;
  int ivalue; // 整数の場合の値を入れる
  char* variable; // 変数の場合、変数名の文字列を入れる
  struct node *child;
  struct node *brother;
} Node;

Node* build_node1(Node* p1);
Node* build_node2(NType t, Node* p1, Node* p2);
Node* build_node3(NType t, Node* p1, Node* p2, Node* p3);
Node* build_node4(NType t, Node* p1, Node* p2, Node* p3, Node* p4);
Node* build_num_node(NType t, int n);
Node* build_ident_node(NType t, char *s);



/*
typedf symbols{
  int symno;  //変数番号，ユニークになるようにつけること
  char *symbolname; //変数名
  struct symbols* next; //次の変数へのリンク
}Symbols;
*/
