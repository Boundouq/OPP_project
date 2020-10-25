#include "Serial.hpp"

SERIAL :: SERIAL(){
  Serial_path = "NULL";
  label = "NULL";
  source = "NULL";
  target = "NULL";
  valid_print = false;
}

SERIAL :: ~SERIAL(){}

void SERIAL ::  get_serial_path(string serial_path){
  Serial_path = serial_path;
}

void SERIAL :: initialisation(){
  fstream file;
  string caract;
  string :: size_type n;

  file.open(Serial_path);
  getline(file, caract);
  caract.erase(std::remove(caract.begin(),caract.end(),'\t'),caract.end());
  while (n != caract.size()) {
    n = caract.find(":");
    if (caract[n+1] == ' ') caract.erase(caract.begin()+n+1);
    else break;
  }
  if (caract == "TYPE:SERIAL"){
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
      else if(caract.find("SOURCE") == 0){
        n = caract.find(":");
        source = caract.substr(n+1);
      }
      else if(caract.find("TARGET") == 0){
        n = caract.find(":");
        target = caract.substr(n+1);
      }
    }
  }
  else cout << "NOT COMPATIBLE PATH" << endl;

}

void SERIAL:: valid_print_details(){
  valid_print = true;
}

void SERIAL :: print_details(){
  if (valid_print){
    cout << "\033[34;1mSERIAL Label: "<< "\t\t\t"<<label << "\033[0m"<< endl;
    cout << "\033[34;1mSource: "<< "\t\t\t"<< source << "\033[0m"<< endl;
    cout << "\033[34;1mTarget: "<< "\t\t\t"<< target << "\033[0m"<< endl;
    cout << endl;
  }
}

void SERIAL :: read_buffer(vector<string> buff){
  buffer = buff;
}

void SERIAL :: simulate(){
  print_details();
  ofstream file;
  file.open(target);
  if (file.is_open()){
    for ( string elm : buffer){
      file << elm << endl;
    }
  }
  //file.close();
}
