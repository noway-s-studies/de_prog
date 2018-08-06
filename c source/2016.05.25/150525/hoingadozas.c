#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int main(int argc, char** argv) {
    FILE *f = fopen(argv[1], "r");
    char sor[1010];
    while(fgets(sor, 1010, f) != NULL){
        char *varos = strtok(sor, " ");
        int min = 0;
        int max = 0;
        int i = 0;
        char *szam;
        while((szam = strtok(NULL, ",")) != 0){
            int tmp = atoi(szam);
            if(i == 0 || tmp < min){
                min = tmp;
            }
            if(i == 0 || tmp > max){
                max = tmp;
            }
            i++;
        }
        printf("%s %d\n", varos, (max - min));
    }
    fclose(f);
    return (EXIT_SUCCESS);
}
*/

