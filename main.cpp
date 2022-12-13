#include <iostream>
#include <new>
#include <cstdlib>
#include <string.h>
#include <typeinfo>
using namespace std;
#include "Avocat.h"
#include "Avocat_Oficiu.h"
// CONSTRUCTOR DE INITIALIZARE
// CITIREA & AFISAREA A n OBIECTE
void citire_n_obiecte()
{
    int n,i,op;
    Avocat**vector_avocati;

    bool input_corect=false;

    while(!input_corect)
        try{
            cout<<"Introduceti numarul de avocati: "; cin>>n;
            if(n<=0)throw 1;
            else input_corect=true;
        }
        catch(int x){
            cout<<"Numarul de avocati introdus este invalid! Mai incercati o data!"<<endl;
        }

    vector_avocati=new Avocat* [n];

    // CITIREA
    for(i=0;i<n;i++){
        bool input_citire=false;
        while(!input_citire){
            cout<<"Introduceti optiunea de citire: 1 pentru citirea unui avocat sau 2 pentru citirea unui avocat din oficiu";
            cout<<endl<<"Optiunea aleasa: "; cin>>op;
            switch(op)
            {
                case 1:{vector_avocati[i]=new Avocat(); input_citire=true; break;}
                case 2:{vector_avocati[i]=new Avocat_Oficiu(); input_citire=true; break;}
                default:{cout<<"Optiunea introdusa nu este valida! Mai incercati o data!"<<endl;}
            }
        }
        vector_avocati[i]->citire();
    }
    // AFISAREA
    for(i=0;i<n;i++){
        vector_avocati[i]->afis();
        cout<<endl;
    }
}

int main(){
    citire_n_obiecte();
    return 0;
}