#include <stdio.h>
#define FALSE 0
#define TRUE !FALSE
main(){
    int t[3], idx =-1, megvolt=FALSE;
    for ( ; ; ){
        scanf( "%d", &t[idx=(idx+1)%3 ] );
        if ( !t[ idx ] )
            break;
        if ( idx == 2 )
            megvolt = TRUE;
        if ( megvolt && t[ idx ] == t[ ( idx + 1 ) % 3 ] + t[ ( idx + 2 ) % 3 ] )
            printf( "%d\n", t[ idx ] );
    }
}
