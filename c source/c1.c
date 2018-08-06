#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
main(){
    int a, b, c, poz;
    char str[160];
    do {
        printf("Kerek ket szamot%*d ", 13, 1);
        gets(str);
        if(str==2) continue;
        poz=Teszt(str);
        if(poz!=-1){
            printf("%s\n", str);
            printf("%*c\n", poz+1,'!');
            continue;
        }
        switch (sscanf(str,"%d,%d",&a,&b)){
        case 0:
            printf("Hias 1. adat!\n");
            break;
        case 1:
            printf("Hias 2. adat!\n");
            break;
        case 2:
            c=a+b;
            printf("A ket szam osszege: %d + %d = %d\n", a, b, c);
            break;
        }

    } while (getch()!=32);

}
 int Teszt(char *p){
    char minta[]="0123456789+-, ";
    int i,j,ok;
    for (i=0;p[i];i++){
        ok=0;
        for (j=0;minta[j];j++)
            if(p[i]==minta[j]) ok=1;
        if(ok==0) return i;
    }
    return -1;
 }
