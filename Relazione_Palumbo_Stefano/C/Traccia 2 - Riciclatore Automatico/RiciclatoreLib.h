#ifndef RICICLATORELIB_H
#define RICICLATORELIB_H
//Header file della libreria "RiciclatoreLib" utilizzata nella seconda traccia (2. Riciclatore automatico) del progetto del corso di programmazione I.
//defizione del tipo booleano, in quanto, nel C, non è un tipo primitivo. viene associato 0 al valore "false" ed 1 al valore "true"
typedef enum {false, true} bool;
//definizione dei vari tipi di rifiuti presenti nel programma, utilizzato per evitare di salvare un intera stringa come variabile. il dizionario verrà poi utilizzato per associare la stringa vera e propria al tipo enumerato
typedef enum {vetro, plastica, carta, organico, indifferenziata} type;
//definizione del rifiuto inserito dall'utente, composto da un nome (name - stringa), un tipo (id - type), ed un costo (cost - numero reale, a virgola mobile)
typedef struct {
    char name[100];
    type id;
    float cost;
} Product;
//defizione dell'array dinamico utilizzato all'interno del programma, composto da un puntatore ad elementi di tipo "Product" sopra definiti, e due valori utilizzati per indicare la dimensione attuale dell'array e la dimensione già occupata dell'array
typedef struct {
    Product *array;
    int used;
    int size;
} Array;
//definizione del dizionario, composto da una chiave, in questo caso un numero intero, ovvero il tipo enumerativo, e dal valore associato, in questo caso la stringa vera e propria.
typedef struct {
    int key;
    char value[20];
} Dict;

//i prototipi delle funzioni create, commentate nel file di libreria .C 
void initArray(Array*, int);
void insertArray(Array*, Product);
void freeArray(Array*);
bool printtime(int);
void initdict(Dict*);
void getname(char*, int);
void lowercase(char*);
void getproduct(Product*, float*, Dict*, bool*, int*);
bool checktype(int*, int);
int maxindex(Product*, int);
void swap(Product*, Product*);
char *gettype(Dict*, int);
void printproducts(Array*, Dict*);
#endif


//Definizione della funzione di "pulizia console", variabile a seconda del software utilizzato, in quanto su Windows è presente la funzione system che accetta, fra le altre cose, anche la variabile "clear", mentre su sistemi Unix e Unix-like, è possibile pulire la console stampando una specifica serie di caratteri
#if defined(_WIN32) || defined(__CYGWIN__)
#define clr() system("clear");
#else
#define clr() printf("\e[1;1H\e[2J");
#endif