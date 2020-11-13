#include <stdio.h>
void printa(int a[], unsigned long n){
    for(int i = 0; i < n; i++){
        printf("%i ", a[i]);
    }
    printf("\n\n");
}

void arraysum(const int a[], const int b[], int c[], int n, int m){
    int cp = 0, cd = 0;
    for(int i = 0; i < n + m; i++){
        if(i%2 == 0){c[i] = a[cp++];}
        else{c[i] = b[cd++];}
        //printf("%i ", c[i]);
    }
}

int main(){
    int n, m;
    printf("Inserisci la dimensione dell'array 1\n");
    scanf("%i", &n);
    int a[n];
    for(int j = 0; j < n; j++){
        printf("Inserisci un numero\n");
        scanf("%i", &a[j]);
    }
    printf("Inserisci la dimensione dell'array 2\n");
    scanf("%i", &m);
    int b[m];
    for(int j = 0; j < m; j++) {
        printf("Inserisci un numero\n");
        scanf("%i", &b[j]);
    }
    //printf("%lu", sizeof(a) / sizeof(a[0]));
    printa(a, n);
    printa(b, m);
    int c[n + m];
    arraysum(a, b, c, n, m);
    printa(c, n + m);
}