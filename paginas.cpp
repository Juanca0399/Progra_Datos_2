
#include <iostream>
using namespace std;

class nodo {
   public:
    nodo(int v)
    {
       valor = v;
       siguiente = NULL;
       anterior = NULL;
    }

nodo(int v, nodo * signodo)
    {
       valor = v;
       siguiente = signodo;
    }

   private:
    int valor;
    nodo *siguiente;
    nodo *anterior;


   friend class listaC;
};

typedef nodo *pnodo;
class listaC {
   public:
    listaC() { primero = actual = NULL; }
    ~listaC();

    
   private:
    pnodo primero;
    pnodo actual;
};

listaC::~listaC()
{
   pnodo aux;

   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   actual = NULL;
}