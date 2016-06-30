//htab_clear.c
//Riesenie IJC-DU2, 16.3.2014
//Autor: Jan Profant, FIT
//Prelozene: gcc 4.8.1

#include <stdio.h>
#include <stdlib.h>
#include "htable.h"

void htab_clear (htab_t *t)
{
    struct htab_listitem *item;
    struct htab_listitem *fire;

    for (unsigned int i=0; i<t->size; i++) //pre kazdu polozku tabulky
	{
        item = t->list[i];
        if (item==NULL) continue; //prejdi cey zoznam
        while (item->next!=NULL)
        {
            fire = item;
            item = item->next;

            free(fire->key); //uvolni pole znakov
            free(fire); //uvolni strukturu
        }
        free (item->key); //uvolni pole znakov
        free(item); //uvolni strukturu
    }
}
