#include <stdio.h>
int main(){
    int n, odd = 0, even = 0;
    float singlen;
    printf("Inserisci i numeri da inserire\n");
    scanf("%i", &n);
    for(int i = 0; i < n; i++){
        printf("Inserisci il numero\n");
        scanf("%f", &singlen);
        if((int)singlen % 2 == 0){even++;}
        else{odd++;}
    }
    printf("Pari: %i\nDispari: %i\n", even, odd);
}