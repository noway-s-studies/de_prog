#include <stdio.h>
int main()
{
    int x, y, z;
    while(1){
        scanf("%d %d %d",&x,&y,&z);
        if(x==0&&y==0&&z==0)break;
        else if(x>=y&&x>=z) printf("%d\n",y>z?y:z);
        else if(y>=x&&y>=z) printf("%d\n",x>z?x:z);
        else if(z>=x&&z>=y) printf("%d\n",x>y?x:y);
    }
	return 0;
}
