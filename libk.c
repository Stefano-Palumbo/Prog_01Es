#include "libk.h"
#include <stdio.h>

void leggi_da_tastiera_a2D (double A[][100], int m, int n)
{
    int i, j;

    printf ("\n Inserisci gli elementi della matrice: \n");

    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
        {
            printf ("\nInserisci l'elemento A[%d][%d]-->", i, j);
            scanf ("%lf", &A[i][j]);
        }
}



void media_righe_a2D (double A[][100], int m, int n, double media_riga[])
{
    int i, j;
    double somma = 0.0;
    for (i=0;i<m;i++)
    {
        somma = 0.0;
        for (j=0;j<n;j++)
            somma += A[i][j];
        media_riga[i] = somma/n;
    }
}


void visualizza_aD (double *v, int n)
{
    int i;
    for (i=0;i<n;i++) {
        printf ("\n Il numero %d-esimo: ", i);
        scanf ("%lf", (v+i));
    }
}
