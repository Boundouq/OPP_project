#include "CPU.hpp"

CPU :: CPU(){
  label = "NULL";
  frequency = 0;
  nb_core = 0;
  out_result = -1998;
  valid = false;
  CPU_path = "nono";
  program_path = "NULL";
  active_core = 0;
  valid_print = false;
}

CPU :: ~CPU(){};

void CPU ::  get_cpu_path(string cpu_path){
  CPU_path = cpu_path;
}

double CPU :: write(){
  if (valid){
    return -1998;
  }
  else{
    out_result = reg.write();
    return out_result;
  }
}

void CPU :: simulate(){
  double res;
  print_details();
  for(unsigned int i = 0; i < frequency ; i++){
    program.get_path(program_path);
    program.get_instruction();

    if (program.eof){
      core[active_core].valid = false;
      if (active_core < nb_core-1){
        active_core += 1;
        if (valid_print){
          cout << "\033[5m\033[1;35mActive core:"<< "\t"<< "\t"<< active_core+1 << "\033[0m" << endl;
          cout << endl;
        }
        core[active_core].valid = true;
      }
      else
        break;
    }

    if (core[active_core].valid){
      program.assignment();
      if (valid_print)  {cout << "Instruction "<< "\t"<< "Result"<< endl;
                        cout << "------------------------------------" << endl;}
      if (valid_print)  cout << program.instruction.instruction << "\t";
      res = core[active_core].calculate(program.instruction.operation,program.instruction.operand1,program.instruction.operand2);
      if (valid_print)  {cout << res << endl; cout<< endl;}

      data_in.data = res;
      reg.read(data_in);
    }
  }
}

void CPU :: initialisation(){
  fstream file;
  string caract;
  string :: size_type n;

  file.open(CPU_path);
  getline(file, caract);
  caract.erase(std::remove(caract.begin(),caract.end(),'\t'),caract.end());
  while (n != caract.size()) {
    n = caract.find(":");
    if (caract[n+1] == ' ') caract.erase(caract.begin()+n+1);
    else break;
  }
  if (caract == "TYPE:CPU"){
    while (getline(file, caract)){
      caract.erase(std::remove(caract.begin(),caract.end(),'\t'),caract.end());
      while (n != caract.size()) {
        n = caract.find(":");
        if (caract[n+1] == ' ') caract.erase(caract.begin()+n+1);
        else break;
      }
      if(caract.find("LABEL") == 0){
        n = caract.find(":");
        label = caract.substr(n+1);
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
      //if (caract.substr(n+2) = "\t" ||caract.substr(n+2) = " " )
        program_path = "" + caract.substr(n+1);
      }
      //else cout << "NOT COMPATIBLE FILE" << endl;
    }
  }
  else cout << "NOT COMPATIBLE PATH" << endl;

}

void CPU :: creat_cores(){
  core = new Core [nb_core];
  for (unsigned int i = 0; i<nb_core; i++){
    core[i].num(i+1);
    core[i].valid = false;
  }
  core[0].valid = true;
}

bool CPU :: isEmpty(){
  valid = reg.empty_reg();
  return valid;
}

void CPU :: valid_print_details(){
  valid_print = true;
}

void CPU :: print_details(){
  if (valid_print){
    cout << "\033[31;1m____________________________________\033[0m" << endl;
    cout << "\033[34;1mCPU Label: "<< "\t\t\t"<<label << "\033[0m"<< endl;
    cout << "\033[34;1mNumber of cores: "<< "\t\t"<< nb_core << "\033[0m"<< endl;
    cout << "\033[34;1mFrequency: "<< "\t\t\t"<< frequency << "\033[0m"<< endl;
    cout << "\033[5m\033[1;35mActive core:"<< "\t\t\t"<< active_core+1 << "\033[0m"<< endl;
    cout << endl;
  }
}
