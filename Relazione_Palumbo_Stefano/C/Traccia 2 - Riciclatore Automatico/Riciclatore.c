#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "RiciclatoreLib.h"
/*
Questa è il main file della seconda traccia (2. Riciclatore automatico) del progetto del corso di programmazione I.
Ha lo scopo di simulare un "distributore automatico di rifiuti", dove è possibile portare i rifiuti per essere riciclati.
Permette di inserire un budget iniziale ad ogni giorno, da cui prelevare i soldi necessari al riciclo del prodotto.
Inoltre, se viene rilevata la fine della settimana, verrà mostrata a schermo, in ordine decrescente di prezzo, la lista di prodotti già inseriti.
di giorno in giorno poi, dopo aver inserito il budget, sarà possibile inserire nuovi rifiuti, terminare o continuare il programma, simulando il giorno successivo. 
nell'inserimento dei rifiuti nello specifico, vengono effettuati diversi controlli, quali: il costo ed il numero, in modo da non eccedere il budget o il limite per tipo di rifiuto, e la correttezza grammaticale sul tipo di prodotto inserito.
*/
int main(){
    float budget;
    int choicemenu, offset = 0;
    bool newday, endweek, menureturn, error;
    Product newproduct;
    Array products;
    Dict dictionary[4];
    int counters[5] = {0};
    setlocale(LC_ALL, "it_IT"); //Utilizzato per ottenere la data secondo il fuso orario italiano, GMT +1
    initdict(dictionary); //Inizializza il dizionario associando, ad ogni tipo di rifiuto, il numero enumerativo, presente nell'Header file.
    initArray(&products, 3); //Inizializza una sorta di array dinamico, allocando, inizialmente, 3 elementi.
    printf("Salve!\n");
    do {
        clr(); //funzione definita all'interno dell'Header file per pulire lo schermo della console
        endweek = printtime(offset); //stampa la data secondo l'offset, che indica quante volte è stata effettuata la scelta di "passare al giorno successivo"
        if(endweek){
            printf("Fine settimana, stampo i prodotti presenti in ordine decrescente di costo:\n");
            printproducts(&products, dictionary);
            //dal valore restituito da printtime(), si determina se la data attuale è una Domenica. se cosi fosse, vengono stampati i prodotti già inseriti tramite la funzione printproducts();
        }
        printf("Inserisci il budget per il riciclo di oggi\n");
        scanf("%f", &budget); //viene letto il budget da utilizzare per la giornata attuale
        clr();
        do {
            menureturn = newday = error = false;
            printf("Scegli l'opzione desiderata:\n1 - Inserisci prodotto\n2 - Passa al giorno successivo\n3 - Termina programma\nBudget disponibile: %f\n", budget);
            scanf("%i", &choicemenu); //viene letta la scelta che l'utente intende effettuare
            switch (choicemenu){ //a seconda della scelta, lo "switch" passa alla scelta desiderata
            case 1:
                //viene letto il rifiuto che l'utente intende inserire, effettuando anche i dovuti controlli.
                //nello specifico, controlla se sono risultati errori nel controllo degli input dell'utente, sia per quanto riguarda i limiti imposti dal programma, sia per quanto riguarda la correttezza grammaticale, effettuati in getproduct(). Se il flag risulta negativo, allora il prodotto inserito viene aggiunto all'array
                getproduct(&newproduct, &budget, dictionary, &error, counters);
                if (error == false) {insertArray(&products, newproduct);} 
                menureturn = true;
                break;

            case 2:
                //Nel caso si scelga di passare al giorno successivo, l'offset viene aumentato per tener conto dei giorni da aggiungere alla data attuale
                offset++; 
                newday = true;
                break;

            case 3:
                //Libera lo spazio allocato in memoria dall'array e termina il programma
                printf("Termino il programma...\n");
                freeArray(&products);
                return 0;
                break;

            default:
                //Caso base, viene utilizzato quando la scelta dell'utente non risulta nella lista pre-programmata. Stampa un messaggio di errore
                printf("Errore, opzione non riconosciuta\n");
                menureturn = true;
                break;
            }
            //A seconda dei flag impostati, il programma ritorna al menù di opzione (menureturn), questo per quanto riguarda il messaggio di errore e l'inserimento (riuscito o no) di un rifiuto, oppure ritorna all'inserimento del budget iniziale della giornata (newday), questo per quanto riguarda la scelta di passare al giorno successivo
        } while(menureturn == true);
    } while(newday == true);
}   