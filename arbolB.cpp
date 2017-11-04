#include <iostream>
#include <string>
using namespace std;

class Pagina{
  
};

class ArbolB{
  
  bool ArbolVacio(Pagina *raiz) {};
  void BuscarNodo(int clave, Pagina *P, bool encontrado, int k);
  void Buscar(int clave, Pagina *raiz, bool encontrado, Pagina *n, int pos);
  void MeterHoja(int x, Pagina *xder, Pagina *p, int k);
  void DividirNodo(int x, Pagina *xder, Pagina *P, int k, int mda, Pagina *mder);
  void Empujar(int c1, Pagina *r, bool empujaArriba, int mdna, Pagina *x);
  void Insertar(int c1, Pagina *raiz);
};

void ArbolB::BuscarNodo(int clave, Pagina *P, bool encontrado, int k){
  if (clave < P.claves[1]){
    encontrado = false;
    k = 0;
  }
  else{
    k=P.Cuenta;
    while (clave<P.claves[k] && k > 1)
      k=k-1;
    encontrado= clave = P.Claves[k];
  }
}

void ArbolB::Buscar(int clave, Pagina *raiz, bool encontrado, Pagina *n, int pos){
  if(ArbolVacio(raiz))
    encontrado=false;
  else{
    BuscarNodo(clave,raiz,encontrado,pos);
    if (encontrado)
      n=raiz;
    else
      Buscar(clave,raiz.Rama[pos],encontrado,n,pos);
  }
}

void ArbolB::MeterHoja(int x, Pagina *xder, Pagina *p, int k){
  int i;
  // "with" al parecer no existe en C mamut, gracias Ivannia
  with p{
    for (i = Cuenta reduciendo hasta K+1){ // Se me olvido como se declaran los for, ya son las 3:30 y quiero dormir
      Claves[I+1]=Claves[I];
      Ramas[I+1]=Ramas[I];
    }
    Claves[K+1]=X];
    Ramas[K+1]=Xder;
    Cuenta=Cuenta+1;
  }
}

void ArbolB::DividirNodo(int x, Pagina *xder, Pagina *P, int k, int mda, Pagina *mder){
  int i;
  int posmda;
  //C mamo joven, este metodo esta muy latgo we alv
  
  if (k <= Min)
    posmda = Min;
  else{
    posmda = Min+1;
    mder= new Pagina();
    //Digo yo que esto se identa así, la verdad no tengo ni puta idea porque esto lo dento un mono o algo así
  }
  with P{ //Ivannia más necia, esto no existe
    for(I=Posmda+1 to Max){ //Sigo sin saber como poner un for
      mder.Claves[I-posmda]=Claves[I];
      mder.Ramas[I-posmda]=Ramas[I];
    }
    mder.Cuenta = Max-posmda;
    Cuenta = Posmda;
    if(k <= Min)
      MeterHoja (x,xder,p,k);
    else
      MeterHoja (X,Xder,Mder,K-Posmda)
      //Una vez más, asumo que la identación es así
    Mda=Claves[Cuenta];
    Mder.Ramas[0]=Ramas[Cuenta];
    Cuenta=Cuenta-1
  }
}

void ArbolB::Empujar(int c1, Pagina *r, bool empujaArriba, int mdna, Pagina *x){
  //Los "Xr" de la hoja de Ivannia los cambie a "x" porque o si no daba errores
  int k;
  bool esta;
  
  if(ArbolVacio()){
    empujaArriba = true;
    mdna = c1;
    x = NULL;
  }
  else{
    BuscarNodo(c1,r,esta,k);
    if (esta){
      cout << "Elemento repetido" << endl;
      Empujar(c1,r.Rama[k],empujaArriba,mdna,xr);
    }
    if(empujaArriba){
    ///////////////////////////////////////////////////////  
    }
    
    if(r.Cuenta < Max){
      empujaArriba = false;
      MeterHoja(mdna,x,r,k);
    }
    else{
      empujaArriba = true;
      DividirNodo(mdna,xr,r,k,mdna,xr);
    }

} }

  
} //Aqui yo no sé que putas Ivannia hizo, le dio como un derrame

void ArbolB::Insertar(int c1, Pagina *raiz){
  bool empujarArriba = false;
  int x; //tipoClave
  Pagina *xr;
  Pagina *p;
  
  Empujar(c1,raiz,empujarArriba,x,xr);
  if(empujaArriba){
    p= new Pagina();
    p.Cuenta = 1;
    p.Claves[1] = x;
    p.Ramas[0] = raiz;
    p.Ramas[1] = xr;
    raiz=p;
  }
}

void ArbolB::Inorden(Pagina *r){
  int i;
  if(!ArbolVacio(r))
    Inorden(r.Ramas[0]);
  for (I=1 to r.Cuenta){
    cout << R.Clave[I];
    Inorden(R.Ramas[I]);
  }
} //Por una ultima vez, yo SUPONGO que así es como se identa, ya llegados a este punto bale berga la bida