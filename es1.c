#include <stdio.h>

int main(){
    int n, pos = 0, neg = 0;
    float singlen;
    printf("Inserisci i numeri da inserire\n");
    scanf("%i", &n);
    for(int i = 0; i < n; i++){
        printf("Inserisci il numero\n");
        scanf("%f", &singlen);
        if(singlen >= 0){pos++;}
        else{neg++;}
    }
    printf("Positivi: %i\nNegativi: %i\n", pos, neg);
}