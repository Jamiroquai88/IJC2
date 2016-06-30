//fold2.cc
//Riesenie IJC-DU2, 16.3.2014
//Autor: Jan Profant, FIT
//Prelozene: gcc 4.8.1

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    string filename="/"; //retazec pre identifikaciu suboru
    string word; //retazec pre slovo
    string line; //retazec pre nacitanie riadku
    int cparam=0;
    int wparam=80;
    int i;
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
                cerr << "Chybne zadane parametre\n";
                return -1;
            }
            if (argv[1][0]=='-' && argv[1][1]=='c') cparam=1;
            else
            {
                filename=argv[1];
            }
        }
            break;
        case 3:
        {
            if ((argv[1][0]=='-' && argv[1][1]=='c') || (argv[2][0]=='-' && argv[2][1]=='c'))
            {
                 if ((argv[1][0]=='-' && argv[1][1]=='w') || (argv[2][0]=='-' && argv[2][1]=='w'))
                 {
                    cerr << "Chybne zadane parametre\n";
                    return -1;
                 }
                 if ((argv[1][0]=='-' && argv[1][1]=='c')) filename=argv[2];
                 else filename=argv[1];
                 cparam=1;
            }
            else
            {
                if ((argv[1][0]=='-' && argv[1][1]=='w'))
                {
                    wparam=atoi(argv[2]);
                    if (wparam<1)
                    {
                        cerr << "Chybne zadane parametre\n";
                        return -1;
                    }
                }
                else
                {
                    cerr << "Chybne zadane parametre\n";
                    return -1;
                }
            }
            break;
        }
        case 4:
        {
            if (argv[1][0]=='-' && argv[1][1]=='c')
            {
                cparam=1;
                if (argv[2][0]=='-' && argv[2][1]=='w')
                {
                    wparam=atoi(argv[3]);
                    if (wparam<1)
                    {
                        cerr << "Chybne zadane parametre\n";
                        return -1;
                    }
                }
                else
                {
                    cerr << "Chybne zadane parametre\n";
                    return -1;
                }
                break;
            }
            if (argv[1][0]=='-' && argv[1][1]=='w')
            {
                wparam=atoi(argv[2]);
                if (wparam<1)
                {
                    cerr << "Chybne zadane parametre\n";
                    return -1;
                }
                if (argv[3][0]=='-' && argv[3][1]=='c')
                {
                    cparam=1;
                }
                else
                {
                   filename=argv[3];
                }
                break;
            }
            if (argv[1][0]=='-' && argv[1][1]=='w')
            {
                wparam=atoi(argv[2]);
                if (wparam<1)
                {
                    cerr << "Chybne zadane parametre\n";
                    return -1;
                }
                filename=argv[3];
                break;
            }
            if (argv[2][0]=='-' && argv[2][1]=='w')
            {
                wparam=atoi(argv[3]);
                if (wparam<1)
                {
                    cerr << "Chybne zadane parametre\n";
                    return -1;
                }
                filename=argv[1];
                break;
            }

            cerr << "Chybne zadane parametre\n";
            return -1;
        }
        case 5:
        {
            if ((argv[1][0]=='-' && argv[1][1]=='c') || (argv[2][0]=='-' && argv[2][1]=='c') || (argv[3][0]=='-' && argv[3][1]=='c') || (argv[4][0]=='-' && argv[4][1]=='c'))
            {
                cparam=1;
            }
            else
            {
                cerr << "Chybne zadane parametre\n";
                return -1;
            }
            for (i=1;i<=4;i++)
            {
                if (argv[i][0]=='-' && argv[i][1]=='w')
                {
                    wparam=atoi(argv[i+1]);
                    if (wparam<1)
                    {
                        cerr << "Chybne zadane parametre\n";
                        return -1;
                    }
                }
            }
            for (i=1;i<=4;i++)
            {
                if ((argv[i][0]!='-' && argv[i][1]!='w') && (argv[i][0]!='-' && argv[i][1]!='c') && (atoi(argv[i])<1))   filename=argv[i];
            }
            break;
        }

        default:
        {
            cerr << "Chybne zadane parametre\n";
            return -1;
        }
    }




    //if (filename==NULL) f=cin;
    ifstream inputfile;
    istream *streamInput = &cin; //identifikacia streamu
    if (filename!="/")
    {

        inputfile.open (filename); //otvaram subor
        if (!inputfile.is_open())
        {
            cerr << "Subor sa nepodarilo otvorit" << endl;
            return -1;
        }
        streamInput=&inputfile; //stream zmenim z cin na subor
    }

    int poc=0;
    i=0;
    int k=0;
    int tab=0;

    while (getline(*streamInput,line)) //nacitavam riadok zo streamu
    {
        tab=0;
        if (line.size()==0) //ak to je prazdny riadok ponecham ho
        {
            cout << endl;
            if (poc!=0 && i!=0) cout << endl;
            i=0;
            poc=0;
            continue;
        }

        istringstream iss(line); //zo stringu spravim stream
        while (iss >> word) //nacitavam po slovach a pracujem s nimi
        {
            i=word.size(); //velkost slova
            if (poc+i<=wparam)
            {
                if (poc>0 && poc+i+1<=wparam)
                {
                    cout << " " << word;
                    poc++;
                    poc=poc+i;
                }
                else
                {
                    if (poc+i+1<=wparam)
                    {
                        cout << word;
                        poc=poc+i;
                    }
                    else
                    {
                        if (cparam==0)
                        {
                            if (poc>0) cout << endl << word;
                            else cout << word;
                            poc=i;
                        }
                        else
                        {
                            if (poc>0) cout << endl;
                            if (i>wparam)
                            {
                                cerr << "Warning: word is too long\n";
                                for (k=0;k<wparam;k++) cout << word[k];
                                cout << endl;
                            }
                            else
                            {
                                poc=i;
                                cout << word;
                            }
                        }
                    }

                }
            }
            else
            {
                if (cparam==0)
                {
                    if (poc>0) cout << endl << word;
                    else cout << word;
                    poc=i;
                }
                else
                {
                    if (poc>0) cout << endl;
                    if (i>wparam)
                    {
                        cerr << "Warning: word is too long\n";
                        for (k=0;k<wparam;k++) cout << word[k];
                        cout << endl;
                        tab=1;
                    }
                    else cout << word;



                }
            }

        }
    }
    if (tab==0) cout << endl; //vytlacim riadok ak to je potrebne
    if (filename!="/") inputfile.close(); //zavriem subor
    return 0;
}


