#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int sor, i, j, db, legkissebb, legnagyobb;
    scanf("%d",&sor);
    i=0;
    while (i!=sor){
        scanf("%d",&db);
        int szam[db];
        for(j=0;j<db;j++){
            scanf("%d", &szam[j]);
        }
        j=0;
        legnagyobb=0;
        legkissebb=szam[0];
        for(j=0;j<db;j++){
            if (szam[j]>legnagyobb)
                legnagyobb=szam[j];
            if (szam[j]<legkissebb)
                legkissebb=szam[j];
        }
        printf("%d %d\n", legkissebb, legnagyobb);
        i++;
    }
    return 0;
}
