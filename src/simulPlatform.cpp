/* prompt du mode shell interactif */
#define PROMPT_STRING "PlatformShell : > "

#include <fstream>
#include <sstream>
#include <string>
#include "Platform.hpp"

//Programme principal
int main ( int argc, char *argv[] ) {
    cout << "\033[1;32mUn message INFO_MSG : Debut du programme \033[0m" << "\033[1;32m" <<argv[0]  <<"\033[0m" << endl; /* macro INFO_MSG */
    cout << "\033[1;33mUn message WARNING_MSG !\033[0m" << endl; /* macro INFO_MSG */
    cout << endl;
    string file_path;
    string command;
    fstream file;
    int nb_it;
    string cmd0;
    int cntr = 0;
    string verbose;
    string debug;

        if ( argc > 3 || (argc < 3) ) {
            cout << "\033[5m\033[1;31mTO MUCH / FEW ARGUMENTS \033[0m" << endl;
            cout << "\033[1;33mUsage : similPlatform <Platform_path> <number_iteration>\033[0m" << endl;
            return(0);
        }
        if(argc == 3) {
          file_path = argv[1];
          stringstream(argv[2]) >> nb_it;
        }

        Platform Pf(file_path);
        file.open(file_path);
        cout << "\033[1;32mDO YOU WANNA SEE SIMULATION DETAILS ? <y/n>\033[0m" << endl;
        cout << "\033[1;36m" << PROMPT_STRING <<"\033[0m";
        cin >> verbose;
        if (verbose == "y") Pf.valid_print_details();
        else if (verbose != "n") {
          cout << "\033[5m\033[1;31mNon Compatible Command !\033[0m" << endl;
          return -1;
        }

        cout << "\033[1;32mEXECUTE ALL NUMBER OF ITERATIONS SIMULATIONS AT ONCE ? <y/n>\033[0m" << endl;
        cout << "\033[1;36m" << PROMPT_STRING <<"\033[0m";
        cin >> cmd0;
    /* boucle infinie : lit puis execute une cmd en boucle */
    while ( 1 ) {
      if (file.is_open()){
        if(cmd0 == "y") {
          cout << "\033[1;32mACTIVE DEBUG OPTION FOR CPU ? <y/n>\033[0m" << endl;
          cout << "\033[1;36m" << PROMPT_STRING <<"\033[0m";
          cin >> debug;
          cout <<endl;
          cout << "gggg" << debug << endl;
          if (debug != "y" && debug != "n") {
            cout << "\033[5m\033[1;31mNon Compatible Command !\033[0m" << endl;
            return -1;
          }
          for(int i=0;i<nb_it;i++) {
            if (i == nb_it -1){
              if (debug == "y") Pf.active_debug_option();
            }
            Pf.simulate();
          }
          return 1;
        }
        else if (cmd0 == "n") {
          if (cntr == nb_it) return 1;
          cout << "\033[1;32mTWO OPTION ARE POSSIBLE: > simulate(s) , > quit(q) \033[0m" << endl;
          cout << "\033[1;36m" << PROMPT_STRING <<"\033[0m";
          cin >> command;
          cout <<endl;
          if (command == "simulate" || command == "s" ){
            cout << "\033[1;32mACTIVE DEBUG OPTION FOR CPU ? <y/n>\033[0m" << endl;
            cout << "\033[1;36m" << PROMPT_STRING <<"\033[0m";
            cin >> debug;
            cout <<endl;
            if (debug == "y") {
              Pf.active_debug_option();
              Pf.simulate();
              cntr += 1;
            }
            else if (debug == "n") {
              Pf.simulate();
              cntr += 1;
            }
            else cout << "\033[1;33mCheck Your Command !!!\033[0m" << endl;
          }

          else if( command == "quit" || command == "q"){
            cout << "\033[1;32mBye bye ! \033[0m" << endl;
            return(0);
          }
          else
            cout << "\033[1;33mCheck Your Command !!!\033[0m" << endl;
        }
        else{
          cout << "\033[5m\033[1;31mNon Compatible Command !\033[0m" << endl;
          return 0;
        }
      }

      else cout << "\033[5m\033[1;31mERR0R! \033[0m" << endl;
    }
    cout << "\033[5m\033[1;31mSHOULD NEVER BE HERE \033[0m" << endl;
}
