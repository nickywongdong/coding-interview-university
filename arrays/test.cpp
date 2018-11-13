#include <stdio.h>
#include "vector.h"

int main() {
  //create an instance of the class we defined in vector:
  vector myVector;


  /*
  Test size() - number of items:
  */
  printf("Capacity of myVector: %d\n", myVector.capacity());
  printf("items in myVector before initializing: %d\n", myVector.size());


  printf("Pushing 5 items into array...\n");
  int i;
  for(i=0; i<5; i++) {
    myVector.push(i);
  }

  printf("Size of vector after pushing: %d\n", myVector.size());
  printf("Capacity of myVector after pushing: %d\n", myVector.capacity());

  /*
  Testing is_empty():
  */

  printf("Invoking is_empty: %d\n", myVector.is_empty());


  printf("Items in myVector: ");
  for(i=0; i<myVector.size(); i++) {
    printf("%d ", myVector.at(i));
  }
  printf("\n");

  printf("Inserting -1 into 0 position...\n");
  //testing insert:
  myVector.insert(0, -1);
  printf("Items in myVector after insert: ");
  for(i=0; i<myVector.size(); i++) {
    printf("%d ", myVector.at(i));
  }
  printf("\n");

  /*
  Testing at():
  */
  printf("Item at index 2: %d\n", myVector.at(2));
  printf("Item at index out of bounds: %d\n", myVector.at(20));

  /*
  testing prepend():
  */
  printf("Prepending 5 to myVector...\n");
  myVector.prepend(5);
  printf("myVector after prepend: \n");
  for(i=0; i<myVector.size(); i++) {
    printf("%d ", myVector.at(i));
  }
  printf("\n");

  /*
  testing pop():
  */

  printf("Popping last element...\n");
  printf("Last element of myVector is: %d\n", myVector.pop());
  printf("myVector after pop: \n");
  for(i=0; i<myVector.size(); i++) {
    printf("%d ", myVector.at(i));
  }
  printf("\n");

  /*
  testing delete():
  */
  printf("deleting element 0 of myVector...\n");
  myVector._delete(0);
  printf("myVector after delete(): \n");
  for(i=0; i<myVector.size(); i++) {
    printf("%d ", myVector.at(i));
  }
  printf("\n");

  /*
  testing remove():
  */
  printf("removing any 1's of myVector...\n");
  myVector.remove(1);
  printf("myVector after remove(): \n");
  for(i=0; i<myVector.size(); i++) {
    printf("%d ", myVector.at(i));
  }
  printf("\n");

  /*
  Testing find():
  */

  printf("finding 2 in myVector...\n");
  printf("2 is at index %d\n", myVector.find(2));

  /*
  testing resize by pushing more items:
  */
  printf("myVector capacity before pushing multiple items: %d\n", myVector.capacity());
  for(i=0; i<20; i++) {
    myVector.push(i);
  }
  printf("myVector capacity after pushing multiple items: %d\n", myVector.capacity());

  printf("myVector capacity before popping multiple items: %d\n", myVector.capacity());
  printf("myVector items before popping multiple items: %d\n", myVector.size());

  for(i=0; i<17; i++) {
    myVector.pop();
  }
  printf("myVector capacity after popping multiple items: %d\n", myVector.capacity());
  printf("myVector items after popping multiple items: %d\n", myVector.size());

  return 0;
}
