#include "PLATFORMS.hpp"




PLATFORMS:: PLATFORMS(string pt){
  path = pt;
  initialisation();
  creat_elements();
}

PLATFORMS:: ~PLATFORMS(){}

void PLATFORMS :: initialisation(){
  fstream file;
  string caract;
  string :: size_type n=0;

  file.open(path);
  getline(file, caract);
  caract.erase(std::remove(caract.begin(),caract.end(),'\t'),caract.end());
  while (n != caract.size()) {
    n = caract.find(":");
    if (caract[n+1] == ' ') caract.erase(caract.begin()+n+1);
    else break;
  }
  if (caract == "TYPE:PLATFORM"){
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
      else if(caract.find("COMPONENT") == 0){
        n = caract.find(":");
        platform_path.push_back(caract.substr(n+1));
      }
      //else cout << "NOT COMPATIBLE FILE" << endl;
    }
    nb_platforms = platform_path.size();
  }
  else cout << "NOT COMPATIBLE PATH" << endl;

}


void PLATFORMS:: creat_elements(){
  platforms = new Platform[nb_platforms];
  int i =0;
  for (auto elm: platform_path){
      platforms[i].get_path(elm);
      platforms[i].get_nb_of_each_element();
      platforms[i].creat_elements();
      platforms[i].affect_num_platform(i+1);
      i++;
  }
}


void PLATFORMS:: simulate(){
  int i =0;
  for (auto elm: platform_path){
      platforms[i].simulate();
      i++;
  }
}
void PLATFORMS:: valid_print_details(){
  int i =0;
  for (auto elm: platform_path){
      platforms[i].valid_print_details();
      i++;
  }
}

void PLATFORMS:: active_debug_option(){
  int i =0;
  for (auto elm: platform_path){
      platforms[i].active_debug_option();
      i++;
  }
}
