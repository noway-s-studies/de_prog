#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myheader.h"
#define N 3
#define M 4




#include <stdlib.h>
#include <string.h>

int *logical( char *t[], int n, int m, char *s ){
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
}




int main()
{
  char *t[ N ][ M ] =
    { { "szaxofon", "szaxofon",    "szaxofon", "szaxofon"    },
      { "szaxofon", "kakukktojas", "szaxofon", "szaxofon"    },
      { "szaxofon", "szaxofon",    "szaxofon", "kakukktojas" } };
  char str[ 100 ];
  int i, j;
  int *p;
  strcpy( str, "kakukktojas" );
  printf( "%d %d *%s*\n\n", N, M, str );
  for ( i = 0; i < N; ++i )
  {
    for ( j = 0; j < M; ++j )
    {
      if ( j > 0 )
        putchar( ' ' );
      printf( "*%s*", t[ i ][ j ] );
    }
    putchar( '\n' );
  }
  putchar( '\n' );
  p = logical( &t[ 0 ][ 0 ], N, M, str );
  for ( i = 0; i < N; ++i )
  {
    for ( j = 0; j < M; ++j )
    {
      if ( j > 0 )
        putchar( ' ' );
      printf( "*%s*", t[ i ][ j ] );
    }
    putchar( '\n' );
  }
  putchar( '\n' );
  for ( j = 0; j < M; ++j )
  {
    if ( j > 0 )
      putchar( ' ' );
    printf( "%d", p[ j ] );
  }
  putchar( '\n' );
  free( p );
  return EXIT_SUCCESS;
}
