#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
/*
	Programa que convierte una cadena a un entero int 
*/

int main () {
    //Declaracion de variables en string
    string NumeroComoCadena;
    
    //pide y guarda los valores en numero
    cout << "Ingrese la cadena de numeros: " << endl;
    cin >> NumeroComoCadena;
    
    //convertir(NumeroComoCadena);
    //convierte la cadena a un entero y muestra el resultado
    cout << "El numero es " << atoi(NumeroComoCadena.c_str());
    return 0;
}


