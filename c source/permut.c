#include <stdio.h>
#include <stdlib.h>

typedef enum { HAMIS, IGAZ } BOOL;

void csere( int t[], int i, int j )
{
  register int seged = t[ i ];
  t[ i ] = t[ j ];
  t[ j ] = seged;
}

void fordit( int t[], int also, int felso )
{
  while ( also < felso )
    csere( t, also++, felso-- );
}

BOOL kov_permutacio( int t[], int n )
{
  int i, j;
  for ( i = n - 1; i > 0 && t[ i - 1 ] >= t[ i ]; --i )
    ;
  if ( i <= 0 )
    return HAMIS;
  --i;
  for ( j = n - 1; t[ j ] <= t[ i ]; --j )
    ;
  csere( t, i, j );
  fordit( t, i + 1, n - 1 );
  return IGAZ;
}

#define MAX_MERET 100
#define MERET 4

int main( int argc, char *argv[] )
{
  int t[ MAX_MERET ], meret = MERET, i;
  if ( argc != 1 )
    meret = atoi( argv[ 1 ] );
  for ( i = 0; i < meret; ++i )
    t[ i ] = i + 1;
  do
  {
    for ( i = 0; i < meret; ++i )
      printf( "%d ", t[ i ] );
    putchar( '\n' );
  } while ( kov_permutacio( t, meret ) );
  return EXIT_SUCCESS;
}
