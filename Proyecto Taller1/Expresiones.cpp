#include "Expresiones.h"

void CargarExpresion(ArbolExpresiones Aexp, Expresion &expre, int &contadorexp)

{
    expre.numero=contadorexp;
    expre.arbol=Aexp;
    contadorexp++;
}



