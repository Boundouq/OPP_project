#include "Instruction.hpp"


Instruction :: Instruction (){
  instruction = "NOP 0 0";
  nb_operands = 0;
}

void Instruction :: getOperation_Operands (){
  int  cnt = 0,cntr = 0;
  double op;
  vector<double> v;
  for (unsigned int i = 0; i < instruction.size(); i++ ){
    if ( instruction[i] == ' '){
      operation = instruction.substr(0,i);
      string operand = instruction.substr(i+1,instruction.size());
      cnt = 0;
      for (unsigned int j = 0; j < operand.size(); j++ ){
        if ( operand[j] == ' '){
          cntr += 1;
          stringstream(operand.substr(cnt,j)) >> op;
          v.push_back(op);
          cnt = j+1;
        }
      }
      nb_operands = cntr;
      operands = v;
      break;
    }
  }
}

void Instruction :: getinst(string inst){
  instruction = inst + ' ';
  return;
}
