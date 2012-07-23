//=============================================================================
//D <One line description>
//
// <Full description.>
//

#include "Engine/engEngine.h"

#include "dgcUtils/Assert.h" // use dgc asserts
#include <iostream>
#include <string>

// types: classes, enums, typedefs, namespaces

using std::cout;
using std::endl;
using std::string;

// variables: consts, statics, exported variables (declared extern elsewhere)
// local forward function declarations

//=============================================================================
engEngine::engEngine(int rows, int columns)
//
//D Default constructor
//
  : m_rows(rows),
    m_columns(columns),
    m_win_number(4) // default to connect 4
{
  m_board.resize(m_columns, vector<int>(m_rows, 0));
}

//=============================================================================
engEngine::engEngine(const vector<vector<int> >& board, const int win_number)
//
//D Default constructor
//
  : m_board(board),
    m_rows(board[0].size()),
    m_columns(board.size()),
    m_win_number(win_number)
{
}

//=============================================================================
engEngine::~engEngine()
//
//D Destructor
//
{
}

//=============================================================================
void engEngine::print() const
//
//D prints the board to std output in ascii characters.
//
{
  cout << "  ";
  for (int i = 0; i < m_columns; ++i) {
    cout << " " << i + 1 << "  ";
  }
  cout << endl;
  string banner(" ");
  for (int i = 0; i < m_columns; ++i) {
    banner += "====";
  }
  banner += "=";
  cout << banner << endl;
  for (int j = 0; j < m_rows; ++j) {
    cout << " ";
    for (int i = 0; i < m_columns; ++i) {
      cout << "| " << m_board[i][j] << " ";
    }
    cout << "|" << endl;
  }
  cout << banner << endl << endl;
}

//=============================================================================
void engEngine::place(int player, int column)
//
//D place the players token in that column.
//D Precondition: column > m_columns
//D Precondition: !full(column)
//
{
  assert(column > m_columns, "Non-existant column place.");
  assert(!full(column), "Placing in a full column.");
  // return so it compiles
  for (int i = 0; i < m_rows; ++i) {
    if (m_board[column][i] != 0) {
      m_board[column][i - 1] = player;
      return;
    }
  }
  // 
  m_board[column][m_rows - 1] = player;
}

//=============================================================================
const int engEngine::state() const
//
//D returns the state of the board.
//D   returns :
//D             -1 - The game is a draw
//D              0 - There is no winner
//D              1 - Player 1 has won
//D              2 - Player 2 has won
//
{
  // to check if the game is over
  bool game_end = false;
  
  // check if there is a horizontal win
  for (int i = 0; i < m_columns; ++i) {
    for (int j = 0; j < m_rows; ++j) {
      // continue if it will go outside of the bounds
      if (i + m_win_number > m_columns) {
        continue;
      }
      // if the token at the start of where we are checking is taken is filled
      game_end = (m_board[i][j] != 0);
      for (int k = 0; k < m_win_number - 1; ++k) {
        // check the next tokens are equal
        game_end = game_end && (m_board[i + k][j] == m_board[i + k + 1][j]);
      }
      if (game_end) {
        return m_board[i][j];
      }
    }
  }
  
  // check if there is a vertical win
  for (int i = 0; i < m_columns; ++i) {
    for (int j = 0; j < m_rows; ++j) {
      // continue if it will go outside of the bounds
      if (j + m_win_number > m_rows) {
        continue;
      }
      // if the token at the start of where we are checking is taken is filled
      game_end = (m_board[i][j] != 0);
      for (int k = 0; k < m_win_number - 1; ++k) {
        // check the next tokens are equal
        game_end = game_end && (m_board[i][j + k] == m_board[i][j + k + 1]);
      }
      if (game_end) {
        return m_board[i][j];
      }
    }
  }

  
  // check if there is a diagonal win, left high
  for (int i = 0; i < m_columns; ++i) {
    for (int j = 0; j < m_rows; ++j) {
      // continue if it will go outside of the bounds
      if (i + m_win_number > m_columns || j + m_win_number > m_rows) {
        continue;
      }
      // if the token at the start of where we are checking is taken is filled
      game_end = (m_board[i][j] != 0);
      for (int k = 0; k < m_win_number - 1; ++k) {
        // check the next tokens are equal
        game_end =
          game_end && (m_board[i + k][j + k] == m_board[i + k + 1][j + k + 1]);
      }
      if (game_end) {
        return m_board[i][j];
      }
    }
  }

  // check if there is a diagonal win, right high
  for (int i = 0; i < m_columns; ++i) {
    for (int j = 0; j < m_rows; ++j) {
      // continue if it will go outside of the bounds
      if (i + m_win_number > m_columns || j - m_win_number < 0) {
        continue;
      }
      // if the token at the start of where we are checking is taken is filled
      game_end = (m_board[i][j] != 0);
      for (int k = 0; k < m_win_number - 1; ++k) {
        // check the next tokens are equal
        game_end =
          game_end && (m_board[i + k][j - k] == m_board[i + k + 1][j - k - 1]);
      }
      if (game_end) {
        return m_board[i][j];
      }
    }
  }

  // no winner, check if there's a draw.
  for (int i = 0; i < m_columns; ++i) {
    if (!full(i)) {
      // if the column is not full it's a draw
      return 0;
    }
  }
  // if it's gotten here it's a draw
  return -1;
}

//=============================================================================
void engEngine::set_win_number(const int& win_number)
//
//D sets the number of tokens in a row you need to win.
//
{
  m_win_number = win_number;
}

//=============================================================================
bool engEngine::full(int column) const
//
//D returns if the column is full
//
{
  // return if the final token is empty or not
  return m_board[column][0] != 0;
}

//=============================================================================
const vector<vector<int> >& engEngine::board() const
//
//D returns the board.
//
{
  return m_board;
}
