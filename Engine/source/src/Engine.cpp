//=============================================================================
//D <One line description>
//
// <Full description.>
//

#include "Engine/Engine.h"
#include <assert.h> // use asserts

// types: classes, enums, typedefs, namespaces
// variables: consts, statics, exported variables (declared extern elsewhere)
// local forward function declarations

//=============================================================================
Engine::Engine(int rows, int columns)
//
//D Default constructor
//
{
}

//=============================================================================
Engine::~Engine()
//
//D Destructor
//
{
}

//=============================================================================
void print()
//
//D prints the board to std output in ascii characters.
//
{
}

//=============================================================================
bool place(int player, int column)
//
//D place the players token in that column.
//D Precondition: column < m_columns
//D Precondition: !full(column)
//
{
  // return so it compiles
  return false;
}

//=============================================================================
int state()
//
//D returns the state of the board.
//D   returns :
//D             -1 - The game is a draw
//D              0 - There is no winner
//D              1 - Player 1 has won
//D              2 - Player 2 has won
//
{
  // return so it compiles
  return 0;
}

//=============================================================================
void set_win_number(int win_number)
//
//D sets the number of tokens in a row you need to win.
//
{
}

//=============================================================================
bool full(int column)
//
//D returns if the column is full
//
{
  // return so it compiles
  return false;
}
