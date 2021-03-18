#ifndef CARTELIB_H
#define CARTELIB_H
//Header file della libreria "CarteLib" utilizzata nella prima traccia (1. Gioco delle coppie di carte) del progetto del corso di programmazione I.
//definizione tipo enumerativo per rappresentare i 4 semi delle carte napoletane all'interno del programma
typedef enum {spade, bastoni, coppe, denari} seme;
//defizione del tipo booleano, in quanto, nel C, non è un tipo primitivo. viene associato 0 al valore "false" ed 1 al valore "true"
typedef enum {false, true} bool;
//Definizione della struttura Mazzo, il quale rappresenta una singola carta all'interno del mazzo, composta da un seme (enum seme), un valore (valore intero 1-10), ed una variabile booleana per verificare se la carta è stata scoperta
typedef struct mazzo {
    seme seed;
    bool isfound;
    int value;
} Mazzo;

//Definizione della struttura Player, il quale rappresenta un giocatore all'interno della partita, composto da un nome (array di caratteri) ed un punteggio (valore intero).
typedef struct player {
    char name[50];
    int score;
} Player;

//Definizione dei vari prototipi delle funzioni utilizzati all'interno del programma
void newdeck(Mazzo*, int);
char *getseed(int);
void printarray(Mazzo*, int);
void getnick(char*, int);
bool checkerror(int, bool);
int choosecard();
int turn(Player*, Mazzo*, int, int*);
void swap(Mazzo*, Mazzo*);
void swapcards(Mazzo*, int);
void printwinner(char*, int);
void checkwinner(Player*, Player*);

#endif

//Definizione della funzione di "pulizia console", variabile a seconda del software utilizzato, in quanto su Windows è presente la funzione system che accetta, fra le altre cose, anche la variabile "clear", mentre su sistemi Unix e Unix-like, è possibile pulire la console stampando una specifica serie di caratteri
#if defined(_WIN32) || defined(__CYGWIN__)
#define clr() system("clear");
#else
#define clr() printf("\e[1;1H\e[2J");
#endif