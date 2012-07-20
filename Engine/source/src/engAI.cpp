//=============================================================================
//D <One line description>
//
// <Full description.>
//

#include "Engine/engAI.h"
#include "dgcUtils/Assert.h" // use dgc asserts

// types: classes, enums, typedefs, namespaces
// variables: consts, statics, exported variables (declared extern elsewhere)
// local forward function declarations

//=============================================================================
engAI::engAI(const int player, const int difficulty)
//
//D Default constructor.
//
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
  return 0; // so it compiles 
}

//=============================================================================
const int engAI::naive_algorithm(const vector<vector<int> >& board)
//
//D if the computer can win it will return there, then if it can stop the other
//D player it will go there, after that it picks a non-full column randomly
//
{
  return 0; // so it compiles 
}

