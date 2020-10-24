#include "Core.hpp"

Core :: Core(){
  result = 0;
}

double Core :: calculate(string operation,int nb_op, vector <double> op){
  double results = op[0];
  if (operation == "ADD"){
    for (int i =1; i < nb_op; i++)
      results += op[i];
    return results;
  }
  else if (operation == "SUB"){
    for (int i =1; i < nb_op; i++)
      results -= op[i];
    return results;
  }
  else if (operation == "MUL"){
    for (int i =1; i < nb_op; i++)
      results *= op[i];
    return results;
  }
  else if (operation == "DIV"){
    for (int i =1; i < nb_op; i++)
      results /= op[i];
    return results;
  }
  else if (operation == "NOP")
    return results= 0 ;
  else return results = -1998;

}

void Core :: num(unsigned int i){
  num_core = i;
}

void Core :: print(){
  cout << "le num du core qui calcule : " << num_core << endl;
}
