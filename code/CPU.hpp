#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include "Core.hpp"
#include "CPU_register.hpp"
#include "CPU_program.hpp"

using namespace std;

class CPU {
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
    double out_result;
  public:
    CPU();
    void get_cpu_path(string cpu_path);
    double write();
    void simulate();
    void initialisation();
    void creat_cores();
    void print();
};
