#ifndef LISTAEXPRESIONES_H_INCLUDED
#define LISTAEXPRESIONES_H_INCLUDED
#include "Expresiones.h"
#include "Boolean.h"


typedef struct nodoL { Expresion expre;
                       nodoL * sig;
                     }NodoL;
typedef NodoL* ListaExpresiones;

//Crear Lista
void CrearListaExpresiones (ListaExpresiones &L);
//Agregar al final de la lista
void InsBackIterExp  (ListaExpresiones &L , Expresion exp);
//Devolver expresion segun numero solicitado
ArbolExpresiones TraerArbolExp(ListaExpresiones ListaExp, int numeroconvertido);
//Devuelve un arbol de expresiones de una lista de expresion
ArbolExpresiones DarArbolexp( ListaExpresiones L);






#endif // LISTAEXPRESIONES_H_INCLUDED
