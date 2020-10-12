#include "CPU_program.hpp"

CPU_program :: CPU_program(){
  instruction_ptr = -1;
  size_inst = 0;
  eof = false;
}
void CPU_program :: get_path(string str){
  path = str;
}

void CPU_program :: get_instruction(){
  fstream file;
  file.open(path);
  string inst;

  if (file.is_open()){
    file.seekg (size_inst);
    eof = !getline(file, inst);
    size_inst += inst.size()+1;

    instruction.getinst(inst);
    if (eof) {
      instruction.getinst("NOP 0 0");
      instruction_ptr = -1;
      size_inst = 0;
      return;
    }
    instruction_ptr += 1;
  }
  else cout << "ERROR" << endl;
}

void CPU_program :: assignment(){
  instruction.getOperation_Operands();
  instruction.print();
}
