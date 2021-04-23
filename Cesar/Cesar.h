#ifndef CESAR_H
#define CESAR_H

#include <string>

using namespace std;

class Emisor{
	private:
		int clave;
	public:
		Emisor(int clv);
		int cifrado(string mensaje, int clave);
};

class Receptor{
	private:
		int clave;
	public:
		Receptor(int clv);
		int descifrado(string mensaje, int clave);
};

#endif
