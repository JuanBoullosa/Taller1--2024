#include <iostream>
#include "ArbolExpresiones.h"
#include "Strigg.h"
#include "ListaString.h"
#include "ListaExpresiones.h"
#include "comando.h"

int main()
{
//Cargamos los comandos
str atomic;
str compound;
str show;
str evaluate;
str save;
str load;
str exit;
str expTrue;
str expFalse;
str expNot;
str expAnd;
str expOr;
CargarComandos(atomic,compound,show,evaluate,save,load,exit,expTrue,expFalse,expNot,expAnd,expOr);// Esto se puede poner en una lista de momento lo deje asi para achicar un poco

//                     Esta es la parte principal del codigo
str comando;                             // Declaramos string donde va a ingresar el usuario comando
strcrear(comando);                      //Creamos el string comando
ListaString Lista1;                     //Declaramos la lista que usaremos para evaluar los string
CrearLista(Lista1);
int contadorexp1=1;
ListaExpresiones ListExpPrincipal;
CrearListaExpresiones(ListExpPrincipal);
                        // Ingreso de comando y division de palabras
printf("Ingrese comando: ");            //Solicitamos al usuario que ingrese un comando
scan(comando);                          // Scan dinamico para el ingreso de el string comando
printf("\n");                          // Salto de linea
partirString(comando, Lista1);          // Procedimiento para partir el string
printf("Mostrar Lista de string: \n");
MostrarLista(Lista1);                   // Mostramos el string partido
printf("\n");


                            //Comando atomic
Atomic(Lista1, contadorexp1, ListExpPrincipal);  // Ejecutamos el comando atomic
printf("\n");
delete[] Lista1;
CrearLista(Lista1);

printf("Ingrese comando: ");            //Solicitamos al usuario que ingrese un comando
scan(comando);                          // Scan dinamico para el ingreso de el string comando
printf("\n");                          // Salto de linea
partirString(comando, Lista1);          // Procedimiento para partir el string
printf("El valor de la expresion ingresa es: \n");
Show(Lista1, ListExpPrincipal,show,contadorexp1);



//Estas variables deberian ir en el comando compound


                         //Creamos la lista
Expresion expre;                    //Creamos  expresion
ArbolExpresiones arbol;
ArbolExpresiones arbolcompuesto;




//%%%%%%%%  COMANDO COMPOUND   %%%%%%%%*/
int numeroconvertido;
ValorNodo ValorNodoNOT;
ValorNodo ValorNodoParIzq;
ValorNodo ValorNodoParDer;
ArbolExpresiones arbolexpreID;
ArbolExpresiones arbolaux;

    if (((LargoRecu(Lista1)>2) || (LargoRecu(Lista1)<5)) && (streq(compound, Lista1->palabra)))
    {
        Lista1=Lista1->sig;
        //Cargar nodo NOT
        if((streq(expNot,Lista1->palabra))&& (LargoRecu(Lista1)<=3))
        {
            Lista1=Lista1->sig;
            sscanf(Lista1->palabra, "%d", &numeroconvertido);
            if( numeroconvertido < contadorexp1)//condicion de si existe en la lista
                                                // es menor a condador es por que existe una expresion con ese numero
                                                //
            {

                //CargarValorNodo(Lista1, valNodo);                                 //Cargar valor NOT
                AsignarValorNodoNOT(ValorNodoNOT);                                  //Cargo ValorNodo NOT sin importar el string
                arbolexpreID=TraerArbolExp(ListExpPrincipal, numeroconvertido);             //trae arbol indicado con ID.
                CargarArbolNOTSinParent(ValorNodoNOT, arbolexpreID, arbolaux);        //Cargar Arbol sin parentesis (Solo hijo derecho)
                AsignarValorParIzq(ValorNodoParIzq);
                AsignarValorParDer(ValorNodoParDer);
                AgregarParentesisIzquierdo(arbolaux, ValorNodoParIzq);
                AgregarParentesisDerecho(arbolaux,ValorNodoParDer);                 //Le agrego parentesis al arbol

                CargarExpresion(arbolaux, expre, contadorexp1);
                InsBackIterExp(ListExpPrincipal, expre);
                printf("\nMostrar arbol: \n");
                MostrarArbol(ListExpPrincipal->expre.arbol);

            }
                else
                    printf("Error");
        }
    }

     } /*  //Cargar nodo OR y AND
        if  (((streq(expAND,Lista1->palabra))&& (LargoRecu(Lista1)<=4)) &&
            ((streq(expOR,Lista1->palabra))&& (LargoRecu(Lista1)<=4)))
        {


        }

 }


*/

//if(streq(evaluate, Lista1->palabra))
    //printf("Es igual al string evaluate");

//if(streq(save, Lista1->palabra))
   // printf("Es igual al string save");

//if(streq(load, Lista1->palabra))
   // printf("Es igual al string load");

//if(streq(exit, Lista1->palabra))
//printf("Es igual al string atomic");




