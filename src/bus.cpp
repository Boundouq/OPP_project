#include "bus.hpp"

BUS::BUS(){
  //BUS_path= "testdata/bus1.txt";
  source= "NULL";
  label= "NULL";
}


void BUS::simulate(){
    cout << "simulation bus en cours" << endl;
    for(int i=0; i<(this->pending_values).size(); i++) {
      ready_values.push_back(pending_values[i]);
      cout << ready_values[i] << endl;
    }
    for (double elm:intermediate) pending_values.push_back(elm);
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
    if (caract == "TYPE: BUS"){
      while (getline(file, caract)){
        if(caract.find("LABEL") == 0){
          n = caract.find(":");
          label = caract.substr(n+2);
        }
        else if(caract.find("WIDTH") == 0){
          n = caract.find(":");
          stringstream(caract.substr(n+1)) >> width;
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

  void BUS :: print(){
    cout << "path : " << BUS_path << endl;
    cout << "Label : " <<label << endl;
    cout << "source : " <<source << endl;
    cout << "width : " <<width << endl;
  }

  vector <double> BUS::write_in_mem(){
    vector <double> inter;
    inter = ready_values;
    ready_values.clear();
    return inter;
  }

  void BUS::read_from_cpu(vector <double> vect){
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
