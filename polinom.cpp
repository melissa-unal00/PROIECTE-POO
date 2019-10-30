#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <math.h>
#include "polinom.h"
using namespace std;

polinom::polinom()  ///constructor de intializare
{
    coef = new double [100];
    for (int i = 0; i <  100; i++)
    {
        coef[i] = 0.0;
    }
    grad = 100;
}

polinom::polinom(int Grad) ///constructor ce initializeaza vectorul de marime Grad
{
    coef = new double[Grad+1];
    for (int i = 0; i <=  Grad; i++)
    {
        coef[i] = 0.0;
    }
    grad = Grad;
}

///constructor de copiere, construieste un polinom nou ce este o copie a unui polinom existent
polinom::polinom(const polinom& apolinom)
{
    coef = new double[apolinom.grad];
    for (int i = 0; i <= apolinom.grad; i++)
    {
        coef[i] = apolinom.coef[i];
    }
    grad = apolinom.grad;
}

polinom::~polinom() ///destructor
{
    delete[] coef;
}

istream& operator>>(istream& in,polinom& ob)
{
    in>>ob.grad;
    ob.coef=new double[ob.grad];
    for(int i=0;i<=ob.grad;i++)
    {
        in>>ob.coef[i];
    }
    return in;
}

ostream& operator<<(ostream& out, polinom& ob)
{
    out<<ob.grad;
    ob.coef=new double[ob.grad];
    for(int i=0;i<=ob.grad;i++)
    {
        out<<ob.coef[i];
    }
    return out;
}

void polinom::n_obiecte(int n)
{
    polinom** obiecte = new polinom*[n];
    for(int i = 0; i < n; ++i)
    {
       obiecte[i] = new polinom[100];
    }
    for(int i=0;i<n;i++)
        {
        obiecte[i]->citire();
        obiecte[i]->afisare();
        }
}

void polinom:: citire()
{
    int gr;
    double c;
    cout<<"De ce grad vrei polinomul?"<<endl;
    cin>>gr;
    grad=gr;
    cout<<"Introdu coeficientii"<<endl;
        for( int i=0;i<=grad;i++)
    {
        cin>>c;
        coef[i]=c;
    }

}

void polinom:: afisare()
{
    for ( int i=0; i<=grad; i++)
        {
             if (coef[i] != 0)
         {
            switch(i)
            {
            case 0:
                cout<<coef[i];
                break;
            case 1:
                cout<<"+"<<coef[i]<<"*x";
                break;
            }
            if(i>=2) cout<<"+"<<coef[i]<<"*x^"<<i;
         }
      }
      cout<<endl;
}

///operator de atribuire
 polinom& polinom::operator= (const polinom& obj)
{
    if (this == &obj){
        return *this;
    }
    polinom temp(obj);
    std::swap(grad, temp.grad);
    std::swap(coef, temp.coef);
    return *this;
}

///returneaza gradul functiei
int polinom::gradul_functiei() const
{
    int gradul_functiei = 0;
    for (int i = 0; i <= this->grad; i++)
    {
        if (coef[i] != 0)
        {
            gradul_functiei = i;
        }
    }
    return gradul_functiei;
}

///inmulteste un polinom cu o constanta
polinom polinom::multiplica_const(double val) const
{
    for (int i = 0; i <= grad; i++)
    {
        this->coef[i] = this->coef[i] * val;
    }
    return *this;
}

///returneaza coeficientul de pe pozitia i
double polinom::recupereaza_coef(int i) const
{
    if (0 <= i)
    {
        return coef[i];
    }
    else if (i >= grad)
    {
        return 0.0;
    }
}

///valoarea polinomului intr-un punct
double polinom::operator()(double x) const
{
    double polinomTotal = 0.0;
    double coef = 0.0;
    for (int i = 0; i <=  grad; i++)
    {
        coef = recupereaza_coef((int) i);
        polinomTotal += (coef * pow(x, (double)i));
    }
    return polinomTotal;
}

///intoarce valoarea de pe pozitia i
double polinom:: operator[](int i) {
            return coef[i];
         }

///face trecerea dintr-un numar real intr-un polinom de grad 0
polinom polinom::real_to_polinom(double val) const
{
    polinom p;
    p.grad=0;
    p.coef=new double[p.grad];
    p.coef[0]=val;
    return p;
}

///adunarea a doua polinoame
const polinom operator+ (const polinom& p1,const polinom& p2)
{
    polinom suma;
    if(p1.grad<p2.grad) suma.grad=p2.grad;
    else suma.grad=p1.grad;
    suma.coef=new double[suma.grad];
    for(int i=0; i<=suma.grad;i++)
    {
        suma.coef[i]=p1.coef[i]+p2.coef[i];
    }
    return suma;
}

const polinom operator+ (double nr,const polinom& p2)
{
    polinom p;
    p=p.real_to_polinom(nr);
    polinom suma;
    suma.grad=p2.grad;
    suma.coef=new double[suma.grad];
    suma=p+p2;
    return suma;
}

const polinom operator+ (const polinom& p1,double nr)
{
    polinom p;
    p=p.real_to_polinom(nr);
    polinom suma;
    suma.grad=p1.grad;
    suma.coef=new double[suma.grad];
    suma=p1+p;
    return suma;
}

///operatorul unar, returneaza suma unui polinom cu el insusi
const polinom operator+ (const polinom& p)
{
    polinom suma;
    suma.grad=p.grad;
    suma.coef=new double[suma.grad];
    suma=p+p;
    return suma;
}

const polinom operator+= (const polinom& p1,const polinom& p2)
{
    int grad;
    if(p1.grad>p2.grad) grad=p1.grad;
    else grad=p2.grad;
    for(int i=0; i<=grad;i++)
    {
        p1.coef[i]=p1.coef[i]+p2.coef[i];
    }
    return p1;
}

const polinom operator+= (double nr,const polinom& p2)
{
    polinom p;
    p=p.real_to_polinom(nr);
    for(int i=0; i<=p2.grad;i++)
    {
        p.coef[i]=p.coef[i]+p2.coef[i];
    }
    return p;
}

const polinom operator+= (const polinom& p1,double nr)
{
    polinom p;
    p=p.real_to_polinom(nr);
      for(int i=0; i<=p1.grad;i++)
    {
        p1.coef[i]=p1.coef[i]+p.coef[i];
    }
    return p1;
}


///diferenta a doua polinoame
const polinom operator- (const polinom& p1,const polinom& p2)
{
    polinom diferenta;
    if(p1.grad<p2.grad) diferenta.grad=p2.grad;
    else diferenta.grad=p1.grad;
    diferenta.coef=new double[diferenta.grad];
    for(int i=0; i<=diferenta.grad;i++)
    {
        diferenta.coef[i]=p1.coef[i]-p2.coef[i];
    }
    return diferenta;
}

const polinom operator- (double nr,const polinom& p2)
{
    polinom p;
    p=p.real_to_polinom(nr);
    polinom diferenta;
    diferenta.grad=p2.grad;
    diferenta.coef=new double[diferenta.grad];
    diferenta=p-p2;
    return diferenta;
}

const polinom operator- (const polinom& p1,double nr)
{
    polinom p;
    p=p.real_to_polinom(nr);
    polinom diferenta;
    diferenta.grad=p1.grad;
    diferenta.coef=new double[diferenta.grad];
    diferenta=p1-p;
    return diferenta;
}

///operator unar, opusul unui polinom
const polinom operator- (const polinom& p)
{
    p.multiplica_const(-1);
    return p;
}

const polinom operator-= (const polinom& p1,const polinom& p2)
{
    int grad;
    if(p1.grad>p2.grad) grad=p1.grad;
    else grad=p2.grad;
    for(int i=0; i<=grad;i++)
    {
        p1.coef[i]=p1.coef[i]-p2.coef[i];
    }
    return p1;
}

const polinom operator-= (double nr,const polinom& p2)
{
    polinom p;
    p=p.real_to_polinom(nr);
    for(int i=0; i<=p2.grad;i++)
    {
        p.coef[i]=p.coef[i]-p2.coef[i];
    }
    return p;
}

const polinom operator-= (const polinom& p1,double nr)
{
    polinom p;
    p=p.real_to_polinom(nr);
      for(int i=0; i<=p1.grad;i++)
    {
        p1.coef[i]=p1.coef[i]-p.coef[i];
    }
    return p1;
}

///inmultirea a doua polinoame
const polinom operator* (const polinom& p1,const polinom& p2)
{
    polinom temp=p2; ///copie pentru a nu fi modificat p2
    polinom inmultire;
    inmultire.grad=p1.grad+p2.grad;
    inmultire.coef=new double[inmultire.grad];

     for (int i = 0; i <=  inmultire.grad; i++)
    {
        inmultire.coef[i] = 0.0;
    }
    for(int i=0; i<=p1.grad;i++) ///consideram ca p2 a fost dat factor comun si desfacem paranteza
    {                            ///facem o suma alcatuita din fiecare element al lui p1 inmultit cu polinomul p2
        double val=p1.coef[i];
        temp.multiplica_const(val); ///inmultim p2 cu coeficientul unui termen din p1

        if(i>0) for(int j=p2.grad;j>=0;j--)
        {
            temp.coef[j+p1.grad]=temp.coef[j]; ///"inmultirea" cu x^p se face prin mutarea la dreapta a tuturor elementelor cu p pozitii
        }                                      //p este o putere
       if(i>0) for(int k=p1.grad-1;k>=0;k--)
        {
            temp.coef[k]=0.0;         ///initializam cu 0 primele p elemente petru a termina mutarea tuturor elementelor cu p pozitii
        }
    inmultire= inmultire+temp; ///adunam termenul sumei la rezultatul partial
    }
    return inmultire;
}

const polinom operator* (double nr,const polinom& p2)
{
    polinom inmultire;
    inmultire.grad=p2.grad;
    inmultire.coef=new double[inmultire.grad];
    inmultire=p2.multiplica_const(nr);
    return inmultire;
}

const polinom operator* (const polinom& p1,double nr)
{
    polinom inmultire;
    inmultire.grad=p1.grad;
    inmultire.coef=new double[inmultire.grad];
    inmultire=p1.multiplica_const(nr);
    return inmultire;
}


const polinom operator*= ( polinom& p1,const polinom& p2)
{
    p1=p1*p2;
    return p1;
}

const polinom operator*= (double nr,const polinom& p2)
{
    polinom p;
    p=p.real_to_polinom(nr);
    polinom inmultire;
    inmultire.grad=p2.grad;
    inmultire.coef=new double[inmultire.grad];
    inmultire=p2.multiplica_const(nr);
    p=inmultire;
    return p;
}

const polinom operator*= (const polinom& p1,double nr)
{
    polinom p;
    p=p.real_to_polinom(nr);
    polinom inmultire;
    inmultire.grad=p1.grad;
    inmultire.coef=new double[inmultire.grad];
    inmultire=p1.multiplica_const(nr);
    p=inmultire;
    return p;
}

///ridicarea la putere
const polinom operator^ (const polinom& p, int putere)
{
    polinom ridicare_putere;
    ridicare_putere.grad=pow(p.grad,putere);
    ridicare_putere.coef=new double[ridicare_putere.grad];
     for (int i = 0; i <=  ridicare_putere.grad; i++)
    {
        ridicare_putere.coef[i] = 0.0;
    }
    for (int i=2;i<=putere;i++)
    {

        ridicare_putere=p*p;
    }
    return ridicare_putere;
}

///impartirea a doua polinoame
///p1 este polinomul cu gradul mai mare
///temp 1 este o copie a polinomului p1 pt ca acesta sa nu fie modificat
const polinom operator/ (const polinom& p1,const polinom& p2)
{
    if(p1.grad<p2.grad)
    {
        cout<<"Nu este posibil!";
        return 0;
    }
    polinom temp1;
    polinom temp2;
    polinom temp3;
    temp1.grad=p1.grad;
    temp2.grad=p1.grad;
    temp3.grad=p1.grad;
    temp1.coef=new double[temp2.grad];
    temp2.coef=new double[temp2.grad];
    temp3.coef=new double[temp3.grad];
    for (int i = 0; i <=  p1.grad; i++)
    {
        temp1.coef[i] = 0.0;
    }
    for (int i = 0; i <=  p1.grad; i++)
    {
        temp2.coef[i] = 0.0;
    }
    for (int i = 0; i <=  p1.grad; i++)
    {
        temp3.coef[i] = 0.0;
    }
    temp1=p1;
    while(temp1.gradul_functiei()>=p2.grad)
    {
        int x=temp1.gradul_functiei()-p2.grad; ///x este pozitia/gradul unui termen din cat
        double y=temp1.coef[temp1.gradul_functiei()]/p2.coef[p2.grad]; ///valoarea termenului de pe pozitia x din cat
        temp2.coef[x]=y;
        temp3=p2*temp2; ///temp 3 este polinomul care va fi scazut din deimpartit pentru a se afla resturile
        temp1=temp1-temp3; ///temp1 va deveni restul la fiecare impartire cu polinomul p2

    }

        return temp2; ///rezultatul imparitii polinoamelor
}

const polinom operator/ (double nr,const polinom& p2)
{

    polinom p;
    p=p.real_to_polinom(nr);
    if(p2.grad>0)
    {
        cout<<"Nu este posibil!";
        return 0;
    }
    polinom impartire;
    impartire.grad=p2.grad;
    impartire.coef=new double[impartire.grad];
    impartire=p/p2;
    return impartire;
}

const polinom operator/ (const polinom& p1,double nr)
{
    polinom p;
    p=p.real_to_polinom(nr);
    polinom impartire;
    impartire.grad=p1.grad;
    impartire.coef=new double[impartire.grad];
    impartire=p1/p;
    return impartire;
}

const polinom operator/= (polinom& p1,const polinom& p2)
{
    p1=p1+p2;
    return p1;
}

const polinom operator/= (double nr,const polinom& p2)
{
    polinom p;
    p=p.real_to_polinom(nr);
    if(p2.grad>0)
    {
        cout<<"Nu este posibil!";
        return 0;
    }
    polinom impartire;
    impartire.grad=p2.grad;
    impartire.coef=new double[impartire.grad];
    impartire=p/p2;
    p=impartire;
    return p;
}

const polinom operator/= ( polinom& p1,double nr)
{
    polinom p;
    p=p.real_to_polinom(nr);
    polinom impartire;
    impartire.grad=p1.grad;
    impartire.coef=new double[impartire.grad];
    impartire=p1/p;
    p1=impartire;
    return p1;
}

///restul impartirii a doua polinoame
///este programul de la impartirea polinoamelor(explicatii incepand cu linia 4)
const polinom operator% (const polinom& p1,const polinom& p2)
{
    if(p1.grad<p2.grad)
    {
        cout<<"Nu este posibil!";
        return 0;
    }
    polinom temp1=p1;
    polinom temp2;
    polinom temp3;
    temp2.grad=p1.grad;
    temp3.grad=p1.grad;
    temp2.coef=new double[p1.grad];
    temp3.coef=new double[temp3.grad];
     for (int i = 0; i <=  p1.grad; i++)
    {
        temp2.coef[i] = 0.0;
    }
    while(temp1.gradul_functiei()>=p2.grad)
    {
        int x=temp1.gradul_functiei()-p2.grad;
        double y=temp1.coef[temp1.gradul_functiei()]/p2.coef[p2.grad];
        temp2.coef[x]=y;
        temp3=p2*temp2;
        temp1=temp1-temp3;
    }
    return temp1; ///returzeaza ultimul rest
}

///returneaza true daca doua polinoame sunt egale, false daca nu sunt
///ma voi folosi de aceasta functie pentru supraincarcarea operatorilor == si !=
const bool egal(const polinom& p1,const polinom&p2)
{
    if (p1.grad != p2.grad)
    {
        return(false);
    }
    for (int i=0; i< p1.grad; i++)
    {
        if (p1.coef[i] != p2.coef[i])
        {
            return (false);
        }
    }
    return (true);
}

///verifica egalitatea
const bool operator== (const polinom&p1,const polinom&p2)
{
    return egal(p1,p2);
}

const bool operator== (double nr,const polinom&p2)
{
    polinom p;
    p=p.real_to_polinom(nr);
    return egal(p,p2);

}

const bool operator== (const polinom&p1,double nr)
{
    polinom p;
    p=p.real_to_polinom(nr);
    return egal(p1,p);
}

///verifica inegalitatea
const bool operator!= (const polinom&p1,const polinom&p2)
{
    return !egal(p1,p2);
}

const bool operator!= (double nr,const polinom&p2)
{
    polinom p;
    p=p.real_to_polinom(nr);
    return !egal(p,p2);

}

const bool operator!= (const polinom&p1,double nr)
{
    polinom p;
    p=p.real_to_polinom(nr);
    return !egal(p1,p);
}

///daca polinomul este nul intoarce 0, altfel 1
const bool operator! (const polinom&p)
{
   if(p.gradul_functiei()==0&&p.coef[0]==0) return 0;
   return 1;
}

///asemanator cu impartirea polinoamelor
///cel mai mare divizor comun este ultimul rest nenul al impartirii
//daca comentati aceasta functie programul va rula
 void cmmdc_Euclid (const polinom& p1,const polinom& p2)
{
    polinom p;
    p=p.real_to_polinom(0);
    if(p1%p2!=p)
    {
        cout<<"Au divizor comun 1";
        return;
    }
    polinom temp1=p1;
    polinom temp2;
    polinom temp3;
    temp2.grad=p1.grad;
    temp3.grad=p1.grad;
    temp2.coef=new double[p1.grad];
    temp3.coef=new double[temp3.grad];
     for (int i = 0; i <=  p1.grad; i++)
    {
        temp2.coef[i] = 0.0;
    }
    while(1)
    {
        int x=temp1.gradul_functiei()-p2.grad;
        double y=temp1.coef[temp1.gradul_functiei()]/p2.coef[p2.grad];
        temp2.coef[x]=y;
        temp3=p2*temp2;
        if(temp1==temp3) return temp1;
        }
}

