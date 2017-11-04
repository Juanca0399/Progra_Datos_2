#include <iostream>
#include <string>

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
void PreordenR(NodoRN *R){

    if(R==NULL){
        return;
    }else{
        cout<<R->valor<<" - ";
        PreordenR(R->Hizq);
        PreordenR(R->Hder);
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
int main() {
  pNodoRN raiz = new NodoRN(5,"A5");
  raiz->InsertaRN(21,"A21");
  raiz->InsertaRN(2,"A2");
  raiz->InsertaRN(1,"A1");
  cout<<raiz->Hizq->Hizq->padre->valor<<endl;
  PreordenR(raiz);
  bool balanceado = Comparar(raiz);
  cout<<endl<<balanceado<<endl; 
  RotacionSimpleDRN(raiz,raiz->Hder);
  PreordenR(raiz);
  cin.get();
  return 0;
}