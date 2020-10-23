#include "bus.hpp"

BUS::BUS(){
  BUS_path= "NULL";
  source= "NULL";
  label= "NULL";
}

BUS :: ~BUS(){}

void BUS::simulate(){
  print_details();
  for(unsigned int i=0; i< pending_values.size(); i++) {
    if (pending_values.size()){
      ready_values.push_back(pending_values[i]);
    }
    else break;
  }
  pending_values.clear();
  pending_values = intermediate;
  intermediate.clear();
}

void BUS::get_bus_path(string bus_path){
    BUS_path = bus_path;
  }

void BUS::initialisation(){
    fstream file;
    string caract;
    string :: size_type n;

    file.open(BUS_path);
    getline(file, caract);
    caract.erase(std::remove(caract.begin(),caract.end(),'\t'),caract.end());
    while (n != caract.size()) {
      n = caract.find(":");
      if (caract[n+1] == ' ') caract.erase(caract.begin()+n+1);
      else break;
    }
    if (caract == "TYPE:BUS"){
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
        else if(caract.find("WIDTH") == 0){
          n = caract.find(":");
          stringstream(caract.substr(n+1)) >> width;
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

vector <double> BUS::write_in_mem(){
    vector <double> inter;
    inter = ready_values;
    ready_values.clear();
    return inter;
  }

void BUS::read_from_cpu(vector <double> vect){
    intermediate.clear();
    intermediate = vect;
  }

bool BUS::bus_is_empty(){
    if (ready_values.size() == 0) valid = true;
    else valid = false;
    return valid;
  }

unsigned int BUS::get_width(){
    return width;
}

void BUS :: valid_print_details(){
  valid_print = true;
}

void BUS :: print_details(){
  if (valid_print){
    cout << "\033[34;1mBUS Label: "<< "\t\t\t"<<label << "\033[0m"<< endl;
    cout << "\033[34;1mNumber of accesses: "<< "\t\t"<< width << "\033[0m"<< endl;
    cout << endl;
  }
}
