#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Core{
  private:
    double result;
    unsigned int num_core;
  public:
    bool valid;
    Core();
    double calculate(string operation, int nb_op, vector <double> op);
    void num(unsigned int i);
    void print();
};
