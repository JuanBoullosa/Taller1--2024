#include "ArbolExpresiones.h"
#include "Expresiones.h"




/* crear un árbol vacío */
void Crear (ArbolExpresiones &a){
    a = NULL;
}
/* saber si el árbol está vacío */
boolean EsVacio (ArbolExpresiones a){
    return (boolean) (a == NULL);
}

void MostrarArbol (ArbolExpresiones a){
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

void MostrarIDdelArbol (ArbolExpresiones a){
    if (a != NULL)
    {
        MostrarIDdelArbol(a->hizq);
        printf(" %d", a->info.identificador);
        MostrarIDdelArbol(a->hder);
    }

}

void CargarArbolAtomic(ValorNodo ValNodo, ArbolExpresiones &a){
    if((ValNodo.dato.valor==FALSE) || (ValNodo.dato.valor==TRUE))
    {
        a=new nodo;
        a->info = ValNodo;
        a->hizq = NULL;
        a->hder = NULL;
    }
}

void AgregarParentesisIzquierdo(ArbolExpresiones &a,ValorNodo ValorNodoParIzq){
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

void AgregarParentesisDerecho(ArbolExpresiones &a, ValorNodo ValorNodoParDer){
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

ArbolExpresiones Cons (ValorNodo v ,ArbolExpresiones d, ArbolExpresiones &Creado, ValorNodo Izq, ValorNodo Der ){
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
}

void guardarAbbValorNodo ( ValorNodo t, ArbolExpresiones &a ){
    if(a==NULL)
        a=new nodo;

          a->info = t;
          a->hder=NULL;
          a->hizq=NULL;
}

void copiarArbol(ArbolExpresiones &a, ArbolExpresiones b){

    if(b != NULL)
    {
        guardarAbbValorNodo(darValorNodoAbb(b),a);
        copiarArbol(a->hizq,b->hizq);
        copiarArbol(a->hder,b->hder);
    }
}

ValorNodo darValorNodoAbb( ArbolExpresiones a){
     if(a != NULL)
    {
        return a->info;
    }

}

void Insert (ArbolExpresiones &a, ValorNodo v){
    if (a == NULL)
    {
        a = new nodo;
        a -> info = v;
        a -> hizq = NULL;
        a -> hder = NULL;
    }
    else
    {
        if (v.identificador < a->info.identificador)
            Insert (a -> hizq, v);
        else
            Insert (a -> hder, v);
    }
}

void AsignarIDenOrden(ArbolExpresiones &a, int &suma){
    if(a!=NULL)
    {
        AsignarIDenOrden(a->hizq, suma);
        a->info.identificador = suma;
        suma=suma +1;
        AsignarIDenOrden(a->hder, suma);
    }
}

void EliminarAbb (ArbolExpresiones &a){

    if (a != NULL)
    {
        EliminarAbb(a->hizq);
        EliminarAbb(a->hder);
        delete a;
        a = NULL;
    }
}
