#include "Archivo.h"


void Agregar (str nomArch, int entero){
     FILE * f = fopen (nomArch, "ab");
     fwrite (&entero, sizeof(int), 1, f);
     fclose (f);
}

boolean Existe (str nomArch){
     boolean existeArchivo = TRUE;
     FILE * f = fopen (nomArch, "rb");
     if (f == NULL)
        existeArchivo = FALSE;
     else
        fclose (f);
     return existeArchivo;
}

boolean Vacio (str nomArch){
     boolean archivoVacio = FALSE;
     FILE * f = fopen (nomArch, "rb");
     fseek (f, 0, SEEK_END);
     if (ftell (f) == 0)
        archivoVacio = TRUE;
     fclose (f);
     return archivoVacio;
}

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

int Largo (str nomArch){
     int largoArchivo;
     FILE * f = fopen (nomArch, "rb");
     fseek (f, 0, SEEK_END);
     largoArchivo = ftell(f) / sizeof(int);
     fclose (f);
     return largoArchivo;
}

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
    if (v.discriminante==VALOR)
    {
        fwrite(&v.discriminante, sizeof (TipoNodo), 1, f);
        fwrite(&v.dato.valor, sizeof(boolean), 1, f);
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

void Levantar_ValorNodo(ValorNodo &v, FILE*f){
    fread(&v.identificador, sizeof (int), 1, f);
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

void Bajar_ArbolExpresiones_Aux(ArbolExpresiones a, FILE*f){
    if (a != NULL)
    {
        Bajar_ValorNodo(a->info , f);
        Bajar_ArbolExpresiones_Aux (a -> hizq, f);
        Bajar_ArbolExpresiones_Aux (a -> hder, f);
    }
}

void Bajar_ArbolExpresiones(ArbolExpresiones a, str nomArch){
   FILE* f = fopen (nomArch, "wb");
   Bajar_ArbolExpresiones_Aux(a, f);
   fclose(f);
}

void Levantar_ArbolExpresiones(ArbolExpresiones &a,  str nomArch){
    FILE* f =fopen(nomArch,"rb");
    if(!Vacio(nomArch))
    {
    ValorNodo buffer;
    Crear(a);
    Levantar_ValorNodo(buffer,f);
    while (!feof(f))
    {
        Insert(a,buffer);
        Levantar_ValorNodo(buffer,f);
    }
    fclose(f);
    }
    else
        printf("\nEl archivo no existe");
}
