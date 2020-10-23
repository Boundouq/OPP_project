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

MEMORY::~MEMORY() {}



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
      printf("Memory is empty \n");
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
    print_details();
    if(counter==0){

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
  caract.erase(std::remove(caract.begin(),caract.end(),'\t'),caract.end());
  while (n != caract.size()) {
    n = caract.find(":");
    if (caract[n+1] == ' ') caract.erase(caract.begin()+n+1);
    else break;
  }
  if (caract == "TYPE:MEMORY"){
    while (getline(file, caract)){
      caract.erase(std::remove(caract.begin(),caract.end(),'\t'),caract.end());
      while (n != caract.size()) {
        n = caract.find(":");
        if (caract[n+1] == ' ') caract.erase(caract.begin()+n+1);
        else break;
      }
      if(caract.find("LABEL") == 0){
        n = caract.find(":");
        label = caract.substr(n+1);
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
        source = caract.substr(n+1);
      }
      else cout << "NOT COMPATIBLE FILE" << endl;
    }
  }
  else cout << "NOT COMPATIBLE PATH" << endl;

}

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

string MEMORY::get_label(){
  return label;
}

int MEMORY :: get_counter(){
  return counter;
}

void MEMORY :: valid_print_details(){
  valid_print = true;
}

void MEMORY :: print_details(){
  if (valid_print){
    cout << "\033[34;1mMEMORY Label: "<< "\t\t\t"<<label << "\033[0m"<< endl;
    cout << "\033[34;1mAccess time: "<< "\t\t\t"<< access << "\033[0m"<< endl;
    cout << "\033[34;1mNumber of free places: "<< "\t\t"<< size - count << "\033[0m"<< endl;
    cout << "\033[34;1mNumber of unread values: "<< "\t"<< counter << "\033[0m"<< endl;
    cout << endl;
  }
}
