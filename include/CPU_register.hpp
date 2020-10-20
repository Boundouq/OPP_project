#include <iostream>
#include <string>

using namespace std;

struct Data{
  double data;
  Data* next;
};

class CPU_register{
  private:
    Data * head;
    Data * tail;

  public:
    CPU_register();
    bool empty_reg();
    void read(Data new_Data);
    double write();
    void print_reg();
};
