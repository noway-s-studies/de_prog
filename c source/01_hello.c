#include <stdio.h>

int main()
{
	printf("Hello!\n");
    Feladt_Oszto();


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
        if((a%b)==0){
            printf("'%d' osztoja '%d'-nak/nek\n", b, a);
        }
        else {
            printf("'%d' nem osztoja '%d'-nak/nek\n", b, a);
        }

}




