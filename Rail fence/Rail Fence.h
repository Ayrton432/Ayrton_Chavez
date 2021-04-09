#ifndef RAILFENCE_H
#define RAILFENCE_H

#include <iostream>

using namespace std;

class RailFence{    
	public:
		string cifrado(int clave, string &mensaje);   //Función miembro de cifrado
		string corte(string &str, int ini, int fin);  //Función miembro de partición
		string descifrado(int clave, string &mensaje);  //Función miembro de descifrado
		
};

class Emisor:RailFence{   //Clase Emisor que hereda de la clase RailFence
	private:
		int clave;
	public:
		Emisor(int clv);   //Constructor
		string EmitirMsg(string mensaje);   //Función miembro
};

class Receptor:RailFence{  //Clase Receptor que hereda de la clase RailFence
	private:
		int clave;  //Variable Privada
	public:
		Receptor(int clv);   //Constructor
		void RecibirMsg(string &mensaje);  //Funcion miembro
};

#endif
