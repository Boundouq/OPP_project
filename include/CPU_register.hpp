#include <iostream>
#include <string>
#include "FIFO.hpp"

using namespace std;


class CPU_register {
  private:
    FIFO fifo;

  public:
    CPU_register();
    bool empty_reg();
    void read(Data new_data);
    double write();
    void print_reg();
};
