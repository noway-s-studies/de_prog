#include <stdio.h>
int main()
{
    int x, y, j;
    for(scanf("%d %d",&x,&y);x<=y;scanf("%d %d",&x,&y)){
        j=0;
        for(;x<=y;x++)
            if(x%3==0&&x%9!=0){
                if(j>0) putchar(' ');
                printf("%d",x);
                j++;
            }
        if(j==0) puts("-1");
        else putchar('\n');
    }
	return 0;
}
