#ifndef RAILFENCE_H
#define RAILFENCE_H

#include <iostream>

using namespace std;

class RailFence{    
	public:
		string cifrado(int clave, string &mensaje);   //Funci�n miembro de cifrado
		string corte(string &str, int ini, int fin);  //Funci�n miembro de partici�n
		string descifrado(int clave, string &mensaje);  //Funci�n miembro de descifrado
		
};

class Emisor:RailFence{   //Clase Emisor que hereda de la clase RailFence
	private:
		int clave;
	public:
		Emisor(int clv);   //Constructor
		string EmitirMsg(string mensaje);
		string RecibirMsg(string mensaje);   //Funci�n miembro
};

class Receptor:RailFence{  //Clase Receptor que hereda de la clase RailFence
	private:
		int clave;  //Variable Privada
	public:
		Receptor(int clv);   //Constructor
		string EmitirMsg(string &mensaje);  //Funcion miembro
		void RecibirMsg(string &mensaje);
};

#endif
