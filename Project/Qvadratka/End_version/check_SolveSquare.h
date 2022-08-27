/// @file //
#ifndef CHECK_SOLVESQUARE_H
#define CHECK_SOLVESQUARE_H

#include "SolveSquare.h"



/// @brief Creates one test
/// @param [in] a - equation coefficient
/// @param [in] b - equation coefficient
/// @param [in] c - equation coefficient
/// @param [in] nRoots - cnt of roots
/// @param [in] solv1 - first root
/// @param [in] solv2 - second root
/// @return
///         0 - test failed
///         1 - test passed
int Test( const double a, const double b, const double c, const int nRoots, const double solv1, const double solv2 );


/// @brief checks the correctness of the function
/// @param [in] method - file reading method
/// @param [in] s - name of file
/// @return
///         0 - correct input
///         1 - invalid input
bool check_SolveSquare(bool method, const char* s);


/// @brief Outputs a verdict to the wrong test
/// @param [in] verdict - cnt of roots
/// @param [in] x1 - first root
/// @param [in] x2 - second root
/// @param [in] is_expected - Is the input expected?
void PrintVerdict( const int verdict, const double* const x1, const double* const x2, const bool is_expected );

/// @brief Reads tests from a file
/// @param [in] file - stream pointer
/// @param [in] OkTest - cnt right tests
/// @param [in] nTest - cnt tests
/// @param [in] valid_test - cnt correct tests
/// @param [in] a - equation coefficient
/// @param [in] b - equation coefficient
/// @param [in] c - equation coefficient
/// @param [in] nRoots - cnt of roots
/// @param [in] x1 - first root
/// @param [in] x2 - second root
void check_from_file( FILE* file, int* OkTest, int* nTest, int* valid_test,
                      double* const a,      double* const b,  double* const c,
                      int*    const nRoots, double* const x1, double* const x2);

#endif //CHECK_SOLVESQUARE_H
