#ifndef ALGORITMOX_H
#define ALGORITMOX_H

#include <iostream>
#include <vector>

using namespace std;

class AlgoritmoX{
	public:
	//Cada uno pedirá la clave y el mensaje(original y cifrado)
		string cifrado(int clave[], string &mensaje);      	      //Función miembro de Cifrado
		string descifrado(int clave[], string &mensaje);          //Función miembro de Descifrado
};

class Emisor{
	public:
		//tamaño del vector(la clave)
		int clave[2];
		Emisor(int clv[]);  		//Constructor de la clase Emisor
};

class Receptor{
	public:
		//tamaño del vector(la clave)
		int clave[2];
		Receptor(int clv[]); 		//Constructor de la clase Receptor
};

#endif
