#ifndef ARBOLEXPRESIONES_H_INCLUDED
#define ARBOLEXPRESIONES_H_INCLUDED
#include "Boolean.h"
#include "ValorNodo.h"
typedef struct nodoA { ValorNodo info;
                       nodoA * hizq;
                       nodoA * hder;
                        }nodo;
typedef nodo * ArbolExpresiones;


// crear un árbol vacío
void Crear (ArbolExpresiones &a);
// saber si el árbol está vacío
boolean EsVacio (ArbolExpresiones a);
//Muestra un arbol dado
void MostrarArbol(ArbolExpresiones a);
//Carga valor nodo en un arbol
void CargarArbolAtomic(ValorNodo ValNodo, ArbolExpresiones &a);
//Agrega parentesis izquierdo a nodo del arbol
void AgregarParentesisIzquierdo(ArbolExpresiones &a,ValorNodo ValorNodoParIzq);
//agrega parentesis derecho a un nodo del arbol
void AgregarParentesisDerecho(ArbolExpresiones &a, ValorNodo ValorNodoParDer);
//Crea un arbol a partir de un valor nodo, un arbol sub arboles y los parentiza EXPRESION NOT)
void Cons (ValorNodo v ,ArbolExpresiones d, ArbolExpresiones &Creado, ValorNodo Izq, ValorNodo Der);
//Crea un arbol a partir de un valor nodo, dos arboles y los parentiza
void Cons2(ValorNodo v, ArbolExpresiones i, ArbolExpresiones d, ValorNodo Izq, ValorNodo Der, ArbolExpresiones &Creado);
//Evalua el valor de las expresiones dentro de un arbol
boolean EvaluarArbol(ArbolExpresiones a, boolean &resultado);
//Copia un arbol en otro
void copiarArbol(ArbolExpresiones &a, ArbolExpresiones b);
//Asigna valor nodo en un arbol
void guardarAbbValorNodo ( ValorNodo t, ArbolExpresiones &a );
//Devuelve el valor nodo de un arbol
ValorNodo darValorNodoAbb( ArbolExpresiones a);
// insertar un nuevo valor en el ABB
// precondición: el valor no existía previamente en el ABB
void Insert (ArbolExpresiones &a, ValorNodo v);
//Asigna ID con un entero para ordenar el arbol binario en su carga
void AsignarIDenOrden(ArbolExpresiones &a, int &suma);
//Muestra el ID de los nodo del arbol
void MostrarIDdelArbol (ArbolExpresiones a);   //borrar despues si no anda
//Eliminar arbol de expresiones
void EliminarAbb (ArbolExpresiones &a);


#endif // ARBOLEXPRESIONES_H_INCLUDED

