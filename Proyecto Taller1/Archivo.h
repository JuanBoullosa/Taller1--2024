#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "ListaExpresiones.h"
/*


// %%%%%%%%%% ---- OPERACIONES BASICAS---- %%%%%%%%%
// Agrega el nuevo entero al final del archivo
void Agregar (str nomArch, int entero);

// Determina si existe o no un archivo con el nombre recibido por parámetro
boolean Existe (str nomArch);

// Determina si el archivo está vacío o no. Precondición: El archivo existe
boolean Vacio (str nomArch);

// Determina si el entero recibido está en el archivo. Precondición: El archivo existe
boolean Pertenece (str nomArch, int entero);

// Devuelve la cantidad de enteros almacenados en el archivo. Precondición: El archivo existe
int Largo (str nomArch);

// Devuelve el k-ésimo entero almacenado en el archivo. Precondición: El archivo existe
// y su largo es  k.
//int K-esimo (str nomArch, int k);

// Despliega por pantalla los enteros almacenados en el archivo. Precondición: El archivo existe
void Desplegar (str nomArch);

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


// Escribe en el archivo los caracteres de ValorNodo
// Precondición: El archivo viene abierto para escritura.
void Bajar_ValorNodo (ValorNodo v, FILE*f);

// Lee desde el archivo los caracteres de ValorNodo
// Precondición: El archivo viene abierto para lectura.
void Levantar_ValorNodo(ValorNodo &v, FILE*f);

void Bajar_ArbolExpresiones_Aux(ArbolExpresiones a, FILE*f);
void Bajar_ArbolExpresiones(ArbolExpresiones a, str nomArch);
void Levantar_ArbolExpresiones(ArbolExpresiones &a, FILE*f);

void Bajar_Expresion(Expresion e, FILE*f);
void Levantar_Expresion(Expresion &e, FILE*f);

void Bajar_ListaExpresiones(ListaExpresiones L, str nomArch);
void Levantar_ListaExpresiones(ListaExpresiones &L, str nomArch);


*/


#endif // ARCHIVO_H_INCLUDED
