#include <stdio.h>
int main()
{
	printf("Hello!\n");
    mit_csinal__tomb4();

	return 0;
}
void Olvas10(){
    int tomb[10], tomb_fajlbol[10], i;
    FILE *f= NULL, *g= NULL;
    for (i = 0; i < 10; i++) {
        printf("Az %d. elem: ", i+1);
        scanf("%d", &tomb[i]);
    }
    f = fopen("adatok.dat", "wb");
    if (f == NULL) {
        printf("Nem sikerult!\n");
        return 1;
    }
}
