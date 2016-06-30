//htab_free.c
//Riesenie IJC-DU2, 16.3.2014
//Autor: Jan Profant, FIT
//Prelozene: gcc 4.8.1

#include <stdio.h>
#include <stdlib.h>
#include "htable.h"

void htab_free (htab_t *t)
{
    htab_clear(t); //volaj clear pre strukturu htab_listitem
    free(t); //uvolni strukturu htab_t
}
