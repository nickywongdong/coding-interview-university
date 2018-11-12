#include <stdio.h>
#include "vector.h"

int main(void) {
  //create an instance of the class we defined in vector through default constructor:
  vector myVector;

  //insure that size is 16 (size we set as default):
  printf("Capacity of myVector: %d\n", myVector.capacity());
  printf("items in myVector before initializing: %d\n", myVector.size());
  //create an instance of the vector class with the constructor defined:
  //vector newVector(32);
  //printf("Capacity of newVector: %d\n", newVector.capacity());

  int i;
  for(i=0; i<5; i++) {
    myVector.push(i);
  }

  printf("Size of vector after pushing: %d\n", myVector.size());

  printf("Invoking is_empty. Should be 0: %d\n", myVector.is_empty());

  printf("Items in myVector: ");
  for(i=0; i<myVector.size(); i++) {
    printf("%d ", myVector.at(i));
  }
  printf("\n");

  //testing insert:
  myVector.insert(0, -1);
  printf("Items in myVector: ");
  for(i=0; i<myVector.size(); i++) {
    printf("%d ", myVector.at(i));
  }

  printf("seems to be a problem with destructor\n");

  return 0;
}
