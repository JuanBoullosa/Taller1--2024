#ifndef LISTAEXPRESIONES_H_INCLUDED
#define LISTAEXPRESIONES_H_INCLUDED
#include "Expresiones.h"
#include "Boolean.h"


typedef struct nodoL { Expresion expre;
                       nodoL * sig;
                     }NodoL;
typedef NodoL* ListaExpresiones;

//Crear Lista
//void CrearLista (ListaExpresiones &L);

//Insertar expresion en lista de expresiones
//void InsFront (ListaExpresiones &L, Expresion exp);


//Mostrar Lista
//void MostrarLista (ListaExpresiones L);


//Agregar al final de la lista
//void InsBackIter  (ListaExpresiones &L , Expresion exp);


#endif // LISTAEXPRESIONES_H_INCLUDED
