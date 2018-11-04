#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{

  char *item;
  struct node *left;
  struct node *right;

}node;

void postOrder(node *root);
node *buildTree(char *expression);
bool isOperator(char a);

int main(int argc, char *argv[]){

  node *root;
  char *expression;

  if(argc != 2){
    printf("ERROR: EXPECTED INPUT: q1.c <EXPRESSION>\n");
    return -1;
  }

  expression = argv[1];
  root = buildTree(expression);

  postOrder(root);
  printf("\n");

  return 0;
}

node *buildTree(char *expression){

  node *root = malloc(sizeof(node));
  int lBracket = 0;
  int rBracket = 0;
  int opIndex = 0;
  char *operator = malloc(sizeof(char));
  char *rExpression = malloc(sizeof(char) * strlen(expression)/2);
  char *lExpression = malloc(sizeof(char) * strlen(expression)/2);

  if(expression[0] != '('){
    root->item = expression;
    root->left = NULL;
    root->right = NULL;
  }
  else{
    expression[strlen(expression)-1] = '\0';
    expression = expression + 1;

    for(int i = 0; i<strlen(expression); i++){

      if(expression[i] == ')'){
        rBracket++;
      }
      else if(expression[i] == '('){
        lBracket++;
      }

      if(rBracket == lBracket){
printf("Index: %d\n", i);
printf("Char @ index: %c\n", expression[i]);
        for(int j = 0; j<strlen(expression); j++){

          if(isOperator(expression[j])){
            strcpy(operator, &expression[j]);
            operator[1] = '\0';
            root->item = operator;
            opIndex = j;

            j = strlen(expression);
          }

        }

        strcpy(lExpression, expression);
        lExpression[opIndex] = '\0';
        printf("L: %s\n", lExpression);
        root->left = buildTree(lExpression);

        expression = expression + opIndex + 1;
        strcpy(rExpression, expression);
        printf("R: %s\n", rExpression);
        root->right = buildTree(rExpression);
      }
    }
  }


  return root;
}

void postOrder(node *root){

  if(root == NULL){
    return;
  }
  else{
    postOrder(root->left);
    postOrder(root->right);
    printf("%s", (root->item));
  }

}

bool isOperator(char a){

  if(a == '*' || a == '/' || a == '+' || a == '-'){
    return true;
  }
  return false;

}
