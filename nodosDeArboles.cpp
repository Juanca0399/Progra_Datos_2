#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


class NodoRN {
   public:

   int valor;
   string codigo;
   string estado;
   bool isRed;
   NodoRN *Hizq, *Hder, *padre, *tio;


    NodoRN(int num, string code,string status, NodoRN *der = NULL, NodoRN *izq = NULL, NodoRN *sig=NULL, NodoRN *ant=NULL):
        Hizq(izq), Hder(der), valor(num),codigo(code),estado(status),padre(padre), tio(tio), isRed(true) {}

    void InsertaRN(int num,string codigo,string estado); 
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
    void InsertarAvion(NodoBinario *raiz, string avion);
    bool BuscarAA(NodoAA *raiz, int llave, string str);
    void leerEInsertarABB(Binario &clientes, Binario &destinos);


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

bool Binario::BuscarAA(NodoAA *raiz, int llave, string str){
  if (raiz != NULL){
    if (llave < raiz->valor){
      BuscarAA(raiz->Hizq, llave, str);
    }
    else{
      if (llave > raiz->valor){
        BuscarAA(raiz->Hder, llave, str);
      }
      else{
        if (str == raiz->codigo){
          return true;
        }else{
          if (BuscarAA(raiz->Hizq,llave,str)){
            return true;  
          }else if (BuscarAA(raiz->Hder,llave,str)){
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

void NodoRN::InsertaRN(int num,string codigo,string estado)
{
    if(num<valor){
        if(Hizq==NULL){
            Hizq = new NodoRN(num,codigo,estado);
            Hizq->padre = this;
        }else{
            Hizq->InsertaRN(num,codigo,estado);
            if(Hizq != NULL){
              Hizq->padre = this;
            }if(Hder != NULL){
              Hder->padre = this;
            }
        }
    }else{
        if(Hder==NULL){
            Hder = new NodoRN(num,codigo,estado);
            Hder->padre = this;
        }else{
            Hder->InsertaRN(num,codigo,estado);
            
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
pNodoBinario EncontrarAgencia(NodoBinario *raiz,string codigo,int llave){
  if (llave < raiz->valor){
    raiz = EncontrarAgencia(raiz->Hizq, codigo,llave);
  }
  else{
    if (llave > raiz->valor){
      raiz = EncontrarAgencia(raiz->Hder, codigo,llave);
    }
    else{
      if (codigo == raiz->codigo){
        return raiz;
      }else{
        raiz = EncontrarAgencia(raiz->Hizq, codigo,llave);
        raiz = EncontrarAgencia(raiz->Hder, codigo,llave);
      }
    }
  }
  return raiz;
}
pNodoAA EncontrarAerolinea(NodoAA *raiz,string codigo,int llave){
  if (llave < raiz->valor){
    raiz = EncontrarAerolinea(raiz->Hizq, codigo,llave);
  }
  else{
    if (llave > raiz->valor){
      raiz = EncontrarAerolinea(raiz->Hder, codigo,llave);
    }
    else{
      if (codigo == raiz->codigo){
        return raiz;
      }else{
        raiz = EncontrarAerolinea(raiz->Hizq, codigo,llave);
        raiz = EncontrarAerolinea(raiz->Hder, codigo,llave);
      }
    }
  }
  return raiz;
}
void Binario::InsertarAerolinea(NodoBinario *raiz, string aerolinea){
  string agencia = getSegmento(aerolinea, 0);
  size_t last_index = agencia.find_last_not_of("0123456789");
  string llaveStr = agencia.substr(last_index + 1);
  int llave = stoi(llaveStr);
  if(Buscar(raiz,llave,agencia)){
    pNodoBinario aux = EncontrarAgencia(raiz,agencia,llave);
    cout<<"llego"<<endl;
    cout<<aux->valor<<endl;
    string codigo = getSegmento(aerolinea,1);
    string nombre = getSegmento(aerolinea,2);
    size_t last_indexAE = codigo.find_last_not_of("0123456789");
    string llaveStrAE = codigo.substr(last_indexAE + 1);
    int llaveAE = stoi(llaveStr);
    if(aux->referencia == NULL){   
      pNodoAA raizAE = new NodoAA(llaveAE,codigo,nombre);
      aux->referencia = raizAE;
      cout<<aux->codigo<<"referencia a "<<aux->referencia->codigo<<endl;
    }else{
      pNodoAA raizAE = aux->referencia;
      cout<<aux->referencia->valor<<endl;
      raizAE->InsertarAA(raizAE,false,llaveAE,codigo,nombre);
    }
  }
}  
void Binario::InsertarAvion(NodoBinario *raiz, string avion){
  string agencia = getSegmento(avion, 0);
  size_t last_index = agencia.find_last_not_of("0123456789");
  string llaveStr = agencia.substr(last_index + 1);
  int llave = stoi(llaveStr);
  if(Buscar(raiz,llave,agencia)){
    pNodoBinario aux = EncontrarAgencia(raiz,agencia,llave);
    cout<<aux->valor<<endl;
    string codigoAE = getSegmento(avion,1);
    size_t last_indexAE = codigoAE.find_last_not_of("0123456789");
    string llaveStrAE = codigoAE.substr(last_indexAE + 1);
    int llaveAE = stoi(llaveStr);
    if(BuscarAA(aux->referencia,llaveAE,codigoAE)){  
      cout<<"llegoAv"<<endl;
      pNodoAA aero = EncontrarAerolinea(aux->referencia,codigoAE,llaveAE);
      cout<<"llego"<<endl;
      cout<<aero->valor<<endl;
      string codigoAvion = getSegmento(avion,2);
      string estadoAvion = getSegmento(avion,4);
      size_t last_indexAvion = codigoAvion.find_last_not_of("0123456789");
      string llaveStrAvion = codigoAvion.substr(last_indexAvion + 1);
      int llaveAvion = stoi(llaveStr);
      if(aero->referencia == NULL){   
        pNodoRN raizRN = new NodoRN(llaveAvion,codigoAvion,estadoAvion);
        aero->referencia = raizRN;
        cout<<aero->codigo<<"referencia a "<<aero->referencia->codigo<<endl;
      }else{
        pNodoRN raizRN = aero->referencia;
        cout<<aero->referencia->valor<<endl;
        raizRN->InsertaRN(llaveAvion,codigoAvion,estadoAvion);
      }
    } 
  }
}

void Binario::leerEInsertarABB(Binario &clientes, Binario &destinos){
  std::ifstream file1("Agencias.txt");
	std::string str1;
	while (std::getline(file1, str1)) {
		InsertaNodo(str1);
	}
  std::ifstream file2("Clientes.txt");
	std::string str2;
	while (std::getline(file2, str2)) {
		clientes.InsertaNodo(str2);
	}
  std::ifstream file3("Destinos.txt");
	std::string str3;
	while (std::getline(file3, str3)) {
		destinos.InsertaNodo(str1);
	}
}


int main(){
  Binario ArbolPrincipal, Clientes, Destinos;
  
  PreordenR(ArbolPrincipal.raiz);
  PreordenR(Clientes.raiz);
  PreordenR(Destinos.raiz);
  
  /*Arbol.InsertaNodo("A08;Agencia8");
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
  Arbol.InsertarAerolinea(Arbol.raiz,"A12;AE012;Aerolinea12");
  Arbol.InsertarAerolinea(Arbol.raiz,"A12;AE011;Aerolinea11");
  Arbol.InsertarAvion(Arbol.raiz,"A12;AE012;AB1;8;Aeronavegable");
  cout<<"salio"<<endl;*/
  cin.get();
  return 0;
}