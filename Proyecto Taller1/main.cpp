#include <iostream>
#include "ArbolExpresiones.h"
#include "Strigg.h"
#include "ListaString.h"
#include "ListaExpresiones.h"

int main()
{


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
print(atomic);
printf("\n");
//Comando compound
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
print(compound);
printf("\n");
//Comando show
str show;
strcrear(show);
show = new char[5];//Solicitamos la cantidad de espacios en memoria para show
show[0]='s';
show[1]='h';
show[2]='o';
show[3]='w';
show[4]='\0';
print(show);
printf("\n");
//Comando evaluate
str evaluate;
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
print(evaluate);
printf("\n");
//Comando save
str save;
strcrear(save);
save = new char[5];//Solicitamos la cantidad de espacios en memoria para save
save[0]='s';
save[1]='a';
save[2]='v';
save[3]='e';
save[4]='\0';
print(save);
printf("\n");
//Comando load
str load;
strcrear(load);
load = new char[5];//Solicitamos la cantidad de espacios en memoria para load
load[0]='l';
load[1]='o';
load[2]='a';
load[3]='d';
load[4]='\0';
print(load);
printf("\n");
//Comando exit
str exit;
strcrear(exit);
exit = new char[4];//Solicitamos la cantidad de espacios en memoria para exit
exit[0]='e';
exit[1]='x';
exit[2]='i';
exit[3]='t';
exit[4]='\0';
print(exit);
printf("\n");
//Expresion true en string para comparar
str expTrue;
strcrear(expTrue);
expTrue = new char[5];//Solicitamos la cantidad de espacios en memoria para true
expTrue[0]='t';
expTrue[1]='r';
expTrue[2]='u';
expTrue[3]='e';
expTrue[4]='\0';
print(expTrue);
printf("\n");
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
print(expFalse);
printf("\n");

str expNot;
strcrear(expNot);
expNot = new char[4];//Solicitamos la cantidad de espacios en memoria operador or
expNot[0]='N';
expNot[1]='O';
expNot[2]='T';
expNot[3]='\0';
print(expNot);
printf("\n");

str comando;                             // Declaramos string donde va a ingresar el usuario comando
strcrear(comando);                      //Creamos el string comando
ListaString Lista1;                     //Declaramos la lista que usaremos para evaluar los string
CrearLista(Lista1);
str aux;
<<<<<<< HEAD
strcrear(aux);                          //Creamos la lista
ArbolExpresiones arbolexp;          // Creamos arbol de expresiones
Expresion expre;                    //Creamos  expresion
=======
strcrear(aux);             //Creamos la lista
partirString(comando, Lista1);  // Procedimiento para partir el string
printf("Mostrar Lista de string: \n");
MostrarLista(Lista1);           // Mostramos el string partido
printf("\n");

ArbolExpresiones arbolexp;        // Creamos arbol de expresiones
ArbolExpresiones arbol;
ArbolExpresiones arbolcompuesto;
Expresion expre;                //Creamos  expresion
>>>>>>> 2477acb09351c792ed7e32e5074818b634fa53d7
ListaExpresiones ListExp;           //Declaramos y creamos lista de expresiones para almacenar expresion
CrearListaExpresiones(ListExp);
ValorNodo valNodo;

//for(int i=0;i<=2;i++){
printf("Ingrese comando: ");            //Solicitamos al usuario que ingrese un comando
scan(comando);                          // Scan dinamico para el ingreso de el string comando
printf("\n");                          // Salto de linea

partirString(comando, Lista1);          // Procedimiento para partir el string
printf("Mostrar Lista de string: \n");
MostrarLista(Lista1);                   // Mostramos el string partido
printf("\n");


//show(arbol);
int contadorexp1=1;

/*%%%%%%%%  COMANDO ATOMIC   %%%%%%%%*/
if((LargoRecu(Lista1) == 2) && (streq(atomic, Lista1->palabra)))
{

            Lista1=Lista1->sig;
            if(streq(expTrue,Lista1->palabra)||streq(expFalse,Lista1->palabra))
            {
                CargarValorNodo(Lista1, valNodo);
                CargarArbolAtomic(valNodo,arbolexp);
                CargarExpresion(arbolexp, expre, contadorexp1);
                InsBackIterExp(ListExp, expre);
                printf("\nMostrar arbol: \n");
                //MostrarArbol(ListExp->expre.arbol)   Son comandos de prueba si cargaron bien.
                //MostrarArbol(arbolexp);
                //MostrarListaExp(ListExp);              Arreglar esto!
            }
        else
            printf("\nComando incorrecto\n");
}




/*%%%%%%%%  COMANDO COMPOUND   %%%%%%%%*/
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
            if( numeroconvertido == expre.numero)//condicion de si existe en la lista
            {

                //CargarValorNodo(Lista1, valNodo);                                 //Cargar valor NOT
                AsignarValorNodoNOT(ValorNodoNOT);                                  //Cargo ValorNodo NOT sin importar el string
                arbolexpreID=TraerArbolExp(ListExp, numeroconvertido);             //trae arbol indicado con ID.
                CargarArbolNOTSinParent(ValorNodoNOT, arbolexpreID, arbolaux);        //Cargar Arbol sin parentesis (Solo hijo derecho)
                AsignarValorParIzq(ValorNodoParIzq);
                AsignarValorParDer(ValorNodoParDer);
                AgregarParentesisIzquierdo(arbolaux, ValorNodoParIzq);
                AgregarParentesisDerecho(arbolaux,ValorNodoParDer);                 //Le agrego parentesis al arbol

                CargarExpresion(arbolaux, expre, contadorexp1);
                InsBackIterExp(ListExp, expre);
                //printf("\nMostrar arbol: \n");
                printf("\nMostrar arbol: \n");
                MostrarArbol(ListExp->expre.arbol);

            }
                else
                    printf("Error");
        }
        //Cargar nodo OR y AND
        if  (((streq(expAND,Lista1->palabra))&& (LargoRecu(Lista1)<=4)) &&
            ((streq(expOR,Lista1->palabra))&& (LargoRecu(Lista1)<=4)))
        {


        }

    }
}







// si la cantidad de palabras menor a 5 y mayor a 2
//if(streq(compound, Lista1->palabra))
 //   printf("Es igual al string compound");
    // si la cantidad de palabras es 3
    // comprobar si la segunda palabra es not y la tercera un entero valido de no ser dar error correspondiente
    //si la cantidad es 4
    // comprobar que la tercera sea and u or y la segunda y la cuarta sean un entero valido de no ser dar error correspondiente
    //crear el arbol de expresion
    //crear valor nodo para los nodos a partir de la expresiones de los numeros enteros
    //asignar un parentesis a abierto al valor mas a la izquierda del arbol y un parentesis cerrrado al valor mas a la derecha del arbol


/*if(LargoRecu(Lista1) == 2)
{
    if(streq(show, Lista1->palabra))
    {
        Lista1 = Lista1->sig;

        if(Lista1->palabra == expre->numero) //Ver como transformar el string para reconocer un numero
        {
            printf("%d", expre.numero);  //Hay que crear selectora para un futuro
        }
                    else
                    {
                        printf("\nComando incorrecto\n");
                    }


    }
}*/

//if(streq(evaluate, Lista1->palabra))
    //printf("Es igual al string evaluate");

//if(streq(save, Lista1->palabra))
   // printf("Es igual al string save");

//if(streq(load, Lista1->palabra))
   // printf("Es igual al string load");

//if(streq(exit, Lista1->palabra))
//printf("Es igual al string atomic");




