#include "Archivo.h"

// Agrega el nuevo entero al final del archivo
void Agregar (str nomArch, int entero){
     FILE * f = fopen (nomArch, "ab");
     fwrite (&entero, sizeof(int), 1, f);
     fclose (f);
}

// Determina si existe o no un archivo con el nombre recibido por parámetro
boolean Existe (str nomArch){
     boolean existeArchivo = TRUE;
     FILE * f = fopen (nomArch, "rb");
     if (f == NULL)
        existeArchivo = FALSE;
     else
        fclose (f);
     return existeArchivo;
}

// Determina si el archivo está vacío o no.
//Precondición: El archivo existe
boolean Vacio (str nomArch){
     boolean archivoVacio = FALSE;
     FILE * f = fopen (nomArch, "rb");
     fseek (f, 0, SEEK_END);
     if (ftell (f) == 0)
        archivoVacio = TRUE;
     fclose (f);
     return archivoVacio;
}

// Determina si el entero recibido está en el archivo.
//Precondición: El archivo existe
boolean Pertenece (str nomArch, int entero){
     boolean esta = FALSE;
     FILE * f = fopen (nomArch, "rb");
     int buffer;
     fread (&buffer, sizeof(int), 1, f);
     while (!feof(f) && !esta)
     {
         if (buffer == entero)
            esta = TRUE;
         else
            fread (&buffer, sizeof(int), 1, f);
     }
     fclose (f);
     return esta;
}

// Devuelve la cantidad de enteros almacenados en el archivo.
//Precondición: El archivo existe
int Largo (str nomArch){
     int largoArchivo;
     FILE * f = fopen (nomArch, "rb");
     fseek (f, 0, SEEK_END);
     largoArchivo = ftell(f) / sizeof(int);
     fclose (f);
     return largoArchivo;
}

// Despliega por pantalla los enteros almacenados en el archivo.
//Precondición: El archivo existe
void Desplegar (str nomArch){
     FILE * f = fopen (nomArch, "rb");
     int buffer;
     fread (&buffer, sizeof(int), 1, f);
     while (!feof(f))
     {
         printf (" %d ", buffer);
         fread (&buffer, sizeof(int), 1, f);
     }
     fclose (f);
}
// Escribe en el archivo los caracteres de ValorNodo
// Precondición: El archivo viene abierto para escritura.
void Bajar_ValorNodo (ValorNodo v, FILE*f){
    fwrite(&v.identificador, sizeof(int), 1, f);
    if (v.discriminante==VALOR) // verifica que sea igual al tipo de nodo.
    {
        fwrite(&v.discriminante, sizeof (TipoNodo), 1, f); //escribe el campo discriminante en el archivo.
        fwrite(&v.dato.valor, sizeof(boolean), 1, f);       //escribe el valor nodo del tipo boolean en el campo dato
    }
    if (v.discriminante==OPERADOR)
    {
        fwrite(&v.discriminante, sizeof (TipoNodo), 1, f);
        fwrite(&v.dato.operador, sizeof(char), 1, f);
    }
      if (v.discriminante==PARENTESIS)
    {
        fwrite(&v.discriminante, sizeof (TipoNodo), 1, f);
        fwrite(&v.dato.parentesis, sizeof(char), 1, f);
    }
}


//lee cada uno de los nodos que alcamenan un ValorNodo y lo guarda en v.dato.valor o v.dato.operador
void Levantar_ValorNodo(ValorNodo &v, FILE*f){
    fread(&v.identificador, sizeof (int), 1, f); //lee el dato desde un archivo (define tamano, tipo de dato)
    fread(&v.discriminante, sizeof(TipoNodo),1,f);
    if(v.discriminante==VALOR)
    {
        fread(&v.dato.valor, sizeof(boolean),1, f);
    }
     if(v.discriminante==OPERADOR)
    {
        fread(&v.dato.operador, sizeof(char),1, f);
    }
     if(v.discriminante==PARENTESIS)
    {
        fread(&v.dato.valor, sizeof(char),1, f);
    }
}


//Guarda el arbol de expresiones en un archivo
//verifica que no este vacio
void Bajar_ArbolExpresiones_Aux(ArbolExpresiones a, FILE*f){
    if (a != NULL)
    {
        Bajar_ValorNodo(a->info , f);
        Bajar_ArbolExpresiones_Aux (a -> hizq, f);
        Bajar_ArbolExpresiones_Aux (a -> hder, f);
    }
}
//Guarda el arbol de expresiones en un archivo
void Bajar_ArbolExpresiones(ArbolExpresiones a, str nomArch){
   FILE* f = fopen (nomArch, "wb"); //abre el archivo en modo escritura.
   Bajar_ArbolExpresiones_Aux(a, f); //usa la funcion auxiliar para realizar la escritura del arbol en el archivo, segun el orden indicado.
   fclose(f);
}

//Carga el arbol de Expresiones desde un archivo
void Levantar_ArbolExpresiones(ArbolExpresiones &a,  str nomArch){
    FILE* f =fopen(nomArch,"rb"); // abre el archivo en modo lectura y se leeran datos binarios.
    if(!Vacio(nomArch))           //Verifica que noe este vacio
    {
    ValorNodo buffer;             //Defino el bufer
    Crear(a);                     //Creo el arbol
    Levantar_ValorNodo(buffer,f);
    while (!feof(f))
    {
        Insert(a,buffer); //inserta los nodos en el arbol
        Levantar_ValorNodo(buffer,f); //lee los nodos del archivo.
    }
    fclose(f);
    }
    else
        printf("\nEl archivo no existe");
}
