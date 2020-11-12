#include <stdio.h>
#include <math.h>

void invert(int *a){
    if(*a == 0){*a = 1;}
    else{*a = 0;}
}

void declare(int riga, int colonna, int matrix[riga][colonna]){
    for(int i = 0; i < colonna; i++) {
        for (int j = 0; j < riga; j++) {
            matrix[j][i] = 0;
        }
    }
}

void addout(int rigaout, int riga, int colonnaout, int matrix[riga][colonnaout + 1]){
    int rigpos;
    for(int i = 0; i < rigaout; i++){
        printf("Inserisci la riga positiva\n");
        scanf("%i", &rigpos);
        matrix[rigpos - 1][colonnaout] = 1;
        //printf("%i", tab[rigpos - 1][ing]);
    }
}

int main(){
    int ing, nusc, counter = 1, swap = 0;
    printf("Inserisci il numero di ingressi\n");
    scanf("%i", &ing);
    printf("Inserisci il numero di uscite = 1\n");
    scanf("%i", &nusc);
    int tab[(int) pow(2, ing)][ing + 1];
    declare(pow(2, ing), ing + 1, tab);
    addout(nusc,pow(2, ing), ing, tab);

    for(int i = 0; i < ing; i++){
        swap = 0;
        counter = 1;
        for(int j = 0; j < pow(2, ing); j++){
            int pot = (int) pow(2, ing);
            //printf("%f\n", pot / pow(2, i + 1));
            if(counter <= (pot / pow(2, i + 1))){
                tab[j][i] = swap;
                counter++;
            } else {
                counter = 1;
                invert(&swap);
                tab[j][i] = swap;
                counter++;
                    }
        }
    }

    for(int i = 0; i < pow(2, ing); i++){
        for(int j = 0; j <= ing; j++){
            if(j == ing){
                printf(" ");
            }
            printf("%i ", tab[i][j]);
        }
        printf("\n");
    }
};
