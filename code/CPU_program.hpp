#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Instruction.hpp"

using namespace std;

class CPU_program{
  private:
    int instruction_ptr;
    int size_inst;
    bool eof;
    string path;
    Instruction instruction;


  public:
    CPU_program();
    void get_path(string str);
    void get_instruction();
    void assignment();
    friend class CPU;
};
