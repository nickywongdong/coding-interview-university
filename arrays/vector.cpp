#include <stdlib.h>
#include "vector.h"


//Default Constructor-> Create array of size 16
vector::vector() {
  this->current_size = 16;
  this->num_items = 0;
  this->arr = (int*)malloc(sizeof(int) * this->current_size);
}

//Constructor
vector::vector(int size) {
  this->current_size = size;
  this->num_items = 0;
  this->arr = (int*)malloc(sizeof(int) * size);

}

//destructor
vector::~vector() {
  free(this->arr);
}


int vector::size() {
  return this->num_items;
}

int vector::capacity() {
  return this->current_size;
}

int vector::is_empty() {
  if(num_items == 0) {
    return 1;
  } else {
    return 0;
  }
}

int vector::at(int index) {
  return *(this->arr + index - 1);
}

void vector::push(int item) {
  if(this->current_size <= this->num_items) {
    //we want to resize the array to have enough room for new item
    this->resize(this->current_size * 2);
  }

  //assign the last "free" position of the array item
  *(this->arr + num_items) = item;

  this->num_items += 1;  //increment number of items in array
}

void vector::insert(int index, int item) {
  //test if adding one more item will overflow array or not:
  if(num_items + 1 >= current_size) {
    this->resize(this->current_size * 2);
  }

  //shift all items to the right of index over by 1:
  int i;
  for(i=this->num_items; i>index; i--) {
    *(this->arr + i) = *(this->arr + i - 1);
  }

  //set arr at 'index' to 'item'
  *(this->arr + index - 1) = item;

  this->num_items += 1;  //increment number of items in the array
}


void vector::prepend(int item) {
  insert(0, item);
}

int vector::pop() {
  this->num_items -= 1;

  return *(this->arr + num_items);
}

void vector::_delete(int index) {
  //shift all elements over to the left:
  int i;
  for(i=index; i<this->num_items; i++) {
    *(this->arr + i) = *(this->arr + i + 1);
  }

  this->num_items -= 1;  //decrement number of items
}

void vector::remove(int item) {
  int i;
  for(i=0; i<this->num_items; i++) { //search for element matching 'item'
    if(*(this->arr + i - 1) == item) {
      _delete(i);    //invoke delete method on found index
    }
  }
}

int vector::find(int item) {
  int i;
  for(i=0; i<this->num_items; i++) {
    if(*(this->arr + i - 1) == item) {
      return i;
    }
  }

  return -1;
}

void vector::resize(int new_capacity) {
  this->arr = (int*)realloc(this->arr, this->current_size * sizeof(int) * 2);
}
