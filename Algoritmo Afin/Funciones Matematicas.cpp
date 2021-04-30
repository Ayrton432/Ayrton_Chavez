#include <iostream>

using namespace std;

int Euclides(int r1, int r2) {
	int r;
	while (r2 > 0)
	{
		int q; 
		q = r1 / r2;	
		if (r1 >= 0) { 
			r = r1 - q*r2; 
		}
		else { 
			r = r1 - (q-1)*r2; 
		}
		
		r1 = r2; 
		r2 = r;
	}
	return r1;
}

int RecursiveEuclides(int a, int b){
	if (a == 0)
		return b;
	return RecursiveEuclides(b % a, a);

}

int ExtendedEu(int r1, int r2, int r, bool n) {
	int s1 = 1, s2 = 0, s; 
	int t1 = 0, t2 = 1 , t;
	while (r2 > 0) {
		int q; 
		q = r1/r2;	
		
		r = r1 - q*r2;
		r1 = r2; 
		r2 = r;
		
		s = s1 - q*s2;
		s1 = s2; 
		s2 = s;
		
		t = t1 - q*t2;
		t1 = t2;
		t2 = t;
	}
	if (n == 0){
		return s1;
	} 
	else if(n == 1){
		return t1;	
	} 
	else{
		return 0;
	}
	
}

int modulo(int a, int n) {
    int q, r;
    q = a / n;//hallamos el cociente
    r = a % n;//hallamos el residuo
    while(r < 0)//mientras que el residuo sea negativo
    {
    	q--;//el cociente hallado se reducirá en 1 hasta que el residuo sea positivo
        r = a - (n * q);
    }
    return r;
}
