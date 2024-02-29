#include <iostream>
#include "ArbolExpresiones.h"
#include "Strigg.h"
#include "ListaString.h"
#include "ListaExpresiones.h"
#include "comando.h"

int main()
{



//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   Esta es la parte principal del codigo    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

str comando;                                            // Declaramos string donde va a ingresar el usuario comando
strcrear(comando);                                      //Creamos el string comando
ListaString Lista1;                                     //Declaramos la lista que usaremos para evaluar los string
CrearLista(Lista1);
int contadorexp1=1;
ListaExpresiones ListExpPrincipal;
CrearListaExpresiones(ListExpPrincipal);

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  Ingreso de comando y division de palabras  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

printf("Ingrese comando: ");                            //Solicitamos al usuario que ingrese un comando
scan(comando);                                          // Scan dinamico para el ingreso de el string comando
printf("\n");                                           // Salto de linea
partirString(comando, Lista1);                          // Procedimiento para partir el string
//printf("Mostrar Lista de string: \n");
//MostrarLista(Lista1);                                   // Mostramos el string partido


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  Comando atomic  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Atomic(Lista1, contadorexp1, ListExpPrincipal);         // Ejecutamos el comando atomic

printf("\n");                                           //Salto de linea
delete[] Lista1;                                        //Liberamos memoria de lista para ingresar nuevo comando
CrearLista(Lista1);                                     //Asignamos memoria a lista
printf("Ingrese comando: ");                            //Solicitamos al usuario que ingrese un comando
scan(comando);                                          // Scan dinamico para el ingreso de el string comando
printf("\n");                                           // Salto de linea
partirString(comando, Lista1);                          // Procedimiento para partir el string



Atomic(Lista1, contadorexp1, ListExpPrincipal);         // Ejecutamos el comando atomic

printf("\n");                                           //Salto de linea
delete[] Lista1;                                        //Liberamos memoria de lista para ingresar nuevo comando
CrearLista(Lista1);                                     //Asignamos memoria a lista
printf("Ingrese comando: ");                            //Solicitamos al usuario que ingrese un comando
scan(comando);                                          // Scan dinamico para el ingreso de el string comando
printf("\n");                                           // Salto de linea
partirString(comando, Lista1);                          // Procedimiento para partir el string

Compound4(Lista1,ListExpPrincipal,contadorexp1);

printf("\n");                                           //Salto de linea
delete[] Lista1;                                        //Liberamos memoria de lista para ingresar nuevo comando
CrearLista(Lista1);                                     //Asignamos memoria a lista
printf("Ingrese comando: ");                            //Solicitamos al usuario que ingrese un comando
scan(comando);                                          // Scan dinamico para el ingreso de el string comando
printf("\n");                                           // Salto de linea
partirString(comando, Lista1);

Show(Lista1,ListExpPrincipal,contadorexp1);




}








