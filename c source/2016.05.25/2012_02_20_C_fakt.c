#include <stdio.h>
main(){
    int db, i=0, n;
    scanf("%d",&db);
    while(i<db){
        scanf("%d", &n);
        int k=0;
        int j=1;
        while(n>0){
            j*=n;
            while(j%10==0){
                j/=10;
                k++;
            }
            j%=100000;
            n--;
        }
        printf("%d\n", k);
    }
    return 0;
}
