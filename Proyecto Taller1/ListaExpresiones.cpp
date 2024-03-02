#include "ListaExpresiones.h"


//Crear Lista
void CrearListaExpresiones (ListaExpresiones &L){
  L=NULL;
}

void InsFrontExp (ListaExpresiones &L, Expresion exp){
  ListaExpresiones aux = new NodoL;
  aux-> expre = exp;
  aux->sig = L;
  L = aux;
}

void InsBackIterExp  (ListaExpresiones &L , Expresion exp){
  ListaExpresiones nuevo = new NodoL;
  nuevo -> expre = exp;
  nuevo -> sig = NULL;

  if (L == NULL)
    L = nuevo;
  else
  {
    ListaExpresiones aux = L;
    while (aux -> sig != NULL)
      aux = aux -> sig;
    aux -> sig = nuevo;
  }
}
//Devolver expresion segun el ID solicitado
ArbolExpresiones TraerArbolExp(ListaExpresiones ListaExp, int numeroconvertido){
    while (ListaExp->expre.numero != numeroconvertido)
    {
        ListaExp=ListaExp->sig;
    }
    return ListaExp->expre.arbol;
}

ArbolExpresiones DarArbolexp( ListaExpresiones L){
    return L-> expre.arbol;
}


