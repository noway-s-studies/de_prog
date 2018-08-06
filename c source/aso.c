#include <stdio.h>
#include <stdlib.h>
struct orszag
{
  char *nev;
  int terulet, nepesseg;
};

char **orszagok(struct orszag *tomb, int sor, int oszlop, double s) {  char **ret = (char **) calloc (sor*oszlop+1, sizeof(char *)) ;  int i,k=0;  for (i=0;i<sor*oszlop;i++) {
    double h = (double)tomb[i].nepesseg / tomb[i].terulet;
    if (h >= s-10 && h<=s+10) {
      int len=0,j;
      for (len=0;tomb[i].nev[len];len++);
      char *tmp = ret[k++] = (char *) calloc (len+1, sizeof(char));
      for (j=0;tomb[i].nev[j];j++) {
          tmp[j]=toupper(tomb[i].nev[j]);
      }
    }
 }
 return ret;
}
