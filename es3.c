#include <stdio.h>
int main(){
    int n = 3, vocn = 0;
    char letter;
    printf("Inserisci il numero di lettere da inserire\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Inserisci la lettera\n");
        scanf(" %c", &letter);
        if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u'){
            vocn++;
        }
    }
    printf("Numero di Vocali: %i\nNumero di consonanti: %i", vocn, n - vocn);
}
