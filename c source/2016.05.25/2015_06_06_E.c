#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int hasonlit(const void *p1, const void *p2)
{
    const char *s1 =(const char *)p1;
    const char *s2 =(const char *)p2;
    int kul = strlen(s2)-strlen(s1);
    return kul != 0 ? kul : strcmp(s1,s2);
}
int main()
{
    char sorok[100][101];
    int db = 0, i;
    double atlag = 0;
    while(gets(sorok[db])!=NULL)
        atlag+=strlen(sorok[db++]);
    atlag/=db;
    qsort(sorok, db, 101*sizeof(char),hasonlit);

    for (i=0;i<db && strlen(sorok[i])>atlag;++i)
        puts(sorok[i]);
    return 0;
}
