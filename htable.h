//htable.h
//Riesenie IJC-DU2, 16.3.2014
//Autor: Jan Profant, FIT
//Prelozene: gcc 4.8.1

#ifndef _HTABLE_H_
#define _HTABLE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//struktury pre pracu s hashovacou tabulkou

//struktura pre pracu so zaznamom
struct htab_listitem
{
    unsigned int data; //pocet vyskytov
    char *key; //ukazovatel na dynamicky alokovany retazec
    struct htab_listitem *next; //ukazovatel na dalsi zaznam
};

//struktura pre hash tabulku
typedef struct htab_t
{
	unsigned int size; // velkost tabulky
	struct htab_listitem *list[]; // pole ukazovatelov na zaznamy
}htab_t;


//funkcie
void htab_clear (htab_t *t);
void htab_free (htab_t *t);
void htab_remove (htab_t *t, const char *key);
unsigned int hash_function (const char *str, unsigned int htab_size);
struct htab_listitem * htab_lookup (htab_t *t, const char *key);
struct htab_t * htab_init (unsigned int size);
void htab_foreach (htab_t *t, void (* function) (const char *key, int data));
void htab_statistics (htab_t *t);







#endif
