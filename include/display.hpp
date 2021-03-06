#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "memory.hpp"
#include "ROM.hpp"
#include "interface.hpp"

using namespace std;

class DISPLAY : public INTERFACE {

private:
  string DISP_path;
  string source;
  string priority;
  int refresh;
  int counter;
  unsigned int indice_mem;
  vector <double> cache_disp;
  bool valid_print;

public:
  bool is_rom;
  DISPLAY();
  ~DISPLAY();
  void get_disp_path(string disp_path);
  void simulate();
  void initialisation();
  void read_from_mem(double element);
  void get_indice_mem(MEMORY mem);
  void get_indice_rom(ROM rom);
  unsigned int indice_mem_return();
  void print_details();
  void valid_print_details();
  int get_counter();
};
