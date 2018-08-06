#include <stdio.h>
#include <stdio.h>
#include <string.h>

int minutes (char * sor){
    int eredmeny = 0;
    int napok = 0;
    char *nap = strtok(sor, " ");
    char *ido = strtok(NULL, " ");
    int ora = atoi(strtok(ido, "."));
    int perc = atoi(strtok(NULL, "."));
    
    if(!strcmp(nap, "K")){
        napok = 1;
    }else if(!strcmp(nap, "Sze")){
        napok = 2;
    }else if(!strcmp(nap, "Cs")){
        napok = 3;
    }else if(!strcmp(nap, "P")){
        napok = 4;
    }else if(!strcmp(nap, "Szo")){
        napok = 5;
    }else if(!strcmp(nap, "V")){
        napok = 6;
    }
    
    eredmeny = napok * 24 * 60 + ora * 60 + perc;
    
    return eredmeny;
}