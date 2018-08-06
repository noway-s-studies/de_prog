#include <stdio.h>
#include <stdlib.h>

double *average( double t[], int n, int m){
    double *tomb = (double *)malloc(m * sizeof(double));
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            tomb[j] += t[(i*m)+j];
        }
    }
    for(j=0;j<m;j++){
        tomb[j] /= n;
    }
    return tomb;
};
