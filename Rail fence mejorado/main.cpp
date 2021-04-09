#include <iostream>
#include "Rail Fence.h"
#include "Rail Fence.cpp"


using namespace std;

int main() {
	int clave = 6;   //Declaración de la clave
	Emisor emisor(clave);   //Crea la variable emisor a partir de la clase Emisor
	Receptor receptor(clave);   //Crea la variable receptor a partir de la clase Receptor
	
	cout << "Funcion encriptado" << endl;
	print();
	
	string MensajeCifrado = emisor.EmitirMsg("Las palomas vuelan mas rapido en verano que en invierno");
	cout << MensajeCifrado << endl;
	receptor.RecibirMsg(MensajeCifrado);
	
	cout << "Funcion Desencriptado" << endl;
	print();
	
	string MessageCifrado = emisor.RecibirMsg("Asmeni t utaau uadveinemgarrqp   e na.i  g  aetarats epoprrcaetdeemroerir");   //Mensaje original
	cout << MessageCifrado << endl;
	receptor.EmitirMsg(MessageCifrado);  //Llamado de la función miembro de Receptor
	
	
	return 0;
}

//To decrypt, all one must do is wrap the leather strip around the rod and read across

//Las palomas vuelan mas rapido en verano que en invierno : mensaje
//Lmaa qnaoalnrpnv uivslse  ieeoe io a umsd rn nenpvaoaer  :  clave 5
//Lsaeqiaa ms n uvesmv  o oenr ounrdvn inpleaaieae oalprn  :  clave 6

