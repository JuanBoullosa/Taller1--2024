#include "comando.h"


void Atomic(ListaString L, int &contadorexp){

//Comando atomic
str atomic; //Declaramos string para ATOMIC
strcrear(atomic); //Creamos string ATOMIC
atomic = new char[7];//Solicitamos la cantidad de espacios en memoria para atomic
atomic[0]='a';
atomic[1]='t';
atomic[2]='o';
atomic[3]='m';              //Ingresamos caracteres de atomic
atomic[4]='i';
atomic[5]='c';
atomic[6]='\0';
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
ValorNodo valNodo;
ArbolExpresiones arbolexp;
Expresion expre;
ListaExpresiones ListExp;

if((LargoRecu(L) == 2) && (streq(atomic, L->palabra)))
{


            L = L->sig;
            if(streq(expTrue,L->palabra)||streq(expFalse,L->palabra))
            {
                CargarValorNodo(L, valNodo);
                CargarArbolAtomic(valNodo,arbolexp);
                CargarExpresion(arbolexp, expre, contadorexp);
                InsBackIterExp(ListExp, expre);
                printf("\nMostrar arbol: \n");
                MostrarArbol(ListExp->expre.arbol);
            }
        else
            printf("\nComando incorrecto\n");
            }
            else
                printf("\nComando incorrecto\n");

}
