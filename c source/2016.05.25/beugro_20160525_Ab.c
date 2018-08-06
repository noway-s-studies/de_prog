#include <stdio.h>
int main() {
    int db;
    do{
        scanf("%d", &db);
        if(db){
            int i = 0, f1 = 0, fn;
            for(i = 1; i <= db; i++){
                scanf(" %d", &fn);
                if(i == 1)
                    f1 = fn;
                if(i == db)
                    puts(f1==fn ? "YES" : "NO");
            }
        }
    }while(db);
    return (0);
}
