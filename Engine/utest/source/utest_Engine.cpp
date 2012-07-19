//=============================================================================
//D unit test for the connect 4 game engine

#include "Engine/Engine.h"

#include <assert.h> // use asserts
#include <iostream>

// types: classes, enums, typedefs, namespaces
using std::cout;
using std::cerr;
using std::endl;
using std::string;
// variables: consts, statics, exported variables (declared extern elsewhere)
// local forward function declarations

//=============================================================================
void utest(const bool test_value, const string& message)
//
//D Test the value and return the message with PASSED or FAILED, assert on fail
//
{
  if (!test_value) {
    cerr << "FAILED: " << message << endl;
    assert(test_value);
  } else {
    cout << "PASSED: " << message << endl;
    cout << endl;
  }
}

//=============================================================================
class utest_Engine {
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

};

//=============================================================================
void utest_Engine::run_tests()
//
//D runs the tests
//
{
  horizontal_win();
  vertical_win();
  diagonal_left_high_win();
  diagonal_right_high_win();
  draw();
  win_number_changed();
}


//=============================================================================
void utest_Engine::horizontal_win()
//
//D tests a win along the bottom row
//
{
  Engine game(6,7);
  utest(game.state() == 0, "Test inital no win");

  game.place(1,0);
  game.place(1,1);
  game.place(1,2);
  game.place(1,3);
  utest(game.state() == 1, "Test horizontal win");
}

//=============================================================================
void utest_Engine::vertical_win()
//
//D tests a win along the right column
//
{
  Engine game(6,7);
  utest(game.state() == 0, "Test inital no win");

  game.place(2,0);
  game.place(2,0);
  game.place(2,0);
  game.place(2,0);
  utest(game.state() == 2, "Test vertical win");
}

//=============================================================================
void utest_Engine::diagonal_left_high_win()
//
//D tests a diagonal win with the left side high
//
{
  Engine game(6,7);
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
void utest_Engine::diagonal_right_high_win()
//
//D tests a diagonal win with the right side high
//
{
  Engine game(6,7);
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
void utest_Engine::draw()
//
//D tests a draw
//
{
  Engine game(6,7);
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
void utest_Engine::win_number_changed()
//
//D tests horizontal wins when the win number isn't 5
//
{
  Engine game(6,7);
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
int main(int num_arguments, char* arguments[])
//
//D The entry for the tests
//
{
  utest_Engine tests;
  tests.run_tests();
  return 0;
}
