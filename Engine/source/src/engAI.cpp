//=============================================================================
//D <One line description>
//
// <Full description.>
//

#include "Engine/engAI.h"
#include "Engine/engEngine.h"
#include "dgcUtils/Assert.h" // use dgc asserts

#include <time.h>

// types: classes, enums, typedefs, namespaces
// variables: consts, statics, exported variables (declared extern elsewhere)
// local forward function declarations

//=============================================================================
engAI::engAI(const int player, const int difficulty, const int win_number)
//
//D Default constructor.
//
  : m_player(player),
    m_difficulty(difficulty),
    m_win_number(win_number)
{
}

//=============================================================================
engAI::~engAI()
//
//D Destructor.
//
{
}

//=============================================================================
const int engAI::move(const vector<vector<int> >& board)
//
//D returns which column the AI will use.
//
{
  // just use a naive algorithm for now
  return naive_algorithm(board);
}

//=============================================================================
const int engAI::naive_algorithm(const vector<vector<int> >& board)
//
//D if the computer can win it will return there, then if it can stop the other
//D player it will go there, after that it picks a non-full column randomly
//
{
  const vector<int> possible(possible_moves(board));
  int opponent = -1;
  if (m_player == 1) {
    opponent = 0;
  } else if (m_player == 2) {
    opponent = 1;
  } else {
    assert(false, "Unknown player");
  }
  for (uint i = 0; i < possible.size(); ++i) {
    engEngine eng(board, m_win_number);
    eng.place(m_player, possible[i]);
    if (eng.state() == m_player) {
      // this will win for the AI
      return i;
    }
  }

  for (uint i = 0; i < possible.size(); ++i) {
    engEngine eng(board, m_win_number);
    eng.place(opponent, possible[i]);
    if (eng.state() == opponent) {
      // this will stop the opponent winning
      return i;
    }
  }

  srand (time(NULL)); //initialize the random seed
  int random_index = rand() % possible.size();
  random_index++;
  return -1;
}

//=============================================================================
const vector<int> engAI::possible_moves(
  const vector<vector<int> >& board
) const
//
//D Returns a vector of the legal moves to make given a certain board
//
{
  vector<int> ret;
  for (uint i = 0; i < board.size(); ++i) {
    if (board[i][0] == 0) {
      ret.push_back(i);
    }
  }
  return ret;
}
