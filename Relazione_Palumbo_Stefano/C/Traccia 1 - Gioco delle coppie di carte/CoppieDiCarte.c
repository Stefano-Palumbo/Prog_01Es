#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "CarteLib.h"

/*
Questa è il main file della prima traccia (1. Gioco delle coppie di carte) del progetto del corso di programmazione I.
Ha lo scopo di simulare un gioco basato sulle coppie di carte. Inizialmente vengono letti i nickname relativi ai due giocatori e viene inizializzato il mazzo di carte napoletane. viene poi effettuato il mescolamento del mazzo tramite scambi randomici (la quantità viene scelta dall'utente). Viene, poi, scelto casualmente il giocatore che inizia la partita. ad ogni turno si ha la possibilitò di scoprire due carte dal mazzo (inizialmente viene totalmente nascosto). Nel caso in cui il valore delle carte scelte sia lo stesso, il turno continua, le carte vengono scoperte e viene assegnato un punto all'attuale giocatore. Altimenti, in caso di errore, il turno viene passato all'altro giocatore che potrà poi effettuare le sue scelte. Il gioco termina quando tutte le carte vengono scoperte e il vincitore sarà il giocatore con il punteggio maggiore (in caso di parità verrà mostrato un messaggio differente).
*/
int main(){
    Mazzo deck[40];
    Player player1, player2;
    player1.score = 0, player2.score = 0; //inizializza i punteggi dei giocatori, entrambi a 0
    int activeturn, nswaps, nturned = 0;
    srand(time(NULL)); //Inizializza il seed della funzione rand, utilizzando il tempo attuale in unix, ottenuto tramite time(NULL)
    newdeck(deck, 10); //Viene inizializzato il mazzo con le 40 carte napoletane (10 rappresenta il numero massimo per ogni seme)
    getnick(player1.name, 1); //Vengono letti dall'utente i nomi di entrambi gli utenti
    getnick(player2.name, 2);
    printf("Inserire il numero di scambi da effettuare sul mazzo\n");
    scanf("%i", &nswaps);
    for(int i = 0; i < nswaps; i++){ //Vengono effettuati scambi randomici di carte sul mazzo, il cui numero è deciso dall'utente
        swapcards(deck, 40);
    }
    activeturn = rand() % 2; //Viene scelto un numero a caso tra 0-1 per determinare il giocatore che inizia la partita
    while (activeturn != -1){  //Il ciclo viene ripetuto finchè non si raggiungono 40 carte scoperte (viene ritornato -1 dalla funzione turn())
        if(activeturn == 0){ //in base al valore inizialmente randomico, inizia il primo oppure il secondo giocatore
            activeturn = turn(&player1, deck, activeturn, &nturned);
            //Quando poi un turno termina, viene restituito un valore opposto a quello inizialmente assegnato, in modo da alternare i due giocatori (0 restituisce 1 e viceversa) 
        }
        else {
            activeturn = turn(&player2, deck, activeturn, &nturned);
        }
    }
    sleep(2);
    clr();
    checkwinner(&player1, &player2); //Una volta che tutte le carte sono state scoperte, viene controllato il giocatore con il punteggio maggiore e stampato a schermo il vincitore (anche con controllo di parità)
    return 0;
}

