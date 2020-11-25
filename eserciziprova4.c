#include <stdio.h>
#include <string.h>
int vocalcount(char[], char[]);
int e_vocale(char);
int main(){
    char testo[] = "All previous releases are listed on GitHub, with release notes, and are available for download from Amazon S3. They are handy for testing, but otherwise we recommend using the latest stable release. Some older GitHub release pages andare asserire include the same binaries for downloading. But we have discontinued including binaries as assets on newer release pages because of the large number of files for each release";
    char parola[100];
    int prova = vocalcount(testo, parola);
    printf("%i %s\n", prova, parola);
}

//Complessità di spazio -> Lunghezza della stringa N
//Complessità di tempo, confronti -> Lunghezza della stringa, al più N volte, se non ci sono spazi nel testo
//Complessità di tempo, operazioni -> 0

int vocalcount(char testo[], char parola[]){ 
    char delim[] = " ";
    char *token;
    int counter, max = 0;
    token = strtok(testo, delim);
    while(token != NULL){
        counter = 0;
        for(int i = 0; i < strlen(token); i++){
            if(e_vocale(token[i])){counter++;}
        }
        if(max < counter){
            max = counter;
            strcpy(parola, token);
        }
        token = strtok(NULL, delim);
    }
    return max;
}

int e_vocale(char lettera){
    if (lettera == *"a" || lettera == *"e" || lettera == *"i" || lettera == *"o" || lettera == *"u"){return 1;}
    else {return 0;}
}