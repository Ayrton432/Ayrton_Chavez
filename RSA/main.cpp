#include <iostream>
#include "RSA.h"

using namespace std;

int main() {
  RSA Emisor;
  int mensaje = 20;
  cout << "mensaje: " << mensaje << endl;
  int m_cifrado = Emisor.cifrado(mensaje);
  cout << "mensaje cifrado: " << m_cifrado << endl;
  cout << endl;
  int m_descifrado = Emisor.descifrado(m_cifrado);
  cout << "mensaje descifrado: " << m_descifrado << endl;;
}
