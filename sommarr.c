#include "library.h"
#include <stdio.h>
int main(){
    double v[100], somma;
    int n;
    printf("Inserisci la grandezza dell'array\n");
    scanf("%i", &n);
    inserisci(v, n);
    somma = arraysumavg(v, n, 1);
    printf("La somma dell'array è uguale a  %lf\n", somma);
    printf("La media è uguale a %lf\n", arraysumavg(v, n, 0));
    printf("Il minimo è %lf\n", checkminmax(v, n, 0));
    printf("Il massimo è %lf\n", checkminmax(v, n, 1));
}

