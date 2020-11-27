#include <stdio.h>
void minswap(int[], int[], int);
int min_val_ind(int[], int);
void scambiare(int*, int*);
void keysearch(char[][100], int, int, char, int[]);

void minswap(int a[], int b[], int n){
    int indexmina = min_val_ind(a,n);
    int indexminb = min_val_ind(b,n);
    scambiare(&a[indexmina], &b[indexminb]);
}

int min_val_ind(int arr[], int len){
    int min = arr[0], minindex = 0;
    for(int i = 0; i < len; i++){
        if(arr[i] < min){
            min = arr[i];
            minindex = i;
        }
    }
    return minindex;
}

void scambiare(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void keysearch(char matrix[][100], int col, int rig, char key, int occorrenze[]){
    int counter;
    for(int j = 0; j < col; j++){
        counter = 0;
        for(int i = 0; i < rig; i++){
            if(matrix[i][j] == key){counter++;}
        }
        occorrenze[j] = counter;
    }
}

int main(){
    int arr1[] = {5,3,4,1,6};
    int arr2[] = {4,5,2,7,8};
    char matrice[][100] = {{*"a", *"b", *"c", *"d", *"e"}, {*"c", *"b", *"z", *"l", *"b"}, {*"b", *"c", *"h", *"j", *"k"}};
    int occurrences[20];
    char chiave = *"b";
    minswap(arr1, arr2, 5);
    keysearch(matrice, 5, 3, chiave, occurrences);
    for(int i = 0; i < 5; i++){
        printf("%i %i %i\n", arr1[i], arr2[i], occurrences[i]);
    }
}