//=============================================================================
//D Uses the engEngine and engAI class to play connect four in the terminal.

#include "Engine/engEngine.h"
#include "Engine/engAI.h"

#include <fstream>
#include <iostream>
#include <string>

#include "dgcUtils/Assert.h" // use dgc asserts

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
void human_go(engEngine& game, const int player)
//
//D 
//
{
  game.print();
  int go = -1;
  while (go < 1 || go > game.columns()) {
    cout << "Player " << player << ": ";
    cin >> go;
  }
  game.place(player, go - 1);
}

//=============================================================================
void simulate_game(engEngine& game, const int win_number)
//
//D play two computers
//
{
  // difficulty does nothing at the moment, set to 0
  engAI comp_1(1, 0, win_number);
  engAI comp_2(2, 0, win_number);
  while (game.state() == 0) {
    int move = comp_1.move(game.board());
    game.place(1, move);
    game.print();
    if (game.state() != 0) {
      break;
    }
    move = comp_2.move(game.board());
    game.place(2, move);
    game.print();
  }
  game.print();
  if (game.state() == -1) {
    cout << "It was a draw." << endl;
  } else {
    cout << "Computer " << game.state() << " has won." << endl;
  }
}

//=============================================================================
void play_one_player(engEngine& game, const int win_number)
//
//D play against the computer
//
{
  engAI computer(1, 0, win_number);
  while (game.state() == 0) {
    human_go(game, 1);
    if (game.state() != 0) {
      break;
    }
    int move = computer.move(game.board());
    game.place(2, move);
  }
  game.print();
  if (game.state() == -1) {
    cout << "It was a draw." << endl;
  } else {
    cout << "Player " << game.state() << " has won." << endl;
  }
}

//=============================================================================
void play_two_player(engEngine& game, const int win_number)
//
//D play against another person
//
{
  while (game.state() == 0) {
    human_go(game, 1);
    if (game.state() != 0) {
      break;
    }
    human_go(game, 2);
  }
  game.print();
  if (game.state() == -1) {
    cout << "It was a draw." << endl;
  } else {
    cout << "Player " << game.state() << " has won." << endl;
  }
}

//=============================================================================
int main(int num_arguments, char* arguments[])
//
//D The entry point and single function of this program
//
{
  int rows = 6;
  int columns = 7;
  int win_number = 4;
  // iterate over command line options
  for (int i = 1; i < num_arguments; ++i) {
    string arg = string(arguments[i]);
    if (arg[0] == '-') {
      if (arg == "-h" || arg == "-help" || arg == "--help") {
        // help option
        print_help(arguments[0]);
        return 0;

      } else if (arg == "-c" || arg == "-configure") {
        // reset these to ridiculous values
        rows = -1;
        columns = -1;
        win_number = -1;
        while (cin.good() && rows < 0) {
          cout << "How many rows?" << endl;
          cin >> rows;
        }        
        while (cin.good() && columns < 0) {
          cout << "How many columns?" << endl;
          cin >> columns;
        }        
        while (cin.good() && win_number < 0) {
          cout << "How many to win?" << endl;
          cin >> win_number;
        }        
      } else {
        cerr << "Unknown option" << endl;
        print_help(arguments[0]);
        return 0;
      }
    }
  }
  int players = -1;
  while (cin.good() && players != 0 && players != 1 && players != 2) {
    cout << "How many players? [0, 1, 2]" << endl;
    cin >> players;
  }
  
  engEngine game(rows, columns);
  game.set_win_number(win_number);
  
  if (players == 0) {
    simulate_game(game, win_number);
  } else if (players == 1) {
    play_one_player(game, win_number);
  } else if (players == 2) {
    play_two_player(game, win_number);
  } else {
    assert(false, "More than two players chosen.");
  }
    
  return 0;
}
