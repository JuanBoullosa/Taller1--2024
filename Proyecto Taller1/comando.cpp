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
                printf("\nExpresion %d:\n",contadorexp-1);
                MostrarArbol(arbolexp);
                printf("\n");
            }
            else
            printf("Error en el comando ingresado\n");

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
            printf("\n");
        }
        else
            printf("\nNo existe una expresion con ese valor\n");


}

void Evaluate (ListaString Lista1, ListaExpresiones ListExpPrincipal,int contadorexp1){

    ArbolExpresiones arbolevaluate;
    Crear(arbolevaluate);
    int numeroconvertido;


        Lista1=Lista1->sig;                                                     //Avanzo al string 2
        sscanf(Lista1->palabra, "%d", &numeroconvertido);                       //Convierto el string en entero
        if (numeroconvertido < contadorexp1)                                    //Me fijo si existe contador en la lista de expresiones
        {

            copiarArbol(arbolevaluate,TraerArbolExp(ListExpPrincipal, numeroconvertido));    //Traigo el arbol de la lista para evaluarlo
            if(EvaluarArbol(arbolevaluate)== TRUE)                               //Funcion para evaluar un arbol de expresiones


                printf("El valor de la expresion es :TRUE\n");

            else
                printf("El valor de la expresion es :FALSE\n");

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
Expresion expre;


        Lista1=Lista1->sig;                                                                                         //Avanzo a string 2

        if((streq("NOT",Lista1->palabra)) && (LargoRecu(Lista1)<=3))                                                //Si el string 2 es NOT y su largo es 3
        {                                                                                                           //{
             Lista1=Lista1->sig;                                                                                    //Avanzo al string 3
             sscanf(Lista1->palabra, "%d", &numeroconvertido);                                                      //Convertimos el string 3 en un entero

             if(numeroconvertido < contadorexp1)                                                                    //Es menor a contador es por que existe una expresion con ese numero
               {                                                                                                    //{
                    AsignarValorNodoNOT(ValorNodoCompound);                                                         //Cargamos un valor nodo con Not
                    AsignarValorParIzq(ValorNodoParIzq);                                                            //Cargamos el valor nodo del parentesis izquierdo
                    AsignarValorParDer(ValorNodoParDer);                                                            //Cargamos un valor nodo del parentesis derecho
                    copiarArbol(arbolDer,TraerArbolExp(ListExpPrincipal, numeroconvertido));                        //Copiamos el arbol de la lista de expresiones que tiene asignado el entero convertido
                    Cons(ValorNodoCompound,arbolDer,arbolPrincipal,ValorNodoParIzq,ValorNodoParDer);                //Construimos el arbol a partir del valor not, el arbol copiado de la lista y le agregamos sus respectivos parentesis
                    CargarExpresion(arbolPrincipal, expre, contadorexp1);                                           //Cargamos expresion con ArbolPrincipal
                    InsBackIterExp(ListExpPrincipal, expre);                                                        //Insertamos la expresion en la Lista Principal de Expresiones
                    printf("Expresion %d",contadorexp1-1);                                                          //Mostramos el numero de expresion
                    MostrarArbol(arbolPrincipal);                                                                   //Mostramos el arbol construido en pantalla
                    printf("\n");                                                                                   //Salto de linea
               }
        }
                            //%%%%%%%%%%   COMANDO AND Y OR  %%%%%%%%%%%%
       else                                                                                                                 //Si no es NOT
       {                                                                                                                    //{
            sscanf(Lista1->palabra, "%d", &numeroconvertido);                                                               //Convierto string 2 a entero

            if (numeroconvertido<contadorexp1)                                                                              //Condicion si el numero existe en la lista de expresiones
            {                                                                                                               //{
                Lista1=Lista1->sig;                                                                                         //Avanzo al string 3

                if (streq("AND",Lista1->palabra))                                                                           // Condicion que el tercer string sea AND
                {                                                                                                           //{
                    AsignarValorNodoAND(ValorNodoCompound);                                                                 //Cargamos el valor nodo con AND
                }                                                                                                           //}
                    else if(streq("OR",Lista1->palabra))                                                                    // Condicion que el tercer string sea OR
                        {                                                                                                   //{
                            AsignarValorNodoOR(ValorNodoCompound);                                                          //Cargamos el valor nodo con OR
                        }                                                                                                   //}
                            if ((ValorNodoCompound.dato.operador == 'A') || (ValorNodoCompound.dato.operador == 'O'))
                           {
                                Lista1=Lista1->sig;                                                                             //Avanzo al cuarto String
                                sscanf(Lista1->palabra, "%d", &numeroconvertido2);                                              //Convierto el string 4 en entero

                                if(numeroconvertido2<contadorexp1)                                                              //condicion de que el entero exista en la lista de expresiones
                                {
                                    AsignarValorParIzq(ValorNodoParIzq);                                                        //Cargamos un valor nodo con (
                                    AsignarValorParDer(ValorNodoParDer);                                                        //Cargamos un valor nodo con )
                                    copiarArbol(arbolIzq, TraerArbolExp(ListExpPrincipal, numeroconvertido));                   //Copiamos el arbol de la lista de expresiones que tiene asignado el primer entero convertido
                                    copiarArbol(arbolDer, TraerArbolExp(ListExpPrincipal, numeroconvertido2));                  //Copiamos el arbol de la lista de expresiones que tiene asignado el segundo entero convertido
                                    Cons2(ValorNodoCompound,arbolIzq,arbolDer,ValorNodoParIzq,ValorNodoParDer,arbolPrincipal);  //Construimos el arbol a partir del valor nodo sea AND u OR sus respectivos arbols copiados a la izquierda y derecha y la correcta parentizacion
                                    CargarExpresion(arbolPrincipal, expre, contadorexp1);                                       //Cargamos expresion con ArbolPrincipal
                                    InsBackIterExp(ListExpPrincipal, expre);                                                    //Insertamos la expresion en la Lista Principal de Expresiones
                                    printf("\nExpresion %d :\n",contadorexp1-1);                                                //Mostramos el numero de expresion
                                    MostrarArbol(arbolPrincipal);                                                               //Mostramos el arbol
                                    printf("\n");                                                                               //Salto de linea
                                }
                                else
                                    printf("Error en el comando ingresado\n");
                            }
                            else
                                 printf("Error en el comando ingresado\n");
                                                                                                    //Mensaje de error
            }else
                printf("Error en el comando ingresado\n");


       }


}

void Save(ListaString Lista1,ListaExpresiones &ListExpPrincipal, int & contadorexp1){

int numeroconvertido;

ArbolExpresiones arbolPrincipal;
Crear(arbolPrincipal);
ArbolExpresiones arbolSinID;
Crear(arbolSinID);
int suma=1;



        Lista1=Lista1->sig;                                                     //Avanzo a string 2
        sscanf(Lista1->palabra, "%d", &numeroconvertido);                       //Convierto string 2 a entero
        if (numeroconvertido<contadorexp1)                                      //Condicion si el numero existe en la lista de expresiones
        {
            Lista1=Lista1->sig;                                                 //Avanzo al string 3
                    copiarArbol(arbolSinID ,TraerArbolExp(ListExpPrincipal, numeroconvertido));     //Extraigo y copio arbol de expresiones
                    AsignarIDenOrden(arbolSinID, suma);                                                   //Asigno ID en orden al arbol
                    MostrarArbol(arbolSinID);
                    MostrarIDdelArbol (arbolSinID);
                    Bajar_ArbolExpresiones(arbolSinID, Lista1->palabra);
        }
                 else
                    printf("Error2\n");



}

void Load(ListaString Lista1,ListaExpresiones &ListExpPrincipal, int & contadorexp1){

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

