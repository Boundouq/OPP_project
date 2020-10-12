#include "FIFO.hpp"

FIFO :: FIFO(){
  head = tail = NULL;
}

bool FIFO :: isEmpty(){
  if (head == NULL) return true;

  return false;
}

void FIFO :: enqueue(Data new_Data){
  Data* add_Data = new Data;
  add_Data -> data = new_Data.data;
  add_Data -> next = NULL;

  if (isEmpty()){
    head = tail = add_Data;
    return;
  }
  tail -> next = add_Data;
  tail = add_Data;
  return;
}

double FIFO :: dequeue(){
  if (isEmpty()){
    return -1;
  }
  double value = head -> data;
  Data* out = head;
  head = head -> next;
  out -> next = NULL;
  delete out;
  return value;
}

void FIFO:: print(){
  Data* out = head;

  while (out != NULL) {
    cout << out -> data << endl;
    out = out -> next;
  }
  return;
}
