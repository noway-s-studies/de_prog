#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    float ertek = 0, max = 0;
    char sor[200], *token;
    while (fgets(sor,200,f)){
        token = strtok(sor, ";");
        max = atof(token);
        while(token = strtok(NULL, ";")){
            ertek = atof(token);
            if(ertek > max)
                max = ertek;
        }
        printf("%.2f\n",max);
    }

return 0;
}
