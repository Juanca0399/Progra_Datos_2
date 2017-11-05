#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


class NodoRN {
   public:

   int valor;
   string str;
   bool isRed;
   NodoRN *Hizq, *Hder, *padre, *tio;


    NodoRN(int num, string cliente, NodoRN *der = NULL, NodoRN *izq = NULL, NodoRN *sig=NULL, NodoRN *ant=NULL):
        Hizq(izq), Hder(der), valor(num),str(cliente),padre(padre), tio(tio), isRed(true) {}

    void InsertaRN(int num,string cliente); 
};

typedef NodoRN *pNodoRN;
class NodoAA {
  public:

  int valor;
  string codigo;
  string nombre;
  NodoAA *Hizq, *Hder, *siguiente, *anterior;
  NodoRN *referencia;
  int FB;

   NodoAA(int llave, string code,string nom, NodoAA *der = NULL, NodoAA *izq = NULL, NodoAA *sig=NULL, NodoAA *ant=NULL , NodoRN *ref=NULL):
       Hizq(izq), Hder(der), valor(llave),codigo(code),nombre(nom),siguiente(sig), anterior(ant),referencia(ref), FB(0) {}

  void InsertarAA(NodoAA *ra, bool Hh, int llave, string codigo, string nombre);
  void RotacionDobleIzquierda(NodoAA* n, NodoAA* n1);
  void RotacionDobleDerecha(NodoAA* n, NodoAA* n1);
  void RotacionSimpleDerecha(NodoAA* n, NodoAA* n1);
  void RotacionSimpleIzquierda(NodoAA* n, NodoAA* n1);
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
    void InsertarAerolinea(NodoBinario *raiz, string aerolinea);
};

class NodoAVL {
   public:

   int valor;
   string codigo;
   string nombre;
   int FB;
   NodoAVL *Hizq, *Hder, *siguiente, *anterior;


    NodoAVL(int llave, string code,string nom, NodoAVL *der = NULL, NodoAVL *izq = NULL, NodoAVL *sig=NULL, NodoAVL *ant=NULL):
        Hizq(izq), Hder(der), valor(llave),codigo(code),nombre(nom),siguiente(sig), anterior(ant), FB(0) {}

    void InsertarAVL(NodoAVL *ra, bool Hh, int llave, string codigo, string nombre);
    void RotacionDobleIzquierda(NodoAVL* n, NodoAVL* n1);
    void RotacionDobleDerecha(NodoAVL* n, NodoAVL* n1);
    void RotacionSimpleDerecha(NodoAVL* n, NodoAVL* n1);
    void RotacionSimpleIzquierda(NodoAVL* n, NodoAVL* n1);
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

void NodoAVL::RotacionDobleIzquierda(NodoAVL* n, NodoAVL* n1){
    NodoAVL *n2;
    n2=n1->Hder;
    n->Hizq = n2->Hder;
    n2->Hder=n;
    n1->Hder=n2->Hizq;
    n2->Hizq=n1;

    if(n2->FB==1){
        n1->FB=-1;
    }else{
        n1->FB=0;
    }
    if(n2->FB==-1){
        n->FB=1;
    }else{
        n->FB=0;
    }
    n2->FB=0;
    n=n2;
}

void NodoAVL::RotacionDobleDerecha(NodoAVL* n, NodoAVL* n1){
    NodoAVL *n2;
    n2=n1->Hizq;
    n->Hder = n2->Hizq;
    n2->Hizq=n;
    n1->Hizq=n2->Hder;
    n2->Hder=n1;

    if(n2->FB==1){
        n->FB=-1;
    }else{
        n->FB=0;
    }
    if(n2->FB==-1){
        n1->FB=1;
    }else{
        n1->FB=0;
    }
    n2->FB=0;
    n=n2;
}

void NodoAVL::RotacionSimpleDerecha(NodoAVL* n, NodoAVL* n1){
    n->Hder=n1->Hizq;
    n1->Hizq=n;

    if(n1->FB==1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=1;
        n1->FB=-1;
    }
    n=n1;
}

void NodoAVL::RotacionSimpleIzquierda(NodoAVL* n, NodoAVL* n1){
    n->Hizq=n1->Hder;
    n1->Hder=n;

    if(n1->FB==-1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=-1;
        n1->FB=-1;
    }
    n=n1;
}

void NodoAVL::InsertarAVL(NodoAVL *ra, bool Hh, int llave, string codigo, string nombre){
  pNodoAVL n1;
  
  if(ra==NULL){
      ra=new NodoAVL(llave, codigo, nombre);
      Hh = true;
  }else{
      if(llave<ra->valor){
          InsertarAVL(ra->Hizq, Hh, llave, codigo, nombre);

      if(Hh){
          switch(ra->valor){
              case 1: ra->FB=0;
              Hh = false;
              break;
              case 0: ra->FB  = -1;
              break;
              case -1: n1=ra->Hizq;
              if(n1->FB == -1){
                  RotacionSimpleIzquierda(ra, n1);
              }else{
                  RotacionDobleIzquierda(ra,n1);
              }
              Hh = false;
              break;
          }
      }
      }else{
          if(llave>ra->valor){
              InsertarAVL(ra->Hder, Hh, llave, codigo, nombre);

              if(Hh){
                  switch(ra->FB){
                      case -1: ra->FB=0;
                      Hh = false;
                      break;
                      case 0: ra->FB=1;
                      break;
                      case 1:n1=ra->Hder;
                      if(n1->FB == 1){
                          RotacionSimpleDerecha(ra, n1);
                      }else{
                          RotacionDobleDerecha(ra, n1);
                      }
                      Hh=false;
                      break;
                  }
              }
          }
      }
  }
}

void NodoAA::RotacionDobleIzquierda(NodoAA* n, NodoAA* n1){
    NodoAA *n2;
    n2=n1->Hder;
    n->Hizq = n2->Hder;
    n2->Hder=n;
    n1->Hder=n2->Hizq;
    n2->Hizq=n1;

    if(n2->FB==1){
        n1->FB=-1;
    }else{
        n1->FB=0;
    }
    if(n2->FB==-1){
        n->FB=1;
    }else{
        n->FB=0;
    }
    n2->FB=0;
    n=n2;
}

void NodoAA::RotacionDobleDerecha(NodoAA* n, NodoAA* n1){
    NodoAA *n2;
    n2=n1->Hizq;
    n->Hder = n2->Hizq;
    n2->Hizq=n;
    n1->Hizq=n2->Hder;
    n2->Hder=n1;

    if(n2->FB==1){
        n->FB=-1;
    }else{
        n->FB=0;
    }
    if(n2->FB==-1){
        n1->FB=1;
    }else{
        n1->FB=0;
    }
    n2->FB=0;
    n=n2;
}

void NodoAA::RotacionSimpleDerecha(NodoAA* n, NodoAA* n1){
    n->Hder=n1->Hizq;
    n1->Hizq=n;

    if(n1->FB==1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=1;
        n1->FB=-1;
    }
    n=n1;
}

void NodoAA::RotacionSimpleIzquierda(NodoAA* n, NodoAA* n1){
    n->Hizq=n1->Hder;
    n1->Hder=n;

    if(n1->FB==-1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=-1;
        n1->FB=-1;
    }
    n=n1;
}

void NodoAA::InsertarAA(NodoAA *ra, bool Hh, int llave, string codigo, string nombre){
  pNodoAA n1;
  
  if(ra==NULL){
      ra=new NodoAA(llave, codigo, nombre);
      Hh = true;
  }else{
      if(llave<ra->valor){
          InsertarAA(ra->Hizq, Hh, llave, codigo, nombre);

      if(Hh){
          switch(ra->valor){
              case 1: ra->FB=0;
              Hh = false;
              break;
              case 0: ra->FB  = -1;
              break;
              case -1: n1=ra->Hizq;
              if(n1->FB == -1){
                  RotacionSimpleIzquierda(ra, n1);
              }else{
                  RotacionDobleIzquierda(ra,n1);
              }
              Hh = false;
              break;
          }
      }
      }else{
          if(llave>ra->valor){
              InsertarAA(ra->Hder, Hh, llave, codigo, nombre);

              if(Hh){
                  switch(ra->FB){
                      case -1: ra->FB=0;
                      Hh = false;
                      break;
                      case 0: ra->FB=1;
                      break;
                      case 1:n1=ra->Hder;
                      if(n1->FB == 1){
                          RotacionSimpleDerecha(ra, n1);
                      }else{
                          RotacionDobleDerecha(ra, n1);
                      }
                      Hh=false;
                      break;
                  }
              }
          }
      }
  }
}

void Binario::InsertarAerolinea(NodoBinario *raiz, string aerolinea){
  string agencia = getSegmento(aerolinea, 0);
  size_t last_index = agencia.find_last_not_of("0123456789");
  string llaveStr = agencia.substr(last_index + 1);
  int llave = stoi(llaveStr);
  if(raiz!=NULL){
    if (llave < raiz->valor){
      InsertarAerolinea(raiz->Hizq, aerolinea);
    }
    else{
      if (llave > raiz->valor){
        InsertarAerolinea(raiz->Hder, aerolinea);
      }
      else{
        if (agencia == raiz->codigo){
          string codigoAE = getSegmento(aerolinea, 1);
          string nombreAE = getSegmento(aerolinea, 2);
          size_t last_indexAE = aerolinea.find_last_not_of("0123456789");
          string llaveAEStr = aerolinea.substr(last_indexAE + 1);
          int llaveAE = stoi(llaveAEStr);
          if(raiz->referencia == NULL){
            pNodoAA raizAE = new NodoAA(llaveAE, codigoAE, nombreAE);
            raiz->referencia = raizAE; 
            cout<<raiz->codigo<<" referencia a "<<raiz->referencia->codigo<<endl; 
          }else{
            pNodoAA raizAE = raiz->referencia;
            raizAE->InsertarAA(raizAE, false, llaveAE, codigoAE, nombreAE);
          }
        }else{
          InsertarAerolinea(raiz->Hizq, aerolinea);
          InsertarAerolinea(raiz->Hder, aerolinea);
        }
      }
    }
  }else{
    return;
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

void NodoRN::InsertaRN(int num,string str)
{
    if(num<valor){
        if(Hizq==NULL){
            Hizq = new NodoRN(num,str);
            Hizq->padre = this;
        }else{
            Hizq->InsertaRN(num,str);
            if(Hizq != NULL){
              Hizq->padre = this;
            }if(Hder != NULL){
              Hder->padre = this;
            }
        }
    }else{
        if(Hder==NULL){
            Hder = new NodoRN(num,str);
            Hder->padre = this;
        }else{
            Hder->InsertaRN(num,str);
            
        }
    }
}
void Balancear(NodoRN *raiz){
  if(raiz == NULL){
    return;
  }
  
}
void leyTio(NodoRN *n){
  pNodoRN tio;
  pNodoRN padre = n->padre;
  if(padre != padre->padre->Hizq){
    tio = padre->padre->Hizq;
  }else{
    tio = padre->padre->Hder;
  }if(tio != NULL){
    tio->isRed = false;
    padre->isRed = false;
  }
}
bool Comparar(NodoRN *raiz){
  bool balanceado = true;
  if(raiz  != NULL){
    if(raiz->isRed == true){
      if(raiz->Hizq != NULL){
        if(raiz->Hizq->isRed == true){
          balanceado = false;
          return balanceado;
        }
      }if(raiz->Hder != NULL){
        if(raiz->Hder->isRed == true){
          balanceado = false;
          return balanceado;
        }
      }
    }else{
      Comparar(raiz->Hizq);
      Comparar(raiz->Hder);
    }
  }
  return balanceado;
}
int NegrosRamaIzq(NodoRN *raiz, int negros){
  if(raiz == NULL){
    negros++;
    return negros;
  }if(raiz->isRed == false){
    negros++;
  }
  NegrosRamaIzq(raiz->Hizq,negros);
  return negros;
}
bool Comparar2(NodoRN *raiz,int negros){
  int totales = NegrosRamaIzq(raiz,0);
  if(raiz!=NULL){
    if(raiz->isRed == false){
      negros++;
    }
    Comparar2(raiz->Hizq,negros);
    Comparar2(raiz->Hder,negros);
  }else{
    negros++;
    if(negros == totales){
      negros --; 
      return true;
    }else{
      return false;
    }
  }
}

void RotacionSimpleDRN(NodoRN *n, NodoRN *n1){
  n->Hder=n1->Hizq;
  n1->Hizq=n;
  n=n1;
  if(n->isRed == true){
    n->isRed = false;
  }else{
    n->isRed = true;
  }if(n->Hizq->isRed == true){
    n->Hizq->isRed = false;
  }else{
    n->Hizq->isRed = true;
  }
  
}
void RotacionSimpleIRN(NodoRN *n,NodoRN *n1){
  n->Hizq=n1->Hder;
  n1->Hder=n;
  n=n1;
  n1->isRed = true;
  if(n->isRed == true){
    n->isRed = false;
  }else{
    n->isRed = true;
  }if(n->Hder->isRed == true){
    n->Hder->isRed = false;
  }else{
    n->Hder->isRed = true;
  }
}
void RotacionDobleIzquierda(NodoRN* n, NodoRN* n1){
    NodoRN *n2;
    n2=n1->Hder;
    n->Hizq = n2->Hder;
    n2->Hder=n;
    n1->Hder=n2->Hizq;
    n2->Hizq=n1;  
    n=n2;
    if(n->isRed == true){
      n->isRed = false;
    }else{
      n->isRed = true;
    }if(n->Hizq->isRed == true){
      n->Hizq->isRed = false;
    }else{
      n->Hizq->isRed = true;
    }
}
void RotacionDobleDerecha(NodoRN* n, NodoRN* n1){
    NodoRN *n2;
    n2=n1->Hizq;
    n->Hder = n2->Hizq;
    n2->Hizq=n;
    n1->Hizq=n2->Hder;
    n2->Hder=n1;
    n=n2;
    if(n->isRed == true){
      n->isRed = false;
    }else{
      n->isRed = true;
    }if(n->Hder->isRed == true){
      n->Hder->isRed = false;
    }else{
      n->Hder->isRed = true;
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
  Arbol.InsertarAerolinea(Arbol.raiz,"A01;AE01;Aerolinea5");
  cin.get();
  return 0;
}