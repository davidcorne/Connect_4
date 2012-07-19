//=============================================================================
//D 

#include "Engine/engEngine.h"

#include <fstream>
#include <iostream>
#include <string>

// types: classes, enums, typedefs, namespaces

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

// variables: consts, statics, exported variables (declared extern elsewhere)
// local forward function declarations

//=============================================================================
void print_help(const string& location)
//
//D Print the helpfile (help.txt) from the location given
//
{
  string file_location(location, 0, location.find_last_of('/'));
  file_location.append("/help.txt");
  ifstream file(file_location.c_str());
  if (file) {
    // print the buffer to standard output
    cout << file.rdbuf();
    file.close();
  } else {
    cerr << "Help file " << file_location << " not found." << endl;
  }
}

//=============================================================================
int main(int num_arguments, char* arguments[])
//
//D The entry point and single function of this program
//
{
  // iterate over command line options
  for (int i = 1; i < num_arguments; ++i) {
    string arg = string(arguments[i]);
    if (arg[0] == '-') {
      if (arg == "-h" || arg == "-help" || arg == "--help") {
        // help option
        print_help(arguments[0]);
        return 0;
      } else {
        cerr << "Unknown option" << endl;
        print_help(arguments[0]);
        return 0;
      }
    }
  }
  engEngine game(6,7);
  game.print();
  
  return 0;
}
