#include <stdio.h>
#include <stdlib.h>

typedef struct listaelem
{
  int adat;
  struct listaelem *kov;
} LISTAELEM;

void bejar_elore( LISTAELEM *fej )
{
  LISTAELEM *seged;
  for ( seged = fej; seged; seged = seged->kov )
    printf( "%d ", seged->adat );
}

void bejar_elore_rek( LISTAELEM *fej )
{
  if ( fej )
  {
    printf( "%d ", fej->adat );
    bejar_elore_rek( fej->kov );
  }
}

void bejar_hatra_rek( LISTAELEM *fej )
{
  if ( fej )
  {
    bejar_hatra_rek( fej->kov );
    printf( "%d ", fej->adat );
  }
}

LISTAELEM *beszur_eleje( LISTAELEM *fej, int adat )
{
  LISTAELEM *ujelem = ( LISTAELEM * )malloc( sizeof( LISTAELEM ) );
  ujelem->adat = adat;
  ujelem->kov = fej;
  return ujelem;
}

LISTAELEM *beszur_vege( LISTAELEM *fej, int adat )
{
  LISTAELEM *ujelem = ( LISTAELEM * )malloc( sizeof( LISTAELEM ) );
  ujelem->adat = adat;
  ujelem->kov = NULL;
  if ( !fej )
    return ujelem;
  else
  {
    LISTAELEM *seged = fej;
    while ( seged->kov )
      seged = seged->kov;
    seged->kov = ujelem;
  }
  return fej;
}

LISTAELEM *beszur_vege_rek( LISTAELEM *fej, int adat )
{
  if ( !fej )
  {
    fej = ( LISTAELEM * )malloc( sizeof( LISTAELEM ) );
    fej->adat = adat;
    fej->kov = NULL;
  }
  else
    fej->kov = beszur_vege_rek( fej->kov, adat );
  return fej;
}

LISTAELEM *beszur_rendezve( LISTAELEM *fej, int adat )
{
  LISTAELEM *ujelem = ( LISTAELEM * )malloc( sizeof( LISTAELEM ) );
  LISTAELEM *akt = fej, *elozo = NULL;
  ujelem->adat = adat;
  for ( ; akt && akt->adat < adat; elozo = akt, akt = akt->kov )
    ;
  ujelem->kov = akt;
  if ( elozo )
    elozo->kov = ujelem;
  else
    fej = ujelem;
  return fej;
}

LISTAELEM *beszur_rendezve_rek( LISTAELEM *fej, int adat )
{
  if ( !fej || fej->adat >= adat )
  {
    LISTAELEM *ujelem = ( LISTAELEM * )malloc( sizeof( LISTAELEM ) );
    ujelem->adat = adat;
    ujelem->kov = fej;
    return ujelem;
  }
  fej->kov = beszur_rendezve_rek( fej->kov, adat );
  return fej;
}

LISTAELEM *torol_eleje( LISTAELEM *fej )
{
  LISTAELEM *elso = fej;
  if ( fej )
  {
    fej = fej->kov;
    free( elso );
  }
  return fej;
}

LISTAELEM *torol_vege( LISTAELEM *fej )
{
  if ( fej )
  {
    LISTAELEM *akt = fej, *elozo = NULL;
    for ( ; akt->kov; elozo = akt, akt = akt->kov )
      ;
    if ( elozo )
      elozo->kov = NULL;
    else
      fej = NULL;
    free( akt );
  }
  return fej;
}

LISTAELEM *torol_vege_rek( LISTAELEM *fej )
{
  if ( fej )
  {
    if ( !fej->kov )
    {
      free( fej );
      return NULL;
    }
    fej->kov = torol_vege_rek( fej->kov );
  }
  return fej;
}

LISTAELEM *torol_rendezve( LISTAELEM *fej, int adat )
{
  LISTAELEM *akt = fej, *elozo = NULL;
  while ( akt && akt->adat < adat )
  {
    elozo = akt;
    akt = akt->kov;
  }
  if ( akt && akt->adat == adat )
  {
    if ( elozo )
      elozo->kov = akt->kov;
    else
      fej = akt->kov;
    free( akt );
  }
  return fej;
}

LISTAELEM *torol_rendezve_rek( LISTAELEM *fej, int adat )
{
  if ( fej && fej->adat <= adat )
    if ( fej->adat == adat )
    {
      LISTAELEM *seged = fej;
      fej = seged->kov;
      free( seged );
      return fej;
    }
    else
      fej->kov = torol_rendezve_rek( fej->kov, adat );
  return fej;
}

LISTAELEM *fordit( LISTAELEM *fej )
{
  LISTAELEM *reszlista, *ujelem;
  if ( !fej )
    return NULL;
  reszlista = fordit( fej->kov );
  ujelem = ( LISTAELEM * )malloc( sizeof( LISTAELEM ) );
  ujelem->adat = fej->adat;
  ujelem->kov = NULL;
  if ( !reszlista )
    reszlista = ujelem;
  else
  {
    LISTAELEM *seged = reszlista;
    while ( seged->kov )
      seged = seged->kov;
    seged->kov = ujelem;
  }
  return reszlista;
}

void kiir_elore( LISTAELEM *fej )
{
  bejar_elore( fej );
  putchar( '\n' );
}

void kiir_elore_rek( LISTAELEM *fej )
{
  bejar_elore_rek( fej );
  putchar( '\n' );
}

void kiir_hatra_rek( LISTAELEM *fej )
{
  bejar_hatra_rek( fej );
  putchar( '\n' );
}

void felszabadit( LISTAELEM *fej )
{
  while ( fej )
  {
    LISTAELEM *seged = fej;
    fej = fej->kov;
    free( seged );
  }
}

int main()
{
  LISTAELEM *fej = NULL, *fej2;
  fej = beszur_eleje( fej, 1 );
  fej = beszur_vege( fej, 10 );
  fej = beszur_rendezve( fej, 5 );
  kiir_elore( fej );
  fej2 = fordit( fej );
  kiir_elore_rek( fej2 );
  kiir_hatra_rek( fej2 );
  felszabadit( fej );
  felszabadit( fej2 );
  return EXIT_SUCCESS;
}
