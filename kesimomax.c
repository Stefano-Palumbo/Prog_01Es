#include <stdio.h>
#include "kesimolib.h"
int main(){
    int n, arr[100], k, kmax;
    printf("Inserisci il size dell'array\n");
    scanf("%i", &n);

    for(int i = 0; i < n; i++){
        printf("Inserisci il numero alla posizione %i\n", i);
        scanf("%i", &arr[i]);
    }

    printf("inserisci il k-esimo elemento\n");
    scanf("%i", &k);

    for(int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }
    printf("\n");
    kmax = k_massimo(arr, n, k);
    printf("%i", kmax);

}