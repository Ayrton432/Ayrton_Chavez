#include <iostream>
#include <vector>
#include "AlgoritmoX.h"

//-----------------------------------------------------------------------------

/*  
	Estructuración de las funciones miembro de la clase AlgoritmoX
    y de los constructores de las clases Emisor y Receptor.
*/

string AlgoritmoX::cifrado(int clave[], string &mensaje)
{
	string msg = mensaje;  //Declaración de la variable msg
	
	int msgLength = mensaje.size(); //Obtener el tamaño del mensaje
	string msgCifrado = "";
											//Convertir el mensaje original
	for (int i = 0; i < clave[1]; i++){     
		string aux;                                //Usando indices, podremos obtener la clave;  
		for (int j = 0; j < clave[0]; j++){        //Además tambien crearemos un auxiliar para 
			aux += msg[i + (j * clave[1])];        //la codificación del mensaje original
		}
		msgCifrado += aux;
	}
	return msgCifrado;  //Devolución del mensaje cifrado
}

string AlgoritmoX::descifrado(int clave[], string &mensaje)
{
	string msg = mensaje;  //Declaración de la variable msg
	
	int msgLength = mensaje.size();  //Obtener el tamaño del mensaje
	string msgDescifrado = "";
	
	for (int i = 0; i < clave[0]; i++){				  //Convertir el mensaje cifrado
		string aux;                                   
		for (int j = 0; j < clave[1]; j++){			  //Mediante indices y usando un auxiliar 
			aux += msg[i + (clave[0] * j)];           //podemos descifrar el mensaje previamente cifrado
		}
		msgDescifrado += aux;
	}
	return msgDescifrado;  //Devuelve el mensaje descifrado
}

Emisor::Emisor(int clv[])
{
	clave[0] = clv[0];   //Declaración de los valores del vector
	clave[1] = clv[1];
}

Receptor::Receptor(int clv[])
{
	clave[0] = clv[0];   //Declaración de los valores del vector
	clave[1] = clv[1];
}

