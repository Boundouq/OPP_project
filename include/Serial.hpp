#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
#include "interface.hpp"

using namespace std;

class SERIAL : public INTERFACE {
  private:
    string Serial_path;
    string label;
    string source;
    string target;
    bool valid_print;
    vector <string> buffer;
  public:
    SERIAL();
    ~SERIAL();
    void get_serial_path(string serial_path);
    void initialisation();
    void valid_print_details();
    void print_details();
    void read_buffer(vector<string> buff);
    void simulate();
};
