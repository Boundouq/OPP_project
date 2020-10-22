#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include "Core.hpp"
#include "CPU_register.hpp"
#include "CPU_program.hpp"
#include "interface.hpp"

using namespace std;

class CPU : public INTERFACE {
  private:
    string CPU_path;
    string label;
    unsigned int frequency;
    unsigned int nb_core;
    string program_path;

    unsigned int active_core;
    Core* core;
    CPU_register reg;
    CPU_program program;
    Data data_in;
    bool valid;
    bool valid_print;
    double out_result;
  public:
    CPU();
    ~CPU();
    void get_cpu_path(string cpu_path);
    double write();
    void simulate();
    bool isEmpty();
    void initialisation();
    void creat_cores();
    void print_details();
    void valid_print_details();
};
