#include "Core.hpp"

Core :: Core(){
  result = 0;
}

double Core :: calculate(string operation, double op1, double op2){
  if (operation == "ADD")
      return result = op1 + op2 ;
  else if (operation == "SUB")
      return result = op1 - op2 ;
  else if (operation == "MUL")
      return result = op1 * op2 ;
  else if (operation == "DIV")
      return result = op1 / op2 ;
  else if (operation == "NOP")
      return result = 0 ;
  else return result = -1998;
}

void Core :: num(unsigned int i){
  num_core = i;
}

void Core :: print(){
  cout << "le num du core qui calcule : " << num_core << endl;
}
