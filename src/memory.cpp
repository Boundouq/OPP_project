#include "memory.hpp"



  //void memory::read(){}
  //void memory::write_in_mem(){}

MEMORY::MEMORY(){
    MEM_path = "empty";
    source= "NULL";
    label="NULL";
    size = 64;
    access = 0;
    data=new double[size];
    cache = new double[1];
    data_valid = true;
    react=false;
    counter = 0;

  }

// MEMORY::~MEMORY() {
//   printf("called destruction\n");
//   delete data;
//   delete cache;
// }



bool MEMORY::empty() { return count == 0; }
bool MEMORY::full() { return count == this->size; }


bool MEMORY::add(double &t) {
    if(full()) {
      data[tail] = t;
      tail = (tail + 1) % this->size;
      return true;
    }
    else {
      data[tail] = t;
      //cout <<data[tail]<<endl;
      tail = (tail + 1) % this->size;
      count++;
    return true;
  }
}

bool MEMORY::remove() { //read
    if ( empty() ) {
      printf("mem is empty \n");
      data_valid = false;
      return false;
    }
    else {
      *cache = data[head];
      data[head] = empty_item;
      head = (head + 1) % this->size;
      count--;
      return true;
    }
  }


void MEMORY::simulate(){

    if(counter==0){
      cout << "simulation mémoire en cours" << endl;
      if(sauv_bus.size()!=0){
          for(double elm : sauv_bus) add(elm);
            sauv_bus.clear();
      }
    }
    this->counter = (this->counter+1)  %(access) ;
}


void MEMORY::get_mem_path(string mem_path){
  MEM_path = mem_path;
}

void MEMORY::initialisation(){
  fstream file;
  string caract;
  string :: size_type n;

  file.open(MEM_path);
  getline(file, caract);
  if (caract == "TYPE: MEMORY"){
    while (getline(file, caract)){
      if(caract.find("LABEL") == 0){
        n = caract.find(":");
        label = caract.substr(n+2);
      }
      else if(caract.find("SIZE") == 0){
        n = caract.find(":");
        stringstream(caract.substr(n+1)) >> this->size;
      }
      else if(caract.find("ACCESS") == 0){
        n = caract.find(":");
        stringstream(caract.substr(n+1)) >> access;
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

void MEMORY :: print(){
  cout << "path : " << MEM_path << endl;
  cout << "source : " << source << endl;
  cout << "label : " << label << endl;
  cout <<"size : " << size << endl;
  cout <<"access : " <<access << endl;
}

void MEMORY :: print_cache(){
  cout << "cache : " << cache[0] << endl;

}

// void MEMORY :: read(BUS bus) {
//   if(react){
//   for (double elm : bus.ready_values) add(elm);
//   }
// }

double MEMORY::write_in_disp(){
  return *cache;
}

void MEMORY::num_mem_aff(unsigned int t){
  num_mem = t;
}

unsigned int MEMORY::num_mem_return(){
  return num_mem;
}

void MEMORY::read_from_bus(vector <double> element){
   sauv_bus = element;
}

//il faudra une classe qui lira le fichier texte et en fonction du nombre de composants fera appel aux classes
//rethink about that
//invalid data value = bool true false
//fonction is_value_valid
//allocation mémoire dans le constructeur
//bus écrit dans mémoire
//mémoire lis du bus
//cpu ecrit dans bus
//bus lis de cpu
//display lis de la mem
//mem ecrit dans display
