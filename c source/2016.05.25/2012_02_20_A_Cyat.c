#include <stdio.h>
main(){
    int db, i=0;
    long int a, b;
    scanf("%d",&db);
    while(i<db){
        scanf("%li %li", &a, &b);
        printf("%li\n",a+b);
        i++;
    }
    return 0;
}
