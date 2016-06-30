//wordcount.c
//Riesenie IJC-DU2, 16.3.2014
//Autor: Jan Profant, FIT
//Prelozene: gcc 4.8.1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "htable.h"
#include "io.h"

#define MAXWORDLENGTH 127

void print_hashtab (const char *key, int data) //funkcia na vypis tabulky
{
    printf ("%s\t%d\n",key,data);
}

int main ()
{
    struct htab_listitem *item; //struktura pre jeden zaznam

    char word[MAXWORDLENGTH]; //pole znakov s max dlzkou

    htab_t *t = htab_init (2048); //inicializacia tabulky velkosti 2048
    if (t==NULL) //t je NULL
    {
        fprintf (stderr,"Nepodarilo sa alokovat pamat");
        return -1;
    }
    int i=0;
    int longer=0;
    while ((i=fgetw(word,MAXWORDLENGTH,stdin))!=EOF)
    {
        if (i>0) item = htab_lookup (t, word); //pridanie vyskytu slova, resp. vytvorenie noveho zaznamu
        if (i==127 && longer==0)
        {
            fprintf (stderr, "Prekrocena dlzka slova\n");
            longer=1;
        }
        if (item == NULL && i>0)
        {
            fprintf (stderr,"Nepodarilo sa alokovat pamat");
            return -1;
        }
    }

    htab_foreach(t,print_hashtab); //volam funkciu pre kazdy zaznam v tabulke
    htab_free (t); ////uvolnime strukturu tabulky
}
