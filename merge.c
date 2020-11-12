#include <stdio.h>
#include "mergelib.h"
#include <string.h>
int main(){
    /*double a[100], b[100];
    int na = riempi(a);
    int nb = riempi(b);
    stampa(a, na);
    printf("------------\n");
    stampa(b, nb);
    printf("------------\n");
    double a[5] = {2,4,6,8,10};
    double b[6] = {1,3,5,7,9,11};
    int na = 5;
    int nb = 6;
    double c[na + nb];
    fusione(a, na, b, nb, c);
    stampa(c, na + nb);
    printf("%i\n", uguaglianza(a, b, na));
    printf("%i\n", uguaglianza(a, a, na)); */
    /*int rig, col;
    double a[100][100];
    printf("Inserisci il numero di righe\n");
    scanf("%i", &rig);
    printf("Inserisci il numero di colonne\n");
    scanf("%i", &col);
    riempi2d(a, rig, col);*/
    char testo[] = "Il nostro sito usa i cookie per offrire il miglior servizio possibile e un’esperienza di navigazione ottimale. Cliccando sul pulsante “Sì, accetto”, l’utente acconsente all’utilizzo dei cookies da noi impiegati e di tecnologie similari (ad es. pixel). Oltre ai cookie necessari per ragioni tecniche, vengono utilizzati anche cookie che, tra l’altro, migliorano le prestazioni del sito e offrono contenuti personalizzati per l’utente. Premendo il pulsante “Impostazioni dei cookie” è possibile modificare e rifiutare in qualsiasi momento l’utilizzo dei cookie e usare il sito senza i cookie. L’apposito link è disponibile anche in fondo alla pagina del sito. Puoi trovare maggiori informazioni nella nostra politica sulla privacy.";
    char chiave[] = "sa";
    int index;
    int indexarr[100];
    int score = bestmatch(testo, chiave, &index);
    int arrlen = strmatch(testo, chiave, indexarr);
    printf("%i %i\n", score, index);
    for(int i = 0; i < arrlen; i++){
        printf("%i -> %c%c\n",indexarr[i], testo[indexarr[i]], testo[indexarr[i] + 1]);
    }
    printf("Sto modificando questo file!!!! Adesso provo a pullare\n");
}