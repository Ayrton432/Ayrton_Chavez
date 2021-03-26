#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AlgoritmoX
{
	private:
		int clave;
		string mensaje;
		string Alfabeto;
	public:
		AlgoritmoX();
		void setClave(int clave);
		void setMensaje();
		string cifrado(string mensaje);
		string descifrado(string mensaje);
		
};

class Emisor{
	private:
		int clave;
		string mensaje;
		string Alfabeto;
	public:
		Emisor();
		void setClave(int clave);	
		string cifrado(string mensaje);
};

class Receptor{
	private:
		int clave;
		string mensaje;
		string Alfabeto;
	public:
		Receptor();
		void setClave(int clave);
		string descifrado(string mensaje);		
};

void Emisor::setClave(int clave){
	
}

string Emisor::cifrado(string mensaje){

}

void Receptor::setClave(int clave){
	
}

string Receptor::descifrado(string mensaje){

}

int main() {
	vector<string>mensaje;
	
	int filas,colms, tamano, k;
	
	AlgoritmoX Emisor();
	AlgoritmoX Receptor();
	
	cout << "Ingresa número de filas: " << endl;
	cin >> filas;
	
	tamano = mensaje.lenght();
	
	colms = tamano / filas;
	
	if(tamano % filas > 0){
			colms++;
	}	
	char matriz[filas][colms];
	
	for(int fil=0; fil < filas; fil++){
		for(int col=0; col < colms; col++){
			matriz[fil][col] = mensaje[k];
		}
	}
	
	for(size_t i=0; i < mensaje.size(); i++){
		string msjcifrado = Emisor.cifrado(mensaje);
		string menoriginal = Receptor.descifrado(msjcifrado);
	}
		
	return 0;
}
