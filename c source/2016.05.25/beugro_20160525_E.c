#include <stdio.h>
#include <stdlib.h>
#include "myheader.h"
#define N 4
#define M 5

double *average( double t[], int n, int m){
    double *tomb = NULL;
    tomb = (double *)malloc(m * sizeof(double));
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            tomb[j] += t[(i*m)+j];
        }
    }
    return tomb;
};

int main()
{
  double t[ N ][ M ] =
    { {  2.25, -4.5,   8.0,   5.75, -13.25 },
      {  6.75,  1.5,   2.25,  3.75,   8.0 },
      { -3.5,   7.0,  -1.75, -6.25,  -3.75 },
      { 12.0,  -6.25, 10.25,  0.0,   10.5 } };
  int i, j;
  double *p;
  printf( "%d %d\n\n", N, M );
  for ( i = 0; i < N; ++i )
  {
    for ( j = 0; j < M; ++j )
    {
      if ( j > 0 )
        putchar( ' ' );
      printf( "%.3f", t[ i ][ j ] );
    }
    putchar( '\n' );
  }
  putchar( '\n' );
  p = average( &t[0][0], N, M );
  for ( i = 0; i < N; ++i )
  {
    for ( j = 0; j < M; ++j )
    {
      if ( j > 0 )
        putchar( ' ' );
      printf( "%.3f", t[ i ][ j ] );
    }
    putchar( '\n' );
  }
  putchar( '\n' );
  for ( j = 0; j < M; ++j )
  {
    if ( j > 0 )
      putchar( ' ' );
    printf( "%.4f", p[ j ] );
  }
  putchar( '\n' );
  free( p );
  return EXIT_SUCCESS;
}
