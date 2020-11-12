#include "library.h"
#include <math.h>
#include <stdio.h>
float areacerchio(float raggio){
    const float pi = 3.141592f;
    return pi * raggio * raggio;
}

float areacorona(float raggiomax, float raggiomin){
    float areamax = areacerchio(raggiomax);
    float areamin = areacerchio(raggiomin);
    return areamax - areamin;
}

float valassoluto(float num){
    if(num > 0) {return num;}
    else {return -num;}
}

float distanza(float x, float y){
    return sqrtf(pow(x, 2) + pow(y, 2));
}

float relerr(float num1, float num2){
    float err = valassoluto(num1 - num2) / valassoluto(num1);
    return err;
}

void inserisci(double v[], int n){
    for(int i = 0; i < n; i++){
        printf("Inserisci il numero alla posizione %i\n", i);
        scanf("%lf", &v[i]);
    }
}

void stampa(double v[], int n){
    for(int i = 0; i < n; i++){printf("Il numero alla posizione %i è: %f\n", i, v[i]);}
}

double arraysumavg(double v[], int n, int choice){
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
    }
    if(choice == 0){return sum / n;}
    else{return sum;}
}

double checkminmax(double v[], int n, int choice){
    double min = v[0], max = v[0];
    for(int i = 1; i < n; i++){
        if(v[i] < min){min = v[i];}
        else if(v[i] > max){max = v[i];}
    }
    if(choice == 1){return max;}
    else{return min;}
}
