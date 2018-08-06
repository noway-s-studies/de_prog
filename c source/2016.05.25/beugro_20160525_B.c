#include <stdio.h>
#include <stdlib.h>
int minutes( char *x ){
    int napN, ossz=0;
    char *nap = strtok(x, " ");
    if(!strcmp(nap, "K"))
        napN = 1;
    else if(!strcmp(nap,"Sze"))
        napN = 2;
    else if(!strcmp(nap,"Cs"))
        napN = 3;
    else if(!strcmp(nap,"P"))
        napN = 4;
    else if(!strcmp(nap,"Szo"))
        napN = 5;
    else if(!strcmp(nap,"V"))
        napN = 6;
    else
        napN = 0;
    int ora = atoi(strtok(NULL, "."));
    int perc = atoi(strtok(NULL, "\n"));
    ossz = (napN * 24 * 60) + (ora * 60) + perc;
    return ossz;
}
