#ifndef VALORNODO_H_INCLUDED
#define VALORNODO_H_INCLUDED
#include "TipoNodo.h"
#include  "ListaString.h"

typedef struct {    int valor;
                    TipoNodo discriminante;
              union {boolean valor;
                      char operador;
                      char parentesis;
                  } dato;
                } ValorNodo;

//Carga por teclado los datos de un Grupo
void CargarValorNodo(ListaString L, ValorNodo &valNodo);

//Mostrar por pantalla los datos de un Grupo
void MostrarValorNodo(ValorNodo ValNodo);

//Selectora Dar tipo de nodo.
TipoNodo DarTipoNodo(ValorNodo ValNodo, TipoNodo &TNodo);

//Selectora Dar Boolean
boolean DarBoolean(ValorNodo ValNodo);

//Selectora Dar operador
char DarOperador(ValorNodo ValNodo);

//Selectora Dar Parentesis
char DarParentesis(ValorNodo ValNodo);

void AsignarValorNodoNOT(ValorNodo &valNodo);

void AsignarValorNodoAND(ValorNodo &valNodo);

void AsignarValorNodoOR(ValorNodo &valNodo);

void AsignarValorParIzq(ValorNodo &valNodo);

void AsignarValorParDer(ValorNodo &valNodo);


#endif // VALORNODO_H_INCLUDED
