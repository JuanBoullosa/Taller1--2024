#ifndef STRIGG_H_INCLUDED
#define STRIGG_H_INCLUDED
#include "Boolean.h"


const int MAX = 80;
typedef char * str;

// Operaciones Basicas

/* crea un string vacío */
void strcrear (str &s);
/* libera la memoria usada por el string */
void strdestruir (str &s);
/* devuelve el largo del string s */
int strlar (str s);
/* copia el contenido del string s2 en s1 */
void strcop (str &s1, str s2);
/* lee el string s desde teclado */
void scan (str &s);
/* concatena el contenido de s2 al final de s1 */
void strcon (str &s1, str s2);
/* intercambia los contenidos de s1 y s2 */
void strswp (str &s1, str &s2);
/* imprime el string s por pantalla */
void print (str s);
/* determina si s1 es alfabéticamente menor que s2 */
boolean strmen (str s1, str s2);
/* determina si los strings s1 y s2 son iguales */
boolean streq (str s1, str s2);
//Divide un string en otro con la primera palabra y el resto de palabras en otro string
void dividirString (str comando, str &palabra1,str &resto);
//Elimina espacios en blanco al principio de un string
void eliminarBlancosPrincipio(str comando, str &s2);
//Devuelve si un string esta vacio
boolean stringVacio (str &s);
#endif // STRIGG_H_INCLUDED
