#include <stdio.h>
#include <string.h>
int media_array(int[], int);
void fusione_array(int[], int, int[], int, int[]);
int es3(int[], int, int[], int, int[]);
int main(){
    int arr1[] = {1,3,5,7,9,11};
    int arr2[] = {2,4,6,8,10};
    size_t n_a = sizeof(arr1) / sizeof(arr1[0]); //1 variabile allocata
    size_t n_b = sizeof(arr2) / sizeof(arr2[0]); //1 variabile allocata
    int arr3[n_a + n_b];
    int media = es3(arr1, n_a, arr2, n_b, arr3);
    for(int i = 0; i < n_a + n_b; i++){
        printf("%i\n", arr3[i]);
    }
    printf("%i\n", media);
}

//Complessità di spazio (n_a + n_b + (n_a + n_b)) -> 2N, considerando N come n_a + n_b; O(N) -> Lineare
//Complessità di tempo, confronti (n_a + n_b) -> N al più, considerando N come n_a + n_b O(N) -> Lineare
//Complessità di tempo, operazioni (n_a + n_b + 1) -> N + 1, considerando N come n_a + n_b O(N) -> Lineare

int es3(int a[], int n_a, int b[], int n_b, int c[]){
    fusione_array(a, n_a, b, n_b, c); //n_a + n_b confronti
    return media_array(c, n_a + n_b); //n_a + n_b + 1 operazioni
}

void fusione_array(int a[], int n_a, int b[], int n_b, int c[]){ //n_a + n_b confronti al più
    int i_a = 0, i_b = 0, i_c = 0, media = 0;
    while(i_a < n_a && i_b < n_b){ 
        if(a[i_a] < b[i_b]){c[i_c++] = a[i_a++];}
        else{c[i_c++] = b[i_b++];}
    } 
    while (i_a < n_a){c[i_c++] = a[i_a++];}
    while (i_b < n_b){c[i_c++] = b[i_b++];}
}

int media_array(int arr[], int len){ //N + 1 somme per chiamata della funzione, 1 variabile allocata
    int media = 0;
    for(int i = 0; i < len; i++){
        media += arr[i];
    }
    return (media / len);
}