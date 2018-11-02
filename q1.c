#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{

  char *item;
  struct node *left;
  struct node *right;

} node;

typedef struct tree{
  node *root;
}tree;

void stringToTree(char *toParse);
void buildNode(tree t, char *item);
void insert(node **t, node *new);

int main(int argc, char *argv[]){

  char *expression; //Stores expression

  if(argc != 2){
    printf("ERROR: EXPECTED INPUT: q1.c <EXPRESSION>\n");
    return -1;
  }

  expression = argv[1];
  stringToTree(expression);

  return 0;
}

void stringToTree(char *toParse){

  //Counts # of brackets
  //int rBracket = 0;
  //int lBracket = 0;
  tree *t;

  for(int i = 0; i < strlen(toParse); i++){

    if(toParse[i] != ')' || toParse[i] != '('){
        buildNode(&t, &toParse[i]);
    }

  }

}

void buildNode(tree t, char *item){

  node *new;
  new = malloc(sizeof(node));
  new->item = item;
  new->left = NULL;
  new->right = NULL;
  insert(&(t.root), new);

}

void insert(node **t, node *new){

  node *base = *t;

  if(base == NULL){
    *t = new;
    return;
  }
  else{
    if(base->left == NULL){
      insert( &(base->left), new );
    }
    else{
      insert( &(base->right), new );
    }
  }

}
