#include <iostream>
using namespace std;
#include "polinom.h"



int main()
{
    cout<<"Un polinom este o expresie construita dintr-una sau mai multe variabile și constante, folosind doar operatii de adunare, scadere, inmulțire si ridicare la putere constanta pozitiva intreaga.";
    cout<<"O fuctie polinomiala este definita astfel:"<<endl<<"f:R->R(se poate extinde pe C)"<<endl<<"f=a0+a1*X+...an*X^n, an!=0"<<endl;
    polinom a,b;
    a.citire();
    b.citire();
    a.afisare();
    a.afisare();
    return 0; //programul ruleaza daca se comenteaza functia cmmdc_Euclid de pe linia 659 din fisierul polinom.cpp
}
