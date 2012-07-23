//=============================================================================
//D unit test for the connect 4 game engine

#include "Engine/engAI.h"
#include "Engine/engEngine.h"

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
  print_test_title("Takes Horizontal Win");
  engEngine game(6,7);
  game.place(1,0);
  game.place(1,1);
  game.place(1,2);

  // at the moment difficulty does not matter, set to 0
  engAI opponent(1, 0, 4);
  utest(
    opponent.naive_algorithm(game.board()) == 3,
    "Test if the computer takes a horizontal win."
  );
}

//=============================================================================
void utest_engAI::takes_vertical_win()
//
//D tests a win along the right column
//
{
  print_test_title("Takes Vertical Win");
  engEngine game(6,7);
  game.place(1,0);
  game.place(1,0);
  game.place(1,0);

  // at the moment difficulty does not matter, set to 0
  engAI opponent(1, 0, 4);
  utest(
    opponent.naive_algorithm(game.board()) == 0,
    "Test if the computer takes a vertical win."
  );
}

//=============================================================================
void utest_engAI::takes_diagonal_left_high_win()
//
//D tests a diagonal win with the left side high
//
{
  print_test_title("Takes Diagonal Left High Win");
  engEngine game(6,7);
  game.place(1,3);
  game.place(2,2);
  game.place(1,2);
  game.place(2,1);
  game.place(2,1);
  game.place(1,1);
  game.place(1,0);
  game.place(2,0);
  game.place(2,0);

  // at the moment difficulty does not matter, set to 0
  engAI opponent(1, 0, 4);
  utest(
    opponent.naive_algorithm(game.board()) == 0,
    "Test if the computer takes a left high diagonal win."
  );
}

//=============================================================================
void utest_engAI::takes_diagonal_right_high_win()
//
//D tests a diagonal win with the right side high
//
{
  print_test_title("Takes Diagonal Right High Win");
  engEngine game(6,7);
  game.place(1,0);
  game.place(2,1);
  game.place(1,1);
  game.place(2,2);
  game.place(2,2);
  game.place(1,2);
  game.place(2,3);
  game.place(2,3);
  game.place(2,3);

  // at the moment difficulty does not matter, set to 0
  engAI opponent(1, 0, 4);
  utest(
    opponent.naive_algorithm(game.board()) == 3,
    "Test if the computer takes a right high diagonal win."
  );
}

//=============================================================================
void utest_engAI::stops_horizontal_win()
//
//D tests a win along the bottom row
//
{
  print_test_title("Stops Horizontal Win");
  engEngine game(6,7);
  game.place(1,0);
  game.place(1,1);
  game.place(1,2);

  // at the moment difficulty does not matter, set to 0
  engAI opponent(2, 0, 4);
  utest(
    opponent.naive_algorithm(game.board()) == 3,
    "Test if the computer stops a horizontal win."
  );
}

//=============================================================================
void utest_engAI::stops_vertical_win()
//
//D tests a win along the right column
//
{
  print_test_title("Stops Vertical Win");
  engEngine game(6,7);
  game.place(1,0);
  game.place(1,0);
  game.place(1,0);

  // at the moment difficulty does not matter, set to 0
  engAI opponent(2, 0, 4);
  utest(
    opponent.naive_algorithm(game.board()) == 0,
    "Test if the computer stops a vertical win."
  );
}

//=============================================================================
void utest_engAI::stops_diagonal_left_high_win()
//
//D tests a diagonal win with the left side high
//
{
  print_test_title("Stops Diagonal Left High Win");
  engEngine game(6,7);
  game.place(1,3);
  game.place(2,2);
  game.place(1,2);
  game.place(2,1);
  game.place(2,1);
  game.place(1,1);
  game.place(1,0);
  game.place(2,0);
  game.place(2,0);

  // at the moment difficulty does not matter, set to 0
  engAI opponent(2, 0, 4);
  utest(
    opponent.naive_algorithm(game.board()) == 0,
    "Test if the computer stops a left high diagonal win."
  );
}

//=============================================================================
void utest_engAI::stops_diagonal_right_high_win()
//
//D tests a diagonal win with the right side high
//
{
  print_test_title("Stops Diagonal Right High Win");
  engEngine game(6,7);
  game.place(1,0);
  game.place(2,1);
  game.place(1,1);
  game.place(2,2);
  game.place(2,2);
  game.place(1,2);
  game.place(2,3);
  game.place(2,3);
  game.place(2,3);

  // at the moment difficulty does not matter, set to 0
  engAI opponent(2, 0, 4);
  utest(
    opponent.naive_algorithm(game.board()) == 3,
    "Test if the computer stops a right high diagonal win."
  );
}

//=============================================================================
void utest_engAI::wins_not_spoils()
//
//D tests that the computer wins rather than stopping the player winning
//
{
  print_test_title("Wins Rather Than Prevents");
  engEngine game(6,7);
  game.place(1,0);
  game.place(1,1);
  game.place(1,2);
  game.place(2,4);
  game.place(2,4);
  game.place(2,4);

  // at the moment difficulty does not matter, set to 0
  engAI opponent(1, 0, 4);
  utest(
    opponent.naive_algorithm(game.board()) == 3,
    "Test if the computer goes for a win rather than stoping the other player."
  );
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
