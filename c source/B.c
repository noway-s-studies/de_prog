#include <stdio.h>
#include <string.h>
main(){
    int db, i=0, n;
    char buffer[200]={0};
    scanf("%d",&db);
    while(i<db){
        scanf("%d", &n);
        n = ((((n*567/9)+7492)*235/47)-498);
        sprintf(buffer,"%d",n);
        n = buffer[strlen(buffer)-2]-('0');
        printf("%d\n",n);
        i++;
    }
    return 0;
}
