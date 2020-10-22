#ifndef MYBUS
#define MYBUS
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <fstream>
#include "interface.hpp"

using namespace std;

class BUS : public INTERFACE{
private:
  string BUS_path;
  string source;
  string label;
  int width;
  bool valid_print;
  vector<double> pending_values;
  vector<double> ready_values;
  vector<double> intermediate;
  bool valid;
public:
  BUS();
  ~BUS();
  void get_bus_path(string bus_path);
  void initialisation();
  void simulate();
  vector <double> write_in_mem();
  void read_from_cpu(vector <double> vect);
  bool bus_is_empty();
  unsigned int get_width();
  void print_details();
  void valid_print_details();
};


#endif
