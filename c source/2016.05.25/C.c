#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int min(int a, int b) {
  return (a < b) ?  a : b;
}

struct szak {
  char veznev[31], kernev[31], neptun[7], szak[11];
  double atlag;
};

int rendez(const void *p1, const void *p2) {
   struct szak *s1 = (struct szak *) p1;
   struct szak *s2 = (struct szak *) p2;

   if (s1->atlag > s2->atlag) return -1;
   if (s1->atlag < s2->atlag) return 1;
   return strcmp(s1->neptun, s2->neptun); }

int main() {

  char sz[11];
  char tmp[100];
  struct szak tomb[1000];
  struct szak k;

  gets(sz);
  int i=0;
  while (gets(tmp) != EOF) {
     if (strlen(tmp) <= 0) break;
     char *p = strtok(tmp, " ");
     strcpy(k.veznev, p);
     p = strtok(NULL, " ");
     strcpy(k.kernev, p);
     p = strtok(NULL, " ");
     strcpy(k.neptun, p);
     p = strtok(NULL, " ");
     strcpy(k.szak, p);
     p = strtok(NULL, " ");
     k.atlag = atof(p);
     if (strcmp(k.szak, sz) == 0) {
        strcpy(tomb[i].veznev, k.veznev);
        strcpy(tomb[i].kernev, k.kernev);
        strcpy(tomb[i].neptun, k.neptun);
        strcpy(tomb[i].szak, k.szak);
        tomb[i].atlag = k.atlag;
        i++;
     }
  }
  qsort((void *)tomb, i, sizeof(struct szak), rendez);

  int j=0;
  for (j=0;j<min(i,3);j++) {
    printf("%s %s %s %.1f\n", tomb[j].veznev, tomb[j].kernev, tomb[j].neptun, tomb[j].atlag);
  }
  return 0;
}
