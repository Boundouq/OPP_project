#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Instruction{
  private:
    string instruction;
    string operation;
    vector <double> operands;
    unsigned int nb_operands;

  public:
    Instruction();
    void getinst(string Inst);
    void getOperation_Operands();
    friend class CPU;
};
