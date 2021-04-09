#include <iostream>
#include "Rail Fence.h"
using namespace std;

//--------------------------------------------------------------------------------------------------------------

string RailFence::cifrado(int clave, string &mensaje){
	unsigned size = mensaje.size();
	string MsgCifrado = "";
	// Indica la distancia entre los elementos en la fila sin contar los que están en diagonal
	const int interval = (2 * (clave - 1));
	for (int i = 0; i < clave; i++){
		bool flag = false;
		string aux = "";
		// Número de elementos en la fila ubicados en la primera etapa
		int rowLimit = 1 + ((size - 1 - i) / interval);
		// Indica si hay al menos un elemento en la otra etapa del algoritmo o si se encuentra lejos del borde
		if ((i != 0 && i != clave - 1) && size > interval - i){
			rowLimit += 1 + ((size - 1 - (interval - i)) / interval);
			flag = true;
		}

		// Muestra el número máximo que tenemos en las filas
		for (int j = 0; j < rowLimit; j++){
			if (flag && (j % 2 == 1)) // El otro fragmento
				aux += mensaje[i + (interval * (j / 2)) + interval - (2 * i)];
			else // main susecion
			{
				if (flag)
					aux += mensaje[i + (interval * j / 2)]; //Analiza el indice
				else
					aux += mensaje[i + (interval * j)];
			}
		}
		MsgCifrado += aux;
	}
	return MsgCifrado;
}
string RailFence::corte(string &str, int ini, int fin){
	string StrCorte = "";
	for (int i = ini; i < fin; i++)
		StrCorte += str[i];
	return StrCorte;
}

string RailFence::descifrado(int clave, string &mensaje){
	unsigned size = mensaje.size();
	string MsgDescifrado = "";
	// Vamos a recortar la cadena principal
	string aux[clave];   // Los almacenará aquí.
	// Indica la distancia entre los elementos en la fila sin contar los que están en diagonal
	const int interval = (2 * (clave - 1));
	unsigned ini = 0;
	unsigned fin = 0;
	// Busca el final de cada sección y los corta.
	for (int i = 0; i < clave; i++){
		fin += 1 + ((size - 1 - i) / interval);
		if ((i != 0) && (i != clave))
			fin += 1 + (((size - 1 - i) - (interval - (2 * i))) / interval);
		aux[i] = corte(mensaje, ini, fin);
		ini = fin;
	}
	// Aquí no es necesario tener los límites de cada fragmento.
	int counters[clave];
	for (int i = 0; i < clave; i++)
		counters[i] = 0;
	unsigned counter = 0; // Se iguala a 0 por ser el tamaño del mensaje.
	bool breaker = false; // Podemos acceder al límite por medio de un for deteniendo a su vez el bucle
	while (counter < size + 1)
	{
		// Primer grupo
		MsgDescifrado += aux[0][counters[0]];
		counters[0]++;
		counter++;
		if (counter == size)
			break;
		for (int i = 1; i < clave - 1; i++){
			MsgDescifrado += aux[i][counters[i]];
			counters[i]++;
			counter++;
			if (counter == size){
				breaker = true;
				break;
			}
		}
		// Punto del grupo medio(el otro borde aparte del inicio)
		if (breaker || (counter == size))
			break;
		MsgDescifrado += aux[clave - 1][counters[clave - 1]];
		counters[clave - 1]++;
		counter++;
		if (counter == size)
			break;

		// El segundo grupo
		for (int i = clave - 2; i > 0; i--){
			MsgDescifrado += aux[i][counters[i]];
			counters[i]++;
			counter++;
			if (counter == size)
			{
				breaker = true;
				break;
			}
		}
		if (breaker || (counter == size))
			break;
	}
	return MsgDescifrado;
}

void print(){
	cout << endl;
}

//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
Emisor::Emisor(int clv){
	clave = clv;  //Declaración de la variable clave
}

string Emisor::EmitirMsg(string mensaje){
	cout << "Mensaje Cifrado: ";
	return cifrado(clave, mensaje);
}

string Emisor::RecibirMsg(string mensaje){
	cout << "Mensaje Descifrado: ";
	return descifrado(clave, mensaje);  //Devuelve el mensaje cifrado
}

Receptor::Receptor(int clv){
	clave = clv;  //Declaración de la variable clave
}
string Receptor::EmitirMsg(string &mensaje){
	cout << "\nMensaje Cifrado: " << cifrado(clave, mensaje) << endl;  //Devuelve el mensaje descifrado
}

void Receptor::RecibirMsg(string &mensaje){
	cout << "\nMensaje Original: " << descifrado(clave, mensaje) << endl;
	print();
	print();
}

