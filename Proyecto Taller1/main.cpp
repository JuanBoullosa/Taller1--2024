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
int numeroconvertido, numeroconvertido2;

ValorNodo ValorNodoNOT;
ValorNodo ValorNodoAND;
ValorNodo ValorNodoOR;
ValorNodo ValorNodoParIzq;
ValorNodo ValorNodoParDer;
ArbolExpresiones arbolPrincipal;
ArbolExpresiones arbolDer;
ArbolExpresiones arbolIzq;
ArbolExpresiones arbolIzqPar;
ArbolExpresiones arbolDerPar;
Expresion expre;

    if (((LargoRecu(Lista1)>2) || (LargoRecu(Lista1)<5)) && (streq(compound, Lista1->palabra))) //Largo entre 2 y 5
    {
        Lista1=Lista1->sig;                                                     //Avanzo a string 2

        if((streq(expNot,Lista1->palabra))&& (LargoRecu(Lista1)<=3))
        {
             Lista1=Lista1->sig;
             sscanf(Lista1->palabra, "%d", &numeroconvertido);

             if(numeroconvertido < contadorexp1)                                //Es menor a contador es por que existe una expresion con ese numero
               {
                AsignarValorNodoNOT(ValorNodoNOT);                               //Cargamos un valor nodo con Not
                AsignarValorParIzq(ValorNodoParIzq);                             //Cargamos un valor nodo con (
                AsignarValorParDer(ValorNodoParDer);                             //Cargamos un valor nodo con )
                arbolDer=TraerArbolExp(ListExpPrincipal, numeroconvertido);      //Trae arbol indicado con ID de la lista de Expresiones.
                CargarArbolParentesis(arbolIzqPar, ValorNodoParIzq);                //Cargamos arbol parentesis izq
                CargarArbolParentesis(arbolDerPar, ValorNodoParDer);             //Cargamos arbol con parentesis der
                arbolPrincipal=Cons(ValorNodoNOT,arbolIzqPar,arbolDer,arbolDerPar); //Cargamos el arbol principal con ( NOT Arbol ID )
                CargarExpresion(arbolPrincipal, expre, contadorexp1);            //Cargamos expresion con ArbolPrincipal
                InsBackIterExp(ListExpPrincipal, expre);                         //Insertamos la expresion en la Lista Principal de Expresiones
               }
                else
                    printf("Error");
        }
                            //%%%%%%%%%%   COMANDO AND Y OR  %%%%%%%%%%%%
       else
            sscanf(Lista1->palabra, "%d", &numeroconvertido);                       //Convierto string 2 a entero
        if (numeroconvertido<contadorexp1)                                      //Condicion si el numero existe en la lista de expresiones
        {
            Lista1=Lista1->sig;                                             //Avanzo al string 3
            //---COMANDO AND----//
            if (streq(expAnd,Lista1->palabra))                                  // Condicion que el tercer string sea AND
             {
                Lista1=Lista1->sig;                                         //Avanzo al cuarto String
                sscanf(Lista1->palabra, "%d", &numeroconvertido2);                      //Convierto el string 4 en entero
                if(numeroconvertido2<contadorexp1)                              //condicion de que el entero exista en la lista de expresiones
                {
                    AsignarValorNodoAND(ValorNodoAND);                           //Cargamos el valor nodo AND
                    AsignarValorParIzq(ValorNodoParIzq);                         //Cargamos un valor nodo con (
                    AsignarValorParDer(ValorNodoParDer);                         //Cargamos un valor nodo con )
                    arbolIzq=TraerArbolExp(ListExpPrincipal, numeroconvertido);  //Trae arbol indicado con ID de la lista de Expresiones.
                    arbolDer=TraerArbolExp(ListExpPrincipal, numeroconvertido2);  //Trae arbol indicado con ID de la lista de Expresiones.
                    CargarArbolParentesis(arbolIzqPar, ValorNodoParIzq);          //Cargamos arbol parentesis izq
                    CargarArbolParentesis(arbolDerPar, ValorNodoParDer);          //Cargamos arbol con parentesis der
                    arbolPrincipal=Cons2(ValorNodoAND,arbolIzq,arbolDer,arbolIzqPar, arbolDerPar); //Cargamos el arbol principal con ( NOT Arbol ID )
                    CargarExpresion(arbolPrincipal, expre, contadorexp1);            //Cargamos expresion con ArbolPrincipal
                    InsBackIterExp(ListExpPrincipal, expre);                         //Insertamos la expresion en la Lista Principal de Expresiones
                }
                 else
                    printf("Error2\n");
             }
             //---COMANDO OR----//
            if(streq(expOr,Lista1->palabra))                                     // Condicion que el tercer string sea OR
            {
                Lista1=Lista1->sig;                                         //Avanzo al cuarto String
                sscanf(Lista1->palabra, "%d", &numeroconvertido2);              //Convierto el string 4 en entero
                if(numeroconvertido2<contadorexp1)                              //condicion de que el entero exista en la lista de expresiones
                {
                    AsignarValorNodoOR(ValorNodoOR);                           //Cargamos el valor nodo AND
                    AsignarValorParIzq(ValorNodoParIzq);                         //Cargamos un valor nodo con (
                    AsignarValorParDer(ValorNodoParDer);                         //Cargamos un valor nodo con )
                    arbolIzq=TraerArbolExp(ListExpPrincipal, numeroconvertido);  //Trae arbol indicado con ID de la lista de Expresiones.
                    arbolDer=TraerArbolExp(ListExpPrincipal, numeroconvertido2);  //Trae arbol indicado con ID de la lista de Expresiones.
                    CargarArbolParentesis(arbolIzqPar, ValorNodoParIzq);          //Cargamos arbol parentesis izq
                    CargarArbolParentesis(arbolDerPar, ValorNodoParDer);          //Cargamos arbol con parentesis der
                    arbolPrincipal=Cons2(ValorNodoOR,arbolIzq,arbolDer,arbolIzqPar,arbolDerPar); //Cargamos el arbol principal con ( NOT Arbol ID )
                    CargarExpresion(arbolPrincipal, expre, contadorexp1);            //Cargamos expresion con ArbolPrincipal
                    InsBackIterExp(ListExpPrincipal, expre);                         //Insertamos la expresion en la Lista Principal de Expresiones
                }
                 else
                    printf("Error3\n");
            }

        }
        else
            printf("Error3\n");

    }
    else
        printf("Error3\n");




printf("\n");                                                                    //Salto de linea
delete[] Lista1;                                                                 //Liberamos memoria de lista para ingresar nuevo comando
CrearLista(Lista1);                                                              //Asignamos memoria a lista
printf("Ingrese comando: ");                                                     //Solicitamos al usuario que ingrese un comando
scan(comando);                                                                   //Scan dinamico para el ingreso de el string comando
printf("\n");                                                                    //Salto de linea
partirString(comando, Lista1);                                                   //Procedimiento para partir el string


Show(Lista1, ListExpPrincipal,show,contadorexp1);                                //Ejecutamos show


printf("\n");                                                                    //Salto de linea
delete[] Lista1;                                                                 //Liberamos memoria de lista para ingresar nuevo comando
CrearLista(Lista1);                                                              //Asignamos memoria a lista
printf("Ingrese comando: ");                                                     //Solicitamos al usuario que ingrese un comando
scan(comando);                                                                   //Scan dinamico para el ingreso de el string comando
printf("\n");                                                                    //Salto de linea
partirString(comando, Lista1);                                                   //Procedimiento para partir el string

Evaluate(Lista1, ListExpPrincipal, evaluate,contadorexp1);

//%%%%%%%%%%%%%%%%%%%  COMANDO EVALUATE   %%%%%%%%%%%%%%%%%%%%%%%*/
/*ArbolExpresiones arbolevaluate;
boolean Resu;

if(streq(evaluate, Lista1->palabra))
{
    if (LargoRecu(Lista1)==2)                                                   //Condicion que el largo de la lista sea 2
    {
        Lista1=Lista1->sig;                                                     //Avanzo al string 2
        sscanf(Lista1->palabra, "%d", &numeroconvertido);                       //Convierto el string en entero
        if (numeroconvertido < contadorexp1)                                    //Me fijo si existe contador en la lista de expresiones
        {

            arbolevaluate=TraerArbolExp(ListExpPrincipal, numeroconvertido);    //Traigo el arbol de la lista para evaluarlo
            //EvaluarArbol(arbolevaluate);                                      //Funcion para evaluar un arbol de expresiones
            if(EvaluarArbol(arbolevaluate)==TRUE)
            {
                printf("TRUE");
            }
                else
                {
                    printf("FALSE");
                }


        }
        else
           printf("Mensaje de error\n");
    }
    else
        printf("Mensaje de error\n");

}




*/





}












//if(streq(evaluate, Lista1->palabra))
    //printf("Es igual al string evaluate");

//if(streq(save, Lista1->palabra))
   // printf("Es igual al string save");

//if(streq(load, Lista1->palabra))
   // printf("Es igual al string load");

//if(streq(exit, Lista1->palabra))
//printf("Es igual al string atomic");




