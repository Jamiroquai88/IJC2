//htab_remove.c
//Riesenie IJC-DU2, 16.3.2014
//Autor: Jan Profant, FIT
//Prelozene: gcc 4.8.1

#include <stdio.h>
#include <stdlib.h>
#include "htable.h"

void htab_remove (htab_t *t, const char *key)
{
    unsigned int line = hash_function (key, t->size); //hashovacia funkcia mi vrati riadok v tabulke
    struct htab_listitem *item = t->list [line]; // ukazovatel mi uakzuje na potrebny riadok
    struct htab_listitem *pointer1 = NULL; //pomocny ukazovatel na vymenu

    while (item!=NULL) //prehladavam zaznam
    {
        if (strcmp(key,item->key)==0)
        {
            break; //narazil som na slovo
        }
        pointer1 = item;
        item = item->next;
    }

    if (item!=NULL) //vymenim ukazovatele a uvolnim z pamati strukturu
    {
        if (pointer1!=NULL) pointer1->next = item->next;
        else t->list [line]=item->next;
        free(item->key);
        free(item);
    }
}
