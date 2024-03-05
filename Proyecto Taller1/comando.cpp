#include "comando.h"

void Atomic(ListaString L, int &contadorexp, ListaExpresiones &ListExp){

ValorNodo valNodo;
ArbolExpresiones arbolexp;
Crear(arbolexp);
Expresion expre;

            L = L->sig;
            if(streq("true",L->palabra)||streq("false",L->palabra))
            {
                CargarValorNodo(L, valNodo);
                CargarArbolAtomic(valNodo,arbolexp);
                CargarExpresion(arbolexp, expre, contadorexp);
                InsBackIterExp(ListExp, expre);
                printf("\nExpresion %d :",contadorexp-1);
                MostrarArbol(arbolexp);
                printf("\n");
            }
            else
            printf("\nExpresion invalida\n");


}

void Show(ListaString Lista1 ,ListaExpresiones L, int contadorexp1){

        int numeroconvertido;
        ArbolExpresiones arbolexpreID;
        Crear(arbolexpreID);

        Lista1 = Lista1->sig;
        if(EsDigito(Lista1->palabra))
        {
            sscanf(Lista1->palabra, "%d", &numeroconvertido);
        if(numeroconvertido < contadorexp1)
        {
            copiarArbol(arbolexpreID, TraerArbolExp(L , numeroconvertido));
            printf("\nLa expresion %d es: ",contadorexp1-1);
            MostrarArbol(arbolexpreID);
            printf("\n");
        }
        else
            printf("\nNo existe una expresion con ese valor\n");
        }
        else
            printf("Expresion incorrecta");





}

boolean EvaluarArbol(ArbolExpresiones a, boolean &resultado) {
    boolean resultadoaux;

    if (a->info.dato.valor == TRUE) {
        resultado = TRUE;
            }
        else
            if (a->info.dato.valor == FALSE) {
                resultado = FALSE;
            }
        else
            if (a->info.dato.operador == 'A') {
                resultado = (boolean)(EvaluarArbol(a->hder, resultado) && EvaluarArbol(a->hizq, resultado));
            }
        else
            if (a->info.dato.operador == 'O') {
                resultado = (boolean)(EvaluarArbol(a->hder, resultado) || EvaluarArbol(a->hizq, resultado));
            }
       else
            if (a->info.dato.operador == 'N') {
                resultadoaux = (boolean)(EvaluarArbol(a->hder, resultado));
                resultado = (boolean)(!resultadoaux);
            }

    return resultado;
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

                                                                           //Convertimos el string 3 en un entero
                if(EsDigito(Lista1->palabra))
                {
                    sscanf(Lista1->palabra, "%d", &numeroconvertido);
                    if(numeroconvertido < contadorexp1)                                                                    //Es menor a contador es por que existe una expresion con ese numero
                       {                                                                                                    //{
                            AsignarValorNodoNOT(ValorNodoCompound);                                                         //Cargamos un valor nodo con Not
                            AsignarValorParIzq(ValorNodoParIzq);                                                            //Cargamos el valor nodo del parentesis izquierdo
                            AsignarValorParDer(ValorNodoParDer);                                                            //Cargamos un valor nodo del parentesis derecho
                            copiarArbol(arbolDer,TraerArbolExp(ListExpPrincipal, numeroconvertido));                        //Copiamos el arbol de la lista de expresiones que tiene asignado el entero convertido
                            Cons(ValorNodoCompound,arbolDer,arbolPrincipal,ValorNodoParIzq,ValorNodoParDer);                //Construimos el arbol a partir del valor not, el arbol copiado de la lista y le agregamos sus respectivos parentesis
                            CargarExpresion(arbolPrincipal, expre, contadorexp1);                                           //Cargamos expresion con ArbolPrincipal
                            InsBackIterExp(ListExpPrincipal, expre);                                                        //Insertamos la expresion en la Lista Principal de Expresiones
                            printf("\nExpresion %d :",contadorexp1-1);                                                          //Mostramos el numero de expresion
                            MostrarArbol(arbolPrincipal);                                                                   //Mostramos el arbol construido en pantalla
                            printf("\n");                                                                                   //Salto de linea
                       }
                       else
                            printf("\nExpresion invalida");
                }
                else
                    printf("\nExpresion invalida");
            }
                                //%%%%%%%%%%   COMANDO AND Y OR  %%%%%%%%%%%%
               else                                                                                                                 //Si no es NOT
               {                                                                                                                    //{
                   if((LargoRecu(Lista1)<5))
                  {

                    if(EsDigito(Lista1->palabra))
                        {
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

                                            if(EsDigito(Lista1->palabra))
                                            {
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
                                                   printf("\nExpresion incorrecta\n");
                                            }else
                                                   printf("\nExpresion incorrecta\n");
                                        }
                                        else
                                             printf("\nExpresion incorrecta\n");
                                                                                                                                    //Mensaje de error
                }else
                    printf("\nExpresion incorrecta\n");
            }else
                printf("\nExpresion incorrecta\n");
            }
            else
                printf("\nExpresion incorrecta\n");

       }


}

void Save(ListaString Lista1,ListaExpresiones &ListExpPrincipal, int & contadorexp1){

int numeroconvertido;
str archivo;
str dat;
char c;
strcrear(archivo);
strcrear(dat);
ArbolExpresiones arbolSinID;
Crear(arbolSinID);
int suma=1;



        Lista1=Lista1->sig;
        if(EsDigito(Lista1->palabra))
        {
            sscanf(Lista1->palabra, "%d", &numeroconvertido);                       //Convierto string 2 a entero
            if (numeroconvertido<contadorexp1)                                      //Condicion si el numero existe en la lista de expresiones
            {
                    Lista1=Lista1->sig;
                    dividirLoad(Lista1->palabra,archivo,dat);

                    if((Alfabeto(archivo))&& (streq(".dat",dat)))
                    {
                        if (!Existe(Lista1->palabra))
                        {


                                    copiarArbol(arbolSinID ,TraerArbolExp(ListExpPrincipal, numeroconvertido));     //Extraigo y copio arbol de expresiones
                                    AsignarIDenOrden(arbolSinID, suma);                                                   //Asigno ID en orden al arbol
                                    Bajar_ArbolExpresiones(arbolSinID, Lista1->palabra);
                                    printf("\nLa expresion se guardo con exito\n");


                        }else
                            printf("\nYa existe una expresion con ese nombre\n");



                    }else
                        printf("\nLa expresion que desea guardar no es valida\n");

            }else
                    printf("\nLa expresion que desea guardar no es valida\n");


        }else
                    printf("\nLa expresion que desea guardar no es valida\n");


}

void Load(ListaString Lista1,ListaExpresiones &ListExpPrincipal, int & contadorexp1){

int numeroconvertido;
Expresion expre;
str archivo;
str dat;
strcrear(archivo);
strcrear(dat);

ArbolExpresiones Arbolaguardar;
Crear(Arbolaguardar);


        Lista1=Lista1->sig;
        dividirLoad(Lista1->palabra,archivo,dat);
        if((Alfabeto(archivo))&& (streq(".dat",dat)))
        {
           if (Existe(Lista1->palabra))                                      //Condicion si el numero existe en la lista de expresiones
        {
        Levantar_ArbolExpresiones(Arbolaguardar, Lista1->palabra);
        CargarExpresion(Arbolaguardar, expre, contadorexp1);            //Cargamos expresion con ArbolPrincipal
        InsBackIterExp(ListExpPrincipal, expre);
        printf("\nEL archivo se cargo correctamente en la Expresion : %d", contadorexp1-1);                        //Insertamos la expresion en la Lista Principal de Expresiones
        }
                 else
                    printf("\nNombre de archivo incorrecto\n");
        }
         else
                    printf("\nNombre de archivo incorrecto\n");



}

