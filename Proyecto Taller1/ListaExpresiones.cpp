#include "ListaExpresiones.h"


//Crear Lista
/*void CrearLista (ListaExpresiones &L)
{
  L=NULL;
}
*/
//Devolver si la lista esta vacia
/*boolean EsVacia (ListaExpresiones L)
{
  boolean es = FALSE;
  if (L==NULL)
    es = TRUE;

    return es;
}
*/
//Insertar expresion en lista de expresiones
/*void InsFront (ListaExpresiones &L, Expresion exp)
{
  ListaExpresiones aux = new NodoL;
  aux-> expre = exp;
  aux->sig = L;
  L = aux;
}*/



//Mostrar Lista
/*void MostrarLista (ListaExpresiones L)
{
    while (L != NULL)
      {
        printf ("%d", L->expre.numero);
        L = L->sig;
      }
}*/

//Agregar al final de la lista
/*void InsBackIter  (ListaExpresiones &L , Expresion exp)
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
*/
