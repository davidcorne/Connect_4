//=============================================================================
// Engine.h
//
//  The game engine for connect 4.
//

#ifndef Engine_H
#define Engine_H

#include <vector>

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs, namespaces

using std::vector;

// variables: consts, statics, exported variables (declared extern elsewhere)
// local forward function declarations

//=============================================================================
class Engine {
public:

  Engine(int rows, int columns);
  // Default constructor.

  ~Engine();
  // Destructor.

  void print();
  // prints the board to std output in ascii characters.

  bool place(int player, int column);
  // place the players token in that column.
  // Precondition: column < m_columns
  // Precondition: !full(column)

  int state();
  // returns the state of the board.
  //   returns :
  //             -1 - The game is a draw
  //              0 - There is no winner
  //              1 - Player 1 has won
  //              2 - Player 2 has won

  void set_win_number(int win_number);
  // sets the number of tokens in a row you need to win.
  
private:

  // friends
  // functions

  bool full(int column);
  // returns if the column is full
  
  Engine();
  // Prohibited default constructor
  
  Engine(const Engine&);
  // Prohibited copy constructor

  void operator=(const Engine&);
  // Prohibited assignment operator

  // variables

  vector<vector<int> > m_board;
  // the 2D array the board is stored as.

  int m_rows;
  int m_columns;
  // the dimensions of the board.

  int m_win_number;
  // the number of tokens needed to win, defaults to 4.
  
};

#endif
