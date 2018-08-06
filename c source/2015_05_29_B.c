#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int i, j, db=0, db2=0;
    for(i=1;i<argc;i++){
        db=0;
        for(j=1;j<argc;j++){
            if(strcmp(argv[i],argv[j])==0)
                db++;
        }
        if(db%2==1)
            db2++;
    }
    if(db2>0)
        puts("NO");
    else
        puts("YES");
    return 0;
}
