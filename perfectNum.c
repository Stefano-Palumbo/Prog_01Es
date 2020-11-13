/*devi fare un programma che ti stampi a video tutti i numeri perfetti ( per semplicità il conteggio inizia da 2)
cos'è un numero perfetto? semplice, è  un numero che è uguale alla somma dei suoi divisori propri. Ad esempio, il numero 28,
divisibile per 1,2,4,7,14 o il numero 6 che è divisibile per 1,2 e 3 */

#include <stdio.h>
int main(){
    int n, sum;
    printf("Inserisci fino a che numero vuoi cercare\n");
    scanf("%i", &n);
    for(int i = 2; i < n; i++){
        sum = 0;
        for(int j = i-1; j > 0; j--){
            if(i % j == 0){sum += j;}
        }
        if(sum == i){printf("%i\n", sum);}
    }
}
