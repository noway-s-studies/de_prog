#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct orszag
{
  char nev[31];
  int terulet, nepesseg;
};

int hasonlit(const void *p1, const void *p2)
{
    double s1= (double)(*p1).nepesseg / (*p1).terulet;
    double s2= (double)(*p2).nepesseg / (*p2).terulet;
    if(s1<s2) return 1;
    if(s1>s2) return -1;
    return strcmp((*p1).nev, (*p2).nev);
}


int main(int argc, char *argv[])
{
    FILE *f = fopen("bemenet.txt", "r");
    struct orszag t[200];
    char sor[1002];
    int db=0, i;
    double kuszob = atof(argv[1]);
    while (fgets(sor,1002,f)!=NULL){
        char *p;
        int nepesseg= 0;
        strcpy(t[db].nev, strtok(sor,";"));
        t[db].terulet = atoi(strtok(NULL,";"));
        while((p= strtok(NULL,";"))!=NULL)
            nepesseg += atoi(p);
        t[db].nepesseg = nepesseg;
        if((double)t[db].nepesseg/t[db].terulet>kuszob)
        ++db;
    }
    fclose(f);
    qsort(t, db, sizeof(struct orszag), hasonlit);
    for(i=0; i<db; ++i)
        printf("%s,%d,%d\n", t[i].nev, t[i].terulet, t[i].nepesseg);
    return 0;
}
