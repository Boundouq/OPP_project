#include <iostream>
#include <string>

using namespace std;

class Core{
  private:
    double result;
    unsigned int num_core;
  public:
    bool valid;
    Core();
    double calculate(string operation, double op1, double op2);
    void num(unsigned int i);
    void print();
};
