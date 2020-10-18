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
    if (!eof){
      size_inst += inst.size()+1;
      instruction.getinst(inst);
      instruction_ptr += 1;
      return;
    }
    else {
        file.close();
        file.open(path);
        size_inst = 0;
        file.seekg (size_inst);
        getline(file, inst);
        instruction.getinst(inst);
        size_inst += inst.size()+1;
        instruction_ptr = 0;
        return;
    }
  }
  else cout << "PROGRAM NOT FOUND !!" << endl;
}

void CPU_program :: assignment(){
  instruction.getOperation_Operands();
  instruction.print();
}
