#include "ArbolExpresiones.h"
#include "Expresiones.h"




/* crear un árbol vacío */
void Crear (ArbolExpresiones &a)
{
    a = NULL;
}

/* saber si el árbol está vacío */
boolean EsVacio (ArbolExpresiones a)
{
    return (boolean) (a == NULL);
}

/* devolver la raíz del árbol */
/* Precondición: Arbol NO vacío */
ValorNodo DarRaiz (ArbolExpresiones a)
{
    return a -> info;
}


/* obtener el subárbol izquierdo */
/* Precondición: Arbol NO vacío */
ArbolExpresiones HijoIzq (ArbolExpresiones a)
{
    return a -> hizq;
}


/* obtener el subárbol derecho */
/* Precondición: Arbol NO vacío */
ArbolExpresiones HijoDer (ArbolExpresiones a)
{
    return a -> hder;
}


/* dados dos árboles y un valor, devolver un nuevo árbol
 colocando dicho valor como una nueva raíz y a los dos
 árboles como subárboles de la misma */
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
        if (a->info.dato.valor == TRUE)
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
    if (a == NULL)
    {
        a =new nodo;
        a->info = ValorNodoParIzq;
        a->hizq = NULL;
        a->hder = NULL;
    }
    else
    {
        AgregarParentesisIzquierdo(a->hizq,ValorNodoParIzq);
    }
}

void AgregarParentesisDerecho(ArbolExpresiones &a, ValorNodo ValorNodoParDer)
{
    if (a == NULL)
    {
        // Agregar un nuevo nodo como hijo derecho si el nodo actual no tiene uno
        a = new nodo;
        a->info = ValorNodoParDer;
        a->hizq = NULL;
        a->hder = NULL;
    }
    else
    {
        AgregarParentesisDerecho(a->hder,ValorNodoParDer);
    }
}

void CargarArbolParentesis(ArbolExpresiones &a, ValorNodo ValorNodoParIzq)
{
        a=new nodo;
        a->info = ValorNodoParIzq;
        a->hder = NULL;
        a->hizq = NULL;
}

ArbolExpresiones Cons (ValorNodo v ,ArbolExpresiones d, ArbolExpresiones &Creado, ValorNodo Izq, ValorNodo Der )
{
    Creado = new nodo;
    Creado -> info = v;
    copiarArbol(Creado->hder, d);

    AgregarParentesisIzquierdo(Creado->hizq, Izq);
    AgregarParentesisDerecho(Creado->hder, Der);
}

void Cons2(ValorNodo v, ArbolExpresiones i, ArbolExpresiones d, ValorNodo Izq, ValorNodo Der, ArbolExpresiones &Creado) {

    Creado = new nodo;
    Creado -> info = v;
    copiarArbol(Creado->hder, d);
    copiarArbol(Creado->hizq, i);

    AgregarParentesisIzquierdo(Creado->hizq, Izq);
    AgregarParentesisDerecho(Creado->hder, Der);






}

boolean EvaluarArbol(ArbolExpresiones a, boolean &result )
{
    if (( a->info.dato.valor == TRUE) || ( a->info.dato.valor == FALSE))
        {
                result = a->info.dato.valor;
        }
    else
        {
                if ((a->info.dato.operador == 'A'))
                    EvaluarArbol(a->hder, result) && EvaluarArbol(a->hizq, result);
                if ((a->info.dato.operador == 'O'))
                    EvaluarArbol(a->hder, result) || EvaluarArbol(a->hizq, result);
                if  ((a->info.dato.operador == 'N'))
                    !EvaluarArbol(a->hder, result);
        }
        return result;

}

void guardarAbbValorNodo ( ValorNodo t, ArbolExpresiones &a )
{
    if(a==NULL)
        a=new nodo;

          a->info = t;
          a->hder=NULL;
          a->hizq=NULL;
}

void abreParentesis( ArbolExpresiones &a){
    ValorNodo t;
   // cargar tipo nodo en t: cargaTNodo(t.discriminante,3);
   // cargo el char parentesis t.dato.parentesis = ')': cargaDatoParentesis(t,'(');

   if(a!=NULL)
        abreParentesis(a->hizq);
    else
    {
         a=new nodo;
         guardarAbbValorNodo(t,a);
     }
}

void copiarArbol(ArbolExpresiones &a, ArbolExpresiones b){

    if(b != NULL)
    {
        guardarAbbValorNodo(darValorNodoAbb(b),a);
        copiarArbol(a->hizq,b->hizq);
        copiarArbol(a->hder,b->hder);
    }
}

ValorNodo darValorNodoAbb( ArbolExpresiones a)
{
     if(a != NULL)
    {
        return a->info;
    }

}



