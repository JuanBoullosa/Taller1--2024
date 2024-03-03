#ifndef TIPONODO_H_INCLUDED
#define TIPONODO_H_INCLUDED
#include "Boolean.h"


typedef enum {VALOR, OPERADOR, PARENTESIS} TipoNodo;

//Devolver tipo nodo
TipoNodo DevolverNodo (TipoNodo Nodo);

#endif // TIPONODO_H_INCLUDED
