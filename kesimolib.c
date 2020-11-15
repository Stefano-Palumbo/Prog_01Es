#include "kesimolib.h"
int kesimo(int arr[], int n, int k){
    int max, index;
    for(int i = 0; i < k; i++){
        index = 0;
        max = 0;
        for(int j = i; j < n; j++){
            if(arr[j] > max){
                max = arr[j];
                index = j;
            }
            swap(&arr[index], &arr[i]);
        }
    }
    return arr[k - 1];
}

void swap(int *n, int *m){
    int temp = *n;
    *n = *m;
    *m = temp;
}