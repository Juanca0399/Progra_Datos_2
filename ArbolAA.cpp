#include <iostream>
#include <string>
using namespace std;

class NodoAA {
   public:

   int valor;
   string str;
   int nivel;
   NodoAA *Hizq, *Hder, *anterior, *siguiente;


    NodoAA(int num, string cliente, NodoAA *der = NULL, NodoAA *izq = NULL, NodoAA *sig=NULL, NodoAA *ant=NULL):
        Hizq(izq), Hder(der), valor(num),str(cliente),anterior(ant), siguiente(sig), nivel(1) {}

    void InsertaAA(int num,string cliente); 
};

typedef NodoAA *pNodoAA;
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