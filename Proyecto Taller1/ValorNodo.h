#ifndef VALORNODO_H_INCLUDED
#define VALORNODO_H_INCLUDED
#include "TipoNodo.h"
#include  "ListaString.h"

typedef struct {    int identificador;
                    TipoNodo discriminante;
              union {boolean valor;
                      char operador;
                      char parentesis;
                  } dato;
                } ValorNodo;

//Carga por teclado los datos de un Grupo
void CargarValorNodo(ListaString L, ValorNodo &valNodo);
//Selectora Dar tipo de nodo.
TipoNodo DarTipoNodo(ValorNodo ValNodo, TipoNodo &TNodo);
//Selectora Dar Boolean
boolean DarBoolean(ValorNodo ValNodo);
//Selectora Dar operador
char DarOperador(ValorNodo ValNodo);
//Selectora Dar Parentesis
char DarParentesis(ValorNodo ValNodo);
//Asigna NOT a un ValorNodo
void AsignarValorNodoNOT(ValorNodo &valNodo);
//Asigna AND a un ValorNodo
void AsignarValorNodoAND(ValorNodo &valNodo);
//Asigna OR a un ValorNodo
void AsignarValorNodoOR(ValorNodo &valNodo);
//Asigna ( a un ValorNodo
void AsignarValorParIzq(ValorNodo &valNodo);
//Asigna ) a un ValorNodo
void AsignarValorParDer(ValorNodo &valNodo);






#endif // VALORNODO_H_INCLUDED
