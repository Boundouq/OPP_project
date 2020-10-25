#include "Platform.hpp"

Platform :: Platform(string pth){
  path = "NULL";
  nb_cpu_bus_mem = 0;
  valid_print = debug_cpu = false;
  get_path(pth);
  get_nb_of_each_element();
  creat_elements();
}

Platform :: ~ Platform(){}

void Platform :: get_path(string pth){
  path = pth;
}

void Platform :: get_nb_of_each_element(){
  string :: size_type n,m;
  fstream file;
  int cnt_cpu = 0;
  int cnt_disp = 0;
  string element;
  file.open(path);
  while (getline(file, element)) {
    elements_path.push_back(element);
    n = element.find("cpu");
    m = element.find("display");
    if(n != string :: npos) cnt_cpu += 1;
    if(m != string :: npos) cnt_disp += 1;

  }

  nb_cpu_bus_mem = cnt_cpu;
  nb_disp = cnt_disp;

}

void Platform :: creat_elements(){
  string :: size_type n;
  int i = 0;
  cpus= new CPU [nb_cpu_bus_mem];
  mems= new MEMORY [nb_cpu_bus_mem];
  busses= new BUS [nb_cpu_bus_mem];
  disps= new DISPLAY [nb_disp];
  serials = new SERIAL [nb_cpu_bus_mem];

  for (auto elm: elements_path){
    n = elm.find("cpu");
    if (n != string :: npos) {
      cpus[i].get_cpu_path(elm);
      cpus[i].initialisation();
      cpus[i].creat_cores();
      i++;
    }
  }

  i=0;

  for (auto elm: elements_path){
    n = elm.find("bus");

    if (n != string :: npos) {
      busses[i].get_bus_path(elm);
      busses[i].initialisation();
      i++;
    }
  }

  i=0;

  for (auto elm: elements_path){
    n = elm.find("mem");
    if (n != string :: npos) {
      mems[i].get_mem_path(elm);
      mems[i].initialisation();
      mems[i].num_mem_aff(i);
      i++;
    }
  }

  i=0;

  for (auto elm: elements_path){
    n = elm.find("display");
    if (n != string :: npos) {
      disps[i].get_disp_path(elm);
      disps[i].initialisation();
      for(unsigned int k=0;k<nb_cpu_bus_mem;k++){
        disps[i].get_indice_mem(mems[k]);
      }
      i++;
    }
  }

  i=0;

  for (auto elm: elements_path){
    n = elm.find("serial");
    if (n != string :: npos) {
      serials[i].get_serial_path(elm);
      serials[i].initialisation();
      i++;
    }
  }
}

void Platform :: simulate(){
  print_details();
  for (unsigned int i = 0; i<nb_cpu_bus_mem; i++){
    cpus[i].simulate();

    debug_option(i);
    serials[i].simulate();

    link_cpu_bus(i);
    busses[i].simulate();
    link_bus_mem(i);
    mems[i].simulate();

    for(unsigned int j=0;j<nb_disp;j++){
      if(i==disps[j].indice_mem_return()) {
        link_mem_disp(j);
        disps[j].simulate();
      }
    }
  }
  debug_cpu = false;
}

void Platform :: link_mem_disp(int i){
  double d;
  unsigned int u;
    u = disps[i].indice_mem_return();
    while(1){
      if(mems[u].empty()) break;
      else {
        if (disps[i].get_counter() == 0){
          mems[u].remove();
          d=mems[u].write_in_disp();
          disps[i].read_from_mem(d);
        }
        else return;
      }
    }
    return;
}

void Platform :: link_bus_mem(int i){
    vector <double> v;
    if (mems[i].get_counter() == 0){
      if(!busses[i].bus_is_empty()){
        v = busses[i].write_in_mem();
        mems[i].read_from_bus(v);
      }
      else return;
    }
    else mems[i].read_from_bus(v);
  }

void Platform :: link_cpu_bus(int i){
  vector<double> v;
  for(unsigned int j =0;j<busses[i].get_width();j++){
    if(!cpus[i].isEmpty()){
       v.push_back(cpus[i].write());
    }
    else break;
  }
  //for (double elm:v) cout << "input " << elm << endl;
  busses[i].read_from_cpu(v);
  return;
}

void Platform :: debug_option(int i){
  vector<string> v;
  if (debug_cpu){
    v = cpus[i].debug();
    serials[i].read_buffer(v);
  }
}

void Platform :: valid_print_details(){
  valid_print = true;
  for (unsigned int i = 0; i<nb_cpu_bus_mem; i++){
    cpus[i].valid_print_details();
    busses[i].valid_print_details();
    mems[i].valid_print_details();
    serials[i].valid_print_details();
  }
  for (unsigned int i = 0; i<nb_disp; i++){
    disps[i].valid_print_details();
  }
}

void Platform :: print_details(){
  if (valid_print){
    cout << "\033[4m\033[31;1mPlatform 1\033[0m" << endl;
    cout << endl;
  }
}

void Platform :: active_debug_option(){
  debug_cpu = true;
}
