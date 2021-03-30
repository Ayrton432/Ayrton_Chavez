#include <iostream>
#include <vector>

#include "AlgoritmoX.h"

using namespace std;

int main() {
	
	int clave[2] = {6, 9};   //Ingresar la clave
	
				//Creacion de variables a partir de las clases
	
	AlgoritmoX algoritmo;       //Creación de la variable algoritmo

	Emisor emisor(clave);       //Creación de la variable emisor
	Receptor receptor(clave);   //Creación de la variable receptor
	
	string mensaje = "To decrypt, all one must do is wrap the leather strip around the rod and read across";  //El mensaje 
	
	string msgCifrado = algoritmo.cifrado(emisor.clave, mensaje);   //Codificación del mensaje original
	
	string msgDescifrado = algoritmo.descifrado(receptor.clave, msgCifrado);   //Decodificación del mensaje luego de ser codificado
	
	cout << "Mensaje Cifrado:\n " << msgCifrado << endl;   //Mostrar el mensaje codificado
	cout << endl;
	cout << "Mensaje Descifrado:\n " << msgDescifrado << endl;   //Mostrar el mensaje descifrado
	return 0;
}

