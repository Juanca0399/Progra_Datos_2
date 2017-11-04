#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class NodoAA {
   public:

   int valor;
   string str;
   int nivel;
   NodoAA *Hizq, *Hder, *anterior, *siguiente, *padre;


    NodoAA(int num, string cliente, NodoAA *der = NULL, NodoAA *izq = NULL, NodoAA *sig=NULL, NodoAA *ant=NULL,NodoAA *pad = NULL):
        Hizq(izq), Hder(der), valor(num),str(cliente),anterior(ant), siguiente(sig), padre(pad),nivel(1) {}

    void InsertaAA(int num,string cliente); 
    void VerificarAA();

    
    friend class NodoBinario;
};

typedef NodoAA *pNodoAA;

class NodoBinario {
   public:

   int valor;
   string codigo;
   string nombre;
   NodoBinario *Hizq, *Hder, *siguiente, *anterior;
   NodoAA *referencia;

    NodoBinario(int llave, string code,string nom, NodoBinario *der = NULL, NodoBinario *izq = NULL, NodoBinario *sig=NULL, NodoBinario *ant=NULL , NodoAA *ref=NULL):
        Hizq(izq), Hder(der), valor(llave),codigo(code),nombre(nom),siguiente(sig), anterior(ant),referencia(ref) {}

    void InsertaBinario(int num,string code,string name);
     
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
    bool Buscar(NodoBinario *raiz, int llave, string str);
    void InsertarAero(NodoBinario *raiz,string Aerolinea);
};

class NodoAVL {
   public:

   int valor;
   string str;
   int FB;
   NodoAVL *Hizq, *Hder, *siguiente, *anterior;


    NodoAVL(int llave, string str, NodoAVL *der = NULL, NodoAVL *izq = NULL, NodoAVL *sig=NULL, NodoAVL *ant=NULL):
        Hizq(izq), Hder(der), valor(llave),str(str),siguiente(sig), anterior(ant), FB(0) {}

    void InsertaBinario(int num,string code,string name);
};

typedef NodoAVL *pNodoAVL;

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



void NodoBinario::InsertaBinario(int llave,string code, string nombre)
{
    if(llave<valor){
        if(Hizq==NULL){
          Hizq = new NodoBinario(llave,code,nombre);
        }else{
          Hizq->InsertaBinario(llave,code,nombre);
        }
    }else{
        if(Hder==NULL){
            Hder = new NodoBinario(llave,code,nombre);
        }else{
            Hder->InsertaBinario(llave,code,nombre);
        }
    }
}

void Binario::InsertaNodo(string str)
{
  size_t last_index = str.find_last_not_of("0123456789");
  string llaveStr = str.substr(last_index + 1);
  int llave = stoi(llaveStr);
  string code = getSegmento(str,0);
  string nombre = getSegmento(str,1);
  if(raiz==NULL){
    raiz = new NodoBinario(llave,code,nombre);
  }else{
    raiz->InsertaBinario(llave,code,nombre);
  }
}

void PreordenR(NodoBinario *R){

    if(R==NULL){
        return;
    }else{
        cout<<R->codigo<<" - ";
        PreordenR(R->Hizq);
        PreordenR(R->Hder);
    }
}

void InordenR(NodoBinario *R){

    if(R==NULL){
        return;
    }else{
        InordenR(R->Hizq);
        cout<<R->valor<<","<<R->codigo<<","<<R->nombre<<" - ";
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


bool Binario::Buscar(NodoBinario *raiz, int llave, string str){
  if (raiz != NULL){
    if (llave < raiz->valor){
      Buscar(raiz->Hizq, llave, str);
    }
    else{
      if (llave > raiz->valor){
        Buscar(raiz->Hder, llave, str);
      }
      else{
        if (str == raiz->codigo){
          return true;
        }else{
          if (Buscar(raiz->Hizq,llave,str)){
            return true;  
          }else if (Buscar(raiz->Hder,llave,str)){
            return true;
          }else{
            return false;
          }
        }
      }
    }
  }
  else{
    cout << "El nodo buscado no está en el árbol" << endl;
    return false;
  }
}
void Binario::InsertarAero(NodoBinario *raiz,string Aerolinea){
  string agencia;
  agencia = getSegmento(Aerolinea,0);
  size_t last_index = agencia.find_last_not_of("0123456789");
  string llaveStr = agencia.substr(last_index + 1);
  int llave = stoi(llaveStr);
  if(raiz!=NULL){
    cout<<raiz->codigo<<endl;
    cout<<llave<<" --- "<<raiz->valor<<endl;
    if (llave < raiz->valor){
      InsertarAero(raiz->Hizq,Aerolinea);
    }
    else{
      if (llave > raiz->valor){
        InsertarAero(raiz->Hder,Aerolinea);
      }
      else{
        cout<<agencia<<" == "<<raiz->codigo<<endl;
        if (agencia == raiz->codigo){
          string CodeAero = getSegmento(Aerolinea,1);
          size_t last_indexAero = Aerolinea.find_last_not_of("0123456789");
          string llaveAeroStr = Aerolinea.substr(last_indexAero + 1);
          int llaveAero = stoi(llaveAeroStr);
          if(raiz->referencia == NULL){
            pNodoAA raizAero = new NodoAA(llaveAero,CodeAero);
            raiz->referencia = raizAero; 
            cout<<raiz->codigo<<" referencia a "<<raiz->referencia->str<<endl;
          }else{
            pNodoAA raizAero = raiz->referencia;
            raizAero->InsertaAA(llaveAero,CodeAero);
            cout<<raiz->referencia->str<<" referencia a "<<raiz->referencia->anterior->str<<endl;

          }
        }else{
          InsertarAero(raiz->Hizq,Aerolinea);
          InsertarAero(raiz->Hder,Aerolinea);
        }
      }
    }
  }else{
    return;
  }
  
  
}
void NodoAA::InsertaAA(int num,string str)
{
    if(num<valor){
        if(Hizq==NULL){
            anterior = new NodoAA(num,str);
        }else{
            Hizq->InsertaAA(num,str);
        }
    }else{  
        if(Hder==NULL){
            siguiente = new NodoAA(num,str);
        }else{
            Hder->InsertaAA(num,str);
        }
    }
}
void VerificarAA(NodoAA *raiz){
  if(raiz != NULL){
    if(raiz->siguiente != NULL){
      if(raiz->siguiente->siguiente != NULL){
        raiz->siguiente->Hder = raiz->siguiente->siguiente;
        raiz->siguiente->Hizq = raiz;
        
      }else if(raiz->anterior != NULL){
        
      }else{
        VerificarAA(raiz->Hizq);
        VerificarAA(raiz->Hder);
      }
    }else if(raiz->anterior != NULL){
      if(raiz->anterior->anterior != NULL){
        
      }else if(raiz->siguiente != NULL){
        
      }else{
        VerificarAA(raiz->Hizq);
        VerificarAA(raiz->Hder);
      }
    }
  }else{
    return;
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
  cout<<endl;
  if(Arbol.Buscar(Arbol.raiz,8,"A08")){
    cout<<":P"<<endl;
  }
  Arbol.InsertarAero(Arbol.raiz,"A08;AE01;Aerolinea5");
  Arbol.InsertarAero(Arbol.raiz,"A08;AE02;Aerolinea1");
  
    
  cin.get();
  return 0;
}