//=============================================================================
//D unit test for the connect 4 game engine

#include "Engine/engAI.h"

#include "dgcUtils/Assert.h" // use asserts
#include "dgcUtils/UTest.h"

#include <iostream>

// types: classes, enums, typedefs, namespaces
using std::cout;
using std::cerr;
using std::endl;
using std::string;

// variables: consts, statics, exported variables (declared extern elsewhere)
// local forward function declarations

//=============================================================================
class utest_engAI {
public:

  void run_tests();
  // run the tests

private:

  void takes_horizontal_win();
  // tests a win along the bottom row

  void takes_vertical_win();
  // tests a win along the right column

  void takes_diagonal_left_high_win();
  // tests a diagonal win with the left side high

  void takes_diagonal_right_high_win();
  // tests a diagonal win with the right side high

  void stops_horizontal_win();
  // tests a win along the bottom row

  void stops_vertical_win();
  // tests a win along the right column

  void stops_diagonal_left_high_win();
  // tests a diagonal win with the left side high

  void stops_diagonal_right_high_win();
  // tests a diagonal win with the right side high

  void wins_not_spoils();
  // tests that the computer wins rather than stopping the player winning

};

//=============================================================================
void utest_engAI::takes_horizontal_win()
//
//D tests a win along the bottom row
//
{
}

//=============================================================================
void utest_engAI::takes_vertical_win()
//
//D tests a win along the right column
//
{
}

//=============================================================================
void utest_engAI::takes_diagonal_left_high_win()
//
//D tests a diagonal win with the left side high
//
{
}

//=============================================================================
void utest_engAI::takes_diagonal_right_high_win()
//
//D tests a diagonal win with the right side high
//
{
}

//=============================================================================
void utest_engAI::stops_horizontal_win()
//
//D tests a win along the bottom row
//
{
}

//=============================================================================
void utest_engAI::stops_vertical_win()
//
//D tests a win along the right column
//
{
}

//=============================================================================
void utest_engAI::stops_diagonal_left_high_win()
//
//D tests a diagonal win with the left side high
//
{
}

//=============================================================================
void utest_engAI::stops_diagonal_right_high_win()
//
//D tests a diagonal win with the right side high
//
{
}

//=============================================================================
void utest_engAI::wins_not_spoils()
//
//D tests that the computer wins rather than stopping the player winning
//
{
}

//=============================================================================
void utest_engAI::run_tests()
//
//D runs the tests
//
{
  print_test_title("Running engAI Tests");
  takes_horizontal_win();
  // tests a win along the bottom row

  takes_vertical_win();
  // tests a win along the right column

  takes_diagonal_left_high_win();
  // tests a diagonal win with the left side high

  takes_diagonal_right_high_win();
  // tests a diagonal win with the right side high

  stops_horizontal_win();
  // tests a win along the bottom row

  stops_vertical_win();
  // tests a win along the right column

  stops_diagonal_left_high_win();
  // tests a diagonal win with the left side high

  stops_diagonal_right_high_win();
  // tests a diagonal win with the right side high

  wins_not_spoils();
}

//=============================================================================
int main(int num_arguments, char* arguments[])
//
//D The entry for the tests
//
{
  utest_engAI tests;
  tests.run_tests();
  return 0;
}
