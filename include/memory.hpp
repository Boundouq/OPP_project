#ifndef MEMOIRE
#define MEMOIRE

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <fstream>
#include"bus.hpp"

using namespace std;

class MEMORY {
private:
  string MEM_path;
  string source;
  string label;
//std::unique_ptr<double[]> data;
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
public:

  MEMORY();
  //~MEMORY();
  bool empty();
  bool full();
  bool add(double &t);
  bool remove();
  void get_mem_path(string mem_path);
  void initialisation();
  //void read();
  double write_in_disp();
  void simulate();
  void print();
  void print_cache();
  void num_mem_aff(unsigned int t);
  unsigned int num_mem_return();
  //void read(BUS bus);
  void read_from_bus(vector <double> element);
};

#endif
