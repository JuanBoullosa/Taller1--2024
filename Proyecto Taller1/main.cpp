#include <iostream>
#include "ArbolExpresiones.h"
#include "Strigg.h"
#include "ListaString.h"
#include "ListaExpresiones.h"
#include "comando.h"

int main()
{



//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   Esta es la parte principal del codigo    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

str comando;                                           // Declaramos string donde va a ingresar el usuario comando
strcrear(comando);                                      //Creamos el string comando
ListaString Lista1;                                     //Declaramos la lista que usaremos para evaluar los string
CrearLista(Lista1);
int contadorexp1=1;
ListaExpresiones ListExpPrincipal;
CrearListaExpresiones(ListExpPrincipal);


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  Ingreso de comando y division de palabras  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
do{


printf("\nIngrese comando: \n");                        //Solicitamos al usuario que ingrese un comando
scan(comando);                                          // Scan dinamico para el ingreso de el string comando
printf("\n");                                           // Salto de linea
partirString(comando, Lista1);                          // Procedimiento para partir el string

if (((LargoRecu(Lista1)>2) || (LargoRecu(Lista1)<5)) && (streq("compound", Lista1->palabra)))
    Compound4(Lista1,ListExpPrincipal,contadorexp1);

    else if(((LargoRecu(Lista1)==2)) && (streq("atomic", Lista1->palabra)))
        Atomic(Lista1,contadorexp1,ListExpPrincipal);

       else  if(((LargoRecu(Lista1)==2)) && (streq("show", Lista1->palabra)))
            Show(Lista1,ListExpPrincipal,contadorexp1);

            else if(((LargoRecu(Lista1)==2)) && (streq("evaluate", Lista1->palabra)))
                Evaluate(Lista1,ListExpPrincipal,contadorexp1);

                else if(((LargoRecu(Lista1)==3)) && (streq("save", Lista1->palabra)))
                Save(Lista1,ListExpPrincipal,contadorexp1);

                    else if(((LargoRecu(Lista1)==2)) && (streq("load", Lista1->palabra)))
                    Load(Lista1,ListExpPrincipal,contadorexp1);

}while(!(streq("exit", Lista1->palabra)));


}








