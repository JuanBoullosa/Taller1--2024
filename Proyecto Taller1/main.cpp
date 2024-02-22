#include <iostream>
#include "ArbolExpresiones.h"
#include "Strigg.h"
#include "ListaString.h"
#include "ListaExpresiones.h"


//Prueba github
//daleeee looocooo

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
str comando; // Declaramos string donde va a ingresar el usuario comando
strcrear(comando);//Creamos el string comando
printf("Ingrese comando: ");//Solicitamos al usuario que ingrese un comando
scan(comando);  // Scan dinamico para el ingreso de el string comando
printf("\n");   // Salto de linea

ListaString Lista1;             //Declaramos la lista que usaremos para evaluar los string
CrearLista(Lista1);
str aux;
strcrear(aux);             //Creamos la lista
partirString(comando, Lista1);  // Procedimiento para partir el string

MostrarLista(Lista1);           // Mostramos el string partido

ArbolExpresiones arbol;
int id=0;
Expresion expre;
ListaExpresiones ListExp;
CrearListaExpresiones(ListExp);




//Para resolver comando atomic
if(LargoRecu(Lista1) == 2){
if(streq(atomic, Lista1->palabra)){
    Lista1 = Lista1->sig;

    if(streq(expTrue, Lista1->palabra)){
        Crear(arbol);
        arbol->info.dato.valor = TRUE;
        expre.numero = id+1;
        expre.arbol = arbol;
        id = id+1;
        InsBackIterExp(ListExp, expre);
                }
    if(streq(expFalse, Lista1->palabra)){
                Crear(arbol);
                arbol->info.dato.valor = FALSE;
                expre.numero = id+1;
                expre.arbol = arbol;
                id = id +1;
                InsBackIterExp(ListExp, expre);
                }
                else
                    printf("\nComando incorrecto\n");

}
}
// si la cantidad de palabras menor a 5 y mayor a 2
if(streq(compound, Lista1->palabra))
    printf("Es igual al string compound");
    // si la cantidad de palabras es 3
    // comprobar si la segunda palabra es not y la tercera un entero valido de no ser dar error correspondiente
    //si la cantidad es 4
    // comprobar que la tercera sea and u or y la segunda y la cuarta sean un entero valido de no ser dar error correspondiente
    //crear el arbol de expresion
    //crear valor nodo para los nodos a partir de la expresiones de los numeros enteros
    //asignar un parentesis a abierto al valor mas a la izquierda del arbol y un parentesis cerrrado al valor mas a la derecha del arbol
if(streq(show, Lista1->palabra))
    printf("Es igual al string show");

if(streq(evaluate, Lista1->palabra))
    printf("Es igual al string evaluate");

if(streq(save, Lista1->palabra))
    printf("Es igual al string save");

if(streq(load, Lista1->palabra))
    printf("Es igual al string load");

if(streq(exit, Lista1->palabra))
    printf("Es igual al string atomic");







}


