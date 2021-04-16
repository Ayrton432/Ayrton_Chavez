#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
	int n;
	string CadenaO("intente analizar mas profundamente los mensajes recibidos");
	cout << "El mensaje original es: " << CadenaO << endl;
	
	cout << "Ingrese el numero de caracteres: "; cin >> n;
	
	//Separacion de los caracteres
	cout << CadenaO.substr(0, n) << endl;
	cout << CadenaO.substr(4, n) << endl;
	cout << CadenaO.substr(8, n) << endl;
	cout << CadenaO.substr(12, n) << endl;
	cout << CadenaO.substr(16, n) << endl;
	cout << CadenaO.substr(20, n) << endl;
	cout << CadenaO.substr(24, n) << endl;
	cout << CadenaO.substr(28, n) << endl;
	cout << CadenaO.substr(32, n) << endl;
	cout << CadenaO.substr(36, n) << endl;
	cout << CadenaO.substr(40, n) << endl;
	cout << CadenaO.substr(44, n) << endl;
	cout << CadenaO.substr(48, n) << endl;
	cout << CadenaO.substr(52, n) << endl;
	cout << CadenaO.substr(56, n) << endl;
	
	cout << "Al ultimo bloque se le agregarán X: " << endl;
	cout << CadenaO.substr(56, n).append("XXX") << endl;
	
	string CadenaN;
	CadenaN = (CadenaN+ CadenaO.substr(0, n)+"*"+CadenaO.substr(4, n)+"*"+CadenaO.substr(8, n)+"*"+CadenaO.substr(12, n)+"*"
	+CadenaO.substr(16, n)+"*"+CadenaO.substr(20, n)+"*"+CadenaO.substr(24, n)+"*"+CadenaO.substr(28, n)+"*"+CadenaO.substr(32, n)+"*"
	+CadenaO.substr(36, n)+"*"+CadenaO.substr(40, n)+"*"+CadenaO.substr(44, n)+"*"+CadenaO.substr(52, n)+"*"+CadenaO.substr(56, n)+"*");
	
	cout << CadenaN << endl;
	
	//vector que recogerá el string
	vector<string>mensaje;
	mensaje;
	
    return 0;
}
/*
	
*/
