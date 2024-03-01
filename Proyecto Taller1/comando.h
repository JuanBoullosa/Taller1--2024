#ifndef COMANDO_H_INCLUDED
#define COMANDO_H_INCLUDED
#include "ValorNodo.h"
#include "ArbolExpresiones.h"
#include "Expresiones.h"
#include "ListaExpresiones.h"
#include "Archivo.h"

void Atomic(ListaString L, int &contadorexp, ListaExpresiones &ListExp);

void CargarComandos (str &atomic, str & compound, str & show, str & evaluate, str & save, str &load, str & exit);

void Show(ListaString Lista1 ,ListaExpresiones L, int contadorexp1);

void Evaluate (ListaString Lista1, ListaExpresiones ListExpPrincipal, str evaluate, int contadorexp1);

void Compound4(ListaString Lista1,ListaExpresiones &ListExpPrincipal, int & contadorexp1);

void Save(ListaString Lista1,ListaExpresiones &ListExpPrincipal, int & contadorexp1);
#endif // COMANDO_H_INCLUDED
