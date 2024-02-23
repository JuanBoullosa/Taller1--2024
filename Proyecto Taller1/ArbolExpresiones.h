#ifndef ARBOLEXPRESIONES_H_INCLUDED
#define ARBOLEXPRESIONES_H_INCLUDED
#include "Boolean.h"
#include "ValorNodo.h"
typedef struct nodoA { ValorNodo info;
                       nodoA * hizq;
                       nodoA * hder;
                        }nodo;
typedef nodo * ArbolExpresiones;


/* crear un �rbol vac�o */
void Crear (ArbolExpresiones &a);


/* saber si el �rbol est� vac�o */
boolean EsVacio (ArbolExpresiones a);

/* devolver la ra�z del �rbol */
/* Precondici�n: Arbol NO vac�o */
ValorNodo DarRaiz (ArbolExpresiones a);

/* obtener el sub�rbol izquierdo */
/* Precondici�n: Arbol NO vac�o */
ArbolExpresiones HijoIzq (ArbolExpresiones a);

/* obtener el sub�rbol derecho */
/* Precondici�n: Arbol NO vac�o */
ArbolExpresiones HijoDer (ArbolExpresiones a);

/* dados dos �rboles y un valor, devolver un nuevo �rbol
 colocando dicho valor como una nueva ra�z y a los dos
 �rboles como sub�rboles de la misma */
//ArbolExpresiones Cons (ValorNodo r, ArbolExpresiones i, ArbolExpresiones d);


void ListarExpresion (ArbolExpresiones a);

void CargarArbolAtomic(ValorNodo ValNodo, ArbolExpresiones &a);





#endif // ARBOLEXPRESIONES_H_INCLUDED

