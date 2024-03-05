#include "Strigg.h"


void strcrear (str &s){
    s = new char[1];
    s[0] = '\0';
}

void strdestruir (str &s){
    delete [] s;
    s = NULL;
}

int strlar (str s){
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void strcop (str &s1,str s2){
    int i = 0;
    int largo = strlar(s2) + 1;
    delete [] s1;
    s1 = new char[largo];
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void scan (str &s){
    str aux = new char[MAX];
    int i=0;
    char c;
    scanf ("%c", &c);
    while (c!= '\n' && i < MAX-1)
    {
        aux[i] = c;
        i++;
        scanf ("%c", &c);
    }
    aux[i] = '\0';
    strcop (s,aux);
    strdestruir (aux);
}

void print (str s){
    int i = 0;
    while(s[i]!= '\0')
    {
        printf ("%c", s[i]);
        i++;
    }
}

boolean streq(str s1, str s2){
    int i = 0;
    boolean iguales =TRUE;
    while (iguales && (s1[i] != '\0') && (s2[i] != '\0')) {
        if (s1[i] != s2[i])
            iguales =FALSE;
        i++;
    }
    if ((s1[i] != '\0') || (s2[i] != '\0'))
        iguales = FALSE;
    return iguales;
}

void eliminarBlancosPrincipio(str comando, str &sinEspacios) {
    int i = 0;
    int j = 0;

    // Ignorar espacios en blanco al principio de comando
    while (comando[i] == ' ') {
        i++;
    }

    // Calcular el largo de la cadena sin los espacios en blanco al principio
    int largo = strlar(comando + i) + 1;

    // Asignar memoria para sinEspacios y copiar comando sin los espacios en blanco al principio
    delete[] sinEspacios;
    sinEspacios = new char[largo];

    // Copiar los caracteres de comando sin los espacios en blanco al principio a sinEspacios
    while (comando[i] != '\0') {
        sinEspacios[j] = comando[i];
        i++;
        j++;
    }
    sinEspacios[j] = '\0'; // Agregar el terminador nulo al final de sinEspacios
}

void dividirString(str comando, str &palabra1, str &resto) {
    // Definir variables para recorrer el string y calcular la longitud de la primera palabra
    int f = 0;
    int j = 0;

    // Calcular la longitud de la primera palabra
    while (comando[f] != ' ' && comando[f] != '\0') {
        f++;
    }
    // Asignar memoria para palabra1 y copiar la primera palabra
    palabra1 = new char[f + 1];
    for (j = 0; j < f; j++) {
        palabra1[j] = comando[j];
    }
    palabra1[f] = '\0';
    // Calcular el largo del resto
    int largo = strlar(comando) - f + 1;

    // Asignar memoria para resto y copiar el resto del string
    resto = new char[largo];
    j = 0;
    while (comando[f] != '\0') {
        resto[j] = comando[f];
        f++;
        j++;
    }
    resto[j] = '\0';
}

boolean stringVacio (str &s){
  int i = 0;
  boolean vacio = FALSE;

  while(s[i] == ' ')
        i++;


  if(s[i]== '\0')
    vacio = TRUE;
  return vacio;
}

boolean EsDigito (str palabra){

boolean Digito = TRUE;
int i=0;

        while ((palabra[i] != '\0') && (Digito == TRUE))
        {
            if (!(palabra[i] >= '0' && palabra[i] <= '9'))
            Digito = FALSE;
            i++;
        }

            return Digito;

}

boolean Alfabeto (str palabra){

boolean Alfabeto = TRUE;
int i=0;

        while ((palabra[i] != '\0') && (Alfabeto == TRUE))
        {
            return Alfabeto;
            if (!(((palabra[i] >= 'A' && palabra[i] <= 'Z') || (palabra[i] >= 'a' && palabra[i] <= 'z')) || (palabra[i] == '.'  )))
            Alfabeto = FALSE;
            i++;
        }


}

void dividirLoad(str comando, str &archivo, str &dat) {
    // Definir variables para recorrer el string y calcular la longitud de la primera palabra
    int f = 0;
    int j = 0;

    // Calcular la longitud de la primera palabra
    while (comando[f] != '.' && comando[f] != '\0') {
        f++;
    }
    // Asignar memoria para palabra1 y copiar la primera palabra
    archivo = new char[f + 1];
    for (j = 0; j < f; j++) {
        archivo[j] = comando[j];
    }
    archivo[f] = '\0';
    // Calcular el largo del resto
    int largo = strlar(comando) - f + 1;

    // Asignar memoria para resto y copiar el resto del string
    dat = new char[largo];
    j = 0;
    while (comando[f] != '\0') {
        dat[j] = comando[f];
        f++;
        j++;
    }
    dat[j] = '\0';
}
