#include <stdio.h>
int main(){
    int size;
    printf("Inserisci la dimensione dell'array\n");
    scanf("%i", &size);
    int a[size];
    int b[size];
    int indiceb = size - 1;
    for(int i = 0; i < size; i++){
        printf("Inserisci un valore\n");
        scanf("%i", &a[i]);
    }
    for(int i = 0; i < size; i++){
        b[indiceb - i] = a[i];
        //printf("%i %i\n", b[n - i], n - i);
    }
    printf("Array invertito:\n");
    for(int i = 0; i < size; i++){
        printf("%i\n", b[i]);
    }
}

