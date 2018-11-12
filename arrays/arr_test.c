#include <stdio.h>
#include <stdlib.h>

//wow this is cool

int main(void) {

  int *arr;

  //initialize dynamic array with all 1's
  arr = malloc(sizeof(int) * 10);
  for(int i=0; i<10; i++) {
    *(arr + i) = 1;
  }


  //display the 1's
  for(int i=0; i<10; i++) {
    printf("%d", *(arr + i));
  }

  printf("\n");

  //assign values using pointer arithmetic
  for(int i=0; i<10; i++) {
    *(arr + i) = i;
  }

  printf("\n");


  //display new array using pointer arithmetic
  for(int i=0; i<10; i++) {
    printf("%d", *(arr + i));
  }

  //testing array access through pointer arithmetic
  int index = 5;
  printf("\n%d\n", *(arr + 5 - 1)); //should print the 5'th element


  //testing if we can use pointer arithmetic on unitialized values in an array:
  int *newArray = malloc(sizeof(int) * 10);

  //commenting this out causes conditional memory jumps:
  for(int i=0; i<10; i++) {
    *(newArray + i) = 0;
  }

  //must be initialized before we do this?
  for(int i=0; i<10; i++) {
    printf("%d ", *(newArray + i));
  }
  //looks like we cannot!!



  //yes you can
  printf("\n");

  printf("freeing dynamic memory\n");
  free(arr);
  printf("successfully freed dynamic memory\n");
  return 0;
}
