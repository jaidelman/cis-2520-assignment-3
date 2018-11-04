#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{

  char *data; //Stores string value
  double value; //Stores actual value
  struct node *left; //Left leaf
  struct node *right; //Right leaf

}node;

void postOrder(node *root); //Prints post order
void inOrder(node *root); //Prints in order
void preOrder(node *root); //Prints pre order
node *buildTree(char *expression); //Builds tree from string
bool isOperator(char a); //Checks if a character is an operator
void display(node *root, int height); //Displays the tree
double answer(node *root); //Finds answer to equation
void setValue(node *root); //Sets value of node
void update(node *root, char *var); //Updates value of node
int findHeight(node *root); //Finds height of subtree
void displayVariables(node *root); //Displays values of variables

int main(int argc, char *argv[]){

  node *root; //Root of expression tree
  char *expression; //Stores expression
  int input = 0; //Stores user input
  char *var = malloc(sizeof(char) * 10); //Stores the variable for setValue
  double ans; //Stores answer

  //Make sure correct amount of arguments
  if(argc != 2){
    printf("ERROR: EXPECTED INPUT: q1.c <EXPRESSION>\n");
    return -1;
  }

  //Builds tree
  expression = argv[1];
  root = buildTree(expression);

  //Loop for user input
  do{

    //Give options
    printf("Type 1 to display tree\nType 2 to display the preorder equation\n");
    printf("Type 3 to display the inorder equation\nType 4 to display the postorder equation\n");
    printf("Type 5 to update a variable\nType 6 to calculate the equation\nType 7 to exit\n");
    scanf("%d", &input);

    //Depending on the user input...
    switch(input){

      //Case 1, display tree and variables
      case 1:
        display(root, findHeight(root));
        displayVariables(root);
        printf("\n");
        break;

      //Case 2, print pre order
      case 2:
        preOrder(root);
        printf("\n");
        break;

      //Case 3, print in order
      case 3:
        inOrder(root);
        printf("\n");
        break;

      //Case 4, print post order
      case 4:
        postOrder(root);
        printf("\n");
        break;

      case 5:
        printf("Which variable would you like to update?\n");
        scanf("%s", var);
        update(root, var);
        break;

      case 6:
        ans = answer(root);
        printf("Answer: %.2lf\n", ans);
        break;

      case 7:
        printf("Exiting...\n");
        break;

      default:
        printf("Invalid number, please try again\n");
        break;

    }

  }while(input != 7);

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
    root->data = expression;
    root->left = NULL;
    root->right = NULL;
    root->value = 0.0;
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

        for(int j = i; j<strlen(expression); j++){

          if(isOperator(expression[j])){
            strcpy(operator, &expression[j]);
            operator[1] = '\0';
            root->data = operator;
            opIndex = j;

            j = strlen(expression);
          }

        }

        strcpy(lExpression, expression);
        lExpression[opIndex] = '\0';
        root->left = buildTree(lExpression);

        expression = expression + opIndex + 1;
        strcpy(rExpression, expression);
        root->right = buildTree(rExpression);
        break;
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
    printf("%s", (root->data));
  }

}

void preOrder(node *root){

  if(root == NULL){
    return;
  }
  else{
    printf("%s", (root->data));
    preOrder(root->left);
    preOrder(root->right);
  }

}

void inOrder(node *root){

  if(root == NULL){
    return;
  }
  if(root->left != NULL){
    printf("(");
    inOrder(root->left);
  }
  printf("%s", (root->data));

  if(root->right != NULL){
    inOrder(root->right);
    printf(")");
  }

}

bool isOperator(char a){

  if(a == '*' || a == '/' || a == '+' || a == '-'){
    return true;
  }
  return false;

}

void display(node *root, int height){

  if(root == NULL){
    return;
  }

  if(root->left != NULL){
    display(root->left, height -1);
  }

  for(int i = 0; i<height; i++){
    printf("\t");
  }
  printf("%s\n", root->data);

  if(root->right != NULL){
    display(root->right, height - 1);
  }
}

void displayVariables(node *root){

  double temp;

  if(root == NULL){
    return;
  }

  if(root->left != NULL){
    displayVariables(root->left);
  }

  if(isOperator(root->data[0]) == false && sscanf(root->data, "%lf", &temp) != 1){
    printf("Value of %s: %.2lf\n", root->data, root->value);
  }

  if(root->right != NULL){
    displayVariables(root->right);
  }

}

double answer(node *root){

  double ans = 0;
  double left, right;

  if(root == NULL){
    return 0;
  }

  if(root->left == NULL && root->right == NULL){
    setValue(root);
    ans = root->value;
    return ans;
  }

  left = answer(root->left);
  right = answer(root->right);

  if(root->data[0] == '+'){
    return left+right;
  }
  else if(root->data[0] == '-'){
    return left-right;
  }
  else if(root->data[0] == '/'){
    if(right == 0.0){
      printf("DIVIDE BY ZERO!\n");
      return -1;
    }
    return left/right;
  }
  else if(root->data[0] == '*'){
    return left*right;
  }

  return 0;
}

void setValue(node *root){

  double num;

  //If it's a variable
  if(sscanf(root->data, "%lf", &num) != 1){
    return;
  }
  //Else val is just what's in data
  else{
    root->value = num;
  }
}

void update(node *root, char *var){

  double num;

  if(root == NULL){
    return;
  }
  if(strcmp(root->data, var) != 0){
    update(root->left, var);
    update(root->right, var);
    return;
  }
  else{
    printf("What would you like to change %s to?\n", var);
    scanf("%lf", &num);
    root->value = num;
    return;
  }

}

int findHeight(node *root){

  int leftHeight = 1;
  int rightHeight = 1;
  node *temp = root;

  while(root != NULL){
    leftHeight++;
    root = root->left;
  }

  while(temp != NULL){
    rightHeight++;
    temp = temp->right;
  }

  if(leftHeight > rightHeight){
    return leftHeight;
  }
  else return rightHeight;
}
