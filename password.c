#include <stdio.h>
#include <string.h>
int main(){
    char pass[256];
    char corretta[] = "sono troppo figo";
    int tentativi = 3;
    while(tentativi > 0) {
        printf("Inserisci la Password\n");
        fgets(pass, sizeof(pass), stdin);
        //printf("%lu %lu\n", strlen(corretta), strlen(pass) - 1);
        if (strlen(pass) - 1 == strlen(corretta)) {
            if (strncmp(corretta, pass, strlen(corretta)) == 0) {
                printf("Password Corretta!\n");
                break;
            } else { printf("Password Errata!\n"); }
        } else { printf("Lungezza Errata!\n"); }

        tentativi--;
    }

    if(tentativi <= 0){
        printf("Troppi tentativi eseguiti, chiusura del programma\n");
    }
}
