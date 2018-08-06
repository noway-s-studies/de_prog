#include <stdio.h>
int main()
{
	printf("Hello!\n");
    mit_csinal__tomb4();

	return 0;
}
void csere1(){
    printf("\ncsere1\n");
    int a, b, tmp;
    printf("Adj meg 2 számot amit megcserélünk: \na=");   scanf("%d", &a);
    printf("b=");   scanf("%d", &b);
        tmp=a;
        a=b;
        b=tmp;
    printf("A megcserélt számok: a='%d' b='%d'\n", a, b);
}
void csere2(){
    printf("\ncsere2\n");
    int a, b, tmp;
    printf("Adj meg 2 számot amit megcserélünk: \na=");   scanf("%d", &a);
    printf("b=");   scanf("%d", &b);
        a=a-b; // a-=b;
        b=a+b; // b+=a;
        a=b-a;
    printf("A megcserélt számok: a='%d' b='%d'\n", a, b);
}
void csere3(){
    printf("\ncsere3\n");
    int a, b, tmp;
    printf("Adj meg 2 számot amit megcserélünk: \na=");   scanf("%d", &a);
    printf("b=");   scanf("%d", &b);
        a^=b;
        b^=a;
        a^=b;
    printf("A megcserélt számok: a='%d' b='%d'\n", a, b);
}
void Feladt_HetNapja(){
    printf("\nFeladt_HetNapja\n");
    int d;
    printf("Adj meg egy szamot 1-7-ig: \nd=");   scanf("%d", &d);

    printf("A het %d. napja: ", d);
    if (d==1){
        printf("Hetfo");
    }
    else if (d==2){
        printf("Kedd");
    }
    else if (d==3){
        printf("Szerda");
    }
    else if (d==4){
        printf("Csutortok");
    }
    else if (d==5){
        printf("Pentek");
    }
    else if (d==6){
        printf("Szombat");
    }
    else if (d==7){
        printf("Vasarnap");
    }
    else{
        printf("Ez nem egy 1-7-ig szam!");
    }
    printf("\n");
}
void Feladt_Oszto(){
    printf("\nFeladt_Oszto\n");
    int a, b;
    printf("Adj meg 2 számo: \na=");   scanf("%d", &a);
    printf("b=");   scanf("%d", &b);
        if(a==0){
            printf("0-nak minden szam osztoja\n");
        }
        else if(b==0){
            printf("0-val valo osztast nem ertelmezunk\n");
        }
        else if((a%b)==0){
            printf("'%d' osztoja '%d'-nak/nek\n", b, a);
        }
        else {
            printf("'%d' nem osztoja '%d'-nak/nek\n", b, a);
        }

}
void Feladt_HetNapja_SWITCH(){
    printf("\nFeladt_HetNapja SWITCH\n");
    int d;
    printf("Adj meg egy szamot 1-7-ig: \nd=");   scanf("%d", &d);

    printf("A het %d. napja: ", d);
    switch (d){
        case 1: printf("Hetfo"); break;
        case 2: printf("Kedd"); break;
        case 3: printf("Szerda"); break;
        case 4: printf("Csutortok"); break;
        case 5: printf("Pentek"); break;
        case 6: printf("Szombat"); break;
        case 7: printf("Vasarnap"); break;
        default: printf("Ez nem egy 1-7-ig szam!");
    }
    printf("\n");
}
void Feladt_Muvelet_SWITCH(){
    printf("\nFeladt_Muvelet SWITCH\n");
    int a, b, c;
    char m;
    scanf("%d%c%d", &a, &m, &b);
    switch (m){
        case '+': c=a+b; break;
        case '-': c=a-b; break;
        case '*': c=a*b; break;
        case '/': if (b==0) printf("Nullaval valo osztast nem ertelmezunk!\n"); else c=a/b; break;
        default: printf("Hibas muveleti jel!\n");
    }
    printf("A muvelet eredmenye: %d", c);
}
void Feladt_HonapNapja_SWITCH(){
    printf("\nFeladt_HonapNapja SWITCH\n");
    int y, m, d;
    printf("Adj meg egy evet es egy honapot: ");   scanf("%d %d", &y, &m);
    printf("%d ev %d. honapja ", y, m);
    switch (m){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            d = 31; break;
        case 4:
        case 6:
        case 9:
        case 11:
            d = 30; break;
        case 2:
            if(((y%4==0)&&!(y%100==0)) || (y%400==0))
                d = 29;
            else
                d = 28;
            break;
        default: d = 0;
    }
    printf("%d napos\n", d);
}
void for_hello(){
    int i;
    for(i=0;i<5;i+=2)
        printf("Hello!\n");
}
void while_hello(){
    int i;
    scanf("%d",&i);
    while(i<5){
        printf("Hello!\n");
        i+=1;
    }
}
void ket_szam_legnagyobb_kozos_osztoja__kivonasos(){
    int a, b;
    scanf("%d %d",&a, &b);
    while(a!=b){
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    printf("%d\n", b);
}
void ket_szam_legnagyobb_kozos_osztoja__maradekosztos1(){
    int a, b, r;
    scanf("%d %d",&a, &b);
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    printf("%d\n", b);
}
void ket_szam_legnagyobb_kozos_osztoja__maradekosztos2(){
    int a, b, r;
    scanf("%d %d",&a, &b);
    while((r=a%b)!=0){
        a=b;
        b=r;
    }
    printf("%d\n", b);
}
void ket_szam_legnagyobb_kozos_osztoja__maradekosztos3(){
    int a, b, r;
    scanf("%d %d",&a, &b);
    while(r=a%b){
        a=b;
        b=r;
    }
    printf("%d\n", b);
}
void ket_szam_legnagyobb_kozos_osztoja__maradekosztos4(){
    int a, b, r;
    for(scanf("%d %d",&a,&b);r=a%b;a=b,b=r);
    printf("%d\n", b);
}
void relativ_primek(){
    int a, b, r;
    for(scanf("%d %d",&a,&b);r=a%b;a=b,b=r);
    if(b==1) printf("IGEN\n");
    else printf("NEM\n");
}
void mit_csinal__1(){
    int a;
    for(scanf("%d",&a);a;scanf("%d",&a));
}
void mit_csinal__2(){
    int a;
    scanf("%d",&a);
    while(a){
        scanf("%d",&a);
    }
}
void paros_szamig_olvas1(){
    int a;
    scanf("%d",&a);
    while(1){
        if(a%2==0)break;
        scanf("%d",&a);
    }
}
void paros_szamig_olvas2(){
    int a;
    scanf("%d",&a);
    while(a%2!=0){
        scanf("%d",&a);
    }
}
void EOFig_olvas(){
    int a;
    while(scanf("%d",&a)!=EOF);
}
void Feladt_MAXandMINnot0(){
    int a,min,max;
    scanf("%d",&a);
    for(min=a,max=a;a!=0;scanf("%d",&a)){
        if(a<min) min=a;
        if(a>max) max=a;
    }
    printf("min=%d max=%d",min,max);
}
void Feladt_kihagy3negyzet(){
    int a;
    for(scanf("%d",&a);a!=0;scanf("%d",&a)){
        if(a%3!=0) printf("%d\n", a*a);
    }
}
void Feladt_kihagy3negyzet2(){
    int a;
    while(1){
        scanf("%d",&a);
        if(a==0) break;
        if(a%3==0) continue;
        printf("%d\n", a*a);
    }
}
void Progcont_Milyen_nap(){
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
}
void Progcont_Angolszasz_idopontok(){
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
}
void Progcont_Oszthatosagvizsgalat(){
    int x, y, i, j;
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
}
void Progcont_Median(){
    int x, y, z;
    while(1){
        scanf("%d %d %d",&x,&y,&z);
        if(x==0&&y==0&&z==0)break;
        else if(x>=y&&x>=z) printf("%d\n",y>z?y:z);
        else if(y>=x&&y>=z) printf("%d\n",x>z?x:z);
        else if(z>=x&&z>=y) printf("%d\n",x>y?x:y);
    }
}
void mit_csinal__3(){
    int c;
    while((c=getchar())!=EOF)
        putchar(c);
}
void mit_csinal__4(){
    int c;
    scanf("%d",&c);
    do{
        printf("Hello!\n");
        c+=1;
    }while(c<5);
}
void mit_csinal__5(){
    int a=5;
    int *p;
    p=&a;
    *p=a+*p-2;
    printf("%d\n",a);
}
void mit_csinal__tomb(){
    int a[3], i;
    for(i=0;i<3;i++)
        scanf("%d",&a[i]);
    for(i=0;i<3;i++);
        printf("%d ",a[i]);
}
void mit_csinal__tomb2(){
    int a[8], i;
    for(i=0;i<8;i++);
        printf("%d ",a[i]);
}
void mit_csinal__tomb3(){
    int a[8]={0}, i;
    for(i=0;i<8;i++);
        printf("%d ",a[i]);
}
void mit_csinal__tomb4(){
    int a[8]={33,24,12,7,4,13,18,52}, b[8]={2,234,142,5,4,13,18,212}, c[8]={0}, i;
    for(i=0;i<8;i++)
        c[i] = a[i] + b[i];
    for(i=0;i<8;i++)
        printf("%d ", c[i]);
}

//84. oldal















