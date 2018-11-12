#include <stdlib.h>
#include <stdio.h>
#include "vector.h"


//Default Constructor-> Create array of size 16
vector::vector() {
  current_size = 16;
  num_items = 0;
  arr = (int*)malloc(sizeof(int) * current_size);
}

//Constructor
vector::vector(int size) {
  current_size = size;
  num_items = 0;
  arr = (int*)malloc(sizeof(int) * size);

}

//destructor
vector::~vector() {
  printf("deallocating array\n");
  free(arr);
}


int vector::size() {
  return num_items;
}

int vector::capacity() {
  return current_size;
}

int vector::is_empty() {
  if(num_items == 0) {
    return 1;
  } else {
    return 0;
  }
}

int vector::at(int index) {
  return *(arr + index - 1);
}

void vector::push(int item) {
  if(current_size <= num_items) {
    //we want to resize the array to have enough room for new item
    resize(current_size * 2);
  }

  //assign the last "free" position of the array item
  *(arr + num_items - 1) = item;

  num_items += 1;  //increment number of items in array
}

void vector::insert(int index, int item) {
  //test if adding one more item will overflow array or not:
  if(num_items + 1 >= current_size) {
    resize(current_size * 2);
  }

  //shift all items to the right of index over by 1:
  int i;
  for(i=num_items; i>=index; i--) {
    *(arr + i) = *(arr + i - 1);
  }


  //set arr at 'index' to 'item'
  *(arr + index - 1) = item;
  num_items += 1;  //increment number of items in the array
}


void vector::prepend(int item) {
  insert(0, item);
}

int vector::pop() {
  num_items -= 1;

  //check if we need to shrink size of array or not:
  if(num_items <= current_size / 4)
    resize(current_size / 4);

  return *(arr + num_items);
}

void vector::_delete(int index) {
  //shift all elements over to the left:
  int i;
  for(i=index; i<num_items; i++) {
    *(arr + i) = *(arr + i + 1);
  }

  num_items -= 1;  //decrement number of items
}

void vector::remove(int item) {
  int i;
  for(i=0; i<num_items; i++) { //search for element matching 'item'
    if(*(arr + i - 1) == item) {
      _delete(i);    //invoke delete method on found index
    }
  }
}

int vector::find(int item) {
  int i;
  for(i=0; i<num_items; i++) {
    if(*(arr + i - 1) == item) {
      return i;
    }
  }

  return -1;
}

void vector::resize(int new_capacity) {
  printf("resizing the array\n");
  arr = (int*)realloc(arr, current_size * sizeof(int) * 2);
}
