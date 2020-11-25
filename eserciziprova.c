#include <stdio.h>
#include <string.h>
void mediaswap(float[], int, float[], int);
float media_array(float[], int);

int main(){
    float arr1[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f}; //n_a variabili allocate
    float arr2[] = {11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f, 17.0f, 18.0f, 19.0f, 20.0f}; //n_b variabili allocate
    size_t n_a = sizeof(arr1) / sizeof(arr1[0]); //1 variabile allocata
    size_t n_b = sizeof(arr2) / sizeof(arr2[0]); //1 variabile allocata
    mediaswap(arr1, 10, arr2, 10); //3 variabili allocate
    for(int i = 0; i < n_a; i++){
        printf("%f %f\n", arr1[i], arr2[i]);
    }
    //Complessità di tempo, confronti = N, lineare, considerando n_a + n_b come N
    //Complessità di tempo, operazioni aritmetiche, N + 2, onsiderando n_a + n_b come N
    //Complessità di spazio (5 + n_a + n_b) -> O(n) = lineare, considerando n_a + n_b come N, ed eliminando le costanti
}

void mediaswap(float a[], int n_a, float b[], int n_b){ //2n_a + 2n_b confronti, 2 variabili allocate
    float avga = (media_array(a, n_a)); //n_a + 1 somme
    float avgb = (media_array(b, n_b)); //n_b + 1 somme
    for(int i = 0; i < n_a; i++){ //n_a confronti
        if(a[i] > avga){a[i] = avga;}
    }
    for(int i = 0; i < n_b; i++){ //n_b confronti
        if(b[i] > avgb){b[i] = avgb;}
    }
}

float media_array(float arr[], int len){ //N + 1 somme per chiamata della funzione, 1 variabile allocata
    float media = 0;
    for(int i = 0; i < len; i++){
        media += arr[i];
    }
    return (media / len);
}