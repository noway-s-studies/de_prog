#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct orszag
{
  char *nev;
  int terulet, nepesseg;
};
void nagy_orszagok(struct orszag t[], int n, char *p){
    int i;
    double atlag = 0;
    FILE *f = fopen(p, "w");
    for(i=0; i<n; i++){
        atlag += t[i].terulet;
    }
    atlag /= n;
    for (i=0;i<n;i++){
        if(t[i].terulet>atlag)
            fprintf(f,"%s %d\n",t[i].nev, t[i].nepesseg);
    }
    fclose(f);
    return 0;
}




int main()
{
  struct orszag t[] = {{"Magyarorszag",                93030,   9893899},
                       {"Amerikai Egyesult Allamok", 9826630, 318697314},
                       {"Nemetorszag",                357023,  80500000},
                       {"Kanada",                    9984670,  35702707},
                       {"Egyesult Kiralysag",         244820,  63705000}};
  FILE *f;
  int c;
  nagy_orszagok(t, 5, "kimenet.txt");
  f = fopen("kimenet.txt", "r");
  while ((c = fgetc(f)) != EOF)
    putchar(c);
  fclose(f);
  return EXIT_SUCCESS;
}
