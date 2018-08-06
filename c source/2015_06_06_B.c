#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int i,j;
    for (i=1;i<argc;++i){
        int hossz;
        hossz = strlen(argv[i]);
        char elsokar = argv[i][0];
        for(j=0;j<hossz;++j){
            if(argv[i][j] != elsokar){
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}
