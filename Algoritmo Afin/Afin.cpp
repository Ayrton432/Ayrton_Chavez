#include <iostream>
#include <string>
#include <stdlib.h>

#include "Afin.h"
#include "Funciones Matematicas.cpp"

using namespace std;

string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ";

int Alphabet = alfabeto.length();

Afin::Afin(string message){
	this -> message = message;
	MsgCifrado = message;

	int verClaveA;
	do
	{
		claveA = rand() % Alphabet;
		verClaveA = Euclides(claveA, Alphabet);
	}
	while (verClaveA != 1);
	
	claveB = rand() % Alphabet;
	cout << "Clave A: " << claveA << endl;
	cout << "Clave B: " << claveB << endl;
	
	cout << "\nFuncion de Cifrado: " << endl;
	Emisor(message, claveA, claveB);
	
	cout << "Funcion de Descifrado: " << endl;
	Receptor(MsgCifrado, claveA, claveB);	
	
}

int Afin::inverseA(int claveA, int  claveB){
	int d = Euclides(claveA,claveB);
	
	int x = ExtendedEu(claveA,claveB,d,0);
	
	if (x < 0) {   
		int q = x / Alphabet; x = x - (q - 1) * Alphabet; 
	}
	return x;
}

void Afin::Emisor(string message, int claveA, int claveB){
	cout << "EMISOR" << endl;
	for(int i = 0; i < message.length(); i++) { 
		MsgCifrado[i] = ' '; 
	}
	
	cout << "Mensaje Original:\t" << message << endl;
	
	for (int i = 0; i < message.length(); i++) {
		for (int j = 0; j < Alphabet; j++) {
			if (message[i] == alfabeto[j]) {
				int r = claveA * j + claveB; //Operacion matematica Cifrado
				if (r >= Alphabet) { 
					int q = r / Alphabet; 
					r = r - q * Alphabet; 
				}
				MsgCifrado[i] = alfabeto[r];
			}
		}
	}
	
	cout << "Mensaje Cifrado:\t" << MsgCifrado << endl;
	cout << endl;
}

void Afin::Receptor(string MsgCifrado, int claveA, int claveB) {
	cout << "RECEPTOR" << endl;
	for(int i=0; i < MsgCifrado.length(); i++) { 
		message[i] = ' '; 
	}

	cout << "Mensaje Cifrado:\t" << MsgCifrado << endl;
	
	claveA = inverseA(claveA, Alphabet);
	for (int i = 0; i < message.length(); i++) {
		for (int j = 0; j < Alphabet; j++) {
			if (MsgCifrado[i] == alfabeto[j]) {
				int r = claveA * (j - claveB);  //Operacion matematica Descifrado
				if (r < 0) {  
					int q = r / Alphabet; 
					r = r - (q - 1) * Alphabet; 
				}
				else if (r >= Alphabet) { 
					int q = r / Alphabet; 
					r = r - q * Alphabet; 
				}
				message[i] = alfabeto[r];
			}
		}
	}

	cout << "Mensaje Decifrado:\t" << message << endl;
}

