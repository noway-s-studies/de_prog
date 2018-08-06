#include <stdio.h>
#include <stdlib.h>
int main()
{
  char line[ 50 ];
  int is_c_identifier( char * );
  while ( gets( line ) != NULL )
    if ( is_c_identifier( line ) )
      puts( "YES" );
    else
      puts( "NO" );
  return EXIT_SUCCESS;
}

int is_c_identifier(char *sor){
    int hossz = strlen(sor), i = 0;
    if(sor[0] == '_' || sor[hossz - 1] == '_' || hossz == 0){
        return 0;
    }
    for(; i < hossz; i++){
        if(sor[i] == '_' && sor[i-1] == '_'){
            return 0;
        }
        if(!strchr("qwertzuiopasdfghjklyxcvbnm_", sor[i])){
            return 0;
        }
    }
    return 1;
}
