//=============================================================================
//D unit test for the connect 4 game engine

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
class utest_engEngine {
public:

  void run_tests();
  // run the tests

private:

  void horizontal_win();
  // tests a win along the bottom row

  void vertical_win();
  // tests a win along the right column

  void diagonal_left_high_win();
  // tests a diagonal win with the left side high

  void diagonal_right_high_win();
  // tests a diagonal win with the right side high

  void draw();
  // tests a draw

  void win_number_changed();
  // tests horizontal wins when the win number isn't 5

  void full_column();
  // tests the full_column() function
};

//=============================================================================
void utest_engEngine::horizontal_win()
//
//D tests a win along the bottom row
//
{
  print_test_title("Horizontal Win");
  engEngine game(6,7);
  utest(game.state() == 0, "Test inital no win");

  game.place(1,0);
  game.place(1,1);
  game.place(1,2);
  game.place(1,3);
  utest(game.state() == 1, "Test horizontal win");
}

//=============================================================================
void utest_engEngine::vertical_win()
//
//D tests a win along the right column
//
{
  print_test_title("Vertical Win");
  engEngine game(6,7);
  utest(game.state() == 0, "Test inital no win");

  game.place(2,0);
  game.place(2,0);
  game.place(2,0);
  game.place(2,0);
  utest(game.state() == 2, "Test vertical win");
}

//=============================================================================
void utest_engEngine::diagonal_left_high_win()
//
//D tests a diagonal win with the left side high
//
{
  print_test_title("Diagonal Win, Left High");
  engEngine game(6,7);
  utest(game.state() == 0, "Test inital no win");

  game.place(3,3);
  game.place(2,2);
  game.place(3,2);
  game.place(2,1);
  game.place(2,1);
  game.place(3,1);
  game.place(2,0);
  game.place(2,0);
  game.place(2,0);
  game.place(3,0);
  utest(game.state() == 3, "Test diagonal win, left side high");
}

//=============================================================================
void utest_engEngine::diagonal_right_high_win()
//
//D tests a diagonal win with the right side high
//
{
  print_test_title("Diagonal Win, Right High");
  engEngine game(6,7);
  utest(game.state() == 0, "Test inital no win");

  game.place(4,0);
  game.place(2,1);
  game.place(4,1);
  game.place(2,2);
  game.place(2,2);
  game.place(4,2);
  game.place(2,3);
  game.place(2,3);
  game.place(2,3);
  game.place(4,3);
  utest(game.state() == 4, "Test diagonal win, right side high");
}

//=============================================================================
void utest_engEngine::draw()
//
//D tests a draw
//
{
  print_test_title("Draw");
  engEngine game(6,7);
  utest(game.state() == 0, "Test inital no win");

  // testing for a draw, lots of coins to place
  game.place(1,0);
  game.place(1,0);
  game.place(2,0);
  game.place(1,0);
  game.place(2,0);
  game.place(1,0);

  game.place(1,1);
  game.place(1,1);
  game.place(2,1);
  game.place(1,1);
  game.place(2,1);
  game.place(1,1);

  game.place(2,2);
  game.place(2,2);
  game.place(1,2);
  game.place(2,2);
  game.place(2,2);
  game.place(1,2);

  game.place(2,3);
  game.place(2,3);
  game.place(1,3);
  game.place(2,3);
  game.place(1,3);
  game.place(2,3);

  game.place(1,4);
  game.place(1,4);
  game.place(2,4);
  game.place(2,4);
  game.place(2,4);
  game.place(1,4);

  game.place(2,5);
  game.place(1,5);
  game.place(2,5);
  game.place(1,5);
  game.place(2,5);
  game.place(1,5);

  game.place(1,6);
  game.place(2,6);
  game.place(1,6);
  game.place(2,6);
  game.place(2,6);
  game.place(1,6);
  utest(game.state() == -1, "Test a draw.");
}

//=============================================================================
void utest_engEngine::win_number_changed()
//
//D tests horizontal wins when the win number isn't 5
//
{
  print_test_title("Win Number Changed");
  engEngine game(6,7);
  game.set_win_number(3);

  game.place(1,0);
  game.place(1,1);
  game.place(1,2);
  
  utest(game.state() == 1, "Test win number of 3");
  
  game.set_win_number(5);
  game.place(1,3);
  
  utest(game.state() == 0, "Test win number of 5 dosn't win with 4 in a row");
  
  game.place(1,4);
  
  utest(game.state() == 1, "Test win number of 5");
}

//=============================================================================
void utest_engEngine::full_column()
//
//D tests the full column function
//
{
  print_test_title("Full Column");
  engEngine game(6,7);
  
  utest(!game.full(0), "Test the column is not full with 1.");
  
  game.place(1,0);
  
  utest(!game.full(0), "Test the column is not full with 2.");
  
  game.place(1,0);
  
  utest(!game.full(0), "Test the column is not full with 3.");
  
  game.place(1,0);
  
  utest(!game.full(0), "Test the column is not full with 4.");
  
  game.place(1,0);
  
  utest(!game.full(0), "Test the column is not full with 5.");
  
  game.place(1,0);
  
  utest(!game.full(0), "Test the column is not full with 6.");
  
  game.place(1,0);

  utest(game.full(0), "Test the column is full with 7.");
}

//=============================================================================
void utest_engEngine::run_tests()
//
//D runs the tests
//
{
  print_test_title("Running engEngine Tests");
  full_column();
  horizontal_win();
  vertical_win();
  diagonal_left_high_win();
  diagonal_right_high_win();
  draw();
  win_number_changed();
}

//=============================================================================
int main(int num_arguments, char* arguments[])
//
//D The entry for the tests
//
{
  utest_engEngine tests;
  tests.run_tests();
  return 0;
}
