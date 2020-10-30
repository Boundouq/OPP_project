#ifndef MYPLA
#define MYPLA

#include "Platform.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class PLATFORMS : public INTERFACE{
  private :
    string path;
    unsigned int nb_platforms;
    string label;
    vector<string> platform_path;
    Platform * platforms;
  public :
    PLATFORMS(string pt);
    ~PLATFORMS();
    void simulate();
    void valid_print_details();
    void active_debug_option();
    void initialisation();
    void creat_elements();

};

#endif
