#include <stdio.h>
#include <stdlib.h>

/* egy tomb merete */
#define MERET( t ) sizeof( t ) / sizeof( int )

/* a sikertelen kereses jele */
#define SIKERTELEN -1

int teljes( int t[], int n, int ertek )
{
  int i;
  for ( i = 0; i < n; ++i )
    if ( t[ i ] == ertek )
      return i;
  return SIKERTELEN;
}

int strazsa( int t[], int n, int ertek )
{
  int i;
  t[ n ] = ertek;
  for ( i = 0; ; ++i )
    if ( t[ i ] == ertek )
      if ( i == n )
        return SIKERTELEN;
      else
        return i;
}

int strazsa2( int t[], int n, int ertek )
{
  int i;
  t[ n ] = ertek;
  for ( i = 0; t[ i ] != ertek; ++i )
    ;
  if ( i == n )
    return SIKERTELEN;
  else
    return i;
}

int teljes_rek( int t[], int n, int kezdo, int ertek )
{
  if ( kezdo == n )
    return SIKERTELEN;
  if ( t[ kezdo ] == ertek )
    return kezdo;
  return teljes_rek( t, n, kezdo + 1, ertek );
}

int linearis( int t[], int n, int ertek )
{
  int i;
  for ( i = 0; i < n; ++i )
  {
    if ( t[ i ] == ertek )
      return i;
    if ( t[ i ] > ertek )
      return SIKERTELEN;
  }
  return SIKERTELEN;
}

int linearis_rek( int t[], int n, int kezdo, int ertek )
{
  if ( kezdo == n )
    return SIKERTELEN;
  if ( t[ kezdo ] == ertek )
    return kezdo;
  if ( t[ kezdo ] > ertek )
    return SIKERTELEN;
  return linearis_rek( t, n, kezdo + 1, ertek );
}

int binaris( int t[], int n, int ertek )
{
  int also = 0, felso = n - 1;
  while ( also <= felso )
  {
    int kozepso = ( also + felso ) / 2;
    if ( t[ kozepso ] == ertek )
      return kozepso;
    if ( t[ kozepso ] > ertek )
      felso = kozepso - 1;
    else
      also = kozepso + 1;
  }
  return SIKERTELEN;
}

int binaris_rek( int t[], int also, int felso, int ertek )
{
  int kozepso;
  if ( also > felso )
    return SIKERTELEN;
  kozepso = ( also + felso ) / 2;
  if ( t[ kozepso ] == ertek )
    return kozepso;
  if ( t[ kozepso ] > ertek )
    return binaris_rek( t, also, kozepso - 1, ertek );
  else
    return binaris_rek( t, kozepso + 1, felso, ertek );
}

void eredmeny( int poz, char *modszer )
{
  printf( "%s: ", modszer );
  if ( poz == SIKERTELEN )
    puts( "Nincs benne a keresett elem." );
  else
    printf( "Benne van, index: %d.\n", poz );
}

int main()
{
/* rendezetlen tomb a teljes kereseshez*/
  int tomb[] = { 23, 235, 634, 6783, 34578, -235, 0, 235, -34 };
/* a strazsas kereseshez eggyel nagyobb meretu tombot foglalunk */
  int tomb2[ MERET( tomb ) + 1 ] =
    { 23, 235, 634, 6783, 34578, -235, 0, 235, -34 };
/* rendezett tomb a linearis es a binaris kereseshez */
  int rend_tomb[] = { 23, 235, 634, 6783, 6783, 22235, 100000, 235000 };
/* a keresett ertek */
  const int keresett = 235;
  int poz_teljes = teljes( tomb, MERET( tomb ), keresett );
  int poz_strazsa = strazsa( tomb2, MERET( tomb ), keresett );
  int poz_teljes_rek = teljes_rek( tomb, MERET( tomb ), 0, keresett );
  int poz_linearis = linearis( rend_tomb, MERET( rend_tomb ), keresett );
  int poz_linearis_rek = linearis_rek( rend_tomb, MERET( rend_tomb ), 0, keresett );
  int poz_binaris = binaris( rend_tomb, MERET( rend_tomb ), keresett );
  int poz_binaris_rek = binaris_rek( rend_tomb, 0, MERET( rend_tomb ) - 1, keresett );
  eredmeny( poz_teljes, "Teljes kereses" );
  eredmeny( poz_strazsa, "Strazsas kereses" );
  eredmeny( poz_teljes_rek, "Rekurziv teljes kereses" );
  eredmeny( poz_linearis, "Linearis kereses" );
  eredmeny( poz_linearis_rek, "Rekurziv linearis kereses" );
  eredmeny( poz_binaris, "Binaris kereses" );
  eredmeny( poz_binaris_rek, "Rekurziv binaris kereses" );
  return EXIT_SUCCESS;
}
