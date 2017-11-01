#include <iostream>
#include <string>

using namespace std;

class NodoBinario {
   public:
    NodoBinario(int num, NodoBinario *der = NULL, NodoBinario *izq = NULL, NodoBinario *sig=NULL, NodoBinario *ant=NULL):
        Hizq(izq), Hder(der), valor(num), siguiente(sig), anterior(ant), FB(0) {}

    int valor;
    int FB;
    NodoBinario *Hizq, *Hder, *siguiente, *anterior;

    void InsertaBinario(int num);
};

typedef NodoBinario *pnodo;
typedef NodoBinario *pNodoBinario;

void NodoBinario::InsertarBinario(int num){
  if (num<valor){
    if (Hizq == NULL){
      Hizq = new NodoBinario(num);
    }
    else{
      Hizq ->InsertaBinario(num);
    }
  }
  else{
    if (Hder == NULL){
      Hder = new NodoBinario(num);
    }
    else{
      Hder->InsertaBinario(num)
    }
  }
}

void NodoBinario
