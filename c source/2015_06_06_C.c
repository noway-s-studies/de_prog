#include <stdio.h>
#include <stdlib.h>
double *gordulo(double *, int, int);
int main()
{
  double t[3][4] = {{1.0,  2.0,  3.0,  4.0},
                    {5.0,  6.0,  7.0,  8.0},
                    {9.0, 10.0, 11.0, 12.0}};
  double *p = gordulo((double *)t, 3, 4);
  int i;
  for (i = 0; i < 3; ++i)
    printf("%.3f\n", p[i]);
  putchar('\n');
  free(p);
  return EXIT_SUCCESS;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double *gordulo(double t[], int n, int m){
    double *tomb = malloc(n * sizeof(double));
    int i;
    double sum=0;
    for(i=0; i<n; ++i){
        int j;
        double osszeg = 0;
        for(j=0; j<m; ++j)
            osszeg+=t[i*m+j];
        tomb[i]= sum += osszeg;
        }
    return tomb;
}
