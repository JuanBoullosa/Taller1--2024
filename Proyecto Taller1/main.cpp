#include <iostream>
#include "ArbolExpresiones.h"
#include "Strigg.h"
#include "ListaString.h"
#include "ListaExpresiones.h"
#include "comando.h"

int main()
{
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   Cargamos los comandos   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
str atomic;                                 //
str compound;                               //
str show;                                   //
str evaluate;                               //
str save;                                   //Todo esto puede ir en una lista(en el modulo comando) para simplificar el codigo
str load;                                   //
str exit;                                   //
str expTrue;                                //
str expFalse;                               //
str expNot;                                 //
str expAnd;                                 //
str expOr;                                  //
CargarComandos(atomic,compound,show,evaluate,save,load,exit,expTrue,expFalse,expNot,expAnd,expOr);

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
printf("Mostrar Lista de string: \n");
MostrarLista(Lista1);                                   // Mostramos el string partido
printf("\n");

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  Comando atomic  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Atomic(Lista1, contadorexp1, ListExpPrincipal);         // Ejecutamos el comando atomic

printf("\n");                                           //Salto de linea
delete[] Lista1;                                        //Liberamos memoria de lista para ingresar nuevo comando
CrearLista(Lista1);                                     //Asignamos memoria a lista
printf("Ingrese comando: ");                            //Solicitamos al usuario que ingrese un comando
scan(comando);                                          // Scan dinamico para el ingreso de el string comando
printf("\n");                                           // Salto de linea
partirString(comando, Lista1);                          // Procedimiento para partir el string


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Prueba del comand Show %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//Show(Lista1, ListExpPrincipal,show,contadorexp1);       //Ejecutamos show


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



                                                //%%%%%%%%  COMANDO COMPOUND   %%%%%%%%*/
int numeroconvertido;
ValorNodo ValorNodoNOT;
ValorNodo ValorNodoParIzq;
ValorNodo ValorNodoParDer;
ArbolExpresiones arbolPrincipal;
ArbolExpresiones arbolDer;
ArbolExpresiones arbolIzq;
ArbolExpresiones arbolDerPar;
Expresion expre;

    if (((LargoRecu(Lista1)>2) || (LargoRecu(Lista1)<5)) && (streq(compound, Lista1->palabra))) //Largo entre 2 y 5
    {
        Lista1=Lista1->sig;

        if((streq(expNot,Lista1->palabra))&& (LargoRecu(Lista1)<=3))
        {
             Lista1=Lista1->sig;
             sscanf(Lista1->palabra, "%d", &numeroconvertido);

             if(numeroconvertido < contadorexp1){                                //Es menor a contador es por que existe una expresion con ese numero
                AsignarValorNodoNOT(ValorNodoNOT);                               //Cargamos un valor nodo con Not
                AsignarValorParIzq(ValorNodoParIzq);                             //Cargamos un valor nodo con (
                AsignarValorParDer(ValorNodoParDer);                             //Cargamos un valor nodo con )
                arbolDer=TraerArbolExp(ListExpPrincipal, numeroconvertido);      //Trae arbol indicado con ID de la lista de Expresiones.
                CargarArbolParentesis(arbolIzq, ValorNodoParIzq);                //Cargamos arbol parentesis izq
                CargarArbolParentesis(arbolDerPar, ValorNodoParDer);             //Cargamos arbol con parentesis der
                arbolPrincipal=Cons(ValorNodoNOT,arbolIzq,arbolDer,arbolDerPar); //Cargamos el arbol principal con ( NOT Arbol ID )
                CargarExpresion(arbolPrincipal, expre, contadorexp1);            //Cargamos expresion con ArbolPrincipal
                InsBackIterExp(ListExpPrincipal, expre);                         //Insertamos la expresion en la Lista Principal de Expresiones


            }
                else
                    printf("Error");
        }
    }


printf("\n");                                                                    //Salto de linea
delete[] Lista1;                                                                 //Liberamos memoria de lista para ingresar nuevo comando
CrearLista(Lista1);                                                              //Asignamos memoria a lista
printf("Ingrese comando: ");                                                     //Solicitamos al usuario que ingrese un comando
scan(comando);                                                                   //Scan dinamico para el ingreso de el string comando
printf("\n");                                                                    //Salto de linea
partirString(comando, Lista1);                                                   //Procedimiento para partir el string


Show(Lista1, ListExpPrincipal,show,contadorexp1);                                //Ejecutamos show

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    Cargar nodo OR y AND      %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        if  (((streq(expAnd,Lista1->palabra))&& (LargoRecu(Lista1)<=4)) &&
            ((streq(expOr,Lista1->palabra))&& (LargoRecu(Lista1)<=4)))
        {
            printf("\n");
        }

}





    /*if (((LargoRecu(Lista1)>2) || (LargoRecu(Lista1)<5)) && (streq(compound, Lista1->palabra))) //Largo entre 2 y 5
    {
        Lista1=Lista1->sig;

        if((streq(expNot,Lista1->palabra))&& (LargoRecu(Lista1)<=3))
        {
            Lista1=Lista1->sig;
            sscanf(Lista1->palabra, "%d", &numeroconvertido);
            if( numeroconvertido < contadorexp1){                                       //es menor a contador es por que existe una expresion con ese numero
                AsignarValorNodoNOT(ValorNodoNOT);                                      //Cargo ValorNodo NOT sin importar el string
                arbolexpreID=TraerArbolExp(ListExpPrincipal, numeroconvertido);         //trae arbol indicado con ID.
                AsignarValorParIzq(ValorNodoParIzq);
                CargarArbolParentesisIZQ(arbolIzq, ValorNodoParIzq);
                CargarArbolNOTSinParent(ValorNodoNOT, arbolexpreID, arbolaux, arbolIzq);//Cargar Arbol sin parentesis (Solo hijo derecho)
                AsignarValorParDer(ValorNodoParDer);
                //AgregarParentesisIzquierdo(arbolaux, ValorNodoParIzq);
                AgregarParentesisDerecho(arbolaux,ValorNodoParDer);                     //Le agrego parentesis al arbol

                CargarExpresion(arbolaux, expre, contadorexp1);
                InsBackIterExp(ListExpPrincipal, expre);
                printf("\nMostrar arbol: \n");
                MostrarArbol(ListExpPrincipal->expre.arbol);

            }
                else
                    printf("Error");
        }
    }*/

      /*  //Cargar nodo OR y AND
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




