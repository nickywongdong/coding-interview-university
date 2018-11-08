#include <iostream>
#include "vector.h"


//Default Constructor. Create array of size 16
vector::vector() {
  this.current_size = 16;
  this.num_items = 0;
  this.arr = malloc(sizeof(int) * this.current_size);
}

//Constructor
vector::vector(int size) {
  this.current_size = size;
  this.num_items = 0;
  this.arr = malloc(sizeof(int) * size);

}

//destructor
vector::~vector() {
  free(this.arr);
}


int vector::size() {
  return this.num_items;
}

int vector::capacity() {
  return this.current_size;
}

int vector::is_empty() {
  if(num_items == 0) {
    return 1;
  } else {
    return 0
  }
}

int vector::at(int index) {
  return *(this.arr + index - 1);
}

void vector::push(int item) {
  if(this.current_size <= this.num_items) {
    //we want to resize the array to have enough room for new item
    this.resize(this.current_size * 2);
  }

  //assign the last "free" position of the array item
  *(this.arr + num_items) = item;
}
void vector::insert(int index, int item);
void vector::prepend(int item);
int vector::pop();
void vector::delete(int index);
void vector::remove(int item);
int vector::find(int item);
void vector::resize(int new_capacity);
