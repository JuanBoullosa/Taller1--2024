#include "ValorNodo.h"
#include "TipoNodo.h"
#include "ListaString.h"


//Carga por teclado los datos de un Grupo
//void CrearValorNodo(ValorNodo &ValNodo)

//Mostrar por pantalla los datos de un Grupo
//void MostrarValorNodo(ValorNodo ValNodo)


void CargarValorNodo(ListaString L, ValorNodo &valNodo){

str expTrue;
strcrear(expTrue);
expTrue = new char[5];//Solicitamos la cantidad de espacios en memoria para true
expTrue[0]='t';
expTrue[1]='r';
expTrue[2]='u';
expTrue[3]='e';
expTrue[4]='\0';

//Expresion false en string para comparar
str expFalse;
strcrear(expFalse);
expFalse = new char[6];//Solicitamos la cantidad de espacios en memoria para false
expFalse[0]='f';
expFalse[1]='a';
expFalse[2]='l';
expFalse[3]='s';
expFalse[4]='e';
expFalse[5]='\0';

str expParCerrado;
strcrear(expParCerrado);
expParCerrado = new char[2];//Solicitamos la cantidad de espacios en memoria para parentesis cerrado
expParCerrado[0]=')';
expParCerrado[1]='\0';

str expParAbierto;
strcrear(expParAbierto);
expParAbierto = new char[2];//Solicitamos la cantidad de espacios en memoria para parentesis abierto
expParAbierto[0]='(';
expParAbierto[1]='\0';

str expAnd;
strcrear(expAnd);
expAnd = new char[4];//Solicitamos la cantidad de espacios en memoria para operador and
expAnd[0]='A';
expAnd[1]='N';
expAnd[2]='D';
expAnd[3]='\0';

str expNot;
strcrear(expNot);
expNot = new char[4];//Solicitamos la cantidad de espacios en memoria operador or
expNot[0]='N';
expNot[1]='O';
expNot[2]='T';
expNot[3]='\0';

str expOr;
strcrear(expOr);
expOr = new char[3];//Solicitamos la cantidad de espacios en memoria operador or
expOr[0]='O';
expOr[1]='R';
expOr[2]='\0';

        if (streq(L->palabra, expAnd)) {
            //valNodo.discriminante = OPERADOR;
            valNodo.dato.operador = 'A';
        } else if (streq(L->palabra, expOr)) {
            //valNodo.discriminante = OPERADOR;
            valNodo.dato.operador = 'O';
        } else if (streq(L->palabra, expNot)) {
            //valNodo.discriminante = OPERADOR;
            valNodo.dato.operador = 'N';
        } else if (streq(L->palabra, expTrue)) {
            //valNodo.discriminante = VALOR;
            valNodo.dato.valor = TRUE;
        } else if (streq(L->palabra, expFalse)) {
            //valNodo.discriminante = VALOR;
            valNodo.dato.valor = FALSE;
        }

}

void AsignarValorNodoNOT(ValorNodo &valNodo)
{
    valNodo.dato.operador = 'N';
}
void AsignarValorNodoAND(ValorNodo &valNodo)
{
    valNodo.dato.operador = 'A';
}
void AsignarValorNodoOR(ValorNodo &valNodo)
{
    valNodo.dato.operador = 'O';
}

void AsignarValorParIzq(ValorNodo &valNodo)
{
    valNodo.dato.parentesis = '(';
}

void AsignarValorParDer(ValorNodo &valNodo)
{
    valNodo.dato.parentesis = ')';
}

//Selectora Dar Boolean
boolean DarBoolean(ValorNodo ValNodo)
{
  return ValNodo.dato.valor;
}
//Selectora Dar operador
char DarOperador(ValorNodo ValNodo)
{
  return ValNodo.dato.operador;
}
//Selectora Dar Parentesis
char DarParentesis(ValorNodo ValNodo)
{
  return ValNodo.dato.parentesis;
}

TipoNodo DarTipoNodo(ValorNodo ValNodo)
{
  return ValNodo.discriminante;
}
