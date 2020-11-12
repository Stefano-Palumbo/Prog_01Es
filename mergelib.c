#include "mergelib.h"
#include <stdio.h>
#include <string.h>
int riempi(double a[]){
    int n;
    printf("Inserisci N\n");
    scanf("%i", &n);
    for(int i = 0; i < n; i++){
        printf("Inserisci il numero alla posizione %i\n", i+1);
        scanf("%lf", &a[i]);
    }
    return n;
}

void stampa(double a[], int n){
    for(int i = 0; i < n; i++){printf("%lf\n", a[i]);}
}

void fusione(const double a[], int na, const double b[], int nb, double c[]){
    int ia = 0, ib = 0, ic = 0;
    while(ia < na && ib < nb){
        if(a[ia] > b [ib]){c[ic++] = b[ib++];}
        else {c[ic++] = a[ia++];}
    }
    while(ia < na){c[ic++] = a[ia++];}
    while(ib < nb){c[ic++] = b[ib++];}
}

int uguaglianza(double a[], double b[], int n){
    int i = 0;
    while(i < n){
        if(a[i] != b[i]){return 0;}
        i++;
    }
    return 1;
}

void riempi2d(double a[][100], int rig, int col){
    for(int i = 0; i < rig; i++){
        for(int j = 0; j < col; j++){
            printf("Inserisci il numero alla colonna %i, riga %i", j+1, i+1);
            scanf("%lf", &a[i][j]);
        }
    }
}


int bestmatch(char stringa[], char key[], int *index){
    int score, maxscore = 0;
    unsigned long long strilen = strlen(stringa);
    unsigned long long keylen = strlen(key);
    for(int i = 0; i < strilen - keylen; i++){
        score = 0;
        for(int j = 0; j < keylen; j++){
            if(stringa[i + j] == key[j]){score++;}
        }
        if(maxscore < score){
            maxscore = score;
            *index = i;
        }
    }
    return maxscore;
}

int strmatch(char stringa[], char key[], int indexarr[]){
    int index = 0, j, k = 0;
    unsigned long long stringalen = strlen(stringa);
    unsigned long long keylen = strlen(key);
    for(int i = 0; i < stringalen - keylen; i++){
        if(strncmp(&stringa[i], key, keylen) == 0){indexarr[k++] = i;}
    }
    return k;
}


