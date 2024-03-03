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

void MostrarArbol(ArbolExpresiones a);

void CargarArbolAtomic(ValorNodo ValNodo, ArbolExpresiones &a);

void AgregarParentesisIzquierdo(ArbolExpresiones &a,ValorNodo ValorNodoParIzq);

void AgregarParentesisDerecho(ArbolExpresiones &a, ValorNodo ValorNodoParDer);

ArbolExpresiones Cons (ValorNodo v ,ArbolExpresiones d, ArbolExpresiones &Creado, ValorNodo Izq, ValorNodo Der);

void Cons2(ValorNodo v, ArbolExpresiones i, ArbolExpresiones d, ValorNodo Izq, ValorNodo Der, ArbolExpresiones &Creado);

boolean EvaluarArbol(ArbolExpresiones a);

void copiarArbol(ArbolExpresiones &a, ArbolExpresiones b);

void guardarAbbValorNodo ( ValorNodo t, ArbolExpresiones &a );

ValorNodo darValorNodoAbb( ArbolExpresiones a);

/* insertar un nuevo valor en el ABB */
/* precondición: el valor no existía previamente en el ABB */
void Insert (ArbolExpresiones &a, ValorNodo v);

void AsignarIDenOrden(ArbolExpresiones &a, int &suma);

void MostrarIDdelArbol (ArbolExpresiones a);   //borrar despues si no anda




#endif // ARBOLEXPRESIONES_H_INCLUDED

