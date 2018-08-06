#include <stdio.h>
int main()
{
    int h, s;
    char ampm[3];
    while(scanf("%d.%d%s",&h,&s,&ampm)!=EOF){
        if(strcmp("am",ampm)==0){
            if(h==12)
                printf("%d.%02d\n",h-12,s);
            else
                printf("%d.%02d\n",h,s);
        }
        else{
            if(h==12)
                printf("%d.%02d\n",h,s);
            else
                printf("%d.%02d\n",h+12,s);
        }
    }
	return 0;
}
