//htab_lookup.c
//Riesenie IJC-DU2, 16.3.2014
//Autor: Jan Profant, FIT
//Prelozene: gcc 4.8.1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "htable.h"

struct htab_listitem * htab_lookup (htab_t *t, const char *key)
{
    unsigned int line = hash_function (key, t->size); //vracia index z hash tabulky
    struct htab_listitem *tmp = NULL;
    struct htab_listitem *item = t->list [line]; //ziskame ukazovatel na zaznam v hashovacej tabulke

    while (item!=NULL) // prechadzame cely zoznam
    {
        if (strcmp(key,item->key)==0)
        {
            item->data++; //ak sa slovo nachadza, zvysim pocet jeho vyskytov
            return item; //vratim ukazovatel
        }
        tmp = item;
        item = item->next;
    }

    struct htab_listitem *new = malloc (sizeof (struct htab_listitem)); //alokujeme novu polozku

    if (new==NULL) return NULL; //ak sa nepodarilo alokovat vraciame null

    new->key = malloc (sizeof(char) * ((strlen(key))+1)); //alokujeme velkost retazca

    if (new->key==NULL)
    {
        free (new); //uvolnime velkost struktury new
        return NULL; //vratime NULL
    }

    new->data = 1; //pocet vyskytov slova
    strcpy (new->key, key); //skopirujeme obsah ukazovatela na retazec do struktury
    new->next = NULL; //dalsia polozka ukazuje na NULL

    if (t->list[line]==NULL)
        t->list[line] = new; //do riadku priradime uakzovatel a vratime ho
    else
        tmp->next=new;

    return new;
}
