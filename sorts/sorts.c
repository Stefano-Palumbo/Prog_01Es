#include <stdio.h>
#include "sortslib.h"
//#include "sortslib.c"

int main(){
    int arr[] = {7,8,4,6,0,1,5,9,3,2,17,14,18,11,12};
    size_t n = sizeof(arr)/sizeof(arr[0]);
    insertion(arr,n);
    for(int i = 0; i < n; i++){
        printf("%i\n", arr[i]);
    }
}

