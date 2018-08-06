#include <stdio.h>
#include <stdlib.h>



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct orszag
{
  char *nev;
  int terulet, nepesseg;
};


char *konv(struct orszag o){
    char *s = malloc((strlen(o.nev)+50)*sizeof(char));
    sprintf(s, "%s (%d,%d)", o.nev, o.terulet, o.nepesseg);
    return s;
}




int main()
{
  struct orszag magyarorszag = {"Magyarorszag", 93030, 9893899};
  char *s = konv(magyarorszag);
  puts(s);
  free(s);
  return EXIT_SUCCESS;
}









