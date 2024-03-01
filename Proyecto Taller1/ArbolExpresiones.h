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

void CargarArbolParentesis(ArbolExpresiones &a, ValorNodo ValorNodoParIzq);

ArbolExpresiones Cons (ValorNodo v ,ArbolExpresiones d, ArbolExpresiones &Creado, ValorNodo Izq, ValorNodo Der);

void Cons2(ValorNodo v, ArbolExpresiones i, ArbolExpresiones d, ValorNodo Izq, ValorNodo Der, ArbolExpresiones &Creado);

boolean EvaluarArbol(ArbolExpresiones a, boolean &result);

void copiarArbol(ArbolExpresiones &a, ArbolExpresiones b);

void guardarAbbValorNodo ( ValorNodo t, ArbolExpresiones &a );

ValorNodo darValorNodoAbb( ArbolExpresiones a);

/* insertar un nuevo valor en el ABB */
/* precondición: el valor no existía previamente en el ABB */
void Insert (ArbolExpresiones &a, ValorNodo v);

#endif // ARBOLEXPRESIONES_H_INCLUDED

