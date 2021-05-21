#include <iostream>
#include <time.h> 
#include <math.h>
//#include "Funciones Matematicas.cpp"

using namespace std;

class RSA{
	private:
		int p = 25;
		int q = 16;
		int d = 0;
	public:
		int N = 0;
		int fi_N = 0;
		int e = 0;	
		RSA(){};
    void clave_p();
		void clave_q();
		void getN();
		void getFi_N();
		void getE();
		int inverse(int a);
		int calcular(int num, int m);
    int cifrado(int num);
    int descifrado(int num);
};
/*
class Emisor:RSA{
  private:
		int p = 25;
		int q = 16;
    int d = 0;
	public:
    void clave_p();
    void clave_q();
    int inverse(int a);
		int cifrado(int num);
};

class Receptor:RSA{
  private:
		int d = 0;
	public:
    //int inverse(int a);
		int descifrado(int numCifrado);
};
*/
int Euclides(int r1, int r2);
int euclides_extendido(int a, int b);
int modulo(int a, int n);

//Para archivo RSA.cpp 
void RSA::clave_p(){
	int a = 0;
  int es = 0;
  srand(time(NULL));
  while(es == 0) {
		a = rand() % (50 + 1);
		for(int aux = 2; aux < 10; aux++) {
      es = (a % aux);
      if(a % aux == 0){
        es = (a % aux);
        break;
      }
    }
  }
  p = a;
}

void RSA::clave_q(){
  int b = 0;
  int es = 0;
  srand(time(NULL));
  while(es == 0 || b == p){
    b = rand() % (55 + 1);
    for(int aux = 2; aux < 10; aux++) {
      es = (b % aux);
      if(b % aux == 0){
        es = (b % aux);
        break;
      }
    }
  }
  q = b;
}
/*
void Emisor::clave_p(){
	int a = 0;
  int es = 0;
  srand(time(NULL));
  while(es == 0) {
		a = rand() % (50 + 1);
		for(int aux = 2; aux < 10; aux++) {
      es = (a % aux);
      if(a % aux == 0){
        es = (a % aux);
        break;
      }
    }
  }
  p = a;
}

void Emisor::clave_q(){
  int b = 0;
  int es = 0;
  srand(time(NULL));
  while(es == 0 || b == p){
    b = rand() % (55 + 1);
    for(int aux = 2; aux < 10; aux++) {
      es = (b % aux);
      if(b % aux == 0){
        es = (b % aux);
        break;
      }
    }
  }
  q = b;
}
*/
void RSA::getN(){
  N = p * q;
}

void RSA::getFi_N(){
  fi_N = (p - 1) * (q - 1);
}

void RSA::getE() {
  int aux = 0;
  int rpta = 0;
  while(rpta != 1) {
    int aux = rand() % (fi_N + 1);
    rpta = Euclides(aux, fi_N);
    e = aux;
  }
}

int RSA::inverse(int a) {
  int mcd = Euclides(a, fi_N);
  int x = euclides_extendido(a, fi_N);
  if(mcd == 1){
    if(x < 0){
       return modulo(x, fi_N);
    }
    return x;
  }
  return 1;
}

/*
int Emisor::inverse(int a) {
  int mcd = Euclides(a, fi_N);
  int x = euclides_extendido(a, fi_N);
  if(mcd == 1){
    if(x < 0){
       return modulo(x, fi_N);
    }
    return x;
  }
  return 1;
}
*/
int RSA::calcular(int num, int m){
  int n = m;
  int rptaMod = num;
  int alCuadrado = num;
  int aux = 1;
  while(aux < m){
    if (aux > 1){
      int potencia = pow(alCuadrado,2);
      alCuadrado = modulo(potencia, N);
    }
    int mod = modulo(n, 2);
    if(mod == 1 && aux > 1){
      int multi = rptaMod * alCuadrado;
      rptaMod = modulo(multi, N);
    }
    n = n / 2;
    aux = aux * 2;
  }
  return rptaMod;
}

int RSA::cifrado(int num){
  int msjCifrado = 0;
  clave_p();
  cout<<"clave p: "<< p <<endl;

  clave_q();
  cout<<"clave q: "<< q <<endl;

  getN();
  cout<<"N: "<< N <<endl;
  getFi_N();
  cout<<"fi_N: "<< fi_N <<endl;

  getE();
  cout<<"e: "<< e << endl;

  d = inverse(e);
  cout << "d: " << d << endl;
  msjCifrado = calcular(num, e);
  return msjCifrado;
}

int RSA::descifrado(int numCifrado){
  int indice = numCifrado;
  int msjDescifrado = calcular(indice,d);
  return msjDescifrado;
}

int Euclides(int r1, int r2) {
	int r;
	while (r2 > 0) {
		int q; 
		q = r1 / r2;	
		if (r1 >= 0) { 
			r = r1 - q*r2; 
		}
		else { 
			r = r1 - (q-1)*r2; 
		}
		r1 = r2; 
		r2 = r;
	}
	return r1;
}

int euclides_extendido(int a, int b){
	int s,t;
	int s_a = 1;
	int s_b = 0;
	int t_a = 0;
	int t_b = 1;
	while(b > 0){
		int q = a/b;
    int r = a-q*b;
    a = b;
    b = r;
    s = s_a - q * s_b;
    s_a = s_b;
    s_b = s;
    t = t_a - q * t_b;
    t_a = t_b;
    t_b = t;
	}
	s = s_a;
	t = t_a;
	return s;
}

int modulo(int a, int n) {
  int q, r;
  q = a / n;//hallamos el cociente
  r = a % n;//hallamos el residuo
  while(r < 0) {//mientras que el residuo sea negativo
    q--;//el cociente hallado se reducir? en 1 hasta que el residuo sea positivo
    r = a - (n * q);
  }
  return r;
}
