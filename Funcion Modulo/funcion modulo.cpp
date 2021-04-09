#include <iostream>
#include "Operador.h"

using namespace std;

void Operador::modulo(int a, int b){
	c = a / b;
	d = c / 10;
	
	cout << "El residuo de: "<< a << " y " << b<< " es: " << d;
}

int main(){
	
	int a, b;
	cout << "Ingrese el valor de a: "; cin >> a;
	cout << "Ingrese el valor de b: "; cin >> b;
	
	Operador mod;
	mod.modulo(a,b);
	
	return 0;
}
