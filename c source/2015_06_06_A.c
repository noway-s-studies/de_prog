#include <stdio.h>
#include <stdlib.h>
void fordit(char *, char *[], int);
int main()
{
  char *t[] = {"alma", "1 alma", "*alma*"};
  FILE *f;
  int c;
  fordit("kimenet.txt", t, 3);
  f = fopen("kimenet.txt", "r");
  while ((c = fgetc(f)) != EOF)
    putchar(c);
  fclose(f);
  return EXIT_SUCCESS;
}




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fordit(char *fajlnev, char *tomb[], int n)
{
    FILE *f = fopen(fajlnev, "w");
    int i;
    for (i=0; i<n; ++i)
        if(!isalpha(tomb[i][0]))
        {
            int j;
            for (j=strlen(tomb[i])-1; j>=0; --j)
                fputc(tomb[i][j],f);
            fputc('\n',f);
        }
        fclose(f);
}
