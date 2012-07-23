//=============================================================================
// engEngine.h
//
//  The game engine for connect 4.
//

#ifndef engEngine_H
#define engEngine_H

#include <vector>

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs, namespaces

using std::vector;

// variables: consts, statics, exported variables (declared extern elsewhere)
// local forward function declarations

//=============================================================================
class engEngine {
public:

  engEngine(int rows, int columns);
  // Default constructor.

  engEngine(const vector<vector<int> >& board, const int win_number);
  // constructor given a filled out board
  
  ~engEngine();
  // Destructor.

  void print() const;
  // prints the board to std output in ascii characters.

  void place(int player, int column);
  // place the players token in that column.
  // Precondition: column > m_columns
  // Precondition: !full(column)

  const int state() const;
  // returns the state of the board.
  //   returns :
  //             -1 - The game is a draw
  //              0 - There is no winner yet
  //              1 - Player 1 has won
  //              2 - Player 2 has won

  void set_win_number(const int& win_number);
  // sets the number of tokens in a row you need to win.

  const vector<vector<int> >& board() const;
  // returns the board.
  
private:

  // friends
  friend class utest_engEngine;
  // functions

  bool full(int column) const;
  // returns if the column is full
  
  engEngine();
  // Prohibited default constructor
  
  engEngine(const engEngine&);
  // Prohibited copy constructor

  void operator=(const engEngine&);
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
