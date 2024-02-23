#ifndef EXPRESIONES_H_INCLUDED
#define EXPRESIONES_H_INCLUDED
#include "ArbolExpresiones.h"


typedef struct { int numero;
                 ArbolExpresiones arbol;
               } Expresion;


void CargarExpresion(ArbolExpresiones Aexp, Expresion &expre, int &contadorexp);

#endif // EXPRESIONES_H_INCLUDED
