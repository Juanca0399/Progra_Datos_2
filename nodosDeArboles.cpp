#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class NodoBinario {
   public:

   int valor;
   string str;
   int FB;
   NodoBinario *Hizq, *Hder, *siguiente, *anterior;


    NodoBinario(int llave, string str, NodoBinario *der = NULL, NodoBinario *izq = NULL, NodoBinario *sig=NULL, NodoBinario *ant=NULL):
        Hizq(izq), Hder(der), valor(llave),str(str),siguiente(sig), anterior(ant), FB(0) {}

    void InsertaBinario(int num,string cliente);
};

typedef NodoBinario *pNodoBinario;

class Binario{
public:
    pNodoBinario raiz;

    Binario():raiz(NULL){}

    void InsertaNodo(string str);
    void PreordenI();
    void InordenI();
    void PostordenI();

    bool Hh;

    void Borrar(NodoBinario *nodoB);
    void BorrarBalanceado(NodoBinario *r, int eliminar);
    void insertarIndices();
    void indexar();
    int insertarCliente();
    void limpiar();
    string EliminarCliente (int cedula);
    int Buscar(NodoBinario *raiz, int llave, string str);

};

class NodoAVL {
   public:

   int valor;
   string str;
   int FB;
   NodoAVL *Hizq, *Hder, *siguiente, *anterior;


    NodoAVL(int llave, string str, NodoAVL *der = NULL, NodoAVL *izq = NULL, NodoAVL *sig=NULL, NodoAVL *ant=NULL):
        Hizq(izq), Hder(der), valor(llave),str(str),siguiente(sig), anterior(ant), FB(0) {}

    void InsertaBinario(int num,string cliente);
};

typedef NodoAVL *pNodoAVL;

void NodoBinario::InsertaBinario(int llave, string str)
{
    if(llave<valor){
        if(Hizq==NULL){
            Hizq = new NodoBinario(llave,str);
        }else{
            Hizq->InsertaBinario(llave,str);
        }
    }else{
        if(Hder==NULL){
            Hder = new NodoBinario(llave,str);
        }else{
            Hder->InsertaBinario(llave,str);
        }
    }
}

void Binario::InsertaNodo(string str)
{
  size_t last_index = str.find_last_not_of("0123456789");
  string llaveStr = str.substr(last_index + 1);
  int llave = stoi(llaveStr);
  if(raiz==NULL){
    raiz = new NodoBinario(llave,str);
  }else{
    raiz->InsertaBinario(llave,str);
  }
}

void PreordenR(NodoBinario *R){

    if(R==NULL){
        return;
    }else{
        cout<<R->str<<" - ";
        PreordenR(R->Hizq);
        PreordenR(R->Hder);
    }
}

void InordenR(NodoBinario *R){

    if(R==NULL){
        return;
    }else{
        InordenR(R->Hizq);
        cout<<R->valor<<","<<R->str<<" - ";
        InordenR(R->Hder);
    }
}

void PostordenR(NodoBinario *R){

    if(R==NULL){
        return;
    }else{
        PostordenR(R->Hizq);
        PostordenR(R->Hder);
        cout<<R->valor<<" - ";
    }
}

string getSegmento(string str, int pos){
  string segmento;
  int cont = 0;
  stringstream stream(str);
  string resultado;
  while (getline(stream, segmento, ';'))
  {
    if (cont == pos){
      resultado = segmento;
    }
    cont++;
  }
  return resultado;
}

int Binario::Buscar(NodoBinario *raiz, int llave, string str){
  int indice;
  if (raiz != NULL){
    if (llave < raiz->valor){
      Buscar(raiz->Hizq, llave, str);
    }
    else{
      if (llave > raiz->valor){
        Buscar(raiz->Hder, llave, str);
      }
      else{
        if (str == raiz->str)
          return true;
        else{
          if (str == raiz->Hizq->str)
            return true;
          else if (str == raiz->Hder->str)
            return true;
          else  return false;
        }
      }
    }
  }
  else{
    cout << "El nodo buscado no está en el árbol" << endl;
    return 0;
  }
}

int main(){
  Binario Arbol;
  Arbol.InsertaNodo("A08;Agencia8");
  Arbol.InsertaNodo("A03;Agencia3");
  Arbol.InsertaNodo("A12;Agencia12");
  Arbol.InsertaNodo("A01;Agencia1");
  Arbol.InsertaNodo("A6;Agencia6");
  Arbol.InsertaNodo("A14;Agencia14");
  Arbol.InsertaNodo("A13;Agencia13");
  PreordenR(Arbol.raiz);
  
  if (Arbol.Buscar(Arbol.raiz, 3,"A03;Agencia3"))
    cout << "pene" << endl;
    
  cin.get();
  return 0;
}