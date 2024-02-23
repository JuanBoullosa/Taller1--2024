#include "Expresiones.h"


CrearExpresion(ArbolExpresiones Aexp, Expresion &expre)

{
    int id=0;
    expre.numero=id+1;
    expre.arbol=Aexp;
    id++;
}


