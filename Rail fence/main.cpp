#include <iostream>
#include "Rail Fence.h"
#include "Rail Fence.cpp"

using namespace std;

int main() {
	int clave = 5;   //Declaración de la clave
	Emisor emisor(clave);   //Crea la variable emisor a partir de la clase Emisor
	Receptor receptor(clave);   //Crea la variable receptor a partir de la clase Receptor

	string MensajeCifrado = emisor.EmitirMsg("Las palomas vuelan mas rapido en verano que en invierno");   //Mensaje original
	cout << MensajeCifrado << endl;
	receptor.RecibirMsg(MensajeCifrado);  //Llamado de la función miembro de Receptor
	
	return 0;
}

//To decrypt, all one must do is wrap the leather strip around the rod and read across

//Lmaa qnaoalnrpnv uivslse  ieeoe io a umsd rn nenpvaoaer
//Las palomas son mas rapidas cuendo vuelan en verano que en invierno
