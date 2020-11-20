#include <stdio.h>
#include <string.h>
int main()
{
    char testo[] = "All previous releases are listed on GitHub, with release notes, and are available for download from Amazon S3. They are handy for testing, but otherwise we recommend using the latest stable release. Some older GitHub release pages include the same binaries for downloading. But we have discontinued including binaries as assets on newer release pages because of the large number of files for each release";
    char spazio[] = " ";
    char maxparola[100] = "";
    char *token;
    token = strtok(testo, spazio);
    int maxlen = 0, index;
    while (token != NULL)
    {
        char *address1 = testo;
        char *address2 = &(*token);
        int calcolo = (address1 - address2) * -1;
        printf("%p %p %s %i\n", &(*token), &testo, token, strlen(token));
        if (maxlen < strlen(token))
        {
            maxlen = strlen(token);
            strcpy(maxparola, token);
            index = calcolo;
        }

        token = strtok(NULL, spazio);
    }

    printf("%i %i %s", maxlen, index, maxparola);
}
