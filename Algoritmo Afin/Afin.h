#ifndef AFIN_H
#define AFIN_H
#include <string>

using namespace std;

class Afin{
	private:
		int claveA, claveB;
		string message, MsgCifrado;
	public:
		Afin(string);
		int inverseA(int claveA, int  claveB);
		void Cifrado(string, int claveA, int claveB);
		void Descifrado(string,int claveA, int claveB);
};

#endif
