#include "display.hpp"



// void DISPLAY::read(MEMORY mem){
//
//   while(!mem.empty()){
//    mem.remove();
//    mem.print_cache();
//  }

//}
void DISPLAY::read_from_mem(double element){
  cache_disp.push_back(element);
}



DISPLAY::DISPLAY(){
//DISP_path = "NULL";
source= "NULL";
refresh=0;
counter=0;
indice_mem=-1;
}

  void DISPLAY::simulate(){
    if(counter==0){
    cout << "simulation display en cours" << endl;
    for(double elm : cache_disp) cout<<elm<<"\t";
    cout<<endl;

  }
    this->counter = (this->counter+1)  %(refresh) ;
    cache_disp.clear();
  }

  void DISPLAY::get_disp_path(string disp_path){
    DISP_path = disp_path;
  }

  void DISPLAY::initialisation(){
    fstream file;
    string caract;
    string :: size_type n;

    file.open(DISP_path);
    getline(file, caract);
    if (caract == "TYPE: DISPLAY"){
      while (getline(file, caract)){
        if(caract.find("REFRESH") == 0){
          n = caract.find(":");
          stringstream(caract.substr(n+1)) >> refresh;
        }

        else if(caract.find("SOURCE") == 0){
          n = caract.find(":");
          source = caract.substr(n+2);
        }
        else cout << "NOT COMPATIBLE FILE" << endl;
      }
    }
    else cout << "NOT COMPATIBLE PATH" << endl;

  }

  void DISPLAY :: print(){
    cout << "path : " << DISP_path << endl;
    cout << "refresh : " <<refresh << endl;
    cout << "source : " <<source << endl;
  }

  void DISPLAY::get_indice_mem(MEMORY mem){
    if(mem.label==source) indice_mem = mem.num_mem_return() ;

  }

  unsigned int DISPLAY::indice_mem_return(){
    return indice_mem;
  }
