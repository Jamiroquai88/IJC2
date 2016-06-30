//fold.c
//Riesenie IJC-DU2, 16.3.2014
//Autor: Jan Profant, FIT
//Prelozene: gcc 4.8.1

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main (int argc, char *argv[])
{
    char buffer[4096];
    int n=0;
    int c;
    int i;
    char *filename=NULL;
    int cparam=0;
    int wparam=80;
    FILE *f=stdin;
    switch (argc) //osetrovanie parametrov
    {
        case 1:
        {
            break;
        }
        case 2:
        {
            if (argv[1][0]=='-' && argv[1][1]=='w')
            {
                fprintf (stderr,"Chybne zadane parametre\n");
                return -1;
            }
            if (argv[1][0]=='-' && argv[1][1]=='c') cparam=1;
            else
            {
                filename=argv[1];
                if ((f=fopen(filename,"r"))==NULL)
                {
                    fprintf(stderr,"Chyba pri otvarani suboru\n");
                    return -1;
                }
            }
        }
            break;
        case 3:
        {
            if ((argv[1][0]=='-' && argv[1][1]=='c') || (argv[2][0]=='-' && argv[2][1]=='c'))
            {
                 if ((argv[1][0]=='-' && argv[1][1]=='w') || (argv[2][0]=='-' && argv[2][1]=='w'))
                 {
                    fprintf (stderr,"Chybne zadane parametre\n");
                    return -1;
                 }
                 if ((argv[1][0]=='-' && argv[1][1]=='c')) filename=argv[2];
                 else filename=argv[1];
                 cparam=1;
                 if ((f=fopen(filename,"r"))==NULL)
                 {
                     fprintf(stderr,"Chyba pri otvarani suboru\n");
                     return -1;
                 }
            }
            else
            {
                if ((argv[1][0]=='-' && argv[1][1]=='w'))
                {
                    wparam=atoi(argv[2]);
                    if (wparam<1)
                    {
                        fprintf (stderr,"Chybne zadane parametre\n");
                        return -1;
                    }
                }
                else
                {
                    fprintf (stderr,"Chybne zadane parametre\n");
                    return -1;
                }
            }
            break;
        }
        case 4:
        {
            if (strcmp (argv[1],"-c")==0)
            {
                cparam=1;
                if (strcmp (argv[2],"-w")==0)
                {
                    wparam=atoi(argv[3]);
                    if (wparam<1)
                    {
                        fprintf (stderr,"Chybne zadane parametre\n");
                        return -1;
                    }
                }
                else
                {
                    fprintf (stderr,"Chybne zadane parametre\n");
                    return -1;
                }
                break;
            }
            if (strcmp (argv[1],"-w")==0)
            {
                wparam=atoi(argv[2]);
                if (wparam<1)
                {
                    fprintf (stderr,"Chybne zadane parametre\n");
                    return -1;
                }
                if (strcmp (argv[3],"-c")==0)
                {
                    cparam=1;
                }
                else
                {
                   filename=argv[3];
                    if ((f=fopen(filename,"r"))==NULL)
                    {
                        fprintf(stderr,"Chyba pri otvarani suboru\n");
                        return -1;
                    }
                }
                break;
            }
            if (strcmp (argv[1],"-w")==0)
            {
                wparam=atoi(argv[2]);
                if (wparam<1)
                {
                    fprintf (stderr,"Chybne zadane parametre\n");
                    return -1;
                }
                filename=argv[3];
                if ((f=fopen(filename,"r"))==NULL)
                {
                    fprintf(stderr,"Chyba pri otvarani suboru\n");
                    return -1;
                }
                break;
            }
            if (strcmp (argv[2],"-w")==0)
            {
                wparam=atoi(argv[3]);
                if (wparam<1)
                {
                    fprintf (stderr,"Chybne zadane parametre\n");
                    return -1;
                }
                filename=argv[1];
                if ((f=fopen(filename,"r"))==NULL)
                {
                    fprintf(stderr,"Chyba pri otvarani suboru\n");
                    return -1;
                }
                break;
            }

            fprintf (stderr,"Chybne zadane parametreee\n");
            return -1;
        }
        case 5:
        {
            if ((strcmp (argv[1],"-c")==0) || (strcmp (argv[2],"-c")==0) || (strcmp (argv[3],"-c")==0) || (strcmp (argv[4],"-c")==0))
            {
                cparam=1;
            }
            else
            {
                fprintf (stderr,"Chybne zadane parametreee\n");
                return -1;
            }
            for (i=1;i<4;i++)
            {
                if (strcmp (argv[i],"-w")==0)
                {
                    wparam=atoi(argv[i+1]);
                    if (wparam<1)
                    {
                        fprintf (stderr,"Chybne zadane parametre\n");
                        return -1;
                    }
                }
            }
            for (i=1;i<=4;i++)
            {
                if ((strcmp(argv[i],"-w")!=0) && (strcmp(argv[i],"-c")!=0) && (atoi(argv[i])<1)) filename=argv[i];
            }
            if ((f=fopen(filename,"r"))==NULL)
                {
                    fprintf(stderr,"Chyba pri otvarani suboru\n");
                    return -1;
                }
            break;
        }

        default:
        {
            fprintf (stderr,"Chybne zadane parametre\n");
            return -1;
        }
    }

    if (filename==NULL) f=stdin;
    i=0;
    int k=1; //indikuje medzeru
    int j;
    int line=0;
    int poc=0; //pocitadlo pozicie riadku
    while (feof(f)==0)
    {

        c=fgetc(f);
        i=0;
        while ((isspace(c))==0 && c!=-1)
        {
            buffer[i]=c;
            i++;
            c=fgetc(f);
        }
        if (i>=4096) fprintf(stderr,"Warning: word is too long");
        if (c=='\n' && i==0) //tlac riadku
        {
            if (line==0) printf ("\n");
            printf ("\n");
            line=1;
            k=1;
            n++;
        }
        if (i>0) { //tlac slova
        if (n>2 && line==1) poc=0;
        n=0;
        if (poc+i<=wparam && k==0 && i>0 && poc>0)
        {
            poc++;
        }
        if (poc+i<=wparam)
        {
            if (k==0 && i>0 && poc>0) //tlac medzery
            {
                printf (" ");
                k=1;
            }
            for (j=0;(j<i && j<4096);j++) printf ("%c",buffer[j]);
            poc=poc+i;
            i=0;
            k=0;
            n=0;
        }
        else
        {

            if (cparam==0)
            {
                if (poc!=0 && line==0) printf ("\n");
                for (j=0;j<i && j<4096;j++) printf ("%c",buffer[j]);
                poc=i;
                i=0;
                k=0;
            }
            else
            {
                 if (poc!=0)
                 {
                    printf ("\n");
                    poc=0;
                    line=1;
                 }
                 if (i>wparam)
                 {
                    fprintf(stderr,"Warning: word is too long\n");
                    for (j=0;j<wparam && j<4096;j++) printf ("%c",buffer[j]);
                    printf ("\n");
                    line=1;
                    poc=0;
                 }
                 else
                 {
                    for (j=0;j<i && j<4096;j++) printf ("%c",buffer[j]);
                    poc=i;
                 }
                 i=0;
                 k=0;

            }
        }
        if (cparam==0) line=0;
        }

    }
    if (poc!=0) printf ("\n");

    if (fclose(f)==EOF) fprintf (stderr,"Chyba pri zatvarani suboru\n");























    return 0;


}
