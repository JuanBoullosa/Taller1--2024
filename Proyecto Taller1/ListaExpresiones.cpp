#include "ListaExpresiones.h"



void CrearListaExpresiones (ListaExpresiones &L){
  L=NULL;
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

ArbolExpresiones TraerArbolExp(ListaExpresiones ListaExp, int numeroconvertido){
    while (ListaExp->expre.numero != numeroconvertido)
    {
        ListaExp=ListaExp->sig;
    }
    return DarArbolexp(ListaExp);
}

ArbolExpresiones DarArbolexp( ListaExpresiones L){
    return L-> expre.arbol;
}

void EliminarListaExpresiones (ListaExpresiones &L){
    if (L != NULL)
    {
        EliminarListaExpresiones (L->sig);
        delete L;
        L = NULL;
    }
}

void EliminarListaYArbol(ListaExpresiones &L) {

    ListaExpresiones temp;
    CrearListaExpresiones(temp);

    while (L != NULL) {
        EliminarAbb(L->expre.arbol);

        temp = L->sig;


        delete L;


        L = temp;
    }
}



