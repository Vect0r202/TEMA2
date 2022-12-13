//
// Created by Simona on 12/13/2022.
//

#include "Avocat_Oficiu.h"
// CONSTRUCTOR DE INITIALIZARE - DERIVATA
Avocat_Oficiu::Avocat_Oficiu():Avocat(){}

// CONSTRUCTOR PARAMETRIZAT - DERIVATA
Avocat_Oficiu::Avocat_Oficiu(int C,string N,int NR_P,string N_C,int D):Avocat(C,N,NR_P)
{
    nume_client=N_C;
    durata=D;
}

// CONSTRUCTOR DE COPIERE - DERIVATA
Avocat_Oficiu::Avocat_Oficiu(const Avocat_Oficiu& A_O):Avocat(A_O)
{
    nume_client=A_O.nume_client;
    durata=A_O.durata;
}

// OPERATOR DE ATRIBUIRE - DERIVATA
Avocat_Oficiu& Avocat_Oficiu::operator=(const Avocat_Oficiu A_O)
{
    if(this!=&A_O){
        this->Avocat::operator=(A_O);

        nume_client=A_O.nume_client;
        durata=A_O.durata;
    }
    return *this;
}

// DESTRUCTOR - DERIVATA
Avocat_Oficiu::~Avocat_Oficiu(){}

// OPERATORII PENTRU ISTREAM & OSTREAM - DERIVATA
istream& operator>>(istream& in,Avocat_Oficiu& A_O)
{
    in>>dynamic_cast<Avocat&>(A_O);

    bool input_corect=false;
    while(!input_corect)
        try{
            cout<<"Nume client: "; cin>>A_O.nume_client;
            int lungime_nume_client=A_O.nume_client.size(),i;
            for(i=0;i<lungime_nume_client;i++)
                if(!isalpha(A_O.nume_client[i]))throw 1;
            input_corect=true;
        }
        catch(int x){
            cout<<"Numele clientului introdus este invalid! Mai incercati o data!"<<endl;
        }

    input_corect=false;
    while(!input_corect)
        try{
            cout<<"Durata: ";
            cin>>A_O.durata;
            if(A_O.durata<=0)throw 1;
            else input_corect=true;
        }
        catch(int x){
            cout<<"Durata introdusa este invalida! Mai incercati o data!"<<endl;
        }
    return in;
}
ostream& operator<<(ostream& out,const Avocat_Oficiu& A_O)
{
    out<<dynamic_cast<const Avocat&>(A_O);

    cout<<"Nume client: "; out<<A_O.nume_client;
    cout<<"Durata: "; out<<A_O.durata;
    return out;
}

// CITIRE & AFISARE PRIN FUNCTIE VIRTUALA
void Avocat_Oficiu::citire()
{
    Avocat::citire();

    bool input_corect=false;
    while(!input_corect)
        try{
            cout<<"Nume client: "; cin>>nume_client;
            int lungime_nume_client=nume_client.size(),i;
            for(i=0;i<lungime_nume_client;i++)
                if(!isalpha(nume_client[i]))throw 1;
            input_corect=true;
        }
        catch(int x){
            cout<<"Numele clientului introdus este invalid! Mai incercati o data!"<<endl;
        }

    input_corect=false;
    while(!input_corect)
        try{
            cout<<"Durata: ";
            cin>>durata;
            if(durata<=0)throw 1;
            else input_corect=true;
        }
        catch(int x){
            cout<<"Durata introdusa este invalida! Mai incercati o data!"<<endl;
        }
}
void Avocat_Oficiu::afis()
{
    Avocat::afis();
    cout<<"Nume client: "<<nume_client<<endl;
    cout<<"Durata: "<<durata;
}