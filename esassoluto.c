#include <stdio.h>
#include "library.h"
int main(){
    float n1, n2;
    printf("Inserisci un numero\n");
    scanf("%f", &n1);
    printf("Inserisci un altro numero\n");
    scanf("%f", &n2);
    printf("Errore relativo: %f", relerr(n1, n2));
}
