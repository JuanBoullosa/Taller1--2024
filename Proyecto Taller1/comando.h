#ifndef COMANDO_H_INCLUDED
#define COMANDO_H_INCLUDED
#include "Archivo.h"

//Toma un string ingresado lo divide en palabras, lo ingresa en una lista y a partir de esta verifica que sea correcto y crear arbol binario y lo guarda en una lista de expresiones
void Atomic(ListaString L, int &contadorexp, ListaExpresiones &ListExp);
//Toma un string ingresado lo divide en palabras, lo ingresa en una lista y a partir de esta verifica que sea correcto y muestra en pantalla una expresion con el valor ingresado
void Show(ListaString Lista1 ,ListaExpresiones L, int contadorexp1);
//Toma un string ingresado lo divide en palabras, lo ingresa en una lista y a partir de esta verifica que sea correcto y evalua las expresiones asignadas en la lista de string
void Evaluate (ListaString Lista1, ListaExpresiones ListExpPrincipal,int contadorexp1);
//Toma un string ingreso lo divide en palabras, lo ingresa en una lista y a partir de esta crear arbol binario y lo guarda en una lista de expresiones
void Compound(ListaString Lista1,ListaExpresiones &ListExpPrincipal, int & contadorexp1);
//Toma un string ingreso lo divide en palabras, lo ingresa en una lista y a partir de esta crea un archivo para guardar el arbol indicado en el string
void Save(ListaString Lista1,ListaExpresiones &ListExpPrincipal, int & contadorexp1);
//Toma un string ingreso lo divide en palabras, lo ingresa en una lista y a partir de esta crea un archivo para cargar el arbol indicado en el string
void Load(ListaString Lista1,ListaExpresiones &ListExpPrincipal, int & contadorexp1);
#endif // COMANDO_H_INCLUDED
