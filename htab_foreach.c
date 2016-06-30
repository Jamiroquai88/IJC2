//htab_foreach.c
//Riesenie IJC-DU2, 16.3.2014
//Autor: Jan Profant, FIT
//Prelozene: gcc 4.8.1

#include <stdio.h>
#include <stdlib.h>
#include "htable.h"

void htab_foreach (htab_t *t, void (* function) (const char *key, int data))
{
    struct htab_listitem *pointer;

    for (unsigned int i=0; i<(t->size); i++)
    {
        pointer = t->list[i]; //volaj funkciu pre kazdy riadok tabulky

        while (pointer!=NULL)
        {
            function (pointer->key,pointer->data);
            pointer = pointer->next;
        }
    }
}
