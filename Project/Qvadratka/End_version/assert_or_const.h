#ifndef ASSERT_OR_CONST_H
#define ASSERT_OR_CONST_H

#include <stdlib.h>

#define ASSERT_ABORT(condition)                              \
        if (!(condition)) {                                  \
        printf( "Error in condition \"%s\" in line - %d "    \
        "in file \"%s\"\n", #condition, __LINE__, __FILE__); \
        abort(); }



#define CNT_ARG_TEST 6

extern const int   proga;
extern const int   from_file;
extern const char* DEFAULT_TEST_FILE;
const int ALL_NUMBER = -1;

#endif
