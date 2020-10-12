#include "Platform.hpp"

Platform :: Platform(){
  path = "NULL";
  nb_cpu_bus_mem = 0;
}

void Platform :: get_path(string pth){
  path = pth;
}

void Platform :: get_nb_of_each_element(){
  fstream file;
  int cnt = 0;
  string element;
  file.open(path);
  while (getline(file, element)) {
    cnt += 1;
    elements_path.push_back(element);
  }
  if ((cnt-1)%3 == 0)
  nb_cpu_bus_mem = (cnt-1)/3;

  else cout << "ERROR" << endl;
}


void Platform :: creat_elements(){
  string :: size_type n;
  int i = 0;
  cpus.resize(nb_cpu_bus_mem);


  for (auto elm: elements_path){
    n = elm.find("cpu");
    if (n == string :: npos) {
      cout << "not found\n";
    }
    else {
      cpus[i].get_cpu_path("../" + elm);
      cpus[i].initialisation();
      cpus[i].creat_cores();
      i++;
    }
  }
  for (unsigned int j = 0; j < nb_cpu_bus_mem ;j++){
    cpus[j].print();
  }
}
