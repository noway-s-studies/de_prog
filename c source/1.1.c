#include <stdio.h>
main()
{
    int c;
    int gyak[ 256 ] = { 0 };
    while ( (c=getchar()) != '@' )
        ++gyak[c];
    for (c=0; c < 256; c++ )
        if (gyak[c] != 0 )
        printf( "%c: %d\n", c, gyak[c] );
}
