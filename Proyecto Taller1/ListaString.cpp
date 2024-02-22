#include "ListaString.h"
#include "Strigg.h"


//Crear lista
void CrearLista (ListaString &L)
{
  L=NULL;
}

//Mostrar Lista
void MostrarLista (ListaString L)
{
    while (L != NULL)
    {
      printf ("%s", L->palabra);
      printf(" ");
      L = L -> sig;
    }
}
int LargoRecu (ListaString L)
{
    if (L == NULL)
        return 0;
    else
        return 1 + LargoRecu (L->sig);
}
//Mostrar si la lista es vacia
boolean Vacia (ListaString L)
{
boolean esVacia = FALSE;
if (L == NULL)
esVacia = TRUE;
return esVacia;
}

//Insertar string al principio de la lista
void InsFront (ListaString &L, str stringg)
{
  ListaString aux = new NodoS;
  aux->palabra = stringg;
  aux->sig = L;
  L = aux;
}
//Agregar al final de la lista
void InsBackIter(ListaString &L, str palabraS) {
    ListaString nuevo = new NodoS;
    nuevo->palabra = palabraS;
    nuevo->sig = NULL;

    if (L == NULL) {
        L = nuevo;
    } else {
        ListaString aux = L;
        // Buscar el último nodo de la lista
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        // Insertar el nuevo nodo al final de la lista
        aux->sig = nuevo;
    }
}


void partirString(str s, ListaString &L) {
    str aux;
    strcrear(aux);
    str aux2;
    strcrear(aux2);
    strcop(aux , s);


        while (!stringVacio(aux)) {
        eliminarBlancosPrincipio(aux , aux2);
        str s1, s2 ;
        dividirString(aux2, s1, s2);
        InsBackIter(L, s1);
        strcop(aux, s2); // Actualizar auxiliar para el siguiente ciclo

        }

    delete[] aux;
    delete[] aux2;
}




