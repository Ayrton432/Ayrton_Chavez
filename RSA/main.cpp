#include <iostream>
#include "RSA.h"

using namespace std;

int main() {
  RSA emisor;
  /*
  Emisor emisor;
  Receptor receptor;
  */
  int mensaje = 20;
  cout << "mensaje: " << mensaje << endl;
  int m_cifrado = emisor.cifrado(mensaje);
  cout << "mensaje cifrado: " << m_cifrado << endl;
  cout << endl;
  int m_descifrado = emisor.descifrado(m_cifrado);
  cout << "mensaje descifrado: " << m_descifrado << endl;;
}
