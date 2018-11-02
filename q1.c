#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{

  char *item;
  struct node *left;
  struct node *right;

} node;

node *stringToTree(char *toParse);
void buildNode(node **root, char *item);
void insert(node **root, node *new);
void postOrder(node *root);

int main(int argc, char *argv[]){

  node *root;

  if(argc != 2){
    printf("ERROR: EXPECTED INPUT: q1.c <EXPRESSION>\n");
    return -1;
  }

  root = stringToTree(argv[1]);

  postOrder(root);
  printf("\n");

  return 0;
}

node *stringToTree(char *toParse){

  //Counts # of brackets
  //int rBracket = 0;
  //int lBracket = 0;
  node *root = NULL;

  for(int i = 0; i < strlen(toParse); i++){

    if(toParse[i] != ')' || toParse[i] != '('){
        buildNode(&root, &toParse[i]);
    }

  }

  return root;

}

void buildNode(node **root, char *item){

  node *new;
  new = malloc(sizeof(node));
  new->item = item;
  new->left = NULL;
  new->right = NULL;

  insert(root, new);

}

void insert(node **root, node *new){

  if(*root == NULL){
    (*root) = new;
    return;
  }
  else{

    if((*root)->left == NULL){
      insert( &((*root)->left), new );
    }
    else{
      insert( &((*root)->right), new );
    }
  }

}

void postOrder(node *root){

  if(root == NULL){
    return;
  }
  else{
    printf("%c ", *(root->item));
    postOrder(root->left);
    postOrder(root->right);
  }

}
