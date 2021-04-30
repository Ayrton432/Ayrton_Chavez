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
		void Emisor(string, int claveA, int claveB);
		void Receptor(string,int claveA, int claveB);
};

#endif
