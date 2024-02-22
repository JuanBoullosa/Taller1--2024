#ifndef LISTASTRING_H_INCLUDED
#define LISTASTRING_H_INCLUDED
#include "Strigg.h"


typedef struct nodoS {str palabra;
                      nodoS * sig;
                    } NodoS;

typedef NodoS*ListaString;

//Crear Lista
void CrearLista (ListaString &L);
//Mostrar Lista
void MostrarLista (ListaString L);
//Devuelve el largo de una lista
int LargoRecu (ListaString L);
//Agregar al principio de la lista
void InsFront (ListaString &L, str s);
//Agregar al final de la lista
void InsBackIter  (ListaString &L , str s);
//Verificar largo del string
//A parte un string en palabras y los coloca en una lista
void partirString (str s, ListaString &L);



#endif // LISTASTRING_H_INCLUDED
