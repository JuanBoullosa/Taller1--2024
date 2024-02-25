#include "ListaExpresiones.h"


//Crear Lista
void CrearListaExpresiones (ListaExpresiones &L)
{
  L=NULL;
}

//Devolver si la lista esta vacia
/*boolean EsVacia (ListaExpresiones L)
{
  boolean es = FALSE;
  if (L == NULL)
    es = TRUE;

    return es;
}*/

//Insertar expresion en lista de expresiones
void InsFrontExp (ListaExpresiones &L, Expresion exp)
{
  ListaExpresiones aux = new NodoL;
  aux-> expre = exp;
  aux->sig = L;
  L = aux;
}

//Mostrar Lista
void MostrarListaExp (ListaExpresiones L)
{
    while (L != NULL)
      {
        MostrarArbol(L->expre.arbol); //DarArbolexp(L->expre);
        L = L->sig;
      }
}

//Agregar al final de la lista
void InsBackIterExp  (ListaExpresiones &L , Expresion exp)
{
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
ArbolExpresiones TraerArbolExp(ListaExpresiones ListaExp, int numeroconvertido)
{
    while (ListaExp->expre.numero != numeroconvertido)
    {
        ListaExp=ListaExp->sig;
    }
    return ListaExp->expre.arbol;
}

ArbolExpresiones DarArbolexp( ListaExpresiones L)
{
    return L-> expre.arbol;
}


