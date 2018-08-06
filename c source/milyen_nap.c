#include <stdio.h>
int main()
{
int nap, m, d, i;
    for(scanf("%d.%d.",&m,&d);!(m==0||d==0);scanf("%d.%d.",&m,&d)){
        nap=0;
        switch(m){
            case 12: nap+=30;
            case 11: nap+=31;
            case 10: nap+=30;
            case 9: nap+=31;
            case 8: nap+=31;
            case 7: nap+=30;
            case 6: nap+=31;
            case 5: nap+=30;
            case 4: nap+=31;
            case 3: nap+=28;
            case 2: nap+=31;
        }
        nap+=d;
        if(nap%7==1) puts("Monday");
        else if(nap%7==2) puts("Tuesday");
        else if(nap%7==3) puts("Wednesday");
        else if(nap%7==4) puts("Thursday");
        else if(nap%7==5) puts("Friday");
        else if(nap%7==6) puts("Saturday");
        else puts("Sunday");
    }
	return 0;
}
