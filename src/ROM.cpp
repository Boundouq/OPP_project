#include "ROM.hpp"




ROM::ROM(){
    MEM_path = "empty";
    source= "NULL";
    label="NULL";
    size = 64;
    data=new double[size];
    cache = new double[1];
    data_valid = true;
    react=false;
    counter = 0;

  }

ROM::~ROM() {}



bool ROM::empty() { return count == 0; }
bool ROM::full() { return count == this->size; }


bool ROM::add(double &t) {
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


void ROM::simulate(){
    print_details();



      *cache = data[counter];

}

void ROM::get_mem_path(string mem_path){
  MEM_path = mem_path;
}

void ROM::initialisation(){
  fstream file;
  string caract;
  string :: size_type n=0;
  string :: size_type m=0;

  file.open(MEM_path);
  getline(file, caract);
  caract.erase(std::remove(caract.begin(),caract.end(),'\t'),caract.end());
  while (n != caract.size()) {
    n = caract.find(":");
    if (caract[n+1] == ' ') caract.erase(caract.begin()+n+1);
    else break;
  }
  if (caract == "TYPE:ROM"){
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
      else if(caract.find("PRIORITY") == 0){
        n = caract.find(":");
        priority = caract.substr(n+1);
      }
      else if(caract.find("SIZE") == 0){
        n = caract.find(":");
        stringstream(caract.substr(n+1)) >> this->size;
      }
      else if(caract.find("INIT") == 0){
        n = caract.find(":");
        m = caract.find('\0');
        string s = caract.substr(n+1,m);
        string word = "";
        vector <double> vect;
        for (auto x : s) {
          if (x == ' ') {
           vect.push_back(stod(word));
           word = "";
       }
       else
       {
           word = word + x;
       }
   }
   vect.push_back(stod(word));
   for (double x : vect) add(x);
      }
      else cout << "NOT COMPATIBLE FILE" << endl;
    }
  }
  else cout << "NOT COMPATIBLE PATH" << endl;
}

double ROM::write_in_disp(){
  return *cache;
}

void ROM::num_mem_aff(unsigned int t){
  num_mem = t;
}

unsigned int ROM::num_mem_return(){
  return num_mem;
}


string ROM::get_label(){
  return label;
}

int ROM :: get_counter(){
  return counter;
}

void ROM :: increment_counter(){
  counter = (counter+1)  %size ;
}

void ROM :: valid_print_details(){
  valid_print = true;
}

void ROM :: print_details(){
  if (valid_print){
    cout << "\033[34;1mROM Label: "<< "\t\t\t"<<label << "\033[0m"<< endl;
    cout << "\033[34;1mROM Priority: "<< "\t\t\t"<<priority << "\033[0m"<< endl;
    cout << "\033[34;1mNumber of free places: "<< "\t\t"<< size - count << "\033[0m"<< endl;
    cout << "\033[34;1mNumber of unread values: "<< "\t"<< size - counter -1 << "\033[0m"<< endl;
    cout << "\033[34;1mReading value position: "<< "\t"<< counter << "\033[0m"<< endl;
    cout << endl;
  }
}
