#include <stdio.h>
#include "library.h"
int main(){
    double v[100];
    int n;
    printf("Inserisci i numeri del vettore\n");
    scanf("%i", &n);
    inserisci(v, n);
    stampa(v, n);
}

