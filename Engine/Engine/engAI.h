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

  engAI(const int player, const int difficulty);
  // Default constructor.

  ~engAI();
  // Destructor.

  const int move(const vector<vector<int> >& board);
  // returns which column the AI will use.
  
private:

  // friends
  friend class utest_engAI;
  // functions

  const int naive_algorithm(const vector<vector<int> >& board);
  // if the computer can win it will return there, then if it can stop the
  // other player it will go there, after that it picks a non-full column
  // randomly.
  
  engAI(const engAI&);
  // Prohibited copy constructor.

  void operator=(const engAI&);
  // Prohibited assignment operator.

  // variables
  int m_difficulty;
  int m_player;
  
};

#endif
