#include "ListaString.h"
#include "Strigg.h"


//Crear lista
void CrearLista (ListaString &L){
  L=NULL;
}
//Mostrar Lista
void MostrarLista (ListaString L){
    while (L != NULL)
    {
      print (L->palabra);
      printf(" ");
      L = L -> sig;
    }
}

int LargoRecu (ListaString L){
    if (L == NULL)
        return 0;
    else
        return 1 + LargoRecu (L->sig);
}
//Mostrar si la lista es vacia
boolean Vacia (ListaString L){
boolean esVacia = FALSE;
if (L == NULL)
esVacia = TRUE;
return esVacia;
}
//Agregar al final de la lista
void InsBackIter(ListaString &L, str palabraS) {
    ListaString nuevo = new NodoS;

    //creamos un nuevo puntero que guarda el contenido de palabraS
    strcrear(nuevo->palabra);
    strcop(nuevo->palabra,palabraS);

    nuevo->sig = NULL;

    if (L == NULL) {
        L = nuevo;
    } else {
        ListaString aux = L;
        // Buscar el �ltimo nodo de la lista
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        // Insertar el nuevo nodo al final de la lista
        aux->sig = nuevo;
    }
}

void EliminarListaString (ListaString &L){
    if (L != NULL)
    {
        EliminarListaString (L->sig);
        delete L;
        L = NULL;
    }
}

void partirString(str s, ListaString &L) {


    EliminarListaString(L);
    CrearLista(L);

    str aux;
    strcrear(aux);
    strcop(aux , s);
    str aux2 ;
    str s1;
    str s2;



    while (!stringVacio(aux)) {
        strcrear(aux2);
        eliminarBlancosPrincipio(aux , aux2);

        strcrear(s1);
        strcrear(s2);
        dividirString(aux2, s1, s2);
        InsBackIter(L, s1);
        strdestruir(aux);
        strcrear(aux);
        strcop(aux, s2); // Actualizar auxiliar para el siguiente ciclo

        strdestruir(aux2);
        strdestruir(s1);
        strdestruir(s2);
        }
    strdestruir(aux);

}






