#include <stdio.h>
#include <string.h>
#include "sortslib.h"
//#include "sortslib.c"

int main(){
    int arr[] = {7,8,4,6,0,1,5,9,3,2,17,14,18,22,24,27,11,12};
    int arr2[] = {7,8,4,6,0,1,5,9,3,2,17,14,18,22,24,27,11,12};
    size_t n = sizeof(arr)/sizeof(arr[0]);
    size_t n2 = sizeof(arr2)/sizeof(arr2[0]);
    //insertion(arr,n);
    //selectionmin(arr, n);
    selectionmax(arr2, n);
    int orderedindex;
    int length = piuordinato2(arr, n, &orderedindex);
    for(int i = 0; i < n2; i++){
        printf("%i\n", arr2[i]);
    }
    printf("%i %i\n", orderedindex, length);
    //Tests
}

