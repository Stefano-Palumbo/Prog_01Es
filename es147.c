#include <stdio.h>
#define len1 100
#define len2 100

void array_concatenazione(int[], int, int[], int, int[]);

int main() {

    int n, m, i;

    printf("Inserisci la dimensione del primo array: \n");
    scanf("%i", &n);
    printf("Inserisci la dimensione del secondo array: \n");
    scanf("%i", &m);
    int a[n], b[m], c[n+m];
    for(i=0; i<n; i++){
        printf("Inserisci %d-esimo numero: \n", i);
        scanf("%i", &a[i]);
    }
    for(i=0; i<m; i++){
        printf("Inserisci %d-esimo numero: \n", i);
        scanf("%i", &b[i]);
    }


    array_concatenazione(a, n, b, m, c);

    for(i=0; i<n+m; i++){
        printf("%i", c[i]);
    }
}
void array_concatenazione(int a[], int n, int b[], int m, int c[]){
    int i, j = 0;

    for(i=0; i<n; i++){
        c[j]=a[i];
        j++;
    }

    for(i=0; i<m; i++) {
        c[j]=b[i];
        j++;
    }

}