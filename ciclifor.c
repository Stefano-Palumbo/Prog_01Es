#include <stdio.h>
#include <math.h>
int main(){
    int c1 = 0, c2 = 0, c3 = 0;
    int n = 15;
    for(int i=0; i < n; i++){
        c1++;
        for(int j=i; j < n; j++){
            c2++;
            for(int k=j; k < n; k++){
                c3++;
            }
        }
    }
    printf("%i %i %i", c1, c2, c3);
}