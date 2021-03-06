//=============================================================================
// engAI.h
//
//  The AI for connect 4 game.
//

#ifndef engAI_H
#define engAI_H

#include <vector>

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs, namespaces

using std::vector;

// variables: consts, statics, exported variables (declared extern elsewhere)
// local forward function declarations

//=============================================================================
class engAI {
public:

  engAI(const int player, const int difficulty, const int win_number);
  // Default constructor.

  ~engAI();
  // Destructor.

  const int move(const vector<vector<int> >& board);
  // returns which column the AI will use.
  
private:

  // friends
  friend class utest_engAI;
  // functions

  const vector<int> possible_moves(const vector<vector<int> >& board) const;
  // return a vector of the possible moves given the board

  const int min_max_algorithm(
    const vector<vector<int> >& board,
    const int depth
  ) const;
  // an implementation of a min max algorithm
  
  const int naive_algorithm(const vector<vector<int> >& board) const;
  // if the computer can win it will return there, then if it can stop the
  // other player it will go there, after that it picks a non-full column
  // randomly.
  
  engAI(const engAI&);
  // Prohibited copy constructor.

  void operator=(const engAI&);
  // Prohibited assignment operator.

  // variables
  int m_player;
  int m_difficulty;
  int m_win_number;
  
};

#endif
