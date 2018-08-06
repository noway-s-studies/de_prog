#include <stdio.h>
#include <stdlib.h>

#define N 4
#define M 5

double *average( double tomb[], int n, int m){
    double *eredmeny = NULL;
    int i, j;
    
    eredmeny = realloc(eredmeny, m * sizeof(double));
    
    for(i = 0; i < m; i++){
        double osszeg = 0;
        for(j = 0; j < n; j++){
            int key = j * m + i;
            osszeg += tomb[key];
        }
        
        eredmeny[i] = osszeg / n;
    }
    
    return eredmeny;
}