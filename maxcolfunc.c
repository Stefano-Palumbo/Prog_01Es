#include "maxcolfunc.h"
#include <stdio.h>
#include <string.h>
double maxcolfunc(double a[][100], int rig, int col){
    double somma, max = 0;
    for(int i = 0; i < col; i++){
        somma = 0;
        for(int j = 0; j < rig; j++){
            somma = somma + a[j][i];
            printf("%f %i %i\n", a[j][i], j, i);
        }
        if(max < somma){max = somma;}
    }
    return max;
}

void riempi2d(double a[][100], int rig, int col){
    for(int i = 0; i < rig; i++){
        for(int j = 0; j < col; j++){
            printf("Inserisci il numero alla riga %i alla colonna %i\n", i, j);
            scanf("%lf", &a[i][j]);
            printf("%f\n", a[i][j]);
        }
    }
}

int maxcolfuncint(int a[][100], int rig, int col){
    int max = 0, somma;
    for(int i = 0; i < rig; i++){
        somma = 0;
        for(int j = 0; j < col; j++){
            somma += a[i][j];
        }
        if(somma > max){max = somma;}
    }
    return max;
}

int treparole(const char *c){
    int i = 0, counter = 0, parole = 0;
    while(c[i] != *"\0"){
        if(c[i] == *" "){
            if(counter == 3){
                parole++;
            }
            counter = 0;
            i++;
            continue;
        }
        i++;
        counter++;
        //printf("%c", c[i]);
    }
    if(counter == 3){parole += 1;}
    return parole;
}

int bestmatch(char stringa[], char key[], int *pointer){
    unsigned long lenstr = strlen(stringa);
    unsigned long keylen = strlen(key);
    int score, maxscore = 0;
    for(int i = 0; i < lenstr - keylen; i++){
        score = 0;
        for(int j = 0; j < keylen; j++){
            if(stringa[j + i] == key[j]){score++;}
            //printf("%i", score);
        }
        if(maxscore < score){
            maxscore = score;
            printf("%i\n", i);
            *pointer = i;
        }
    }
    return maxscore;
}
