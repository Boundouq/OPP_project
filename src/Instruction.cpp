#include "Instruction.hpp"


Instruction :: Instruction (){
  instruction = "NOP 0 0";
}

void Instruction :: getOperation_Operands (){
  for (unsigned int i = 0; i < instruction.size(); i++ ){
    if ( instruction[i] == ' '){
      operation = instruction.substr(0,i);
      string operands = instruction.substr(i+1,instruction.size());
      for (unsigned int j = 0; i < operands.size(); j++ ){
        if ( operands[j] == ' '){
          stringstream(operands.substr(0,j)) >> operand1;
          stringstream(operands.substr(j+1,operands.size()-1)) >> operand2;
          return;
        }
      }
    }
  }
}

void Instruction :: print(){
  cout << "Operation: " << operation << endl;
  cout << "Operand 1: " << operand1 << endl;
  cout << "Operand 2: " << operand2 << endl;
  return;
}

void Instruction :: getinst(string inst){
  instruction = inst + ' ';
  return;
}
