//
// Created by Simona on 12/13/2022.
//

#ifndef VICTOR_AVOCAT_H
#define VICTOR_AVOCAT_H
#include "string"
#include "iostream"
using namespace std;

class Avocat{
    int cod;
    string nume;
    int nr_procese;
    int *vector_procese= new int[30];

public:
    // CONSTRUCTOR DE INITIALIZARE
    Avocat();

    // CONSTRUCTOR PARAMETRIZAT
    Avocat(int,string,int);

    // CONSTRUCTOR DE COPIERE
    Avocat(const Avocat&);

    // OPERATOR DE ATRIBUIRE
    Avocat& operator=(const Avocat);

    // DESTRUCTOR
    virtual ~Avocat();

    // OPERATORI ISTREAM & OSTREAM
    friend istream& operator>>(istream&,Avocat&);
    friend ostream& operator<<(ostream&,const Avocat&);

    // CITIREA & AFISAREA A n OBIECTE
    friend void citire_n_obiecte();
    virtual void citire();
    virtual void afis();

    // OPERATOR > & <
    int operator>(Avocat);
    int operator<(Avocat);

    // SORTAREA UNEI LISTE DE AVOCATI DUPA NUMARUL DE PROCESE

};


#endif //VICTOR_AVOCAT_H
