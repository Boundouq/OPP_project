#include "CPU.hpp"

CPU :: CPU(){
  label = "NULL";
  frequency = 0;
  nb_core = 0;
  out_result = -1998;
  valid = false;
  CPU_path = "nono";
  program_path = "NULL";
}

double CPU :: write(){
  if (reg.empty_reg()){
    valid = false;
    cout << -1998 << endl;
    return -1998;
  }
  else{
    valid = true;
    out_result = reg.write();
    reg.print_reg();
    cout << out_result << endl;
    return out_result;
  }
}

void CPU :: simulate(){
  for(unsigned int i = 0; i < frequency ; i++){
    program.get_path(program_path);
    program.get_instruction();
    program.assignment();
    double res = 0; //= core.calculate(program.instruction.operation,program.instruction.operand1,program.instruction.operand2);
    data_in.data = res;
    reg.read(data_in);
    reg.print_reg();
  }
}

void CPU ::  get_cpu_path(string cpu_path){
  CPU_path = cpu_path;
}

void CPU :: initialisation(){
  fstream file;
  string caract;
  string :: size_type n;

  file.open(CPU_path);
  getline(file, caract);
  if (caract == "TYPE: CPU"){
    while (getline(file, caract)){
      if(caract.find("LABEL") == 0){
        n = caract.find(":");
        label = caract.substr(n+2);
      }
      else if(caract.find("CORES") == 0){
        n = caract.find(":");
        stringstream(caract.substr(n+1)) >> nb_core;
      }
      else if(caract.find("FREQUENCY") == 0){
        n = caract.find(":");
        stringstream(caract.substr(n+1)) >> frequency;
      }
      else if(caract.find("PROGRAM") == 0){
        n = caract.find(":");
        program_path = "../" + caract.substr(n+1);
      }
      else cout << "NOT COMPATIBLE FILE" << endl;
    }
  }
  else cout << "NOT COMPATIBLE PATH" << endl;

}

void CPU :: creat_cores(){
  core.resize(nb_core);
}

void CPU :: print(){
  cout << CPU_path << endl;
  cout << label << endl;
  cout << nb_core << endl;
  cout << frequency << endl;
  cout << program_path << endl;
}
