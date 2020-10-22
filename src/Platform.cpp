#include "Platform.hpp"

Platform :: Platform(string pth){
  path = "NULL";
  nb_cpu_bus_mem = 0;
  get_path(pth);
  get_nb_of_each_element();
  creat_elements();
}

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


  for (auto elm: elements_path){
    n = elm.find("cpu");
    if (n == string :: npos) {
      cout << "not found\n";
    }
    else {
      cpus[i].get_cpu_path(elm);
      cpus[i].initialisation();
      cpus[i].creat_cores();
      i++;
    }
  }
  for (unsigned int j = 0; j < nb_cpu_bus_mem ;j++){
    cpus[j].print();
  }


  i=0;

  for (auto elm: elements_path){
    n = elm.find("bus");

    if (n == string :: npos) {
      cout << "not found bus\n";
    }
    else {
      busses[i].get_bus_path(elm);
      busses[i].initialisation();
      i++;
    }
  }
  for (unsigned int j = 0; j < nb_cpu_bus_mem ;j++){
    busses[j].print();
  }

  i=0;

  for (auto elm: elements_path){
    n = elm.find("mem");
    if (n == string :: npos) {
      cout << "not found mem\n";
    }
    else {
      mems[i].get_mem_path(elm);
      mems[i].initialisation();
      mems[i].num_mem_aff(i);
      i++;
    }
  }
  for (unsigned int j = 0; j < nb_cpu_bus_mem ;j++){
    mems[j].print();
  }

  i=0;

  for (auto elm: elements_path){
    n = elm.find("display");
    if (n == string :: npos) {
      cout << "not found display\n";
    }
    else {
      disps[i].get_disp_path(elm);
      disps[i].initialisation();
      for(unsigned int k=0;k<nb_cpu_bus_mem;k++){
        disps[i].get_indice_mem(mems[k]);
      }
      i++;
    }
  }
  for (unsigned int j = 0; j < nb_disp ;j++){
    disps[j].print();
  }
}

void Platform :: simulate(){
  for (unsigned int i = 0; i<nb_cpu_bus_mem; i++){
    cpus[i].simulate();
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

}

void Platform::link_mem_disp(int i){
  double d;
  unsigned int u;
    u = disps[i].indice_mem_return();
    while(1){
      if(mems[u].empty()) break;
      else {
        mems[u].remove();
        d=mems[u].write_in_disp();
        disps[i].read_from_mem(d);
      }

    }
    return;


}


void Platform::link_bus_mem(int i){
    vector <double> v;
    if(!busses[i].bus_is_empty()){
    v = busses[i].write_in_mem();
    mems[i].read_from_bus(v);
    }
    else mems[i].read_from_bus(v);
  }

void Platform::link_cpu_bus(int i){
  vector<double> v;
  for(unsigned int j =0;j<busses[i].get_width();j++){
    if(!cpus[i].isEmpty()) v.push_back(cpus[i].write());
    else return;
  }
  busses[i].read_from_cpu(v);
}
