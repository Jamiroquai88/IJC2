//htab_statistics.c
//Riesenie IJC-DU2, 16.3.2014
//Autor: Jan Profant, FIT
//Prelozene: gcc 4.8.1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "htable.h"

void htab_statistics (htab_t *t)
{
    struct htab_listitem *item;
    unsigned int min=0;
    unsigned int max=0;
    unsigned int poc=0;
    unsigned int zoz=0;
    double priemer=0;
    int pole[t->size];
    unsigned int i=0;
    for (i=0;i<t->size;i++)
	{
        pole[i]=0; //nulujeme pole
    }
    for (i=0; i<t->size; i++) //pre kazdu polozku tabulky
	{
        item = t->list[i];
        while (item!=NULL)
        {
            poc++; //pocitadlo zaznamov
            if (poc>max) max=poc;

            if (poc>=1) min=1;
            item = item->next; //ukazovatel na dalsi zaznam
        }
        pole[i]=poc; //do pola pridat pocitadlo
        poc=0;
	}
	for (i=0;i<t->size;i++)
	{
        if (pole[i]>0)
        {
            priemer=priemer+pole[i]; //ak bolo viac ako nula zaznamov, prirad do priemeru
            zoz++;
        }
	}

    priemer = priemer/zoz; //vypocitaj priemer

	printf ("Priemerna dlzka zoznamu: %f\n",priemer);
	printf ("Min. dlzka zoznamu: %d\n",min);
	printf ("Max. dlzka zoznamu: %d\n",max);

}
