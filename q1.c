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

      //Case 5, updates variable
      case 5:
        printf("Which variable would you like to update?\n");
        scanf("%s", var);
        update(root, var);
        break;

      //Case 6, finds answer to expression
      case 6:
        ans = answer(root);
        printf("Answer: %.2lf\n", ans);
        break;

      //Exits program
      case 7:
        printf("Exiting...\n");
        break;

      //Otherwise invalid number
      default:
        printf("Invalid number, please try again\n");
        break;

    }

  }while(input != 7);

  return 0;
}

/*
  Builds a tree based on a string.
  Takes a string (InOrder expression) paramater
  Returns a pointer to a root node
*/
node *buildTree(char *expression){

  node *root = malloc(sizeof(node)); //Creates node
  int lBracket = 0; //Counts right brackets
  int rBracket = 0; //Counts left brackets
  int opIndex = 0; //Finds index of operator
  char *operator = malloc(sizeof(char)); //Stores operator

  //Stores strings on each side of operator
  char *rExpression = malloc(sizeof(char) * strlen(expression)/2);
  char *lExpression = malloc(sizeof(char) * strlen(expression)/2);

  //If string doesn't start on a bracket, set data to expression and children to NULL
  if(expression[0] != '('){
    root->data = expression;
    root->left = NULL;
    root->right = NULL;
    root->value = 0.0; //Default object has a value of 0.0
  }

  //Otherwise...
  else{

    //Cut off brackets from the ends
    expression[strlen(expression)-1] = '\0';
    expression = expression + 1;

    //To find an expression to cut up (when lBracket and rBracket are equal)
    for(int i = 0; i<strlen(expression); i++){

      //Count brackets
      if(expression[i] == ')'){
        rBracket++;
      }
      else if(expression[i] == '('){
        lBracket++;
      }

      //When they are equal
      if(rBracket == lBracket){

        //Find position of operator
        for(int j = i; j<strlen(expression); j++){

          if(isOperator(expression[j])){
            strcpy(operator, &expression[j]);
            operator[1] = '\0';
            root->data = operator; //Set data to correct operator
            opIndex = j; //Save index of operator

            j = strlen(expression); //End for loop
          }

        }

        //Copy everything before the operator to lExpression, then recurse
        strcpy(lExpression, expression);
        lExpression[opIndex] = '\0';
        root->left = buildTree(lExpression);

        //Copy everything after the operator to rExpression, then recurse
        expression = expression + opIndex + 1;
        strcpy(rExpression, expression);
        root->right = buildTree(rExpression);
        break; //Once done stop looping
      }
    }
  }


  return root;
}

/*
  Prints in post order notation
  takes in a root, returns nothing
*/
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

/*
  Prints in pre order notation
  takes in a root, returns nothing
*/
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

/*
  Prints in in-order notation
  takes in a root, returns nothing
*/
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

/*
  Checks if a char is an operator. Takes in a character
  returns a boolean true or false
*/
bool isOperator(char a){

  if(a == '*' || a == '/' || a == '+' || a == '-'){
    return true;
  }
  return false;

}

//Displays a tree. Takes a root and a height to know how many times to tab
void display(node *root, int height){

  //Base case
  if(root == NULL){
    return;
  }

  /* Otherwise, use an in-order traversal to print */

  //If left exists, recurse with height -1
  if(root->left != NULL){
    display(root->left, height -1);
  }

  //Print appropriate # of tabs and then the string
  for(int i = 0; i<height; i++){
    printf("\t");
  }
  printf("%s\n", root->data);

  //If right exists, recurse with height - 1
  if(root->right != NULL){
    display(root->right, height - 1);
  }
}

//Displays the value of variables
void displayVariables(node *root){

  double temp;

  //Base case
  if(root == NULL){
    return;
  }

  /* Uses in-order traversing to find correct node*/
  if(root->left != NULL){
    displayVariables(root->left);
  }

  //If the node is not an operator or a number, print value
  if(isOperator(root->data[0]) == false && sscanf(root->data, "%lf", &temp) != 1){
    printf("Value of %s: %.2lf\n", root->data, root->value);
  }

  if(root->right != NULL){
    displayVariables(root->right);
  }

}

//Calculates expression
double answer(node *root){

  double ans = 0; //To store answer
  double left, right; //To store right and left values

  //Base case
  if(root == NULL){
    return 0;
  }

  //If the node isn't a parent
  if(root->left == NULL && root->right == NULL){
    setValue(root); //Find value of node
    ans = root->value; //Return value
    return ans;
  }

  //Recurse to get all values
  left = answer(root->left);
  right = answer(root->right);

  //If root is an operator, apply it to it's children
  if(root->data[0] == '+'){
    return left+right;
  }
  else if(root->data[0] == '-'){
    return left-right;
  }
  else if(root->data[0] == '/'){

    //Divide by 0 check
    if(right == 0.0){
      printf("DIVIDE BY ZERO! Returning -1...\n");
      return -1;
    }
    return left/right;

  }
  else if(root->data[0] == '*'){
    return left*right;
  }

  return 0;
}

//Sets the value in a node
void setValue(node *root){

  double num;

  //If it's a variable, don't set the value
  if(sscanf(root->data, "%lf", &num) != 1){
    return;
  }
  //Else val is just what's in data
  else{
    root->value = num;
  }
}

//Updates a variables value
void update(node *root, char *var){

  double num;

  //Base case
  if(root == NULL){
    return;
  }
  //Recursive search for correct variable
  if(strcmp(root->data, var) != 0){
    update(root->left, var);
    update(root->right, var);
    return;
  }
  //When found, ask for new value and set the value
  else{
    printf("What would you like to change %s to?\n", var);
    scanf("%lf", &num);
    root->value = num;
    return;
  }

}

//Finds height of parental node. Returns height
int findHeight(node *root){

  int leftHeight = 1; //Counts # of left children
  int rightHeight = 1; //Counts # of right children
  node *temp = root; //Temp root to check right side

  //Finds how many left nodes there are
  while(root != NULL){
    leftHeight++;
    root = root->left;
  }

  //Finds how many right nodes there are
  while(temp != NULL){
    rightHeight++;
    temp = temp->right;
  }

  //Get biggest and return
  if(leftHeight > rightHeight){
    return leftHeight;
  }
  else return rightHeight;
}
