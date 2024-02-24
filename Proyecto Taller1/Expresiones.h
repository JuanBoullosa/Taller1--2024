#ifndef EXPRESIONES_H_INCLUDED
#define EXPRESIONES_H_INCLUDED
#include "ArbolExpresiones.h"


typedef struct { int numero;
                 ArbolExpresiones arbol;
               } Expresion;

//Cargo expresion
void CargarExpresion(ArbolExpresiones Aexp, Expresion &expre, int &contadorexp);

int DarNumero( Expresion expre);

ArbolExpresiones DarArbolexp( Expresion expre );

#endif // EXPRESIONES_H_INCLUDED
