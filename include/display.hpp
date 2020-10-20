#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <fstream>
#include "memory.hpp"
#include "interface.hpp"

using namespace std;

class DISPLAY : public INTERFACE {

private:
  string DISP_path;
  string source;
  int refresh;
  int counter;
  unsigned int indice_mem;
  vector <double> cache_disp;
public:

  DISPLAY();
  void get_disp_path(string disp_path);
  void simulate();
  void initialisation();
  void print();
  void read_from_mem(double element);
  // void read(MEMORY memo);
  void get_indice_mem(MEMORY mem);
  unsigned int indice_mem_return();
};
