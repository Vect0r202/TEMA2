
#include "Avocat.h"
Avocat::Avocat(){}

// CONSTRUCTOR PARAMETRIZAT
Avocat::Avocat(int C,string N,int NR_P)
{
    cod=C;
    nume=N;

    try{
        vector_procese=new int[NR_P];
    }
    catch (bad_alloc xa){
        cout<<"Numarul de procese introdus este invalid! Mai incercati o data!"<<endl;
        exit(EXIT_FAILURE);
    }

    nr_procese=NR_P;
}

// CONSTRUCTOR DE COPIERE
Avocat::Avocat(const Avocat& A)
{
    cod=A.cod;
    nume=A.nume;

    try{
        vector_procese=new int[A.nr_procese];
    }
    catch (bad_alloc xa){
        cout<<"Numarul de procese introdus este invalid! Mai incercati o data!"<<endl;
        exit(EXIT_FAILURE);
    }

    nr_procese=A.nr_procese;
    for(int i=0;i<nr_procese;i++)
        vector_procese[i]=A.vector_procese[i];
}

// OPERATOR DE ATRIBUIRE
Avocat& Avocat::operator=(const Avocat A)
{
    if(this!=&A){
        cod=A.cod;
        nume=A.nume;
        vector_procese=new int[A.nr_procese];
        nr_procese=A.nr_procese;
        for(int i=0;i<nr_procese;i++)
            vector_procese[i]=A.vector_procese[i];
    }
    return *this;
}

// DESTRUCTOR
Avocat::~Avocat()
{
    delete[] vector_procese;
}

// OPERATORII PENTRU ISTREAM & OSTREAM
istream& operator>>(istream& in,Avocat& A)
{
    bool input_corect=false;
    while(!input_corect)
        try{
            cout<<"Codul avocatului: ";
            in>>A.cod;
            if(A.cod<0)throw 1;
            else input_corect=true;
        }
        catch(int x){
            cout<<"Codul avocatului introdus este invalid! Mai incercati o data!"<<endl;
        }

    input_corect=false;
    while(!input_corect)
        try{
            cout<<"Numele avocatului: "; in>>A.nume;
            int lungime_nume=(A.nume).size(),i;
            for(i=0;i<lungime_nume;i++)
                if(!isalpha(A.nume[i]))throw 1;
            input_corect=true;
        }
        catch(int x){
            cout<<"Numele avocatului introdus este invalid! Mai incercati o data!"<<endl;
        }

    input_corect=false;
    while(!input_corect)
        try{
            cout<<"Numarul de procese ale avocatului: ";
            in>>A.nr_procese;
            if(A.nr_procese<=0)throw 1;
            else input_corect=true;
        }
        catch(int x){
            cout<<"Numarul de procese introdus este invalid! Mai incercati o data!"<<endl;
        }

    try{
        A.vector_procese=new int[A.nr_procese];
    }
    catch (bad_alloc xa){
        cout<<"Numarul de procese introdus este invalid! Mai incercati o data!"<<endl;
        exit(EXIT_FAILURE);
    }

    for(int i=0;i<A.nr_procese;i++){
        input_corect=false;
        while(!input_corect)
            try{
                cout<<"Suma primita pentru procesul "<<i+1<<": ";
                cin>>A.vector_procese[i];
                if(A.vector_procese[i]<=0)throw 1;
                else input_corect=true;
            }
            catch(int x){
                cout<<"Suma introdusa pentru procesul "<<i+1<<" este invalida! Mai incercati o data!"<<endl;
            }
    }
    return in;
}
ostream& operator<<(ostream& out,const Avocat& A)
{
    cout<<"Codul avocatului: "; out<<A.cod<<endl;
    cout<<"Numele avocatului: "; out<<A.nume<<endl;
    cout<<"Numarul de procese ale avocatului: "; out<<A.nr_procese<<endl;
    for(int i=0;i<A.nr_procese;i++){
        cout<<"Suma primita pentru procesul "<<i+1<<": ";
        out<<A.vector_procese[i]<<endl;
    }
    return out;
}

// AFISARE PRIN FUNCTIE VIRTUALA
void Avocat::citire()
{
    bool input_corect=false;
    while(!input_corect)
        try{
            cout<<"Codul avocatului: "; cin>>cod;
            if(cod<0)throw 1;
            else input_corect=true;
        }
        catch(int x){
            cout<<"Codul avocatului introdus este invalid! Mai incercati o data!"<<endl;
        }

    input_corect=false;
    while(!input_corect)
        try{
            cout<<"Numele avocatului: "; cin>>nume;
            int lungime_nume=nume.size(),i;
            for(i=0;i<lungime_nume;i++)
                if(!isalpha(nume[i]))throw 1;
            input_corect=true;
        }
        catch(int x){
            cout<<"Numele avocatului introdus este invalid! Mai incercati o data!"<<endl;
        }

    input_corect=false;
    while(!input_corect)
        try{
            cout<<"Numarul de procese ale avocatului: ";
            cin>>nr_procese;
            if(nr_procese<=0)throw 1;
            else input_corect=true;
        }
        catch(int x){
            cout<<"Numarul de procese introdus este invalid! Mai incercati o data!"<<endl;
        }

    try{
        vector_procese=new int[nr_procese];
    }
    catch (bad_alloc xa){
        cout<<"Numarul de procese introdus este invalid! Mai incercati o data!"<<endl;
        exit(EXIT_FAILURE);
    }

    for(int i=0;i<nr_procese;i++){
        input_corect=false;
        while(!input_corect)
            try{
                cout<<"Suma primita pentru procesul "<<i+1<<": ";
                cin>>vector_procese[i];
                if(vector_procese[i]<=0)throw 1;
                else input_corect=true;
            }
            catch(int x){
                cout<<"Suma introdusa pentru procesul "<<i+1<<" este invalida! Mai incercati o data!"<<endl;
            }
    }
}
void Avocat::afis()
{
    cout<<"Codul avocatului: "<<cod<<endl;
    cout<<"Numele avocatului: "<<nume<<endl;
    cout<<"Numarul de procese ale avocatului: "<<nr_procese<<endl;
    for(int i=0;i<nr_procese;i++){
        cout<<"Suma primita pentru procesul "<<i+1<<": ";
        cout<<vector_procese[i]<<endl;
    }
}

// OPERATOR > & <
int Avocat::operator>(Avocat A)
{
    if(nr_procese>A.nr_procese)return 1;
    return 0;
}
int Avocat::operator<(Avocat A)
{
    if(nr_procese<A.nr_procese)return 1;
    return 0;
}