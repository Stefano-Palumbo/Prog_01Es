#include "sortslib.h"
void insertion(int arr[], int n){
    int key, j;
    for(int i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void swap(int* n, int* m){
    int temp = *n;
    *n = *m;
    *m = temp;
}

void findmin(int arr[], int len, int* minind){
    int minfun = arr[0], minindfun = 0;
    for(int i = 0; i < len; i++){
        if(arr[i] < minfun){
            minfun = arr[i];
            minindfun = i;
        }
        *minind = minindfun;
    }
}

void selectionmin(int arr[], int len){
    int swapindex = 0;
    for(int i = 0; i < len; i++){
        findmin(&arr[i], len - i, &swapindex);
        swap(&arr[i], &arr[swapindex + i]);
    }
}