#include <string.h>
#include <stdio.h>
int tokenstr(char text[], char maxword[])
{
    char separatori[] = " ";
    char *token;
    int max = 0;
    token = strtok(text, separatori);
    while (token != NULL)
    {
        if (strlen(token) > max)
        {
            max = strlen(token);
            strcpy(maxword, token);
        }
        token = strtok(NULL, separatori);
    }
    return max;
}

int main()
{
    char testo[] = "All previous releases are listed on GitHub, with release notes, and are available for download from Amazon S3. They are handy for testing, but otherwise we recommend using the latest stable release. Some older GitHub release pages andare asserire include the same binaries for downloading. But we have discontinued including binaries as assets on newer release pages because of the large number of files for each release";
    int max = 0;
    char maxword[100] = "";
    max = tokenstr(testo, maxword);
    printf("%s %i\n", maxword, max);
}