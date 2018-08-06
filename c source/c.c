#include <stdio.h>
#include <string.h>
main(){
    int db, i=0, n;
    scanf("%d",&db);
    while(i<db){
        scanf("%d", &n);
        int k=0, p=1;
        char t[100];
        signed long long int j=1;
        while(p<=n){
            j*=p;
            p++;
        }
        printf("%lli\n", j);
        sprintf(t,"%lli",j);
        p=strlen(t);
        printf("%d\n", p);
        while(t[p-1]=='0'){
            k++;
            p--;
        }
        printf("%d\n", k);
    }
    return 0;
}
