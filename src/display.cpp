#include "display.hpp"



DISPLAY :: ~DISPLAY(){}

void DISPLAY::read_from_mem(double element){
  cache_disp.push_back(element);
}

DISPLAY::DISPLAY(){
DISP_path = "NULL";
source= "NULL";
refresh=0;
counter=0;
indice_mem=-1;
is_rom=false;
}

void DISPLAY::simulate(){
  print_details();
  if(counter==0){
    if(valid_print){
      cout << "\033[5m\033[36;1mDISPLAY\033[0m" << endl;
      for(double elm : cache_disp) cout<<elm<<"\t";
        cout<<endl;
    }
  }
  this->counter = (this->counter+1)  %(refresh) ;
  cache_disp.clear();
  if (valid_print){
    //cout << "\033[31;1m____________________________________\033[0m" << endl;
    cout << endl;
  }
}

void DISPLAY::get_disp_path(string disp_path){
    DISP_path = disp_path;
}

void DISPLAY::initialisation(){
  fstream file;
  string caract;
  string :: size_type n=0;

  file.open(DISP_path);
  getline(file, caract);
  caract.erase(std::remove(caract.begin(),caract.end(),'\t'),caract.end());
  while (n != caract.size()) {
    n = caract.find(":");
    if (caract[n+1] == ' ') caract.erase(caract.begin()+n+1);
    else break;
  }
  if (caract == "TYPE:DISPLAY"){
    while (getline(file, caract)){
      caract.erase(std::remove(caract.begin(),caract.end(),'\t'),caract.end());
      while (n != caract.size()) {
        n = caract.find(":");
        if (caract[n+1] == ' ') caract.erase(caract.begin()+n+1);
        else break;
      }
      if(caract.find("REFRESH") == 0){
        n = caract.find(":");
        stringstream(caract.substr(n+1)) >> refresh;
      }
      else if(caract.find("SOURCE") == 0){
        n = caract.find(":");
        source = caract.substr(n+1);
        if(source.find("DROM")== 0) is_rom = true;
        else is_rom= false;
      }
      else if(caract.find("PRIORITY") == 0){
        n = caract.find(":");
        priority = caract.substr(n+1);
      }
      else cout << "NOT COMPATIBLE FILE" << endl;
    }
  }
  else cout << "NOT COMPATIBLE PATH" << endl;
}

void DISPLAY::get_indice_mem(MEMORY mem){
  if(mem.get_label()==source) indice_mem = mem.num_mem_return() ;
}

void DISPLAY::get_indice_rom(ROM rom){
  if(rom.get_label()==source) indice_mem = rom.num_mem_return() ;
}

unsigned int DISPLAY::indice_mem_return(){
  return indice_mem;
}

int DISPLAY :: get_counter(){
  return counter;
}

void DISPLAY :: valid_print_details(){
  valid_print = true;
}

void DISPLAY :: print_details(){
  if (valid_print){
    cout << "\033[34;1mDISPLAY Priority: "<< "\t\t"<<priority << "\033[0m"<< endl;
    cout << "\033[34;1mSource: "<< "\t\t\t"<<source << "\033[0m"<< endl;
    cout << "\033[34;1mRefresh time: "<< "\t\t\t"<< refresh << "\033[0m"<< endl;
    cout << "\033[34;1mNumber of unprint values: "<< "\t"<< counter << "\033[0m"<< endl;
  }
}
