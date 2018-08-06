#include <stdio.h>
#include <stdlib.h>
#include "myheader.h"
#define N 5

int *sitdown( int *t, int k){
    int *tomb = NULL, i, j;
    tomb = realloc(tomb, m*sizeof(int));
    for(i=0; i<m; i++){
        tomb[i]=0;
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(!strcmp(t[i*m+j],s)){
                tomb[j]=1;
            }
        }
    }
    return tomb;
};



int main()
{
  int t[ N ][ N ] =
    { {  2,  5, 24, 15,  3 },
      { 17, 10,  6, 18, 14 },
      { 19,  8, 20, 22, 16 },
      { 12,  7,  1,  4, 25 },
      { 11, 13, 21,  9, 23 } };
  int i, j, *p;
  printf( "%d\n\n", N );
  for ( i = 0; i < N; ++i )
  {
    for ( j = 0; j < N; ++j )
    {
      if ( j > 0 )
        putchar( ' ' );
      printf( "%d", t[ i ][ j ] );
    }
    putchar( '\n' );
  }
  putchar( '\n' );
  p = sitdown( &t[ 0 ][ 0 ], N );
  for ( i = 0; i < N; ++i )
  {
    for ( j = 0; j < N; ++j )
    {
      if ( j > 0 )
        putchar( ' ' );
      printf( "%d", t[ i ][ j ] );
    }
    putchar( '\n' );
  }
  putchar( '\n' );
  for ( i = 0; i < N; ++i )
  {
    if ( i > 0 )
      putchar( ' ' );
    printf( "%d", p[ i ] );
  }
  putchar( '\n' );
  free( p );
  return EXIT_SUCCESS;
}
