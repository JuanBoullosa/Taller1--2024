#include "Expresiones.h"

void CargarExpresion(ArbolExpresiones Aexp, Expresion &expre, int &contadorexp)

{
    expre.numero=contadorexp;
    expre.arbol=Aexp;
    contadorexp++;
}

int DarNumero(Expresion expre)
{
    return expre.numero;
}

ArbolExpresiones DarArbolexp( Expresion expre)
{
    return expre.arbol;
}
