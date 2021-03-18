#include "RiciclatoreLib.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//C file della libreria "RiciclatoreLib" utilizzata nella seconda traccia (2. Riciclatore automatico) del progetto del corso di programmazione I.

/* Inizializza l'array dinamico con malloc(), allocandogli una dimensione a seconda della variabile di input, e imposta le variabili di utilizzo e dimensione dell'array di conseguenza.
In input richiede: 
Array *a -> puntatore dell'array (di tipo Array) da inizializzare
int initialSize -> la sua dimensione iniziale (initialSize) */
void initArray(Array *a, int initialSize) {
    a->array = malloc(initialSize * sizeof(Product));
    a->used = 0;
    a->size = initialSize;
}

/* Inserisce un elemento nell'array dinamico, aumentandone le dimensioni con realloc() nel caso in cui non ci sia sufficiente spazio. il controllo viene effettuato grazie alle variabili (used e size) del tipo Array
In input richiede:
Array *a -> puntatore dell'array (di tipo Array) a cui aggiungere un elemento
Product element -> l'elemento da aggiungere (in questo caso di tipo Product) */
void insertArray(Array *a, Product element) {
    if (a->used == a->size) {
        a->size += 2;
        a->array = realloc(a->array, a->size * sizeof(Product));
    }
    a->array[a->used++] = element;
}

/* Libera la memoria dall'array dinamico con free() e reimposta le variabili interne.
/In input richiede: 
Array *a -> puntatore dell'array (di tipo Array) da liberare */
void freeArray(Array *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

/*controlla se la giornata attuale è una Domenica e stampa a schermo il tempo attuale, tenendo anche in considerazione la differenza di giorni da applicare alla data attuale. utilizza funzioni di libreria time.h per ottenere il tempo (con l'aggiunta dell' offset), costruire la struttura tm e creare la stringa da stampare.
in input richiede:
int offset -> la differenza in giorni da applicare alla data
in output viene restituito:
bool printtime() -> un valore booleano che indica al programma se la data attuale è una Domenica */
bool printtime(int offset) {
    time_t t = time(NULL) + (offset * 86400);  //salva in variabile il tempo rappresentato in Unix, ovvero secondi passati dal 1/1/1970 sommato alla differenza, dove 86400 rappresentano i secondi in un giorno
    struct tm *tm = localtime(&t); //crea e riempie la struttura tm, che contiene la data scomposta nelle singole componenti (tm_sec -> secondi, tm_min -> minuti, tm_hour -> ore, etc...)
    char date[80];
    strftime(date, 80, "%A %d %B", tm);  //riempie la stringa da stampare, con strftime() è possibile definire le parti della data a cui si è interessati. in questo caso %A indica il nome per intero del giorno della settimana, %d, il giorno del mese, range 1-31, e %B il nome per intero del mese
    printf("Data attuale: %s\n", date);
    if (tm->tm_wday == 0) {return true;} //Effettua il controllo per il fine della settimana, utilizzando il valore della struttura tm_wday, che rappresenta il giorno della settimana in range 0-6, dalla Domenica = 0 al Sabato = 6
    else {return false;}
}

/*Inizializza in dizionario associando, ad ogni chiave, la corrispettiva stringa, tramite ciclo for.
In input richiede:
Dict *dictionary -> puntatore ad array (di tipo Dict) da inizializzare */
void initdict(Dict *dictionary) {
    for (type i = vetro; i <= indifferenziata; i++) {
        dictionary[i].key = i;
        switch (i) {
            case 0:
                strcpy(dictionary[i].value, "vetro");
                break;
            case 1:
                strcpy(dictionary[i].value, "plastica");
                break;
            case 2:
                strcpy(dictionary[i].value, "carta");
                break;
            case 3:
                strcpy(dictionary[i].value, "organico");
                break;
            case 4:
                strcpy(dictionary[i].value, "indifferenziata");
                break;
            default:
                strcpy(dictionary[i].value, "errore");
                break;
        }
    }
}

/*Utilizzato per ottenere in ingresso una stringa dall'utente, utilizzando fgets (che richiede anche una lunghezza massima) anzichè scanf, in quanto più sicuro
in input richiede:
char *name -> puntatore ad array (di tipo char) dove andare a salvare la stringa
int len -> lunghezza massima della stringa */
void getname(char *name, int len) {
    fpurge(stdin); //pulisce il buffer d'ingresso, ovvero stdin, da caratteri precedenti
    fgets(name, len, stdin); //File GET Stream, legge la stringa inserita dall'utente, "catturandola" dal buffer d'ingesso come se fosse un file
    name[strcspn(name, "\n")] = 0;  //utilizzando strcspn(), la stringa dal carattere "\n" in poi viene annullata. processo da effettuare in quanto fgets() cattura anche l'invio di tastiera
}

/*Trasforma eventuali caratteri di una stringa da maiuscolo a minuscolo, per standardizzare gli input
In input richiede:
char *str -> puntatore ad array (di tipo char) da trasformare in minuscolo */
void lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

/* Utilizzato per ottenere dall'utente un nuovo rifiuto da inserire, effettuando tutti i controlli del caso
In input richiede:
Product *activeprd -> puntatore di un elemento (di tipo prodotto) dove salvare i dati inseriti
float *budgetleft -> puntatore di un elemento (di tipo float) dove andare a ridurre e controllare il budget
Dict *dictionary -> puntatore ad array (di tipo Dict) per effettuare i vari controlli
bool *error -> puntatore ad elemento (di tipo bool), il cui valore viene modificato a seconda del risultato dei controlli
int *counters -> puntatore ad array (di tipo int) dove sono presenti i contatori dei vari tipi, utilizzato per effettuare controlli */
void getproduct(Product *activeprd, float *budgetleft, Dict *dictionary, bool *error, int *counters) {
    char prdtype[20];
    bool correct = false;
    printf("Inserisci il costo del prodotto\n");
    scanf("%f", &activeprd->cost);
    if (*budgetleft < activeprd->cost) { //Legge dall'utente il costo del prodotto, e controlla se il costo supera il budget
        clr();
        printf("Budget rimanente non sufficiente\n");
        *error = true;
        return; //Se il costo risulta troppo elevato, la funzione si interrompe e viene segnalato un "errore" al main() tramite *error
    }

    printf("inserisci il nome del prodotto\n");
    getname(activeprd->name, 100);  //Legge dall'utente il nome del rifiuto da riciclare
    printf("inserisci il tipo di prodotto\n");
    getname(prdtype, 20);  //Legge dall'utente il tipo di rifiuto da riciclare
    lowercase(prdtype); //trasforma la stringa letta in minuscolo, in modo da confermare l'inserimento anche in caso di maiuscole (Case - Insensitive)
    for (type i = vetro; i <= indifferenziata; i++) {
        if (strcmp(dictionary[i].value, prdtype) == 0) { //viene effettuata la ricerca del tipo inserito all'interno del dizionario
            correct = true;
            activeprd->id = i;
            break;
            //nel caso in cui la ricerca sia riuscita, viene impostato l'id del rifiuto come valore enumerativo e la variabile "correct" a "true"
        }
    }
    if (correct == false) {
        //nel caso in cui la ricerca non sia riuscita, ovvero la variabile "correct" non è mai stata portata a "true", il programma stampa un errore e lo segnala anche al main() tramite *error
        clr();
        printf("Errore, tipo non riconosciuto\n");
        *error = true;
        return;
    }

    if (checktype(counters, activeprd->id) == false) {  //viene controllato se è stato superato il numero massimo di rifiuti per un determinato tipo
        //Nel caso in cui vengano passati tutti i controlli, viene ridotto il costo del rifiuto dal budget e aumentato il contatore
        *budgetleft -= activeprd->cost;
        counters[activeprd->id]++;
    } else {*error = true;} //Altrimenti viene segnalato l'errore al main tramite *error
}

/* Utilizzato per verificare se è già stato raggiunto il limite di 20 prodotti per tipo all'interno dell'array
In input richiede:
int *counters -> puntatore dell'array (di tipo int) dove sono presenti i contatori da controllare
int checktype -> il tipo di rifiuto da controllare
In output restituisce:
bool checktype() -> un valore booleano, per indicare al main() se è già stato raggiunto il limite per quel tipo di rifiuto */
bool checktype(int *counters, int checktype) {
    if (counters[checktype] > 20) { /*se il contatore risulta maggiore del limite, allora il programma stampa un errore e restiuisce "true" per indicare al main() il raggiungimento del limite, altrimenti restituisce "false" */
        clr();
        printf("Errore, impossibile aggiungere il prodotto, troppi prodotti gi%lc presenti dello stesso tipo\n", 0x00E1);
        return true;
    }

    return false;
}

/*Funzione per restituire l'indice dell'elemento più grande all'interno dell'array fornito, utilizzato per ordinare l'array
In input richiede:
Product *arr -> puntatore dell'array (di tipo Product) in cui effettuare la ricerca
int endarr -> lunghezza dell'array fornito
in output restituisce:
int maxindex() -> un valore intero che rappresenta l'indice dell'elemento più grande all'interno dell'array */
int maxindex(Product *arr, int endarr) {
    int max = 0, maxind = 0;
    for (int j = 0; j < endarr; j++) { //Scorre tutti gli elementi dell'array
        if (arr[j].cost > max) { //Se l'elemento attuale ha un costo maggiore del massimo rilevato, viene salvato all'interno di una variabile il costo e l'indice
            max = arr[j].cost;
            maxind = j;
        }
    }
    return maxind; //al termine restituisce l'indice dal costo più grande
}

/* Funzione per scambiare due elementi di tipo Product, utilizzando una variabile temporanea
In input richiede:
Product *a -> Puntatore ad elemento (di tipo Product) su cui effettuare lo scambio
Product *b -> Puntatore ad un ulteriore elemento (di tipo Product) su cui effettuare lo scambio con il primo */
void swap(Product *a, Product *b) {
    Product temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
/* Funzione per ottenere la stringa di caratteri del tipo, dato il tipo enumerativo "type"
In input richiede:
Dict *activedict* -> puntatore ad array (di tipo Dict) dove controllare la stringa corrispondente
int valuecheck -> Il valore enumerativo da cui si intende ottenere la stringa di caratteri */
char *gettype(Dict *activedict, int valuecheck) {
    return activedict[valuecheck].value;
}

/* Funzione per effettuare l'ordinamento e la stampa dell'array alla fine della settimana. Viene ordinato tramite selezione di massimo, posizionando, però, l'elemento più grande alla prima posizione dell'array anzichè l'ultima.
in input richiede:
Array *activearr -> puntatore dell'array (di tipo Array) da ordinare
Dict *activedict -> puntatore ad array (di tipo Dict) utilizzato per ottenere la stringa del tipo associata al valore enumerativo */
void printproducts(Array *activearr, Dict *activedict) {
    int maxind;
    for (int i = 0; i < activearr->used - 1; i++) { //Algoritmo di selezione di massimo che posiziona l'elemento più grande nella prima posizione
        maxind = maxindex(&activearr->array[i], activearr->used - i); //Trova l'elemento più grande nella sezione attuale
        swap(&activearr->array[i], &activearr->array[maxind + i]); //Scambia l'elemento più grande con l'elemento attuale
    }
    for (int i = 0; i < activearr->used; i++) { //Scorre l'intero array e ne stampa le varie variabili, ottenendo la stringa dal valore "type" con gettype()
        printf("Prodotto N. %i: %s, costo: %f, tipo: %s\n", i + 1, activearr->array[i].name, activearr->array[i].cost, gettype(activedict, activearr->array[i].id));
    }
}