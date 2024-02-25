#ifndef ARBOLEXPRESIONES_H_INCLUDED
#define ARBOLEXPRESIONES_H_INCLUDED
#include "Boolean.h"
#include "ValorNodo.h"
typedef struct nodoA { ValorNodo info;
                       nodoA * hizq;
                       nodoA * hder;
                        }nodo;
typedef nodo * ArbolExpresiones;


/* crear un árbol vacío */
void Crear (ArbolExpresiones &a);


/* saber si el árbol está vacío */
boolean EsVacio (ArbolExpresiones a);

/* devolver la raíz del árbol */
/* Precondición: Arbol NO vacío */
ValorNodo DarRaiz (ArbolExpresiones a);

/* obtener el subárbol izquierdo */
/* Precondición: Arbol NO vacío */
ArbolExpresiones HijoIzq (ArbolExpresiones a);

/* obtener el subárbol derecho */
/* Precondición: Arbol NO vacío */
ArbolExpresiones HijoDer (ArbolExpresiones a);

/* dados dos árboles y un valor, devolver un nuevo árbol
 colocando dicho valor como una nueva raíz y a los dos
 árboles como subárboles de la misma */
//ArbolExpresiones Cons (ValorNodo r, ArbolExpresiones i, ArbolExpresiones d);


void MostrarArbol(ArbolExpresiones a);

void CargarArbolAtomic(ValorNodo ValNodo, ArbolExpresiones &a);

void AgregarParentesisIzquierdo(ArbolExpresiones &a,ValorNodo ValorNodoParIzq);

void AgregarParentesisDerecho(ArbolExpresiones &a, ValorNodo ValorNodoParDer);

void CargarArbolNOTSinParent(ValorNodo ValorNodoNOT,ArbolExpresiones arbolexpreID,ArbolExpresiones &a,ArbolExpresiones ArbolParIzq);

void CargarArbolParentesisIZQ(ArbolExpresiones &a, ValorNodo ValorNodoParIzq);

#endif // ARBOLEXPRESIONES_H_INCLUDED

