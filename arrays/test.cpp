#include <stdio.h>
#include "vector.h"

int main(void) {
  //create an instance of the class we defined in vector through default constructor:
  vector myVector;

  //insure that size is 16 (size we set as default):
  printf("Size of vector: %d\n", myVector.capacity());

  //create an instance of the vector class with the constructor defined:
  vector newVector(32);
  printf("Size of vector: %d\n", newVector.capacity());



  return 0;
}
