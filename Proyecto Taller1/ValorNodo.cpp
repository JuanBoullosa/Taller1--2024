#include "ValorNodo.h"
#include "TipoNodo.h"
#include "ListaString.h"


//Carga por teclado los datos de un Grupo
//void CrearValorNodo(ValorNodo &ValNodo)

//Mostrar por pantalla los datos de un Grupo
//void MostrarValorNodo(ValorNodo ValNodo)


void CargarValorNodo(ListaString L, ValorNodo &valNodo){

        if (streq(L->palabra, "AND")) {
            valNodo.discriminante = OPERADOR;
            valNodo.dato.operador = 'A';
        } else if (streq(L->palabra, "OR")) {
            valNodo.discriminante = OPERADOR;
            valNodo.dato.operador = 'O';
        } else if (streq(L->palabra, "NOT")) {
            valNodo.discriminante = OPERADOR;
            valNodo.dato.operador = 'N';
        } else if (streq(L->palabra, "true")) {
            valNodo.discriminante = VALOR;
            valNodo.dato.valor = TRUE;
        } else if (streq(L->palabra, "false")) {
            valNodo.discriminante = VALOR;
            valNodo.dato.valor = FALSE;
        }

}

void AsignarValorNodoNOT(ValorNodo &valNodo){
    valNodo.discriminante = OPERADOR;
    valNodo.dato.operador = 'N';
}

void AsignarValorNodoAND(ValorNodo &valNodo){
    valNodo.discriminante = OPERADOR;
    valNodo.dato.operador = 'A';
}

void AsignarValorNodoOR(ValorNodo &valNodo){
    valNodo.discriminante = OPERADOR;
    valNodo.dato.operador = 'O';
}

void AsignarValorParIzq(ValorNodo &valNodo){
    valNodo.discriminante = PARENTESIS;
    valNodo.dato.parentesis = '(';
}

void AsignarValorParDer(ValorNodo &valNodo){
    valNodo.discriminante = PARENTESIS;
    valNodo.dato.parentesis = ')';
}
//Selectora Dar Boolean
boolean DarBoolean(ValorNodo ValNodo){
  return ValNodo.dato.valor;
}
//Selectora Dar operador
char DarOperador(ValorNodo ValNodo){
  return ValNodo.dato.operador;
}
//Selectora Dar Parentesis
char DarParentesis(ValorNodo ValNodo){
  return ValNodo.dato.parentesis;
}

TipoNodo DarTipoNodo(ValorNodo ValNodo){
  return ValNodo.discriminante;
}


