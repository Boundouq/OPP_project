#ifndef MEMOIRE
#define MEMOIRE

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include"bus.hpp"
#include "interface.hpp"

using namespace std;

class MEMORY : public INTERFACE {
private:
  string MEM_path;
  string source;
  string label;
  string priority;
  double *data;
  int size;
  int access;
  int counter;
  double *cache;
  vector <double> sauv_bus;
  int head;
  int tail;
  int count;
  double empty_item;
  bool data_valid;
  bool react;
  unsigned int num_mem;
  bool valid_print;
public:

  MEMORY();
  ~MEMORY();
  bool empty();
  bool full();
  bool add(double &t);
  bool remove();
  void get_mem_path(string mem_path);
  void initialisation();
  string get_label();
  int get_counter();
  double write_in_disp();
  void simulate();
  void num_mem_aff(unsigned int t);
  unsigned int num_mem_return();
  void read_from_bus(vector <double> element);
  void print_details();
  void valid_print_details();
};

#endif
