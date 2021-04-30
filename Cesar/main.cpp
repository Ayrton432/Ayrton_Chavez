#include <iostream>
#include "Cesar.h"
#include "Cesar.cpp"

using namespace std;

int main() {
	int clave;
	Emisor emisor(clave);
	Receptor receptor(clave);
	
	string msg;
	cout << "Ingrese el mensaje a cifrar o descifrar: ";
	getline(cin, msg);
	
	cout << "Si va a vulnerar el algoritmo, ingrese el 0: " << endl;
	cout << "Ingrese la clave: " << endl;
	cin >> clave;
	
	int n;

	if(clave != 0){
		cout << "Ingrese 1 si quiere cifrar el mensaje, si quiere desencriptar el 2: " << endl;
		cin >> n;
		if(n == 1) {
		emisor.cifrado(msg, clave);
		}
		else if(n == 2){
			receptor.descifrado(msg, clave);
		}
	}
	else{
		string mensaje_c;

		cout << "Ingrese el 3 para vulnerar el algoritmo:" << endl;
		cin >> n;
		if(n == 3){
			vulnerar_algoritmo(mensaje_c);
			mensaje_c = receptor.descifrado(msg, clave);
		}
	}
}

//Prueba  Las palomas vuelan más rapido, en verano que en invierno.  clave 4
//Encriptada  Ti5h2it1ui5h51vhuá5h4i2qli5,hmvh8m4iv1h37mhmvhqv8qm4v1H

//rjsyfojehnkxfitehtsehjyfxe1yfsiteqfehqf2je ejsejqeh1xyteijefqljgxfefgyzxfhzf  clave 5    Dayevska
//mentaje cifsado con cetas 1tando la cla2e   en el c1sto de algebsa abtusacua

//mtqfev1jezfq clave     Rodrigo Aranzaens
//
