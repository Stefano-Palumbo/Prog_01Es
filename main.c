#include <stdio.h>

int main() {
    float numero_letto, max, min;
    int n, i;
    printf("Inserisci la quantità di numeri\n");
    scanf("%i", &n);
    printf("Inserisci un numero\n");
    scanf("%f", &numero_letto);
    max = numero_letto;
    min  = numero_letto;
    //printf("%f %f %i", max, min, n);
    for(i = 2; i <= n; i++){
        printf("Inserisci un numero\n");
        scanf("%f", &numero_letto);
        if(numero_letto > max) {max = numero_letto;}
        else if(numero_letto < min) {min = numero_letto;}
    }
    printf("%i %i", (int)max, (int)min);
}