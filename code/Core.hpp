#include <iostream>
#include <string>

using namespace std;

class Core{
  private:
    double result;
  public:
    Core();
    double calculate(string operation, double op1, double op2);
    void print();
};
