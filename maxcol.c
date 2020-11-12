#include <stdio.h>
#include <stdlib.h>
#include "maxcolfunc.h"
#include <string.h>

int main(){
    //int c[100][100] = {{9, 2, 8},{2, 7, 4}};
    char c[] = "queste sono parole di tre dimensioni compreso questa tre tre tre tre";
    char k[] = "dimensionatore";
    int indicatore;
    //double c[100][100];
    //riempi2d(c, 2, 5);
    //printf("%f", maxcolfunc(c, 2, 5));
    //printf("%i", maxcolfuncint(c, 2, 3));
    int punteggio = bestmatch(c, k, &indicatore);
    printf("%i %i",punteggio ,indicatore);
}

