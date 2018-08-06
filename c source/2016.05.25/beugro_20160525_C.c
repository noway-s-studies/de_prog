#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hallgato{
  char vnev[31], knev[31], neptun[7], szak[11];
  float atlag;
};
main (){
    char szakv[11]={0}, lista[100];
    int sor = 0;
    gets(szakv);
    struct hallgato dbt[1000];
    while (fgets(lista, 100, stdin) != NULL){
        strcpy(dbt[sor].vnev, strtok(lista, " "));
        strcpy(dbt[sor].knev, strtok(NULL, " "));
        strcpy(dbt[sor].neptun, strtok(NULL, " "));
        strcpy(dbt[sor].szak, strtok(NULL, " "));
        dbt[sor].atlag = atof(strtok(NULL, "\n"));
        sor++;

    };
    printf("%s\n",dbt[0].vnev);
    return 0;
}
