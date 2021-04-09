#ifndef ALGORITMOX_H
#define ALGORITMOX_H

#include <iostream>
#include <vector>

using namespace std;

class AlgoritmoX{
	public:
	//Cada uno pedir� la clave y el mensaje(original y cifrado)
		string cifrado(int clave[], string &mensaje);      	      //Funci�n miembro de Cifrado
		string descifrado(int clave[], string &mensaje);          //Funci�n miembro de Descifrado
};

class Emisor{
	public:
		//tama�o del vector(la clave)
		int clave[2];
		Emisor(int clv[]);  		//Constructor de la clase Emisor
};

class Receptor{
	public:
		//tama�o del vector(la clave)
		int clave[2];
		Receptor(int clv[]); 		//Constructor de la clase Receptor
};

#endif
