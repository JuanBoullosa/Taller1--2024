#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "ListaExpresiones.h"

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
// Despliega por pantalla los enteros almacenados en el archivo. Precondición: El archivo existe
void Desplegar (str nomArch);
// Escribe en el archivo los caracteres de ValorNodo
// Precondición: El archivo viene abierto para escritura.
void Bajar_ValorNodo (ValorNodo v, FILE*f);
// Lee desde el archivo los caracteres de ValorNodo
// Precondición: El archivo viene abierto para lectura.
void Levantar_ValorNodo(ValorNodo &v, FILE*f);
//Escribe el arbol de expresiones en un archivo, usando un auxiliar.
void Bajar_ArbolExpresiones_Aux(ArbolExpresiones a, FILE*f);
//Escribe el arbol de expresiones en un archivo
void Bajar_ArbolExpresiones(ArbolExpresiones a, str nomArch);
//Carga el arbol de Expresiones desde un archivo
void Levantar_ArbolExpresiones(ArbolExpresiones &a, str nomArch);




#endif // ARCHIVO_H_INCLUDED
