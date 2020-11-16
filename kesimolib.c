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

int k_massimo(int a[], int n, int k)
{
    int i, max = 0, k_max;
    for (i = 0; i < n; i++){   // prima scorro l'array per trovare l'elemento massimo
        if (a[i] > max)
            max = a[i];
    }
    k_max = max;
    do{
        max = k_max;
        k_max = 0;
        for (i = 0; i < n; i++){                    //scorro di nuovo l'array per trovare il
            if (a[i] > k_max && a[i] < max)         //secondo massimo, confrontandolo col massimo
                k_max = a[i];                       //precedente
        }
        k--;                                        // ripeto l'operazione in base al valore di k
    }while (k > 1);                                // e a ogni ripetizione troverò il massimo precedente
    return k_max;
}

void swap(int *n, int *m){
    int temp = *n;
    *n = *m;
    *m = temp;
}