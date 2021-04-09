#include <iostream>
#include "Rail Fence.h"
#include "Rail Fence.cpp"

using namespace std;

int main() {
	int clave = 6;   //Declaración de la clave
	Emisor emisor(clave);   //Crea la variable emisor a partir de la clase Emisor
	Receptor receptor(clave);   //Crea la variable receptor a partir de la clase Receptor

	string MsgCifrado = emisor.EmitirMsg("To decrypt, all one must do is wrap the leather strip around the rod and read across");   //Mensaje original
	cout << MsgCifrado << endl;
	receptor.RecibirMsg(MsgCifrado);  //Llamado de la función miembro de Receptor

	return 0;
}

