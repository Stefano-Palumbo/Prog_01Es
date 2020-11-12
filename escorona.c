#include <stdio.h>
#include "library.h"
int main(){
    float raggiomax, raggiomin;
    printf("Inserisci il raggio maggiore\n");
    scanf("%f", &raggiomax);
    printf("Inserisci il raggio minore\n");
    scanf("%f", &raggiomin);
    printf("Area Corona: %f\n", areacorona(raggiomax, raggiomin));
}
