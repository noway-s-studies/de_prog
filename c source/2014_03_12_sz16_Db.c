#include <stdio.h>
int main()
{
    char szo[16];
    while(gets(szo)!=NULL){
        int i;
        char fordito[16] = {};
        if(strcmp("THE END",szo)==0)
            return 0;
        int hosz = strlen(szo);
        for(i=0;i<hosz;i++){
            fordito[i]=szo[hosz-i-1];
        }
        puts(fordito);
    }
	return 0;
}
