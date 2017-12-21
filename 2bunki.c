
/**********************************/
/* 二分探索木　解答例　　　　　　     */
/**********************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *left;
  struct node *right;
} Node;

/* Node の作成*/
Node *
newNode(int n) {
  Node *obj;
  obj = (Node *)malloc(sizeof(Node));
  obj->value = n;
  obj->left = NULL;
  obj->right = NULL;
  return obj;
}


/* Node の追加*/
Node *
addNode(Node *obj, int n) {
  /* obj が NULL の場合*/
  if (obj == NULL) {
    return newNode(n);
  }

  /* 追加する場所を探して追加 */
  if (obj->value == n) { /* obj->value == n の時は追加しない*/
    /* do nothing */
  } else if(obj->value < n) {
    obj->right = addNode(obj->right, n);
  } else { /* obj->value > n の時*/
    obj->left = addNode(obj->left, n);
  }
    
  return obj;
} /* end of addNode */

/* Nodes を一番右に追加*/
Node *
appendRightEnd(Node *obj, Node *right) {
  if (obj != NULL) {
    if (obj->right == NULL) {
      obj->right = right;
    } else {
      obj->right = appendRightEnd(obj->right, right);
    }
  }
  return obj;
}

/* Node の削除 */
Node *
deleteNode(Node *obj, int n) {
  Node *newobj;

  if (obj != NULL) {
    if (obj->value == n) {

      if (obj->left == NULL) {
        newobj = obj->right;
        free(obj);
        return newobj;
      } else if(obj->right == NULL) {
        newobj = obj->left;
        free(obj);
        return newobj;
      } else {
        /* 右の子供たちのつけかえ */
        obj->left = appendRightEnd(obj->left, obj->right);
        newobj = obj->left;
        free(obj);
        return newobj;
      }
    } else {
      if (obj->value < n)
        obj->right = deleteNode(obj->right, n);
      else
        obj->left = deleteNode(obj->left, n);
      }
  }
  return obj;
}


/* Node の表示*/
void 
printNodes(Node *obj){
  if (obj != NULL) {
    if (obj->left != NULL) {
      printNodes(obj->left);
    }

    printf("%d\t", obj->value);

    if (obj->right != NULL) {
      printNodes(obj->right);
    }
  }

}

int
main(int argc, char *argv[]){
  Node *topnode = NULL;

  topnode = addNode(topnode, 5);
  topnode = addNode(topnode, 7);
  topnode = addNode(topnode, 1);
  topnode = addNode(topnode, -1);
  topnode = addNode(topnode, 4);
  topnode = addNode(topnode, 10);
  
  printNodes(topnode);
  printf("\n");

  topnode = deleteNode(topnode, 5);

  printNodes(topnode);

  return 0;
}

