#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    double min=0, ertekv;
    char sor[110], *gyarto, *tipus, *ertek;
    min=atof(argv[2]);
    while (fgets(sor,110,f)){
        gyarto=strtok(sor, ";");
        tipus=strtok(NULL, ";");
        ertek=strtok(NULL, "\n");
        ertekv=atof(ertek);
        if(ertekv>=min){
           printf("%s %s\n",gyarto,tipus);
        }
    }

fclose(f);
return 0;
}
