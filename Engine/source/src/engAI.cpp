//=============================================================================
//D AI for a connect four game
//
// This currently implements a very naive algorithm, which wins if it can, then
// tries to stop it's opponent winning, otherwise chooses randomly.
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
  assert((m_player == 1 || player == 2), "Player number should be 1 or 2.");
  assert((m_difficulty >= 0), "difficulty should be non-negative.");
  assert((m_win_number >= 0), "win number shoule be non-negative.");
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
  // if difficulty is 0 use the naive algorithm else use min-max with the
  // difficulty as the depth
  int move = -1;
  if (m_difficulty == 0) {
    move = naive_algorithm(board);
  } else {
    move = min_max_algorithm(board, m_difficulty) ;
  }
  return move;
}

//=============================================================================
const int engAI::min_max_algorithm(
  const vector<vector<int> >& board,
  const int depth
) const
//
//
//
{
  return 0;
}

//=============================================================================
const int engAI::naive_algorithm(const vector<vector<int> >& board) const
//
//D if the computer can win it will return there, then if it can stop the other
//D player it will go there, after that it picks a non-full column randomly
//
{
  const vector<int> possible(possible_moves(board));
  int opponent = -1;
  if (m_player == 1) {
    opponent = 2;
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

  // if can't win or prevent a win then choose randomly

  // initialize the random seed
  srand (time(NULL)); 
  int random_index = rand() % possible.size();
  return possible[random_index];
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
