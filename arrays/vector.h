#include <iostream>


class vector
{
private:
  int current_size;
  int num_items;
  int *arr;
  void resize(int new_capacity);

public:
  vector();
  vector(int size);
  ~vector();
  int size();
  int capacity();
  int is_empty();
  int at(int index);
  void push(int item);
  void insert(int index, int item);
  void prepend(int item);
  int pop();
  void delete(int index);
  void remove(int item);
  int find(int item);
}
