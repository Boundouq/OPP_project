#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "CPU.hpp"

using namespace std;

class Platform{
  private:
    string path;
    unsigned int nb_cpu_bus_mem;
    vector<string> elements_path;
    CPU* cpus;

  public:
    Platform(string pth);
    void get_path(string pth);
    void get_nb_of_each_element();
    void creat_elements();
    void simulate();
};
