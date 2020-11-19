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

int piuordinato(int arr[], int len, int *piugrande){
    int seqlen = 0, maxlen = 0;
    for(int i = 0; i < len - 1; i++){
        int j = i;
        seqlen = 0;
        while(arr[j + 1] >= arr[j]){
            j++;
            seqlen++;
        }
        if(maxlen < seqlen){
            maxlen = seqlen;
            *piugrande = i;
        }
    }
    return maxlen;
}

int piuordinato2(int arr[], int len, int *piugrande)
{
    int seqlen = 1, maxlen = 0;
    for (int i = 0; i < len - 1; i++){
        if(arr[i + 1] >= arr[i]){seqlen++;}
        else {
            if(maxlen < seqlen){
                maxlen = seqlen;
                *piugrande = i - seqlen + 1;
            }
            seqlen = 1;
        }
    }
    return maxlen;
}

void selectionmax(int arr[], int len){
    int maxindex;
    for(int i = len - 1; i > 0; i--){
        findmax(&arr[0], i + 1, &maxindex);
        swap(&arr[i], &arr[maxindex]);
    }
}

void findmax(int arr[], int len, int *maxindex){
    int max = 0;
    for(int i = 0; i < len; i++){
        if(max < arr[i]){
            max = arr[i];
            *maxindex = i;
        }
    }
}