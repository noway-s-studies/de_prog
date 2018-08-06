#include <stdio.h>
#include <stdlib.h>

struct listaelem
{
    int adat;
    struct listaelem *kov;
};

typedef struct listaelem LISTAELEM;

LISTAELEM *fej = NULL;

/* ************************************* */

void elejere_beszur(int szam)
{
    LISTAELEM *uj = (LISTAELEM *)malloc(sizeof(LISTAELEM));

    uj->adat = szam;
    uj->kov = fej;
    fej = uj;
}

void vegere_beszur(int szam)
{
    LISTAELEM *akt = fej;
    LISTAELEM *uj = (LISTAELEM *)malloc(sizeof(LISTAELEM));
    uj->adat = szam;
    uj->kov = NULL;

    if (fej == NULL) {
        fej = uj;
    }
    else
    {
        while (akt->kov != NULL) {
            akt = akt->kov;
        }
        akt->kov = uj;
    }
}

void bejar(LISTAELEM *fej)
{
    LISTAELEM *akt = fej;

    while (akt != NULL)
    {
        printf("%d, ", akt->adat);
        akt = akt->kov;
    }
    printf("\n");
}

int lista_merete(LISTAELEM *fej)
{
    LISTAELEM *akt = fej;
    int cnt = 0;

    while (akt != NULL) {
        ++cnt;
        akt = akt->kov;
    }

    return cnt;
}

void rendezetten_beszur(int szam)
{
    LISTAELEM *elozo = NULL;
    LISTAELEM *akt = fej;

    LISTAELEM *uj = (LISTAELEM *)malloc(sizeof(LISTAELEM));
    uj->adat = szam;
    uj->kov = NULL;
    
    if (fej == NULL) {
        fej = uj;
    }
    else
    {
        while (!((akt == NULL) || (akt->adat > szam))) {
            elozo = akt;
            akt = akt->kov;
        }
        if (elozo != NULL)
        {
            elozo->kov = uj;
        }
        else {
            fej = uj;
        }
        uj->kov = akt;
    }
}

void utolso_torles()
{
    LISTAELEM *elozo = NULL;
    LISTAELEM *akt = fej;

    if (fej == NULL) {
        return;     /* a lanc ures */
    }
    /* else */
    while (akt->kov != NULL) {
        elozo = akt;
        akt = akt->kov;
    }

    if (elozo == NULL)  /* egyelemu */
    {
        free(akt);
        fej = NULL;
    }
    else {
        free(akt);
        elozo->kov = NULL;
    }
}

int benne_van(LISTAELEM *fej, int keresett)
{
    LISTAELEM *akt = fej;

    // while (!( (akt == NULL) || (akt->adat == keresett) ))
    while ( (akt != NULL) && (akt->adat != keresett) )
    {
        akt = akt->kov;
    }
    if (akt != NULL) return 1;
    else return 0;
}

void felszabadit(LISTAELEM *akt)
{
    LISTAELEM *seged;

    while (akt != NULL)
    {
        seged = akt;
        akt = akt->kov;
        free(seged);
    }

    fej = NULL;
}

int main()
{
    int tomb[] = {1,8,5,9,2,3,4,9};
    int meret = sizeof(tomb) / sizeof(int);
    int i;

    for (i = 0; i < meret; ++i)
    {
        /*printf("%d ", tomb[i]);*/
        /* elejere_beszur(tomb[i]); */
        vegere_beszur(tomb[i]);
        /* rendezetten_beszur(tomb[i]); */
    }
    /* printf("\n"); */

    utolso_torles();

    bejar(fej);

    printf("a lista merete: %d\n", lista_merete(fej));

    int keresett = 13;
    printf("%d benne van? %d\n", keresett, benne_van(fej, keresett));

    printf("a lista merete: %d\n", lista_merete(fej));
    felszabadit(fej);
    printf("a lista merete: %d\n", lista_merete(fej));

    return 0;
}

