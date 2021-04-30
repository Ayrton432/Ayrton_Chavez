#include <iostream>
#include <string>
#include "Cesar.h"

using namespace std;

Emisor::Emisor(int clv){
	clave = clv;
}

Receptor::Receptor(int clv){
	clave = clv;
}

int Emisor::cifrado(string mensaje, int clave) {
	string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz1234567890-.";
	string AlfaMayus = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz1234567890-.";
	
	int MsgCifrado = mensaje.length();
	for (int i = 0; i < MsgCifrado; i++) {
		for (int j = 0; j < 65; j++) {
			if (mensaje[i] == AlfaMayus[j]) {
				int result = (j + clave) % 65;
				mensaje[i] = AlfaMayus[result];
				break;
			}
		}
		
		for (int j = 0; j < 65; j++) {
			if (mensaje[i] == alfabeto[j]) {
				int result = (j + clave) % 65;
				mensaje[i] = alfabeto[result];
				break;
			}
		}
	}
	cout << mensaje;
	return 1;
}

int Receptor::descifrado(string mensaje, int clave) {
	string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz1234567890-.";
	string AlfaMayus = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz1234567890-.";
	
	int MsgDescifrado = mensaje.length();
	for (int i = 0; i < MsgDescifrado; i++) {
		for (int j = 0; j < 65; j++) {
			if (mensaje[i] == AlfaMayus[j]) {
				int result = (j - clave) % 65;
				mensaje[i] = AlfaMayus[result];
				break;
			}
		}
		
		for (int j = 0; j < 65; j++) {
			if (mensaje[i] == alfabeto[j]) {
				int result = (j - clave) % 65;
				mensaje[i] = alfabeto[result];
				break;
			}
		}
	}
	cout << mensaje;
	return 1;
}

int funcion_modulo(int a, int n) {
    int q, r;
    q = a / n;//hallamos el cociente
    r = a % n;//hallamos el residuo
    while(r < 0)//mientras que el residuo sea negativo
    {
    	q--;//el cociente hallado se reducirá en 1 hasta que el residuo sea positivo
        r = a - (n * q);
    }
    return r;
}

void vulnerar_algoritmo(string texto_cifrado){
	int clave = 0;
	string mensaje_descifrado[65];
	string alfabeto = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz1234567890-.");
	while(clave < 65) {
		string mensaje;
		int aux=0;
		while(aux < texto_cifrado.length()) {
			if(alfabeto.find(texto_cifrado[aux]) < alfabeto.length()) {
				int indice = alfabeto.find(texto_cifrado[aux]);   
				int pos = funcion_modulo((indice + (alfabeto.length() - clave)), alfabeto.length());
				mensaje += alfabeto[pos];
			}
			aux++;
		}
		mensaje_descifrado[clave] = mensaje;
		clave++;
	}
	int i=0;
	cout << "Usando la clave: " << i << endl; 
	cout << "El mensaje es: "<< mensaje_descifrado[i] << endl;
	i++;
}

//Alfabeto minusc  abcdefghijklmnopqrstuvwxyz   26 caracteres
//Alfabeto Mayusc  ABCDEFGHIJKLMNOPQRSTUVWXYZ   26 caracteres
//Alfabeto de la profesora  ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz1234567890-.  65 caracteres
