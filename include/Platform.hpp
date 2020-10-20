#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "CPU.hpp"
#include "memory.hpp"
#include "bus.hpp"
#include "display.hpp"

using namespace std;

class Platform{
  private:
    string path;
    unsigned int nb_cpu_bus_mem;
    unsigned int nb_disp;
    vector<string> elements_path;
    CPU* cpus;
    MEMORY * mems;
    BUS* busses;
    DISPLAY* disps;

  public:
    Platform(string pth);
    void get_path(string pth);
    void get_nb_of_each_element();
    void creat_elements();
    void simulate();
    void link_mem_disp(int i);
    void link_bus_mem(int i);
    void link_cpu_bus(int i);
};
