//
// Created by Simona on 12/13/2022.
//

#ifndef VICTOR_AVOCAT_OFICIU_H
#define VICTOR_AVOCAT_OFICIU_H
#include "string"
#include "iostream"
#include "Avocat.h"
using namespace std;

class Avocat_Oficiu: public Avocat{
    string nume_client;
    int durata;

public:
    // CONSTRUCTOR DE INITIALIZARE
    Avocat_Oficiu();

    // CONSTRUCTOR PARAMETRIZAT
    Avocat_Oficiu(int,string,int,string,int);

    // CONSTRUCTOR DE COPIERE
    Avocat_Oficiu(const Avocat_Oficiu&);

    // OPERATOR DE ATRIBUIRE
    Avocat_Oficiu& operator=(const Avocat_Oficiu);

    // DESTRUCTOR
    ~Avocat_Oficiu();

    // OPERATORII ISTREAM & OSTREAM
    friend istream& operator>>(istream&,Avocat_Oficiu&);
    friend ostream& operator<<(ostream&,const Avocat_Oficiu&);

    // CITIREA & AFISAREA A n OBIECTE
    friend void citire_n_obiecte();
    void citire();
    void afis();
};

#endif //VICTOR_AVOCAT_OFICIU_H
