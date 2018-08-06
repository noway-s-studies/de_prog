#include <stdio.h>
int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    int max=0, masodperc=0;
    char sor[150], akteloado[100], maxeloado[100], *sorszam, *eloado, *zeneszam_cime, *idotartam;
    while (fgets(sor, 150, f)){
        sorszam=strtok(sor, ";");
        eloado=strtok(NULL, ";");
        strcpy(akteloado,eloado);
        zeneszam_cime=strtok(NULL, ";");
        idotartam=strtok(NULL, ":");
        masodperc=atoi(idotartam)*60;
        idotartam=strtok(NULL, "\n");
        masodperc+=atoi(idotartam);
        if(masodperc>max){
            max=masodperc;
            strcpy(maxeloado, akteloado);
        }
    }
    fclose(f);
    return 0;
}
