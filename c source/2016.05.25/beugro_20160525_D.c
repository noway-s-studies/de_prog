#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    int now, hmin, hmax;
    char sor[1000], *telep;
    while (fgets(sor,1000,f)!=NULL){
        telep=strtok(sor, " ");
        hmin = hmax = atoi(strtok(NULL, ","));
        char *num;
        while ((num = strtok(NULL, ",")) != 0){
            now = atoi(num);
            if(now<hmin)
                hmin = now;
            if(now>hmax)
                hmax = now;
        }
        printf("%s %d\n",telep,hmax-hmin);
    }
    fclose(f);
    return 0;
}
