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
