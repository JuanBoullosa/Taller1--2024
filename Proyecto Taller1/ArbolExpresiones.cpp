#include "ArbolExpresiones.h"
#include "Expresiones.h"




/* crear un �rbol vac�o */
void Crear (ArbolExpresiones &a)
{
    a = NULL;
}

/* saber si el �rbol est� vac�o */
boolean EsVacio (ArbolExpresiones a)
{
    return (boolean) (a == NULL);
}

/* devolver la ra�z del �rbol */
/* Precondici�n: Arbol NO vac�o */
ValorNodo DarRaiz (ArbolExpresiones a)
{
    return a -> info;
}


/* obtener el sub�rbol izquierdo */
/* Precondici�n: Arbol NO vac�o */
ArbolExpresiones HijoIzq (ArbolExpresiones a)
{
    return a -> hizq;
}


/* obtener el sub�rbol derecho */
/* Precondici�n: Arbol NO vac�o */
ArbolExpresiones HijoDer (ArbolExpresiones a)
{
    return a -> hder;
}


/* dados dos �rboles y un valor, devolver un nuevo �rbol
 colocando dicho valor como una nueva ra�z y a los dos
 �rboles como sub�rboles de la misma */
ArbolExpresiones ConsCompound (ValorNodo r,ArbolExpresiones i,ArbolExpresiones d)
{


    ArbolExpresiones a = new nodo;
    a -> info = r;
    a -> hizq = i;
    a -> hder = d;


    return a;
}
// Si el comando compound es una expresion negada se hace de esta forma
ArbolExpresiones CosCompoundNot (ValorNodo r, ArbolExpresiones i)
{
    ArbolExpresiones a = new nodo;
    a-> info = r;
    a-> hder = i;
    return a;
}


void MostrarArbol (ArbolExpresiones a)
{
    if (a != NULL)
    {
        MostrarArbol(a->hizq);

        if (a->info.dato.valor == FALSE)
            printf(" FALSE ");
        if (a->info.dato.valor== TRUE)
                    printf(" TRUE ");
        if (a->info.dato.operador == 'A')
                printf(" AND ");
        if (a->info.dato.operador == 'O')
                printf(" OR ");
        if (a->info.dato.operador == 'N')
                printf(" NOT ");
        if (a->info.dato.parentesis == '(' )
                printf(" ( ");
        if (a->info.dato.parentesis == ')' )
                printf(" ) ");

        MostrarArbol(a->hder);

    }

}

void CargarArbolNOTSinParent(ValorNodo ValorNodoNOT,ArbolExpresiones arbolexpreID,ArbolExpresiones &a,ArbolExpresiones ArbolParIzq)
{
        a=new nodo;
        a->info = ValorNodoNOT;
        a->hder = arbolexpreID;
        a->hizq = ArbolParIzq;
}



void CargarArbolAtomic(ValorNodo ValNodo, ArbolExpresiones &a)
{
    if((ValNodo.dato.valor==FALSE) || (ValNodo.dato.valor==TRUE))
    {
        a=new nodo;
        a->info = ValNodo;
        a->hizq = NULL;
        a->hder = NULL;
    }
}




void AgregarParentesisIzquierdo(ArbolExpresiones &a,ValorNodo ValorNodoParIzq)
{
    if (a->hizq == NULL)
    {
        a->hizq =new nodo;
        a->hizq->info = ValorNodoParIzq;
        a->hder->hizq = NULL;
        a->hder->hder = NULL;
    }
    else
    {
        AgregarParentesisIzquierdo(a->hizq,ValorNodoParIzq);
    }
}


void AgregarParentesisDerecho(ArbolExpresiones &a, ValorNodo ValorNodoParDer)
{
    if (a->hder == NULL)
    {
        // Agregar un nuevo nodo como hijo derecho si el nodo actual no tiene uno
        a->hder = new nodo;
        a->hder->info = ValorNodoParDer;
        a->hder->hizq = NULL;
        a->hder->hder = NULL;
    }
    else
    {
        AgregarParentesisDerecho(a->hder,ValorNodoParDer);
    }
}


void CargarArbolParentesisIZQ(ArbolExpresiones &a, ValorNodo ValorNodoParIzq)
{
        a=new nodo;
        a->info = ValorNodoParIzq;
        a->hder = NULL;
        a->hizq = NULL;
}
