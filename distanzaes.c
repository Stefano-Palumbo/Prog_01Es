#include <stdio.h>
#include "library.h"
int main(){
    float x, y;
    printf("Inserisci x e y\n");
    scanf("%f %f", &x, &y);
    printf("Distanza dall'origine: %i", (int) distanza(x, y));
}

