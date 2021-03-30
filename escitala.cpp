#include <iostream>
#include <vector>

#include "AlgoritmoX.h"

using namespace std;

int main() {
	
	int clave[2] = {6, 9};   //Ingresar la clave
	
				//Creacion de variables a partir de las clases
	
	AlgoritmoX algoritmo;       //Creaci�n de la variable algoritmo

	Emisor emisor(clave);       //Creaci�n de la variable emisor
	Receptor receptor(clave);   //Creaci�n de la variable receptor
	
	string mensaje = "To decrypt, all one must do is wrap the leather strip around the rod and read across";  //El mensaje 
	
	string msgCifrado = algoritmo.cifrado(emisor.clave, mensaje);   //Codificaci�n del mensaje original
	
	string msgDescifrado = algoritmo.descifrado(receptor.clave, msgCifrado);   //Decodificaci�n del mensaje luego de ser codificado
	
	cout << "Mensaje Cifrado:\n " << msgCifrado << endl;   //Mostrar el mensaje codificado
	cout << endl;
	cout << "Mensaje Descifrado:\n " << msgDescifrado << endl;   //Mostrar el mensaje descifrado
	return 0;
}

