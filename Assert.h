//=============================================================================
//D Define my own assertion macro so that it can display a message. Put the
//D unit test function I use in this for reuse.

#ifndef Assert_H
#define Assert_H

#include <iostream>
#include <stdlib.h>
#include <string>

// Asserts returning a message in the following format:
// Assertion `test_value` failed in source/utest_Test.cpp line 25: Test
#define assert(condition, message) \
do { \
    if (!condition) { \
        std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                  << " line " << __LINE__ << ": " << message << std::endl;\
                                                                            exit(EXIT_FAILURE); \
      } \
    } while (false)

#endif
