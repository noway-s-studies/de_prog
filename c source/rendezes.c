#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MERET( t ) sizeof( t ) / sizeof( int )

#define HAMIS 0
#define IGAZ  !HAMIS

void csere( int tomb[], int i, int j )
{
  register int seged = tomb[ i ];
  tomb[ i ] = tomb[ j ];
  tomb[ j ] = seged;
}

void minkival( int t[], int n )
{
  int i;
  for ( i = 0; i < n - 1; ++i )
  {
    int j, min = i;
    for ( j = i + 1; j < n; ++j )
      if ( t[ j ] < t[ min ] )
        min = j;
    csere( t, i, min );
  }
}

void buborekos( int t[], int n )
{
  int i, j;
  for ( i = n - 1; i > 0; --i )
    for ( j = 0; j < i; ++j )
      if ( t[ j ] > t[ j + 1 ] )
        csere( t, j, j + 1 );
}

void buborekos2( int t[], int n )
{
  int i, j, voltcsere = IGAZ;
  for ( i = n - 1; i > 0 && voltcsere; --i )
  {
    voltcsere = HAMIS;
    for ( j = 0; j < i; ++j )
      if ( t[ j ] > t[ j + 1 ] )
      {
        csere( t, j, j + 1 );
        voltcsere = IGAZ;
      }
  }
}

void buborekos3( int t[], int n )
{
  int i, j, utolsocsere;
  for ( i = n - 1; i > 0; i = utolsocsere )
  {
    utolsocsere = 0;
    for ( j = 0; j < i; ++j )
      if ( t[ j ] > t[ j + 1 ] )
      {
        csere( t, j, j + 1 );
        utolsocsere = j;
      }
  }
}

void beszurasos( int t[], int n )
{
  int i;
  for ( i = 1; i < n; ++i )
  {
    int kulcs = t[ i ], j;
    for ( j = i - 1; j >= 0 && t[ j ] > kulcs; --j )
      t[ j + 1 ] = t[ j ];
    t[ j + 1 ] = kulcs;
  }
}

void shell( int t[], int n )
{
  int lk[] = { 1750, 701, 301, 132, 57, 23, 10, 4, 1 };
  int lkindex;
  for ( lkindex = 0; lkindex < MERET( lk ); ++lkindex )
  {
    int lepeskoz = lk[ lkindex ];
    int eltolas, j;
    for ( eltolas = 0; eltolas < lepeskoz; ++eltolas )
      for ( j = eltolas + lepeskoz; j < n; j += lepeskoz )
      {
        int i, kulcs = t[ j ];
        for ( i = j - lepeskoz; i >= 0 && t[ i ] > kulcs; i-= lepeskoz )
          t[ i + lepeskoz ] = t[ i ];
        t[ i + lepeskoz ] = kulcs;
      }
  }
}

void shell2( int t[], int n )
{
  int lk[] = { 1750, 701, 301, 132, 57, 23, 10, 4, 1 };
  int lkindex;
  for ( lkindex = 0; lkindex < MERET( lk ); ++lkindex )
  {
    int lepeskoz = lk[ lkindex ];
    int j;
    for ( j = lepeskoz; j < n; ++j )
    {
      int i, kulcs = t[ j ];
      for ( i = j - lepeskoz; i >= 0 && t[ i ] > kulcs; i -= lepeskoz )
        t[ i + lepeskoz ] = t[ i ];
      t[ i + lepeskoz ] = kulcs;
    }
  }
}

int feloszt_hoare( int t[], int bal, int jobb )
{
  int also = bal, felso = jobb + 1, kulcs = t[ bal ];
  for ( ;; )
  {
    do
      ++also;
    while ( also < felso && t[ also ] <= kulcs );
    do
      --felso;
    while ( t[ felso ] > kulcs );
    if ( also >= felso )
      break;
    csere( t, also, felso );
  }
  csere( t, bal, felso );
  return felso;
}

int feloszt_clrs( int t[], int bal, int jobb )
{
  int kulcs = t[ jobb ], hatar = bal, akt;
  for ( akt = bal; akt < jobb; ++akt )
    if ( t[ akt ] < kulcs )
      csere( t, hatar++, akt );
  csere( t, hatar, jobb );
  return hatar;
}

void gyors( int t[], int bal, int jobb )
{
  if ( bal < jobb )
  {
    int kozepso = feloszt_hoare( t, bal, jobb );
/*
    int kozepso = feloszt_clrs( t, bal, jobb );
*/
    gyors( t, bal, kozepso - 1 );
    gyors( t, kozepso + 1, jobb );
  }
}

void gyors2( int t[], int bal, int jobb )
{
  while ( bal < jobb )
  {
    int kozepso;
    if ( jobb - bal < 13 )
    {
      beszurasos( t + bal, jobb - bal + 1 );
      break;
    }
    kozepso = feloszt_hoare( t, bal, jobb );
/*
    kozepso = feloszt_clrs( t, bal, jobb );
*/
    if ( kozepso - 1 - bal > jobb - ( kozepso + 1 ) )
    {
      gyors2( t, kozepso + 1, jobb );
      jobb = kozepso - 1;
    }
    else
    {
      gyors2( t, bal, kozepso - 1 );
      bal = kozepso + 1;
    }
  }
}

int hasonlit( const void *egyik, const void *masik )
{
  return *( int * )egyik - *( int * )masik;
}

#define N 10

int t[ N ];

int main()
{
  int i;
  srand( ( unsigned int )time( NULL ) + getpid() );
  for ( i = 0; i < N; ++i )
    t[ i ] = i + 1;
  for ( i = N; i > 1; --i )
  {
    int pos = ( int )( ( double )i * rand() / ( RAND_MAX + 1.0 ) );
    csere( t, pos, i - 1 );
  }
  for ( i = 0; i < N; ++i )
    printf( "%d ", t[ i ] );
  putchar( '\n' );
 /*
  minkival( t, N );
  buborekos( t, N );
  buborekos2( t, N );
  buborekos3( t, N );
  beszurasos( t, N );
  shell( t, N );
  shell2( t, N );
  gyors( t, 0, N - 1 );
  gyors2( t, 0, N - 1 );
*/
  qsort( t, N, sizeof( int ), hasonlit );
  for ( i = 0; i < N; ++i )
    printf( "%d ", t[ i ] );
  putchar( '\n' );
  return EXIT_SUCCESS;
}
