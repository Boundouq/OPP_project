#ifndef MYROM
#define MYROM

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "interface.hpp"

using namespace std;

class ROM : public INTERFACE {
private:
  string MEM_path;
  string source;
  string label;
  string priority;
  double *data;
  int size;
  int counter;
  double *cache;
  vector <double> sauv_bus;
  int tail;
  int count;
  bool data_valid;
  bool react;
  unsigned int num_mem;
  bool valid_print;
public:

  ROM();
  ~ROM();
  bool empty();
  bool full();
  bool add(double &t);
  void get_mem_path(string mem_path);
  void initialisation();
  string get_label();
  int get_counter();
  void increment_counter();
  double write_in_disp();
  void simulate();
  void num_mem_aff(unsigned int t);
  unsigned int num_mem_return();
  void print_details();
  void valid_print_details();
};

#endif
