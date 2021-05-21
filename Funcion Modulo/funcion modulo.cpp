#include <iostream>

using namespace std;

int modulo(int a, int n) {
    int q, r;
    q = a / n;//hallamos el cociente
    r = a % n;//hallamos el residuo
    while(r < 0)//mientras que el residuo sea negativo
    {
    	q--;//el cociente hallado se reducirá en 1 hasta que el residuo sea positivo
        r = a - (n * q);
        cout << r << endl;
    }
    return r;
    
}

int main(){
	int a,b;
	cout << "Ingrese el valor de A: " << endl;
	cin >> a;
	cout << "Ingrese el valor de B: " << endl;
	cin >> b;
	
	cout << "El residuo es: " << modulo(a,b) << endl;
	
	
	return 0;
}
