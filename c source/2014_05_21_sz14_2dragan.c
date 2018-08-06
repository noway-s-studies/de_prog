#include <stdio.h>
int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    char sor[101], *etelnev, *osszetevok,*archar;
    int ar=0;
    while(fgets(sor,101,f)){
        etelnev=strtok(sor,";");
        osszetevok=strtok(NULL, ";");
        archar=strtok(NULL, ";");
        ar=atoi(archar);
        if(ar>1000)
            puts(etelnev);
        }
    fclose(f);
    return 0;
}
