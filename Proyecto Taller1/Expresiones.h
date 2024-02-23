#ifndef EXPRESIONES_H_INCLUDED
#define EXPRESIONES_H_INCLUDED
#include "ArbolExpresiones.h"


typedef struct { int numero;
                 ArbolExpresiones arbol;
               } Expresion;


CrearExpresion(ArbolExpresiones Aexp, Expresion &expre);

#endif // EXPRESIONES_H_INCLUDED
