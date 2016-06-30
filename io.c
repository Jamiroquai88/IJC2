//io.c
//Riesenie IJC-DU2, 16.3.2014
//Autor: Jan Profant, FIT
//Prelozene: gcc 4.8.1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "io.h"

int fgetw (char *s, int max, FILE *f)
{
    int i=0;
    int c; //nacitavany znak
    c=fgetc(f);

    while (isspace(c)==0 && i<=max && c!=-1) //kym nie je nacitavany znak medzera a je mensi ako limit pre slovo
    {
        if (i==127) //ak sme dosiahli limit
        {
            break;
        }
        s[i]=c;
        i++;
        c=fgetc(f);
    }

    if (c==EOF) return EOF; //nacitali
    s[i]='\0'; //zapisanie koncovej nuly na koniec retazca
    if (i==127)
    {
        while (isspace(c)==0)
            c=fgetc(f);
    }
    return i; //vratim pocet nacitanych znakov

}
