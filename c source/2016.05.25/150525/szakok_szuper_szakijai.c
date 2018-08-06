#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct diakok {
    char vnev[32];
    char knev[32];
    char neptunkod[8];
    double atlag;
};

int cmp(const void *p1, const void *p2) {
    const struct diakok *s1 = (const struct diakok *) p1;
    const struct diakok *s2 = (const struct diakok *) p2;

    if (s1->atlag < s2->atlag) {
        return 1;
    } else if (s1->atlag > s2->atlag) {
        return -1;
    } else {
        return strcmp(s1->neptunkod, s2->neptunkod);
    }
}

int main(int argc, char** argv) {
    struct diakok *diakok = NULL;
    char sor[1002];
    int db = 0, i = 0, sorsz = 0;
    char keresett_szak[11];
    while (fgets(sor, 1002, stdin) != NULL) {
        if (sorsz > 0) {

            char *vnev = strtok(sor, " ");
            char *knev = strtok(NULL, " ");
            char *kod = strtok(NULL, " ");
            char *szak = strtok(NULL, " ");
            double atlag = atof(strtok(NULL, " "));

            strcat(szak, "\n");



            if (!strcmp(szak, keresett_szak)) {

                diakok = realloc(diakok, ++db * sizeof (struct diakok));
                diakok[db - 1].atlag = atlag;

                strcpy(diakok[db - 1].vnev, vnev);
                strcpy(diakok[db - 1].knev, knev);
                strcpy(diakok[db - 1].neptunkod, kod);
                
            }
        } else {

            char *p = strtok(sor, "\n");
            strcpy(keresett_szak, p);
        }
        sorsz++;
    }
    qsort(diakok, db, sizeof (struct diakok), cmp);
    for (i = 0; i < (db > 3 ? 3 : db); i++) {
        printf("%s %s %s %.1f\n", diakok[i].vnev, diakok[i].knev, diakok[i].neptunkod, diakok[i].atlag);
    }
    return (EXIT_SUCCESS);
}

