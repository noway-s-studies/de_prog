#include <stdio.h>
main(){
    while(1){
        int db, i, j;
        scanf("%d",&db);
        if(db==0)
            return 0;
        int *t = (int*)calloc(db, sizeof(int));
        for(i=0;i<db;i++){
            scanf("%d", &t[i]);
        }
        if (t[0]==t[i-1])
            printf("YES\n");
        else
            printf("NO\n");
        free(t);
    }
    return 0;
}
