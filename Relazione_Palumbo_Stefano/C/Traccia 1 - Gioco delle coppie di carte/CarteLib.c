#include "CarteLib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//C file della libreria "CarteLib" utilizzata nella prima traccia (1. Gioco delle coppie di carte) del progetto del corso di programmazione I.

/* Funzione per inizializzare un nuovo mazzo con 40 carte napoletane, 10 per ogni seme
In input richiede:
Mazzo *var -> puntatore dell'array (di tipo Mazzo) da inizializzare
 int maxval -> valore massimo del valore di ogni seme (Es. maxval = 10, genera un mazzo di carte da 1 a 10 per i 4 semi napoletani) */
void newdeck(Mazzo *var, int maxval){
    //Scorre ogni casella dell'array come se fosse una matrice
    for (seme j = spade; j <= denari; j++){
        for (int i = 0; i < maxval; i++){ //Per ogni seme (seme j) vengono aggiunte carte con i valori da 1 a 10 (int i)
            var[j * maxval + i].seed = j;
            var[j * maxval + i].value = i + 1;
            var[j * maxval + i].isfound = false;
        }
    }
}

/* Funzione utilizzata per ottenere la stringa vera e proria dal valore enumerativo associato
in input richiede:
int seednum -> il valore enumerativo da "convertire"
in output restituisce:
char *getseed -> stringa corrispondente al valore enumerativo */
char *getseed(int seednum){
    switch (seednum){
    case 0:
        return "spade";
        break;
    case 1:
        return "bastoni";
        break;
    case 2:
        return "coppe";
        break;
    case 3:
        return "denari";
        break;
    default:
        return "errore";
        break;
    }
}

/* Funzione utilizzata per stampare il mazzo, controllando anche se le carte sono già state scoperte oppure no 
in input richiede:
Mazzo *deck -> puntatore dell'array (di tipo Mazzo) da controllare e stampare
int decklen -> lunghezza dell'array fornito */
void printarray(Mazzo *deck, int decklen){
    printf("Stampo il mazzo...\n");
    for (int i = 0; i < decklen; i++){ //scorre l'intero array fornito
        //Operatore ternario, se la carta è stata trovata (deck[i].isfound == true), allora viene stampato valore e seme della carta
        //(" - %i di %s - "), altrimenti viene stampata una stringa placeholder (" - %s - ", "XXXX")
        (deck[i].isfound == true) ? printf(" - %i di %s - ", deck[i].value, getseed(deck[i].seed)) : printf(" - %s - ", "XXXX");
        if ((i + 1) % 10 == 0){
            printf("\n"); //Ogni 10 carte, viene utilizzata una nuova riga, in modo da stampare 10 carte per riga
        }
    }
}

/* Funzione utilizzata per ottenere il nickname dei giocatori tramite fgets (più sicuro) all'interno del programma
in input richiede:
char *name -> puntatore ad array (di tipo char) dove conservare il nome inserito
int num -> il numero del giocatore N.esimo (1st, 2nd, 3rd, etc) */
void getnick(char *name, int num){
    printf("Inserire il nickname del Giocatore N. %i (Max 50 Caratteri):\n", num);
    fgets(name, 50, stdin); //File GET Stream, legge il nome inserito dall'utente dal buffer stdin come se fosse un file
    name[strcspn(name, "\n")] = 0; //la parte di stringa dal carattere "\n" in poi viene annullata
}

/* Funzione utilizzata per verificare se la scelta dell'utente è errata (se è compreso tra 0 e 39, e la carta scelta non è già stata scoperta)
in input richiede:
int activechoice -> scelta inserita dall'utente 
bool activefound -> valore booleano che indica se la carta scelta dall'utente è già stata trovata 
in output restituisce:
bool checkerror() -> restituisce un valore booleano per indicare al programma se sono stati trovati errori nella scelta dell'utente */
bool checkerror(int activechoice, bool activefound){
    if (activechoice < 0 || activechoice > 39 || activefound == true){
        printf("Errore, hai inserito un numero fuori range oppure hai scelto una carta già scoperta\n");
        return true;
    }
    else{return false;}
}

/* Funzione utilizzata per ottenere la scelta della carta da parte dell'utente
in output restituisce:
int choosecard() -> valore intero che rappresenta la scelta dell'utente */
int choosecard(){
    int choice;
    printf("inserisci l'indice (1-40) della carta del mazzo da scoprire\n");
    scanf("%i", &choice);
    return choice - 1; //Viene sottratta di 1 in quanto l'array presenta posizioni da 0-39, mentre un utente inserisce la posizione in range 1-40
}

/* Funzione utilizzata per effettuare un turno interno all'interno del gioco, eseguendo anche i vari controlli del caso
in input richiede:
Player *activeplr -> puntatore ad elemento (di tipo Player) che rappresenta il giocatore che sta effettuando il turno
Mazzo *activedeck -> puntatore ad array (di tipo Mazzo) che rappresenta il mazzo attualmente in uso
int activevalue -> valore intero che indica il giocatore che effettuerò il turno successivo
int *turnedcards -> puntatore ad elemento (di tipo int) che rappresenta il numero di carte che sono già state scoperte
in output restituisce:
int Turn() -> un valore intero (opposto ad activevalue) per indicare al main() il giocatore del turno successivo */
int turn(Player *activeplr, Mazzo *activedeck, int activevalue, int *turnedcards){
    int choice1, choice2;
    bool found, error;
    do {
        sleep(2);
        clr();
        error = found = false;
        printarray(activedeck, 40); //Stampa il mazzo di carte a schermo, mostrando solamente quelle già scoperte
        printf("è il turno di %s - Punteggio attuale: %i\n", activeplr->name, activeplr->score); //Mosta a schermo il giocatore attuale
        //Vengono fatte scegliere due carte dall'utente
        do { // Prima scelta
            choice1 = choosecard(); //viene letto il valore inserito dall'utente
            error = checkerror(choice1, activedeck[choice1].isfound); //viene controllato il valore inserito 
        } while (error == true); //Ripete l'inserimento se è risultato un errore

        printf("la carta scelta è la seguente -> %i di %s\n", activedeck[choice1].value, getseed(activedeck[choice1].seed)); //Stampa prima scelta
        do { // Seconda scelta
            error = false;
            choice2 = choosecard();  //viene letto il valore inserito dall'utente
            error = checkerror(choice2, activedeck[choice2].isfound);  //viene controllato il valore inserito
            if (choice2 == choice1){ //Controlla se il secondo valore è uguale al primo
                printf("Scegli una carta diversa da quella già scelta\n");
                error = true;
            }
        } while (error == true); //Ripete l'inserimento se è risultato un errore

        printf("la carta scelta è la seguente -> %i di %s\n", activedeck[choice2].value, getseed(activedeck[choice2].seed)); //Stampa seconda scelta
        if (activedeck[choice1].value == activedeck[choice2].value){ //Se i valori delle due carte scelte sono uguali:
            printf("Hai trovato una coppia! Continua il turno...\n");
            found = true; //Viene cambiato il flag in modo da far ripetere il turno al giocatore
            activeplr->score++; //Viene aumentato il punteggio
            activedeck[choice1].isfound = true; //cambia il valore booleano "isfound" per le carte scelte
            activedeck[choice2].isfound = true;
            *turnedcards = *turnedcards + 2; //Incrementa di 2 il conto di carte scoperte
            if (*turnedcards == 40){ //Se le carte scoperte sono 40, vuol dire che sono state tutte scoperte.
                printf("Tutte le carte sono state scoperte!\n");
                return -1; //Ritorna il valore -1 per segnalare al main il termine della partita
            }
        }
    } while (found == true); //Ripete finchè sono state trovate due carte uguali

    printf("Non sei riuscito a scoprire due carte dello stesso valore! Cambio turno...\n");
    sleep(2);
    return !activevalue; //Se le carte sono diverse, la funzione termina e viene ritornato il valore opposto di !activevalue, per indicare al main() di passare all'altro giocatore
}

/* Funzione utilizzata per scambiare due elementi con una variabile temporanea, in questo caso di tipo Mazzo 
in input richiede:
Mazzo *a -> puntatore all'elemento (di tipo Mazzo) da scambiare 
Mazzo *b -> ulteriore puntatore all'elemento (di tipo Mazzo) con cui effettuare lo scambio con il primo elemento */
void swap(Mazzo *a, Mazzo *b){
    Mazzo temp = *a;
    *a = *b;
    *b = temp;
}

/* Funzione utilizzata per scambiare randomicamente due carte all'interno di un mazzo 
in input richiede:
Mazzo *activedeck -> puntatore ad array (di tipo Mazzo) su cui effettuare gli scambi
int decklen -> lunghezza massima dell'array, per limitare i numeri casuali */
void swapcards(Mazzo *activedeck, int decklen){
    int index1 = rand() % decklen, index2 = rand() % decklen; //ottiene due indici randomici, limitati da decklen
    swap(&activedeck[index1], &activedeck[index2]); //scambia i due indici casuali
}

/* Funzione utilizzata per stampare a schermo un messaggio di vittoria
in input richiede:
char* name -> stringa che rappresenta il nome del giocatore vincente
int score -> punteggio del giocatore vincente */
void printwinner(char *name, int score){
    printf("%s ha vinto con un totale di %i punti!\n", name, score);
}

/* Funzione utilizzata per controllare e mostrare a schermo il vincitore della partita 
in input richiede:
Player *p1 -> puntatore ad elemento (di tipo Player) che rappresenta il primo giocatore 
Player *p2 -> puntatore ad elemento (di tipo Player) che rappresenta il secondo giocatore */
void checkwinner(Player *p1, Player *p2){
    //Stampa il messaggio di vittoria utilizzando nickname e punteggio del giocatore con lo "score" più alto
    if (p1->score > p2->score){
        printwinner(p1->name, p1->score);
    }
    else if (p2->score > p1->score){
        printwinner(p2->name, p2->score);
    }
    else { //Stampa un messaggio diverso, con i nick di entrambi i giocatori, in caso di parità
        printf("La partita si è conclusa in parità con un punteggio di %i per entrambi i giocatori %s e %s\n", p1->score, p1->name, p2->name);
    }
}