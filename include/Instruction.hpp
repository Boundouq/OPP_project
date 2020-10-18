#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Instruction{
  private:
    string instruction;
    string operation;
    double operand1;
    double operand2;

  public:
    Instruction();
    void getinst(string Inst);
    void getOperation_Operands();
    void print();
    friend class CPU;
};
