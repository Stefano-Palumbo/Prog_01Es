#include <stdio.h>
#include "kesimolib.h"
int main(){
    int n, k, kmax;
    printf("Inserisci il size dell'array\n");
    scanf("%i", &n);
    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Inserisci il numero alla posizione %i\n", i);
        scanf("%i", &arr[i]);
    }

    printf("inserisci il k-esimo elemento\n");
    scanf("%i", &k);

    kmax = kesimo(arr, n, k);
    printf("%i", kmax);

}