#include <stdio.h>
#include <stdlib.h>

//To store array-based heap of objects
typedef struct object{

  int key[3];
  int data[7];

}object;

int keyLess(object *a, object *b); //Find if key 1 is less than key 2
void printObj(object obj, int i); //Prints object
void downheap(object heap[21], int index); //Applies Downheap
void preOrder(object *root, int i); //Prints pre-order traversal

int main(){

  object heap[21]; //Array based heap
  FILE *fp; //File pointer

  fp = fopen("f.dat", "r");


  //Read data into array of objects to create heap
  for(int i = 1; i<21; i++){

    for(int j = 0; j<10; j++){

      if(j<3){
        fscanf(fp, "%d", &heap[i].key[j]);
      }
      else{
        fscanf(fp, "%d", &heap[i].data[j-3]);
      }

    }

  }
  fclose(fp); //Close file

  for(int i = 10; i>0; i--){
    //Downheap every node to make it a max-heap
    downheap(heap, i);
  }

  //preOrder print
  printf("PREORDER TRAVERSAL\n-------------------------\n");
  preOrder(heap, 1);

  //InOrder print
  printf("\n\nINORDER TRAVERSAL\n------------------------\n");
  for(int i = 1; i<21; i++){
    printObj(heap[i], i);
  }


  return 0;
}

//Runs downheap on heap to make it a max-heap
void downheap(object heap[21], int index){

  object temp;

  //For all parent nodes, check if left child is less than parent, and swap if true
  if(index < 11 && keyLess(&heap[index*2], &heap[index]) == 1){

    if(index == 1) printf("HERE\n");
    //Swap
    temp = heap[index*2];
    heap[index*2] = heap[index];
    heap[index] = temp;

    //Downheap again on child
    downheap(heap, index*2);
  }
  //For all parent nodes (with a right child), check if right child is less than parent, and swap if true
  if(index < 10 && keyLess(&heap[index*2+1], &heap[index]) == 1){

    //Swap
    temp = heap[index*2+1];
    heap[index*2+1] = heap[index];
    heap[index] = temp;

    //Downheap again on child
    downheap(heap, index*2+1);
  }

}

//Checks if sum of keys is less than sum of keys of another object
int keyLess(object *a, object *b){

  //To store totals
  int aTotal = 0;
  int bTotal = 0;

  //Adds keys
  for(int i = 0; i<3; i++){

    aTotal += a->key[i];
    bTotal += b->key[i];

  }

  //If it's less, return 1
  if(aTotal<bTotal){
    return 1;
  }
  //Else return 0
  else{
    return 0;
  }
}

//Prints in pre-order
void preOrder(object *root, int i){

  //If invalid range, return
  if(i > 20 || i < 0){
    return;
  }
  //Else apply pre-order algorithm
  else{
    printObj(root[i], i);
    preOrder(root, i*2);
    preOrder(root, i*2+1);
  }

}

//Prints object
void printObj(object obj, int i){

  int keyTotal = 0; //Stores sum of keys
  printf("index %d: ", i); //Prints index of array

  //Prints out keys and adds them to keyTotal
  for(int i = 0; i<3; i++){
    printf("%d ", obj.key[i]);
    keyTotal += obj.key[i];
  }
  //Prints out data
  for(int j = 0; j<7; j++){
    printf("%d ", obj.data[j]);
  }
  //Prints out keyTotal so you know if downheap was applied correctly
  printf("KeyTotal: %d\n", keyTotal);

}
