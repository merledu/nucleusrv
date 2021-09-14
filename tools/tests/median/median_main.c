// See LICENSE for license details.

//**************************************************************************
// Median filter bencmark
//--------------------------------------------------------------------------
//
// This benchmark performs a 1D three element median filter. The
// input data (and reference data) should be generated using the
// median_gendata.pl perl script and dumped to a file named
// dataset1.h.

#include "util.h"

#include "median.h"

//--------------------------------------------------------------------------
// Input/Reference Data

#include "dataset1.h"

//--------------------------------------------------------------------------
// Main
void median( int n, int input[], int results[] )
{
  int A, B, C, i;

  // Zero the ends
  results[0]   = 0;
  results[n-1] = 0;

  // Do the filter
  for ( i = 1; i < (n-1); i++ ) {

    A = input[i-1];
    B = input[i];
    C = input[i+1];

    if ( A < B ) {
      if ( B < C )
        results[i] = B;
      else if ( C < A )
        results[i] = A;
      else
        results[i] = C;
    }

    else {
      if ( A < C )
        results[i] = A;
      else if ( C < B )
        results[i] = B;
      else
        results[i] = C;
    }

  }

}
int main( int argc, char* argv[] )
{
  int results_data[DATA_SIZE];

#if PREALLOCATE
  // If needed we preallocate everything in the caches
  median( DATA_SIZE, input_data, results_data );
#endif

  // Do the filter
 // setStats(1);
  median( DATA_SIZE, input_data, results_data );
  //setStats(0);

  // Check the results
  return verify( DATA_SIZE, results_data, verify_data );
}
