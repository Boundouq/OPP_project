#include "CPU_register.hpp"

CPU_register :: CPU_register(){
  head = tail = NULL;
}

bool CPU_register :: empty_reg(){
  if (head == NULL) return true;

  return false;
}

void CPU_register :: read(Data new_Data){
  Data* add_Data = new Data;
  add_Data -> data = new_Data.data;
  add_Data -> next = NULL;

  if (empty_reg()){
    head = tail = add_Data;
    return;
  }
  tail -> next = add_Data;
  tail = add_Data;
  return;
}

double CPU_register :: write(){
  if (empty_reg()){
    return -1;
  }
  double value = head -> data;
  Data* out = head;
  head = head -> next;
  out -> next = NULL;
  delete out;
  return value;
}

void CPU_register:: print_reg(){
  Data* out = head;
 cout << "CPU_register Values :" << endl;
  while (out != NULL) {
    cout << out -> data << endl;
    out = out -> next;
  }
  return;
}
