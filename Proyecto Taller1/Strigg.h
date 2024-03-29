#ifndef STRIGG_H_INCLUDED
#define STRIGG_H_INCLUDED
#include "Boolean.h"


const int MAX = 80;
typedef char * str;

// Operaciones Basicas

/* crea un string vac�o */
void strcrear (str &s);
/* libera la memoria usada por el string */
void strdestruir (str &s);
/* devuelve el largo del string s */
int strlar (str s);
/* copia el contenido del string s2 en s1 */
void strcop (str &s1, str s2);
/* lee el string s desde teclado */
void scan (str &s);
/* imprime el string s por pantalla */
void print (str s);
/* determina si los strings s1 y s2 son iguales */
boolean streq (str s1, str s2);
//Divide un string en otro con la primera palabra y el resto de palabras en otro string
void dividirString (str comando, str &palabra1,str &resto);
//Elimina espacios en blanco al principio de un string
void eliminarBlancosPrincipio(str comando, str &s2);
//Devuelve si un string esta vacio
boolean stringVacio (str &s);
//Verifica que palabra sea un entero
boolean EsDigito (str palabra);
//Verifica que solo haya caracteres alfabeticos
boolean Alfabeto (str palabra);
//Divide el comando Load para verificar la correcta escritura
void dividirLoad(str comando, str &archivo, str &dat);
#endif // STRIGG_H_INCLUDED
