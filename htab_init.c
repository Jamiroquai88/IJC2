//htab_init.c
//Riesenie IJC-DU2, 16.3.2014
//Autor: Jan Profant, FIT
//Prelozene: gcc 4.8.1

#include <stdio.h>
#include "htable.h"
#include <stdlib.h>

htab_t * htab_init (unsigned int size)
{
    struct htab_t *t;

    t = (struct htab_t *) malloc (sizeof(struct htab_t) + (size * sizeof(struct htab_listitem *)));     //alokovanie struktury tabulky
    if (t==NULL) return NULL; //nepodarila sa alokacia

    t->size = size; //do struktury prirad max velkost

    return t;
}
