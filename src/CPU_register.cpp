#include "CPU_register.hpp"


CPU_register :: CPU_register(){
  FIFO f;
  fifo = f;
}


bool CPU_register :: empty_reg(){
  return fifo.isEmpty();
}

void CPU_register :: read(Data new_Data) {
  fifo.enqueue(new_Data);
}

double CPU_register :: write () {
  return fifo.dequeue ();
}

void CPU_register :: print_reg(){
  fifo.print();
}
