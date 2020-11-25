#include <stdio.h>
#include <string.h>
void sommeinarr(int[][100], int, int, int[], int[]);
int main(){

}
//Complessità di spazio (rig * col) -> N, considerando N come rig * col
//Complessità di tempo, operazioni (2 * rig * col) -> 2N, considerando N come rig * col
void sommeinarr(int matrix[][100], int rig, int col, int sommarig[], int sommacol[]){
    int somme;
    //Somma Righe
    for(int i = 0; i < rig; i++){ //rig * col operazioni
        somme = 0;
        for (int j = 0; j < col; j++){
            somme += matrix[i][j];
        }
        sommarig[i] = somme;
    }
    //Somma Colonne
    for (int j = 0; j < rig; j++){ //rig * col operazioni
        somme = 0;
        for (int i = 0; i < col; i++){
            somme += matrix[i][j];
        }
        sommacol[j] = somme;
    }
}