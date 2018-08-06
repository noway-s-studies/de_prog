#include <stdio.h>
#include <stdlib.h>

int main()
{
    char line[1000];
    gets( line );

    char nap;
    int hnap, ossz=0;
    nap = strtok(line, " ");
    if(strcmp(nap,"H"))
            hnap = 0;
    if(strcmp(nap,"K"))
            hnap = 1440;
    if(strcmp(nap,"Sze"))
            hnap = 2880;
    if(strcmp(nap,"V"))
            hnap = 10000000;
    ossz = hnap;

    printf( "%C\n", nap );
    return ossz;
}
