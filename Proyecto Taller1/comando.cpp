#include "comando.h"


void Atomic(ListaString L, int &contadorexp, ListaExpresiones &ListExp){

//Comando atomic
str atomic; //Declaramos string para ATOMIC
strcrear(atomic); //Creamos string ATOMIC
atomic = new char[7];//Solicitamos la cantidad de espacios en memoria para atomic
atomic[0]='a';
atomic[1]='t';
atomic[2]='o';
atomic[3]='m';              //Ingresamos caracteres de atomic
atomic[4]='i';
atomic[5]='c';
atomic[6]='\0';
str expTrue;
strcrear(expTrue);
expTrue = new char[5];//Solicitamos la cantidad de espacios en memoria para true
expTrue[0]='t';
expTrue[1]='r';
expTrue[2]='u';
expTrue[3]='e';
expTrue[4]='\0';
//Expresion false en string para comparar
str expFalse;
strcrear(expFalse);
expFalse = new char[6];//Solicitamos la cantidad de espacios en memoria para false
expFalse[0]='f';
expFalse[1]='a';
expFalse[2]='l';
expFalse[3]='s';
expFalse[4]='e';
expFalse[5]='\0';
ValorNodo valNodo;
ArbolExpresiones arbolexp;
Expresion expre;


if((LargoRecu(L) == 2) && (streq(atomic, L->palabra)))
{


            L = L->sig;
            if(streq(expTrue,L->palabra)||streq(expFalse,L->palabra))
            {
                CargarValorNodo(L, valNodo);
                CargarArbolAtomic(valNodo,arbolexp);
                CargarExpresion(arbolexp, expre, contadorexp);
                InsBackIterExp(ListExp, expre);
                //printf("\nMostrar arbol: \n");
                //MostrarArbol(ListExp->expre.arbol);
            }
        else
            printf("\nComando incorrecto\n");
            }
            else
                printf("\nComando incorrecto\n");



}

void CargarComandos (str &atomic, str & compound, str & show, str & evaluate, str & save, str &load, str & exit, str &expTrue, str &expFalse, str &expNot, str & expAnd, str & expOr){
//Comando atomic

strcrear(atomic); //Creamos string ATOMIC
atomic = new char[7];//Solicitamos la cantidad de espacios en memoria para atomic
atomic[0]='a';
atomic[1]='t';
atomic[2]='o';
atomic[3]='m';              //Ingresamos caracteres de atomic
atomic[4]='i';
atomic[5]='c';
atomic[6]='\0';

//Comando compound

strcrear(compound);
compound = new char[9];//Solicitamos la cantidad de espacios en memoria para compound
compound[0]='c';
compound[1]='o';
compound[2]='m';
compound[3]='p';
compound[4]='o';
compound[5]='u';
compound[6]='n';
compound[7]='d';
compound[8]='\0';

//Comando show

strcrear(show);
show = new char[5];//Solicitamos la cantidad de espacios en memoria para show
show[0]='s';
show[1]='h';
show[2]='o';
show[3]='w';
show[4]='\0';

//Comando evaluate

strcrear(evaluate);
evaluate = new char[9];//Solicitamos la cantidad de espacios en memoria para evaluate
evaluate[0]='e';
evaluate[1]='v';
evaluate[2]='a';
evaluate[3]='l';
evaluate[4]='u';
evaluate[5]='a';
evaluate[6]='t';
evaluate[7]='e';
evaluate[8]='\0';

//Comando save

strcrear(save);
save = new char[5];//Solicitamos la cantidad de espacios en memoria para save
save[0]='s';
save[1]='a';
save[2]='v';
save[3]='e';
save[4]='\0';

//Comando load

strcrear(load);
load = new char[5];//Solicitamos la cantidad de espacios en memoria para load
load[0]='l';
load[1]='o';
load[2]='a';
load[3]='d';
load[4]='\0';

//Comando exit

strcrear(exit);
exit = new char[4];//Solicitamos la cantidad de espacios en memoria para exit
exit[0]='e';
exit[1]='x';
exit[2]='i';
exit[3]='t';
exit[4]='\0';

//Expresion true en string para comparar

strcrear(expTrue);
expTrue = new char[5];//Solicitamos la cantidad de espacios en memoria para true
expTrue[0]='t';
expTrue[1]='r';
expTrue[2]='u';
expTrue[3]='e';
expTrue[4]='\0';

//Expresion false en string para comparar

strcrear(expFalse);
expFalse = new char[6];//Solicitamos la cantidad de espacios en memoria para false
expFalse[0]='f';
expFalse[1]='a';
expFalse[2]='l';
expFalse[3]='s';
expFalse[4]='e';
expFalse[5]='\0';



strcrear(expNot);
expNot = new char[4];//Solicitamos la cantidad de espacios en memoria operador or
expNot[0]='N';
expNot[1]='O';
expNot[2]='T';
expNot[3]='\0';

strcrear(expAnd);
expAnd = new char[4];//Solicitamos la cantidad de espacios en memoria operador or
expAnd[0]='A';
expAnd[1]='N';
expAnd[2]='D';
expAnd[3]='\0';

strcrear(expOr);
expOr = new char[4];//Solicitamos la cantidad de espacios en memoria operador or
expOr[0]='O';
expOr[1]='R';
expOr[2]='\0';


}

void Show(ListaString Lista1 ,ListaExpresiones L, int contadorexp1){

    str show;
    strcrear(show);
    show = new char[5];//Solicitamos la cantidad de espacios en memoria para show
    show[0]='s';
    show[1]='h';
    show[2]='o';
    show[3]='w';
    show[4]='\0';
    ArbolExpresiones arbolexpreID;
    int numeroconvertido;
     if(streq(show, Lista1->palabra))
    {
        Lista1 = Lista1->sig;
        sscanf(Lista1->palabra, "%d", &numeroconvertido);
        if(numeroconvertido < contadorexp1)
        {
            arbolexpreID=TraerArbolExp(L , numeroconvertido);
            printf("El valor de la expresion es: \n");
            MostrarArbol(arbolexpreID);
        }
                    else
                    {
                        printf("\nNo existe una expresion con ese valor\n");
                    }

    }

        else
            printf("\nNo existe una expresion con ese valor\n");

}

void Evaluate (ListaString Lista1, ListaExpresiones ListExpPrincipal, str evaluate, int contadorexp1){

    ArbolExpresiones arbolevaluate;
    int numeroconvertido;
    boolean resu;

if(streq(evaluate, Lista1->palabra))
{
    if (LargoRecu(Lista1)==2)                                                   //Condicion que el largo de la lista sea 2
    {
        Lista1=Lista1->sig;                                                     //Avanzo al string 2
        sscanf(Lista1->palabra, "%d", &numeroconvertido);                       //Convierto el string en entero
        if (numeroconvertido < contadorexp1)                                    //Me fijo si existe contador en la lista de expresiones
        {

            arbolevaluate=TraerArbolExp(ListExpPrincipal, numeroconvertido);    //Traigo el arbol de la lista para evaluarlo
            if(EvaluarArbol(arbolevaluate, resu))                               //Funcion para evaluar un arbol de expresiones
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
}

void Compound4(ListaString Lista1,ListaExpresiones &ListExpPrincipal, int & contadorexp1){
str compound;
strcrear(compound);
compound = new char[9];//Solicitamos la cantidad de espacios en memoria para compound
compound[0]='c';
compound[1]='o';
compound[2]='m';
compound[3]='p';
compound[4]='o';
compound[5]='u';
compound[6]='n';
compound[7]='d';
compound[8]='\0';
str expNot;
strcrear(expNot);
expNot = new char[4];//Solicitamos la cantidad de espacios en memoria operador or
expNot[0]='N';
expNot[1]='O';
expNot[2]='T';
expNot[3]='\0';
str expAnd;
strcrear(expAnd);
expAnd = new char[4];//Solicitamos la cantidad de espacios en memoria operador or
expAnd[0]='A';
expAnd[1]='N';
expAnd[2]='D';
expAnd[3]='\0';
str expOr;
strcrear(expOr);
expOr = new char[4];//Solicitamos la cantidad de espacios en memoria operador or
expOr[0]='O';
expOr[1]='R';
expOr[2]='\0';



int numeroconvertido, numeroconvertido2;

ValorNodo ValorNodoNOT;
ValorNodo ValorNodoAND;
ValorNodo ValorNodoOR;
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


    if (((LargoRecu(Lista1)>2) || (LargoRecu(Lista1)<5)) && (streq(compound, Lista1->palabra))) //Largo entre 2 y 5
    {
        Lista1=Lista1->sig;                                                     //Avanzo a string 2

        if((streq(expNot,Lista1->palabra)) && (LargoRecu(Lista1)<=3))
        {
             Lista1=Lista1->sig;
             sscanf(Lista1->palabra, "%d", &numeroconvertido);

             if(numeroconvertido < contadorexp1)                                //Es menor a contador es por que existe una expresion con ese numero
               {
                AsignarValorNodoNOT(ValorNodoNOT);                               //Cargamos un valor nodo con Not
                AsignarValorParIzq(ValorNodoParIzq);                             //Cargamos un valor nodo con (
                AsignarValorParDer(ValorNodoParDer);                             //Cargamos un valor nodo con )
                CargarArbolParentesis(arbolIzqPar, ValorNodoParIzq);                //Cargamos arbol parentesis izq
                CargarArbolParentesis(arbolDerPar, ValorNodoParDer);             //Cargamos arbol con parentesis der



                copiarArbol(arbolDer,TraerArbolExp(ListExpPrincipal, numeroconvertido));
                Cons(ValorNodoNOT,arbolDer,arbolPrincipal,ValorNodoParIzq,ValorNodoParDer);





                CargarExpresion(arbolPrincipal, expre, contadorexp1);            //Cargamos expresion con ArbolPrincipal
                InsBackIterExp(ListExpPrincipal, expre);                         //Insertamos la expresion en la Lista Principal de Expresiones

               }
        }
                            //%%%%%%%%%%   COMANDO AND Y OR  %%%%%%%%%%%%
       else
       {


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

                    CargarArbolParentesis(arbolIzqPar, ValorNodoParIzq);          //Cargamos arbol parentesis izq
                    CargarArbolParentesis(arbolDerPar, ValorNodoParDer);


                    copiarArbol(arbolIzq, TraerArbolExp(ListExpPrincipal, numeroconvertido));
                    copiarArbol(arbolDer, TraerArbolExp(ListExpPrincipal, numeroconvertido2));
                    Cons2(ValorNodoAND,arbolIzq,arbolDer,ValorNodoParIzq,ValorNodoParDer,arbolPrincipal);

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

                    copiarArbol(arbolIzq, TraerArbolExp(ListExpPrincipal, numeroconvertido));
                    copiarArbol(arbolDer, TraerArbolExp(ListExpPrincipal, numeroconvertido2));
                    Cons2(ValorNodoOR,arbolIzq,arbolDer,ValorNodoParIzq,ValorNodoParDer,arbolPrincipal); //Cargamos el arbol principal con ( NOT Arbol ID )


                    CargarExpresion(arbolPrincipal, expre, contadorexp1);            //Cargamos expresion con ArbolPrincipal
                    InsBackIterExp(ListExpPrincipal, expre);                         //Insertamos la expresion en la Lista Principal de Expresiones
                }

            }

         }
        }

    }

}
