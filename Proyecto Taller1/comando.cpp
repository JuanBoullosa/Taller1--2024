#include "comando.h"


void Atomic(ListaString L, int &contadorexp, ListaExpresiones &ListExp){

ValorNodo valNodo;
ArbolExpresiones arbolexp;
Expresion expre;

            L = L->sig;
            if(streq("true",L->palabra)||streq("false",L->palabra))
            {
                CargarValorNodo(L, valNodo);
                CargarArbolAtomic(valNodo,arbolexp);
                CargarExpresion(arbolexp, expre, contadorexp);
                InsBackIterExp(ListExp, expre);
                MostrarArbol(arbolexp);
            }
            else
            printf("\nComando incorrecto\n");

}

void Show(ListaString Lista1 ,ListaExpresiones L, int contadorexp1){

        int numeroconvertido;
        ArbolExpresiones arbolexpreID;
        Crear(arbolexpreID);

        Lista1 = Lista1->sig;
        sscanf(Lista1->palabra, "%d", &numeroconvertido);
        if(numeroconvertido < contadorexp1)
        {
            copiarArbol(arbolexpreID, TraerArbolExp(L , numeroconvertido));
            printf("El valor de la expresion es: \n");
            MostrarArbol(arbolexpreID);
        }
        else
            printf("\nNo existe una expresion con ese valor\n");


}

void Evaluate (ListaString Lista1, ListaExpresiones ListExpPrincipal,int contadorexp1){

    ArbolExpresiones arbolevaluate;
    Crear(arbolevaluate);
    int numeroconvertido;
    boolean resu;

        Lista1=Lista1->sig;                                                     //Avanzo al string 2
        sscanf(Lista1->palabra, "%d", &numeroconvertido);                       //Convierto el string en entero
        if (numeroconvertido < contadorexp1)                                    //Me fijo si existe contador en la lista de expresiones
        {

            copiarArbol(arbolevaluate,TraerArbolExp(ListExpPrincipal, numeroconvertido));    //Traigo el arbol de la lista para evaluarlo
            if(EvaluarArbol(arbolevaluate)== TRUE)                               //Funcion para evaluar un arbol de expresiones

                printf("TRUE");

            else
                printf("FALSE");

        }
        else
           printf("Mensaje de error\n");

}

void Compound(ListaString Lista1,ListaExpresiones &ListExpPrincipal, int & contadorexp1){


int numeroconvertido, numeroconvertido2;
ValorNodo ValorNodoCompound;
ValorNodo ValorNodoParIzq;
ValorNodo ValorNodoParDer;
ArbolExpresiones arbolPrincipal;
Crear(arbolPrincipal);
ArbolExpresiones arbolDer;
Crear(arbolDer);
ArbolExpresiones arbolIzq;
Crear(arbolIzq);
ArbolExpresiones arbolIzqPar;
Crear(arbolIzqPar);
ArbolExpresiones arbolDerPar;
Crear(arbolDerPar);
Expresion expre;




        Lista1=Lista1->sig;                                                     //Avanzo a string 2

        if((streq("NOT",Lista1->palabra)) && (LargoRecu(Lista1)<=3))
        {
             Lista1=Lista1->sig;
             sscanf(Lista1->palabra, "%d", &numeroconvertido);

             if(numeroconvertido < contadorexp1)                                                                //Es menor a contador es por que existe una expresion con ese numero
               {
                AsignarValorNodoNOT(ValorNodoCompound);                                                         //Cargamos un valor nodo con Not
                AsignarValorParIzq(ValorNodoParIzq);                                                            //Cargamos un valor nodo con (
                AsignarValorParDer(ValorNodoParDer);                                                            //Cargamos un valor nodo con )
                CargarArbolParentesis(arbolIzqPar, ValorNodoParIzq);                                            //Cargamos arbol parentesis izq
                CargarArbolParentesis(arbolDerPar, ValorNodoParDer);                                            //Cargamos arbol con parentesis der
                copiarArbol(arbolDer,TraerArbolExp(ListExpPrincipal, numeroconvertido));
                Cons(ValorNodoCompound,arbolDer,arbolPrincipal,ValorNodoParIzq,ValorNodoParDer);
                CargarExpresion(arbolPrincipal, expre, contadorexp1);                                           //Cargamos expresion con ArbolPrincipal
                InsBackIterExp(ListExpPrincipal, expre);                                                        //Insertamos la expresion en la Lista Principal de Expresiones
                MostrarArbol(arbolPrincipal);
               }
        }
                            //%%%%%%%%%%   COMANDO AND Y OR  %%%%%%%%%%%%
       else
       {


            sscanf(Lista1->palabra, "%d", &numeroconvertido);                                                   //Convierto string 2 a entero
        if (numeroconvertido<contadorexp1)                                                                      //Condicion si el numero existe en la lista de expresiones
        {
            Lista1=Lista1->sig;                                                                                 //Avanzo al string 3

            if (streq("AND",Lista1->palabra))                                                                   // Condicion que el tercer string sea AND
             {
                AsignarValorNodoAND(ValorNodoCompound);
             }
             else if(streq("OR",Lista1->palabra)){                                                              // Condicion que el tercer string sea OR
                AsignarValorNodoOR(ValorNodoCompound);
             }
                Lista1=Lista1->sig;                                                                             //Avanzo al cuarto String
                sscanf(Lista1->palabra, "%d", &numeroconvertido2);                                              //Convierto el string 4 en entero

                if(numeroconvertido2<contadorexp1)                                                              //condicion de que el entero exista en la lista de expresiones
                {
                    AsignarValorParIzq(ValorNodoParIzq);                                                        //Cargamos un valor nodo con (
                    AsignarValorParDer(ValorNodoParDer);                                                        //Cargamos un valor nodo con )
                    CargarArbolParentesis(arbolIzqPar, ValorNodoParIzq);                                        //Cargamos arbol parentesis izq
                    CargarArbolParentesis(arbolDerPar, ValorNodoParDer);
                    copiarArbol(arbolIzq, TraerArbolExp(ListExpPrincipal, numeroconvertido));
                    copiarArbol(arbolDer, TraerArbolExp(ListExpPrincipal, numeroconvertido2));
                    Cons2(ValorNodoCompound,arbolIzq,arbolDer,ValorNodoParIzq,ValorNodoParDer,arbolPrincipal);
                    CargarExpresion(arbolPrincipal, expre, contadorexp1);                                       //Cargamos expresion con ArbolPrincipal
                    InsBackIterExp(ListExpPrincipal, expre);                                                    //Insertamos la expresion en la Lista Principal de Expresiones
                    MostrarArbol(arbolPrincipal);
                }
                 else
                    printf("Error2\n");
         }

            }


}

void Save(ListaString Lista1,ListaExpresiones &ListExpPrincipal, int & contadorexp1)
{

int numeroconvertido;

ArbolExpresiones arbolPrincipal;
Crear(arbolPrincipal);
ArbolExpresiones arbolSinID;
Crear(arbolSinID);




        Lista1=Lista1->sig;                                                     //Avanzo a string 2
        sscanf(Lista1->palabra, "%d", &numeroconvertido);                       //Convierto string 2 a entero
        if (numeroconvertido<contadorexp1)                                      //Condicion si el numero existe en la lista de expresiones
        {
            Lista1=Lista1->sig;                                                 //Avanzo al string 3
                    copiarArbol(arbolSinID ,TraerArbolExp(ListExpPrincipal, numeroconvertido));     //Extraigo y copio arbol de expresiones
                    AsignarIDenOrden(arbolSinID);                                                   //Asigno ID en orden al arbol
                    MostrarArbol(arbolSinID);
                    Bajar_ArbolExpresiones(arbolSinID, Lista1->palabra);
        }
                 else
                    printf("Error2\n");



}

void Load(ListaString Lista1,ListaExpresiones &ListExpPrincipal, int & contadorexp1)
{

int numeroconvertido;
Expresion expre;

ArbolExpresiones Arbolaguardar;
Crear(Arbolaguardar);

ArbolExpresiones arbolSinID;
Crear(arbolSinID);



        Lista1=Lista1->sig;                                                     //Avanzo a string 2
        if (Existe(Lista1->palabra))                                      //Condicion si el numero existe en la lista de expresiones
        {
        Levantar_ArbolExpresiones(Arbolaguardar, Lista1->palabra);
        CargarExpresion(Arbolaguardar, expre, contadorexp1);            //Cargamos expresion con ArbolPrincipal
        InsBackIterExp(ListExpPrincipal, expre);                        //Insertamos la expresion en la Lista Principal de Expresiones
        }
                 else
                    printf("Error2\n");



}

