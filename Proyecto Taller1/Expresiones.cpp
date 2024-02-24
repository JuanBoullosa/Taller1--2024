#include "Expresiones.h"

void CargarExpresion(ArbolExpresiones Aexp, Expresion &expre, int &contadorexp)

{
    expre.numero=contadorexp;
    expre.arbol=Aexp;
    contadorexp++;
}

int DarNumero( Expresion )
{
    return expresion.numero;
}

ArbolExpresiones DarArbolexp( Expresion)
{
    return expresion.arbol;
}
