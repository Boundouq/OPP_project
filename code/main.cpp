//#include "CPU_register.hpp"
//#include "CPU_program.hpp"
//#include "Core.hpp"
//#include "CPU.hpp"
#include "Platform.hpp"

// test of CPU_register
/*int main(){
  CPU_register new_reg;
  double data;
  Data new_Data;
  Data* get_Data = new Data;
  char sel;

  while(true){
    cout << "choose one of the following operations:" << endl;
    cout << "a - add data:" << endl;
    cout << "b - print your queue:" << endl;
    cout << "c - remove the last element:" << endl;

    cin >> sel;

    switch(sel){
      case 'a':
        cout << "enter a data: ";
        cin >> data;
        new_Data.data = data;
        new_reg.read(new_Data);
        cout << endl << endl;
        break;
      case 'b':
        new_reg.print_reg();
        cout << endl;
        break;
      case 'c':
        new_reg.write(get_Data);
        cout << get_Data -> data << endl;
        break;
      default: break;
    }
  }
  return 0;
}
*/

//test of Instruction
/*int main(){
  Instruction in;
  string inst;
  std::cout << " add inctruction : " << '\n';
  getline (cin, inst);
  in.getinst(inst);
  in.getOperation_Operands ();
  in.print();
}
*/

//test of CPU_program
/*int main(){
  CPU_program prog ;
  Core core;
  Instruction inst;
  string path;
  std::cout << " add file : " << '\n';
  while(true){
    getline (cin, path);
    prog.get_path(path);
    prog.get_instruction();
    prog.assignment();
  }
}
*/

//test of Core
/*
int main(){
  string op;
  double op1,op2;
  cout << "add operation" << endl;
  cin >> op;
  cout<< "add operande 1 " << endl;
  cin >> op1;
  cout<< "add operande 2 " << endl;
  cin >> op2;
  Core core;
  core.calculate(op,op1,op2);
  core.print();
}
*/
// test of CPU
/*int main(){
  CPU cpu;
  string path;
  unsigned int fr;
  cout << "add program" << endl;
  cin >> path;
  cout << "add frequency" << endl;
  cin >> fr;
  cpu.initialisation(path,fr);
  cpu.simulate();
  //cpu.write();
}
*/

int main(){

  string path;
  std::cout << "add path" << '\n';
  cin >> path;
  Platform Pf(path);
  Pf.simulate();
  Pf.simulate();
  Pf.simulate();
  Pf.simulate();
  Pf.simulate();
  Pf.simulate();
  Pf.simulate();
  Pf.simulate();
  Pf.simulate();
  Pf.simulate();

}
