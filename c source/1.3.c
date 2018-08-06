#include <stdio.h>
void rendez_csok( int t[], int meret ){
    int i, j;
    for ( i = meret - 2; i >= 0; --i )
        for ( j = 0; j <= i; ++j )
            if ( t[ j ] < t[ j + 1 ] ){
                int seged = t[ j ];
                t[ j ] = t[ j + 1 ];
                t[ j + 1 ] = seged;
            }
}
main(){
    int *tomb = NULL, meret = 0;
    for ( ; ; ){
        tomb = ( int * )realloc( tomb, ( meret + 1 ) * sizeof( int ) );
        scanf( "%d", &tomb[ meret ] );
        if ( tomb[ meret ] == 0 )
        break;
        ++meret;
    }
    if ( meret < 3 )
        puts( "Nincs három érték." );
    else{
        rendez_csok( tomb, meret );
        printf( "%d, %d, %d\n", tomb[ 0 ], tomb[ 1 ], tomb[ 2 ] );
    }
    free( tomb );
}
