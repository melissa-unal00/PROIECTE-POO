using namespace std;
class polinom
{

private:

  int grad;
  double *coef;

public:
  polinom ();
  polinom (int size);
  polinom (const polinom& apolinom);
  ~polinom ();
  friend istream& operator>>(istream&,polinom&);
  friend ostream& operator<<(ostream&, polinom&);
  void n_obiecte(int n);


  void citire();
  void afisare();
  polinom& operator= (const polinom&);
  int gradul_functiei () const;
  polinom multiplica_const (double val) const;
  double recupereaza_coef (int i) const;
  double operator() (double x) const;
  double operator[](int i);
  polinom real_to_polinom(double val) const;

  const friend polinom operator+ (const polinom&,const polinom&);
  const friend polinom operator+ (double,const polinom&);
  const friend polinom operator+ (const polinom&,double);
  const friend polinom operator+ (const polinom&);
  const friend polinom operator+= ( const polinom&,const polinom&);
  const friend polinom operator+= (double,const polinom&);
  const friend polinom operator+= (const polinom&,double);

  const friend polinom operator- (const polinom&,const polinom&);
  const friend polinom operator- (double,const polinom&);
  const friend polinom operator- (const polinom&,double);
  const friend polinom operator- (const polinom&);
  const friend polinom operator-= (const polinom&,const polinom&);
  const friend polinom operator-= (double,const polinom&);
  const friend polinom operator-= (const polinom&,double);

  const friend polinom operator* (const polinom&,const polinom&);
  const friend polinom operator* (double,const polinom&);
  const friend polinom operator* (const polinom&,double);
  const friend polinom operator*= (const polinom&,const polinom&);
  const friend polinom operator*= (double,const polinom&);
  const friend polinom operator*= (const polinom&,double);

  const friend polinom operator^ (const polinom&,int);

  const friend polinom operator/ (const polinom&,const polinom&);
  const friend polinom operator/ (double,const polinom&);
  const friend polinom operator/ (const polinom&,double);
  const friend polinom operator/= ( polinom&,const polinom&);
  const friend polinom operator/= (double,const polinom&);
  const friend polinom operator/= ( polinom&,double);

  const friend polinom operator% (const polinom&,const polinom&);

  const friend bool egal (const polinom&, const polinom&);
  const friend bool operator== (const polinom&,const polinom&);
  const friend bool operator== (double,const polinom&);
  const friend bool operator== (const polinom&,double);
  const friend bool operator!= (const polinom&,const polinom&);
  const friend bool operator!= (double,const polinom&);
  const friend bool operator!= (const polinom&,double);
  const friend bool operator! (const polinom&);

  void friend cmmdc_Euclid (const polinom&,const polinom&);
};

